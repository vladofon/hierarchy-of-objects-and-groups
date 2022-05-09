#pragma once
#include "Object.h"


class integer : public object
{
public:

   integer()
   {
      this->value = 0;
   }

   explicit integer(const int value)
   {
      this->value = value;
   }

   int value;

   std::string to_string() override
   {
      return std::to_string(value);
   }
};
