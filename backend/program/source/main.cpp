#include <iostream>

#include "main.hpp"
#include <crow/app.h>

int main()
{
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([]() { return "Hello, World!"; });

  app.port(8080).multithreaded().run();
  return 0;
}

void say_hello() { std::cout << "Hello, World!" << std::endl; }
