import { useState, useEffect } from "react";
import "./App.css";

function App() {
  const [message, setMessage] = useState("");
  const [number, setNumber] = useState(0);

  useEffect(() => {
    fetchMessage();
  }, []);

  const fetchMessage = async () => {
    const response = await fetch("http://localhost:8080/message");
    if (!response.ok) {
      setMessage("Error");
      setNumber(0);
      return;
    }
    const data = await response.json();
    setMessage(data.message);
    setNumber(data.number);
  };

  return <h1>{message} | {number}</h1>;
}

export default App;
