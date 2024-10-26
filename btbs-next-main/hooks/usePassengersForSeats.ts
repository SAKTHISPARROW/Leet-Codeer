import { Passenger } from "@/components/Passengers";
import useFetch from "react-fetch-hook";

const usePassengersForSeats = (
  username: string,
  date: string,
  bus_id: number
) => {
  return useFetch<Passenger[]>(
    `http://127.0.0.1:8000/passenger/${username}?date=${date}&bus_id=${bus_id}`
  );
};

export default usePassengersForSeats;
