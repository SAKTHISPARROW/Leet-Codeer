"use client";

import React from "react";
import useSuperUserStore from "@/store/useSuperUserStore";
import { useRouter } from "next/navigation";
import VisitorDetails from "@/components/VisitorDetails";
import MergeBuses from "@/components/MergeBuses";
import BusManager from "@/components/BusManager";

const Admin = () => {
  const superUserStore = useSuperUserStore();
  const router = useRouter();
  if (superUserStore.username === "") {
    router.push("/admin/login");
  }

  return (
    <div className="flex flex-col">
      <h1 className="text-3xl m-4">Admin</h1>
      <VisitorDetails />
      <MergeBuses />
      <BusManager />
    </div>
  );
};

export default Admin;
