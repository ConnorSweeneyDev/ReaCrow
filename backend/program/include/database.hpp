#pragma once

#include <string>
#include <vector>

#include "sqlite3.h"

namespace reacrow
{
  class Database
  {
  public:
    Database(const std::string &name);
    ~Database();

    void execute(const std::string &sql);
    template <typename Type> std::vector<Type> query(const std::string &sql);

  private:
    sqlite3 *db = nullptr;
  };
}

#include "database.inl"
