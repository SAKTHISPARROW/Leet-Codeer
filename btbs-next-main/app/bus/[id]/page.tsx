"use client";

import Bus from "@/components/Bus";
import { usePathname, useRouter, useSearchParams } from "next/navigation";

export default function Page() {
  const pathname = usePathname();
  const busNumber = pathname.split("/")[2];

  return (
    <div>
      <Bus id={busNumber} />
    </div>
  );
}
