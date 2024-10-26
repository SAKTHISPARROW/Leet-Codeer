"use client";

import React from "react";
import { useRouter } from "next/navigation";

export interface BusProps {
  id: number;
}

export interface BusesProps {
  buses: number[];
}

const BusCard = ({ id }: BusProps) => {
  const router = useRouter();

  return (
    <div
      className="box-border h-32 w-48 p-4 border-2 m-4 hover:box-content"
      onClick={() => router.push("bus/" + id)}
    >
      <h1>Bus</h1>
      <h2>{id}</h2>
    </div>
  );
};

const Buses = ({ buses }: BusesProps) => {
  return (
    <div className="mx-10">
      <ul className="flex flex-wrap">
        {buses.map((bus) => (
          <li key={bus}>
            <BusCard id={bus} />
          </li>
        ))}
      </ul>
    </div>
  );
};
export default Buses;
