"use client";

import sha256 from "crypto-js/sha256";
import { useRouter } from "next/navigation";
import { useRef } from "react";
import { Button } from "../ui/button";
import useSuperUserStore from "@/store/useSuperUserStore";

const AdminLogin = () => {
  const superUserStore = useSuperUserStore();
  const router = useRouter();

  const usernameRef = useRef<HTMLInputElement>(null);
  const passwordRef = useRef<HTMLInputElement>(null);

  async function handleLogin() {
    const username = usernameRef.current?.value;
    const password = passwordRef.current?.value;

    if (username === "" || password === "") {
      alert("Please fill all the fields");
      return;
    }

    const hashedPassword = sha256(password as string);

    const options = {
      method: "GET",
      headers: {
        accept: "application/json",
        "content-type": "application/x-www-form-urlencoded",
      },
    };

    await fetch(
      `http://127.0.0.1:8000/admin/login?username=${username}&password=${hashedPassword}`,
      options
    )
      .then((res) => res.json())
      .then((data) =>
        data === true
          ? (superUserStore.setUsername(username as string),
            router.push("/admin"))
          : router.push("/admin/login?error=Invalid username or password")
      );
  }

  return (
    <div className="flex flex-col p-24">
      <h1 className="mb-8 text-3xl text-center">Login</h1>
      <input
        type="text"
        className="p-3 rounded mb-4 bg-black"
        name="username"
        placeholder="Username"
        ref={usernameRef}
      />

      <input
        type="password"
        className="p-3 rounded mb-4 bg-black"
        name="password"
        placeholder="Password"
        ref={passwordRef}
      />

      <Button onClick={handleLogin}>Login</Button>
    </div>
  );
};

export default AdminLogin;
