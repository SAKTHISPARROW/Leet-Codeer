import APIFetchClient from "@/api-fetch-client";

export interface VisitorDetailProps {
  date: string;
  visitor_count: number;
}

const apiFetchClient = new APIFetchClient<VisitorDetailProps[]>(
  "/admin/visitors/all"
);

const useVisitors = () => apiFetchClient.get();

export default useVisitors;
