const BASE_URL = "http://127.0.0.1:8000";

class FetchClient {
  get = async (endpoint: string) =>
    fetch(BASE_URL + endpoint, {
      method: "GET",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
    }).then((res) => res.json());

  post = async (endpoint: string) =>
    fetch(BASE_URL + endpoint, {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
    }).then((res) => res.json());

  delete = async (endpoint: string) =>
    fetch(BASE_URL + endpoint, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
    }).then((res) => res.json());
}

export default FetchClient;
