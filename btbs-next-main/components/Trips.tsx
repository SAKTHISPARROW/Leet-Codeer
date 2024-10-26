import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import usePassengers from "@/hooks/usePassengers";
import useTrips from "@/hooks/useTrips";
import useUserStore from "@/store/userStore";
import { Button } from "./ui/button";
import useCancelTrip from "@/hooks/useCancelTrip";
import { Trip } from "@/hooks/useTrips";
import { useState } from "react";
import { TicketDetailProps } from "@/hooks/useTickets";

const Trips = () => {
  const userStore = useUserStore();

  const { data: passengers } = usePassengers(userStore.username);

  const passengerMap = new Map<number, string>();
  passengers?.forEach((p) => passengerMap.set(p.id, p.name));

  const { isLoading, trips, error } = useTrips(userStore.username);

  const handleCancel = (tickets: TicketDetailProps[]) => {
    useCancelTrip(tickets);
  };

  if (isLoading) {
    return <p>Loading...</p>;
  }

  if (error) {
    return <p>{error.message}</p>;
  }

  if (!trips) {
    return <p>Loading...</p>;
  }

  return (
    <div>
      <h1 className="text-2xl m-4">Trips</h1>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Date</TableHead>
            <TableHead>Cancel Trip</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {Object.entries(trips).map(([date, tickets]) => {
            return (
              <TableRow key={date}>
                <TableCell>{date}</TableCell>
                <TableCell>
                  <Button
                    onClick={() => {
                      handleCancel(tickets);
                    }}
                  >
                    Cancel
                  </Button>
                </TableCell>
              </TableRow>
            );
          })}
        </TableBody>
      </Table>
    </div>
  );
};

export default Trips;
