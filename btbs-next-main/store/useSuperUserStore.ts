import { create } from "zustand";

interface superUserStoreProps {
    username: string;
    setUsername: (newUsername: string) => void;
}
  
const useSuperUserStore = create<superUserStoreProps>((set) => ({
    username: "superadmin",
    setUsername: (newUsername: string) => set({ username: newUsername }),
}));

export default useSuperUserStore;