#include <string>

#include "model.hpp"

namespace reacrow
{
  Message::Message(const std::string &i_message, int i_number) : message(i_message), number(i_number) {}
}
