import APIClient from "@/api-client";

const apiClient = new APIClient("bus/");

const useBook = async (id: number, data: any) => apiClient.post(`${id}/book`, data);

export default useBook;
