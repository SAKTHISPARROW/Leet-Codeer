import useFetch from "react-fetch-hook";

const baseURL = "http://127.0.0.1:8000";

const options = {
  method: "GET",
  headers: {
    accept: "application/json",
    "content-type": "application/x-www-form-urlencoded",
  },
};

class APIFetchClient<T> {
  endpoint: string;

  constructor(endpoint: string) {
    this.endpoint = endpoint;
  }

  get = (data?: string) => {
    if (data === undefined) data = "";
    options.method = "GET";
    return useFetch<T>(baseURL + this.endpoint + data, options);
  };

  post = (data: string) => {
    options.method = "POST";
    return useFetch<T>(baseURL + this.endpoint + data, options);
  };
}

export default APIFetchClient;
