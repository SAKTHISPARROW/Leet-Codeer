import { useState } from "react";
import Seat from "./Seat";
import { Button } from "./ui/button";
import { useRouter } from "next/navigation";
import useBook from "@/hooks/useBook";
import { Bus } from "./Bus";
import useCancel from "@/hooks/useCancel";
import useUserStore from "@/store/userStore";
import usePassengers from "@/hooks/usePassengers";
import { Select, SelectItem, SelectTrigger, SelectValue } from "./ui/select";
import { SelectContent } from "@radix-ui/react-select";
import { Passenger } from "./Passengers";
import { Dialog } from "./ui/dialog";
import PaymentDialog from "./PaymentDialog";
import usePassengersForSeats from "@/hooks/usePassengersForSeats";

interface Props {
  bus: Bus;
  date: string;
}

interface SeatMap {
  seat: number;
  passenger: number;
}

const Seats = ({ bus, date }: Props) => {
  const userStore = useUserStore();
  const {
    isLoading,
    data: passengers,
    error,
  } = usePassengersForSeats(userStore.username, date, bus.id);

  const [seatMap, setSeatMap] = useState<SeatMap[]>([]);

  const { id: bus_id, total_seats, booked_seats } = bus;

  const [selectedSeats, setSelectedSeats] = useState<number[]>([]);
  const [selectedSeatsForCancellation, setSelectedSeatsForCancellation] =
    useState<number[]>([]);

  const [bookedPassengers, setBookedPassengers] = useState<number[]>([]);

  const [lock, setLock] = useState(false);

  const handleSeatPassengerSelection = (seat: number, passenger: number) => {
    const newSeatMap = seatMap.filter((map) => map.seat !== seat);
    setSeatMap([...newSeatMap, { seat, passenger }]);
  };

  const handleBooking = async () => {
    if (!lock) {
      console.log("Can't proceed with the request. Lock not acquired");
    }

    if (selectedSeats.length === 0) {
      alert("Please select a seat");
      return;
    }

    if (passengers && selectedSeats.length > passengers?.length) {
      alert("Passenger must be present for every seat");
      return;
    }

    const ticketsDetail = selectedSeats.map((seat) => {
      return {
        bus_id,
        seat_id: seat,
        passenger_id: seatMap.find((m) => m.seat === seat)?.passenger,
        date,
        lock,
      };
    });

    const res = await useBook(bus_id, ticketsDetail);
    if (res[0].success) {
      window.location.reload();
    }
  };

  const handleCancellation = async () => {
    if (selectedSeatsForCancellation.length === 0) {
      alert("No seats selected for cancellation");
      return;
    }

    selectedSeatsForCancellation.forEach((seat) => {
      useCancel(bus_id, ["seat_id=" + seat, "date=" + date], userStore.username)
        .then((res) => {
          if (res.success) {
            window.location.reload();
          }
        })
        .catch((error) => {
          alert(error.response.data.error);
        });
    });
  };

  return (
    <>
      <div className="flex">
        {Array.from({ length: total_seats }, (_, i) =>
          booked_seats.includes(i + 1) ? (
            <Seat
              key={i + 1}
              id={i + 1}
              isBooked={true}
              selectedFn={() => {}}
              selectedFnCancel={(id) =>
                selectedSeatsForCancellation.includes(id)
                  ? setSelectedSeatsForCancellation(
                      selectedSeatsForCancellation.filter((seat) => seat !== id)
                    )
                  : setSelectedSeatsForCancellation([
                      ...selectedSeatsForCancellation,
                      id,
                    ])
              }
            />
          ) : (
            <Seat
              key={i + 1}
              id={i + 1}
              isBooked={false}
              selectedFn={(id) =>
                selectedSeats.includes(id)
                  ? setSelectedSeats(
                      selectedSeats.filter((seat) => seat !== id)
                    )
                  : setSelectedSeats([...selectedSeats, id])
              }
              selectedFnCancel={() => {}}
            />
          )
        )}
      </div>
      {selectedSeats.length > 0 && (
        <div className="flex flex-row">
          <h2 className="text-2xl mr-4">Seat</h2>
          <h2 className="text-2xl">Passenger</h2>
        </div>
      )}
      {selectedSeats.map((seat) => (
        <div className="flex flex-row m-4" key={seat}>
          <h2 className="text-2xl mr-8">{seat}</h2>
          <Select
            onValueChange={(value) => (
              handleSeatPassengerSelection(seat, Number(value)),
              setBookedPassengers([...bookedPassengers, Number(value)])
            )}
          >
            <SelectTrigger className="w-[180px]">
              <SelectValue placeholder="Select a passenger">
                {passengers?.find(
                  (p) =>
                    p.id === seatMap.find((m) => m.seat === seat)?.passenger
                )?.name || ""}
              </SelectValue>
            </SelectTrigger>
            <SelectContent>
              {passengers
                ?.filter((p) => !bookedPassengers.includes(p.id))
                .map((passenger) => (
                  <SelectItem
                    key={passenger.id}
                    value={passenger.id.toString()}
                  >
                    {passenger.name}
                  </SelectItem>
                ))}
            </SelectContent>
          </Select>
        </div>
      ))}
      <div className="my-2">
        {
          <PaymentDialog
            bookButton={<Button className="m-2 ml-0">Book</Button>}
            handleBooking={handleBooking}
            date={date}
            bus_id={bus.id}
            selectedSeats={selectedSeats}
            setLock={setLock}
          />
        }
        <Button className="m-2" onClick={handleCancellation}>
          Cancel
        </Button>
      </div>
    </>
  );
};

export default Seats;
