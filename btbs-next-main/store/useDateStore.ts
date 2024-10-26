import { create } from "zustand";

interface dateStoreProps {
  date: string;
  setDate: (newDate: string) => void;
}

const useDateStore = create<dateStoreProps>((set) => ({
  date: "2024-02-16",
  setDate: (newDate: string) => set({ date: newDate }),
}));

export default useDateStore;
