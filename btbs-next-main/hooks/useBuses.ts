import APIFetchClient from "@/api-fetch-client";

export interface BusProps {
  id: number;
  total_seats: number;
}

const apiFetchClient = new APIFetchClient<BusProps[]>("/admin/bus/all");

const useBuses = () => apiFetchClient.get();

export default useBuses;
