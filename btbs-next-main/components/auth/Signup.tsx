"use client";

import React, { useRef } from "react";
import sha256 from "crypto-js/sha256";
import { Button } from "../ui/button";
import { useRouter } from "next/navigation";

const Signup = () => {
  const router = useRouter();
  const usernameRef = useRef<HTMLInputElement>(null);
  const passwordRef = useRef<HTMLInputElement>(null);
  const confirmPasswordRef = useRef<HTMLInputElement>(null);

  async function handleSignup() {
    const username = usernameRef.current?.value;
    const password = passwordRef.current?.value;
    const confirmPassword = confirmPasswordRef.current?.value;

    if (username === "" || password === "") {
      alert("Please fill all the fields");
      return;
    }

    if (password !== confirmPassword) {
      alert("Passwords do not match");
      return;
    }

    const hashedPassword = sha256(password as string);

    const options = {
      method: "POST",
      headers: {
        accept: "application/json",
        "content-type": "application/x-www-form-urlencoded",
      },
    };

    await fetch(
      `http://127.0.0.1:8000/user?username=${username}&password=${hashedPassword}`,
      options
    )
      .then((res) => res.json())
      .then((data) =>
        data === true ? router.push("/login") : alert("Signup failed")
      );
  }

  return (
    <div className="flex flex-col p-24">
      <h1 className="mb-8 text-3xl text-center">Signup</h1>
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
      <input
        type="password"
        className="p-3 rounded mb-4 bg-black"
        name="confirmPassword"
        placeholder="Confirm Password"
        ref={confirmPasswordRef}
      />

      <Button onClick={handleSignup}>Signup</Button>
    </div>
  );
};

export default Signup;
