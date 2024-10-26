import APIFetchClient from "@/api-fetch-client";

export interface TicketDetailProps {
  id: number;
  passenger_id: number;
  bus_id: number;
  seat_id: number;
  date: string;
}

const apiFetchClient = new APIFetchClient<TicketDetailProps[]>(`/ticket/all`);

const useTickets = (username: string) => apiFetchClient.get(`/${username}`);

export default useTickets;
