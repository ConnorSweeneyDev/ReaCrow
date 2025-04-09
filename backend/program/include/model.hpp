#pragma once

#include <string>

namespace reacrow
{
  class Message
  {
  public:
    Message(const std::string &i_message, const int i_number);

  public:
    std::string message = "";
    int number = 0;
  };
}
