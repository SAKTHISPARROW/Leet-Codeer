import APIFetchClient from "@/api-fetch-client";

const apiFetchClient = new APIFetchClient<number[][]>(
  "/admin/bus/mergecandidates"
);

const useMergeCandidates = (date: string) =>
  apiFetchClient.get(`?date=${date}`);

export default useMergeCandidates;
