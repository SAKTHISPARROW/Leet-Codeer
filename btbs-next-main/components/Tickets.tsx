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
import { useRef, useState } from "react";
import useTickets from "@/hooks/useTickets";
import useCancel from "@/hooks/useCancel";
import useCancelwID from "@/hooks/useCancelwID";

// response is either {"error": "error message"} or {"success": "success message"}

const Tickets = () => {
  const userStore = useUserStore();

  const { isLoading, data: tickets, error } = useTickets(userStore.username);
  const { data: passengers } = usePassengers(userStore.username);

  const passengerMap = new Map<number, string>();
  passengers?.forEach((p) => passengerMap.set(p.id, p.name));

  const handleCancel = (ticket_id: number) => {
    useCancelwID(ticket_id).then((data) =>
      data.error ? console.log(data.error) : window.location.reload()
    );
  };

  if (isLoading) {
    return <p>Loading...</p>;
  }

  if (error) {
    return <p>{error.message}</p>;
  }

  if (!tickets) {
    return <p>Loading...</p>;
  }

  return (
    <div>
      <h1 className="text-2xl m-4">Tickets</h1>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Date</TableHead>
            <TableHead>Passenger Name</TableHead>
            <TableHead>Bus Id</TableHead>
            <TableHead>Seat Id</TableHead>
            <TableHead>Cancel</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {tickets?.map((p) => (
            <TableRow key={p.id}>
              <TableCell>{p.date}</TableCell>
              <TableCell>{passengerMap.get(p.passenger_id)}</TableCell>
              <TableCell>{p.bus_id}</TableCell>
              <TableCell>{p.seat_id}</TableCell>
              <TableCell>
                <Button onClick={() => handleCancel(p.id)}>Cancel</Button>
              </TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
    </div>
  );
};

export default Tickets;
