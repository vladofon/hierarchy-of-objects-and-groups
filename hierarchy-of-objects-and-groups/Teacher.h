#pragma once
#include "Person.h"


class teacher : public person
{
public:
   teacher()
   {
      this->name_ = "undefined";
      this->course_ = "undefined";
   }

   explicit teacher(const string& name, const string& course)
   {
      this->name_ = name;
      this->course_ = course;
   }

   string to_string() override
   {
      return "Teacher [name=\"" + name_ + "\"]";
   }
};
