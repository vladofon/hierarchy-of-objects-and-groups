#pragma once
#include "Person.h"


class director : public person
{
public:
   director()
   {
      this->name_ = "undefined";
   }

   explicit director(const string& name)
   {
      this->name_ = name;
   }

   string to_string() override
   {
      return "Director [name=\"" + name_ + "\"]";
   }
};
