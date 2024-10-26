import React, { useState } from "react";
import { Popover, PopoverTrigger } from "@/components/ui/popover";
import { Button } from "@/components/ui/button";
import { CalendarIcon } from "lucide-react";
import { format } from "date-fns";
import { cn } from "@/lib/utils";
import { PopoverContent } from "@radix-ui/react-popover";
import { Calendar } from "@/components/ui/calendar";
import { SelectSingleEventHandler } from "react-day-picker";

interface Props {
  date: Date | undefined;
  setDate_: SelectSingleEventHandler;
}

const DatePicker = ({ date, setDate_ }: Props) => {
  return (
    <div className="flex justify-center items-center p-4">
      <Popover>
        <PopoverTrigger asChild>
          <Button
            variant={"outline"}
            className={cn(
              "w-[280px] justify-start text-left font-normal",
              !date && "text-muted-foreground"
            )}
          >
            <CalendarIcon className="mr-2 h-4 w-4" />
            {date ? format(date, "PPP") : <span>Pick a date</span>}
          </Button>
        </PopoverTrigger>
        <PopoverContent className="w-auto p-0">
          <Calendar
            mode="single"
            selected={date}
            onSelect={setDate_}
            initialFocus
            disabled={(date) =>
              date < new Date("2024-02-15") || date > new Date("2024-02-20")
            }
          />
        </PopoverContent>
      </Popover>
    </div>
  );
};

export default DatePicker;
