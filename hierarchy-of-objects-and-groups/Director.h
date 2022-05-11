#pragma once
#include "Person.h"


class director : public person
{
public:
   director()
   {
      this->name_ = "undefined";
      this->course_ = "undefined";
   }

   explicit director(const string& name, const string& course)
   {
      this->name_ = name;
      this->course_ = course;
   }

   string to_string() override
   {
      return "Director [name=\"" + name_ + "\"]";
   }
};
