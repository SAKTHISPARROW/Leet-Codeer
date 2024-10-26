import APIClient from "@/api-client";

const apiClient = new APIClient("bus/");

const useBus = (id: number) => apiClient.get(`${id}?date=2024-02-16`);

export default useBus;
