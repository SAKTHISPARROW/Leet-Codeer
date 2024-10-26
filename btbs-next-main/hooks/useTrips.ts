import useTickets from "./useTickets";
import { TicketDetailProps } from "./useTickets";

export interface Trip {
  date: string;
  tickets: TicketDetailProps[];
}

const useTrips = (username: string) => {
  const { isLoading, data: tickets, error } = useTickets(username);
  const trips = tickets?.reduce((acc, ticket) => {
    if (acc[ticket.date]) {
      acc[ticket.date].push(ticket);
    } else {
      acc[ticket.date] = [ticket];
    }
    return acc;
  }, {} as { [key: string]: TicketDetailProps[] });

  return { isLoading, trips, error };
};

export default useTrips;
