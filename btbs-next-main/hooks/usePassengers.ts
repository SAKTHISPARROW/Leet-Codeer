import { Passenger } from "@/components/Passengers";
import useFetch from "react-fetch-hook";

const usePassengers = (username: string) => {
  return useFetch<Passenger[]>(
    `http://127.0.0.1:8000/passenger/${username}/all`
  );
};

export default usePassengers;
