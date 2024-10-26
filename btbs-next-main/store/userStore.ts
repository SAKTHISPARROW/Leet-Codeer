import { create } from "zustand";

interface userStoreProps {
    username: string;
    setUsername: (newUsername: string) => void;
  }

const useUserStore = create<userStoreProps>()((set) => ({
  username: "arvind",
  setUsername: (newUsername: string) => set({ username: newUsername }),
}));

export default useUserStore;