#include <crow/app.h>
#include <crow/common.h>
#include <crow/http_response.h>
#include <crow/json.h>
#include <crow/middlewares/cors.h>

#include "main.hpp"

int main()
{
  crow::App<crow::CORSHandler> app;
  auto cors = app.get_middleware<crow::CORSHandler>();

  CROW_ROUTE(app, "/message")
    .methods(crow::HTTPMethod::GET)(
      []()
      {
        crow::json::wvalue response({
          {"message", "Hello, world!"},
          {"number", 42},
        });
        return response;
      });

  app.port(8080).multithreaded().run();
  return 0;
}
