import APIClient from "@/api-client";

const apiClient = new APIClient("bus/");

const useCancel = async (id: number, data: string[], username: string) =>
  apiClient.delete(`cancel/${id}?${data.join("&")}&username=${username}`);

export default useCancel;
