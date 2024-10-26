import FetchClient from "@/fetch-client";

const fetchClient = new FetchClient();

export interface CancelResponse {
  error?: string;
  success?: string;
}

const useCancelwID = (ticket_id: number) =>
  fetchClient.delete(`/ticket/${ticket_id}`);

export default useCancelwID;
