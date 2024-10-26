import { TicketDetailProps } from "./useTickets";
import useCancelwID from "./useCancelwID";

const useCancelTrip = (tickets: TicketDetailProps[]) => {
  tickets.forEach((ticket) => {
    useCancelwID(ticket.id).then((data) =>
      data.error ? console.log(data.error) : ""
    );
  });
  return true;
};

export default useCancelTrip;
