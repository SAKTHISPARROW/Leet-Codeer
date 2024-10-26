import React from "react";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import useVisitors from "@/hooks/useVisitors";

const VisitorDetails = () => {
  const { isLoading, data: visitors, error } = useVisitors();

  return (
    <div>
      <h2 className="text-2xl m-4">Visitors</h2>
      <Table>
        <TableHeader>
          <TableRow>
            <TableHead>Date</TableHead>
            <TableHead className="">Visitor Count</TableHead>
          </TableRow>
        </TableHeader>
        <TableBody>
          {visitors?.map((visitor) => (
            <TableRow key={visitor.date}>
              <TableCell>{visitor.date}</TableCell>
              <TableCell>{visitor.visitor_count}</TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
      {isLoading && <p>Loading...</p>}
      {error && <p>Error loading visitors {error.message}</p>}
    </div>
  );
};

export default VisitorDetails;
