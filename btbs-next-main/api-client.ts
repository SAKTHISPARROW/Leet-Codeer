import axios from "axios";

const axiosInstance = axios.create({
  baseURL: "http://127.0.0.1:8000/",
  headers: {
    "Content-Type": "application/json",
  },
});

class APIClient {
  endpoint: string;

  constructor(endpoint: string) {
    this.endpoint = endpoint;
  }

  get = (str?: string) => {
    return axiosInstance.get(this.endpoint + str).then((res) => res.data);
  };

  post = (str: string, data: any) => {
    return axiosInstance
      .post(this.endpoint + str, data)
      .then((res) => res.data);
  };

  delete = (str: string) => {
    return axiosInstance.delete(this.endpoint + str).then((res) => res.data);
  };
}

export default APIClient;
