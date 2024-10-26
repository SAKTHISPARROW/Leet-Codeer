import useFetch from "react-fetch-hook";
import Seats from "./Seats";
import useDateStore from "@/store/useDateStore";
import { useEffect } from "react";
import FetchClient from "@/fetch-client";
import { useRouter } from "next/navigation";

export interface Bus {
  id: number;
  total_seats: number;
  available_seats: number[];
  booked_seats: number[];
  load_factor: number;
}

const Bus = ({ id }: any) => {
  const dateStore = useDateStore();
  const fetchClient = new FetchClient();

  const {
    isLoading,
    data: bus,
    error,
  } = useFetch<Bus>(`http://127.0.0.1:8000/bus/${id}?date=${dateStore.date}`);

  const ws = new WebSocket("ws://127.0.0.1:8000/ws/mergestatus");
  ws.onmessage = (event) => {
    let res = JSON.parse(event.data);
    let mergeDetails = JSON.parse(res);

    if (mergeDetails.date === dateStore.date) {
      if (
        Number(id) === mergeDetails.bus1_id ||
        Number(id) === mergeDetails.bus2_id
      ) {
        if (alert("Bus alteration in process") !== null) {
          window.location.reload();
        }
      }
    }
  };

  if (isLoading) {
    return <p>Loading...</p>;
  }

  if (error) {
    return <p>Error: {error.message}</p>;
  }

  return (
    <div className="m-10">
      <h1 className="text-3xl">Bus ID: {bus?.id}</h1>
      <Seats bus={bus as Bus} date={dateStore.date} />
    </div>
  );
};

export default Bus;
