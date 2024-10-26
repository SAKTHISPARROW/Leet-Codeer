import useBuses from "@/hooks/useBuses";
import React, { useRef } from "react";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import { Button } from "./ui/button";
import { useRouter } from "next/navigation";
import { Input } from "./ui/input";
import FetchClient from "@/fetch-client";

const BusManager = () => {
  const router = useRouter();
  const { isLoading, data: buses, error } = useBuses();

  const busIDRef = useRef<HTMLInputElement>(null);
  const totalSeatsRef = useRef<HTMLInputElement>(null);

  const fetchClient = new FetchClient();

  const handleAdd = async () => {
    const bus_id = busIDRef.current?.value;
    const total_seats = totalSeatsRef.current?.value;

    if (!bus_id || !total_seats) {
      alert("Please fill in all fields");
      return;
    }

    await fetchClient
      .post(`/admin/bus/add?bus_id=${bus_id}&total_seats=${total_seats}`)
      .then((data) =>
        data === true ? window.location.reload() : console.log(data)
      );
  };

  const handleRemove = async (bus_id: number) => {
    await fetchClient
      .delete(`/admin/bus/delete?bus_id=${bus_id}`)
      .then((data) =>
        data === true ? window.location.reload() : console.log(data)
      );
  };

  return (
    <div>
      <h2 className="text-2xl m-4">BusManager</h2>
      <div className="flex flex-row m-4 space-x-4">
        <Input type="number" placeholder="Bus ID" ref={busIDRef} />
        <Input type="number" placeholder="Total Seats" ref={totalSeatsRef} />
        <Button onClick={handleAdd}>Add Bus</Button>
      </div>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Bus ID</TableHead>
            <TableHead className="">Total Seats</TableHead>
            <TableHead>Remove</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {buses?.map((bus) => (
            <TableRow key={bus.id}>
              <TableCell>{bus.id}</TableCell>
              <TableCell>{bus.total_seats}</TableCell>
              <TableCell>
                <Button onClick={() => handleRemove(bus.id)}>Remove</Button>
              </TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
      {isLoading && <p>Loading...</p>}
      {error && <p>Error loading visitors {error.message}</p>}
    </div>
  );
};

export default BusManager;
