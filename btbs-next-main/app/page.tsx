"use client";

import useFetch from "react-fetch-hook";
import Buses from "@/components/Buses";
import { useEffect, useState } from "react";
import { formatDate } from "date-fns";
import DatePicker from "@/components/DatePicker";
import Login from "@/components/auth/Login";
import Passengers from "@/components/Passengers";
import useUserStore from "@/store/userStore";
import useDateStore from "@/store/useDateStore";
import Tickets from "@/components/Tickets";
import Trips from "@/components/Trips";

export default function Home() {
  const userStore = useUserStore();
  const dateStore = useDateStore();

  const [date, setDate] = useState<Date>();

  useEffect(() => {
    if (date) {
      dateStore.setDate(formatDate(date, "yyyy-MM-dd"));
    }
  }, [date]);

  const {
    isLoading,
    data: buses,
    error,
  } = useFetch(
    `http://127.0.0.1:8000/?date=${
      date ? formatDate(date, "yyyy-MM-dd") : "2024-02-16"
    }`
  );

  if (isLoading) {
    return "Loading...";
  }

  if (error) {
    return <div>Error: {error.message}</div>;
  }

  if (userStore.username === "") {
    return <Login />;
  }

  return (
    <>
      <div className="flex flex-row my-20">
        <DatePicker date={date} setDate_={setDate} />
        <Buses buses={buses as number[]} />
      </div>
      <Passengers />
      <Tickets />
      <Trips />
    </>
  );
}
