#pragma once
#include "Person.h"


class teacher : public person
{
public:
   teacher()
   {
      this->name_ = "undefined";
   }

   explicit teacher(const string& name)
   {
      this->name_ = name;
   }

   string to_string() override
   {
      return "Teacher [name=\"" + name_ + "\"]";
   }
};
