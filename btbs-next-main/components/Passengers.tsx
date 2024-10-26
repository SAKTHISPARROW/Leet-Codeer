import useUserStore from "@/store/userStore";
import usePassengers from "@/hooks/usePassengers";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import { Button } from "./ui/button";
import FetchClient from "@/fetch-client";
import { Input } from "./ui/input";
import { useRef } from "react";

export interface Passenger {
  id: number;
  name: string;
  gender: string;
}

const Passengers = () => {
  const userStore = useUserStore();
  const fetchClient = new FetchClient();

  const {
    isLoading,
    data: passengers,
    error,
  } = usePassengers(userStore.username);

  const nameRef = useRef<HTMLInputElement>(null);
  const genderRef = useRef<HTMLInputElement>(null);

  const handleAdd = async () => {
    const name = nameRef.current?.value;
    const gender = genderRef.current?.value;

    if (!name || !gender) {
      alert("Please fill in all fields");
      return;
    }

    await fetchClient
      .post(
        `/passenger?name=${name}&gender=${gender}&username=${userStore.username}`
      )
      .then((data) =>
        data === true
          ? window.location.reload()
          : console.log("Failed to add user")
      );
  };

  const handleRemove = async (passenger_id: number) => {
    await fetchClient
      .delete(`/passenger?passenger_id=${passenger_id}`)
      .then((data) =>
        data === true
          ? window.location.reload()
          : console.log("Failed to remove user")
      );
  };

  if (isLoading) {
    return <p>Loading...</p>;
  }

  if (error) {
    return <p>{error.message}</p>;
  }

  if (!passengers) {
    return <p>Loading...</p>;
  }

  return (
    <div>
      <h1 className="text-2xl m-4">Passengers</h1>
      <div className="flex flex-row m-4 space-x-4">
        <Input type="text" placeholder="Passenger name" ref={nameRef} />
        <Input type="text" placeholder="Gender" ref={genderRef} />
        <Button onClick={handleAdd}>Add Passenger</Button>
      </div>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Name</TableHead>
            <TableHead>Gender</TableHead>
            <TableHead>Remove</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {passengers?.map((p) => (
            <TableRow key={p.id}>
              <TableCell>{p.name}</TableCell>
              <TableCell>{p.gender}</TableCell>
              <TableCell>
                <Button onClick={() => handleRemove(p.id)}>Remove</Button>
              </TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
    </div>
  );
};

export default Passengers;
