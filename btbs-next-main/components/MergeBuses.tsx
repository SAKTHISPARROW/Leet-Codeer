"use client";

import useMergeCandidates from "@/hooks/useMergeCandidates";
import React from "react";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import { Button } from "./ui/button";
import useDateStore from "@/store/useDateStore";
import useMerge from "@/hooks/useMerge";
import APIFetchClient from "@/api-fetch-client";
import FetchClient from "@/fetch-client";

const MergeBuses = () => {
  // const dateStore = useDateStore();
  const date = "2024-02-16";

  const { isLoading, data: mergeCandidates, error } = useMergeCandidates(date);

  const handleMerge = (bus1: number, bus2: number) => () => {
    fetch(
      `http://127.0.0.1:8000/admin/bus/merge?date=${date}&bus1=${bus1}&bus2=${bus2}`,
      {
        method: "POST",
        headers: {
          "Content-Type": "application/x-www-form-urlencoded",
        },
      }
    )
      .then((res) => res.json())
      .then((data) => console.log(data));
  };

  return (
    <div>
      <h2 className="text-2xl m-4">Merge Buses</h2>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Bus 1</TableHead>
            <TableHead className="">Bus 2</TableHead>
            <TableHead>Merge</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {mergeCandidates?.map((m) => (
            <TableRow key={`${m[0]} ${m[1]}`}>
              <TableCell>{m[0]}</TableCell>
              <TableCell>{m[1]}</TableCell>
              <TableCell>
                <Button onClick={handleMerge(m[0], m[1])}>Merge</Button>
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

export default MergeBuses;
