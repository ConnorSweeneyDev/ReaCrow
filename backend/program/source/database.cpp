#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

#include "sqlite3.h"

#include "database.hpp"

namespace reacrow
{
  Database::Database(const std::string &name)
  {
    std::filesystem::path path(name);
    if (!path.parent_path().empty() && !std::filesystem::exists(path.parent_path()))
      std::filesystem::create_directories(path.parent_path());

    if (sqlite3_open(name.c_str(), &db) != SQLITE_OK)
    {
      std::cerr << "Failed to open database: " << std::string(sqlite3_errmsg(db)) << std::endl;
      exit(1);
    }
  }

  Database::~Database()
  {
    if (db != nullptr) sqlite3_close(db);
  }

  void Database::execute(const std::string &sql)
  {
    char *error_message = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_message) != SQLITE_OK)
    {
      std::cerr << "SQL error: " << std::string(error_message) << std::endl;
      sqlite3_free(error_message);
      exit(1);
    }
  }
}
