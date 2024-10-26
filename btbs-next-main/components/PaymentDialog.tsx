import React, { ReactNode, useEffect, useRef, useState } from "react";
import {
  Dialog,
  DialogClose,
  DialogContent,
  DialogDescription,
  DialogFooter,
  DialogHeader,
  DialogTitle,
  DialogTrigger,
} from "./ui/dialog";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import FetchClient from "@/fetch-client";

interface PaymentDialogProps {
  bookButton: ReactNode;
  handleBooking: () => void;
  date: string;
  bus_id: number;
  selectedSeats: number[];
  setLock: (lock: boolean) => void;
}

const PaymentDialog = ({
  bookButton,
  handleBooking,
  date,
  bus_id,
  selectedSeats: seat_ids,
  setLock,
}: PaymentDialogProps) => {
  const [timer, setTimer] = useState(15);
  const closeRef = useRef<HTMLButtonElement>(null);

  const setBeingBooked = () => {
    fetch(
      `http://127.0.0.1:8000/beingbooked/set?date=${date}&bus_id=${bus_id}`,
      {
        method: "POST",
        headers: {
          accept: "application/json",
          "Content-Type": "application/json",
        },
        body: JSON.stringify(seat_ids),
      }
    );
  };

  const resetBeingBooked = () => {
    fetch(
      `http://127.0.0.1:8000/beingbooked/reset?date=${date}&bus_id=${bus_id}`,
      {
        method: "POST",
        headers: {
          accept: "application/json",
          "Content-Type": "application/json",
        },
        body: JSON.stringify(seat_ids),
      }
    );
  };

  const handleOpening = (open: boolean) => {
    if (open) {
      fetch(
        `http://127.0.0.1:8000/checkbeingbooked?date=${date}&bus_id=${bus_id}`,
        {
          method: "POST",
          headers: {
            accept: "application/json",
            "Content-Type": "application/json",
          },
          body: JSON.stringify(seat_ids),
        }
      )
        .then((res) => res.json())
        .then((data) => {
          data
            ? (alert("Seats are already being booked by someone else"),
              closeRef.current?.click())
            : (setBeingBooked(), setLock(true));
        });
      setTimer(15);
      const interval = setInterval(() => {
        setTimer((prev) => {
          if (prev === 0) {
            clearInterval(interval);
            closeRef.current?.click();
            return 0;
          }
          return prev - 1;
        });
      }, 1000);
      return () => clearInterval(interval);
    } else {
      setTimer(15);
      resetBeingBooked();
    }
  };

  return (
    <Dialog onOpenChange={handleOpening}>
      <DialogTrigger asChild>{bookButton}</DialogTrigger>
      <DialogContent>
        <DialogHeader>
          <DialogTitle>Payment</DialogTitle>
          <DialogDescription>
            Make your payment within the time window{" "}
            <span className="text-red-500">{timer}</span>
          </DialogDescription>
        </DialogHeader>
        <div className="flex flex-col m-4">
          <Input placeholder="Amount" />
          <DialogFooter>
            <DialogClose asChild>
              <div>
                <Button className="m-4" onClick={handleBooking}>
                  Pay
                </Button>
                <Button className="m-4" ref={closeRef}>
                  Cancel
                </Button>
              </div>
            </DialogClose>
          </DialogFooter>
        </div>
      </DialogContent>
    </Dialog>
  );
};

export default PaymentDialog;
