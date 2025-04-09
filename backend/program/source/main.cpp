#include <vector>

#include "crow/app.h"
#include "crow/common.h"
#include "crow/json.h"
#include "crow/middlewares/cors.h"

#include "database.hpp"
#include "main.hpp"
#include "model.hpp"

int main()
{
  reacrow::Database database("asset/reacrow.db");
  database.execute("DROP TABLE message");
  database.execute("CREATE TABLE IF NOT EXISTS message (message TEXT, number INTEGER)");
  database.execute("INSERT INTO message VALUES ('Hello, world!', 42)");
  database.execute("INSERT INTO message VALUES ('Hi, earth!', 41)");
  auto target_messages = database.query<reacrow::Message>("SELECT message, number FROM message WHERE number = 41");

  crow::App<crow::CORSHandler> app;
  auto cors = app.get_middleware<crow::CORSHandler>();

  CROW_ROUTE(app, "/message")
    .methods(crow::HTTPMethod::GET)(
      [target_messages]()
      {
        crow::json::wvalue response({
          {"message", target_messages[0].message},
          {"number", target_messages[0].number},
        });
        return response;
      });

  app.port(8080).multithreaded().run();
  return 0;
}
