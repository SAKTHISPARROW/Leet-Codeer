import APIFetchClient from "@/api-fetch-client";

const apiFetchClient = new APIFetchClient<number[][]>("/admin/bus/merge");

const useMerge = (date: string, bus1: number, bus2: number) =>
  apiFetchClient.post(`?date=${date}&bus1=${bus1}&bus2=${bus2}`);

export default useMerge;
