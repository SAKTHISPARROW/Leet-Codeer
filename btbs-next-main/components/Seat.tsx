import { useState } from "react";

interface SeatProps {
  id: number;
  isBooked: boolean;
  selectedFn: (id: number) => void;
  selectedFnCancel: (id: number) => void;
}

const Seat = ({ id, isBooked, selectedFn, selectedFnCancel }: SeatProps) => {
  const [selected, setSelected] = useState(false);
  const [selectedForCancellation, setSelectedForCancellation] = useState(false);

  return (
    <div
      className="box-border h-8 w-8 p-2 border-2 m-2 ml-0 hover:bg-gray-400 items-center justify-center flex rounded-md cursor-pointer"
      style={{
        backgroundColor: isBooked
          ? selectedForCancellation
            ? "red"
            : "gray"
          : selected
          ? "green"
          : "",
      }}
      onClick={() => {
        if (!isBooked) {
          setSelected(!selected);
          selectedFn(id);
        } else {
          setSelectedForCancellation(!selectedForCancellation);
          selectedFnCancel(id);
        }
      }}
    >
      {id}
    </div>
  );
};

export default Seat;
