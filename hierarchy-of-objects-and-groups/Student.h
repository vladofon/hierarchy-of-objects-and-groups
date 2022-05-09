#pragma once
#include "Person.h"


class student : public person
{
public:
   student()
   {
      this->name_ = "undefined";
   }

   explicit student(const string& name)
   {
      this->name_ = name;
   }

   string to_string() override
   {
      return "Student [name=\"" + name_ + "\"]";
   }
};
