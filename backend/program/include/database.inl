#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include "sqlite3.h"

#include "database.hpp"
#include "model.hpp"

namespace reacrow
{
  template <typename Type> std::vector<Type> Database::query(const std::string &sql)
  {
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
      std::cerr << "Failed to prepare statement: " << std::string(sqlite3_errmsg(db)) << std::endl;
      exit(1);
    }

    std::vector<Type> results;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
      if constexpr (std::is_same<Type, Message>::value)
      {
        const std::string message = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        const int number = sqlite3_column_int(stmt, 1);
        results.push_back(Message(message, number));
      }
      else
      {
        std::cerr << "Unsupported query type: " << typeid(Type).name() << std::endl;
        exit(1);
      }
    }

    sqlite3_finalize(stmt);
    return results;
  }
}
