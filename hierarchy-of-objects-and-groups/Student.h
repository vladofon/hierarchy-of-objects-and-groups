#pragma once
#include "Person.h"


class student : public person
{
public:
   student()
   {
      this->name_ = "undefined";
      this->course_ = "undefined";
   }

   explicit student(const string& name, const string& course)
   {
      this->name_ = name;
      this->course_ = course;
   }

   string to_string() override
   {
      return "Student [name=\"" + name_ + "\", course=\"" + course_ + "\"]";
   }
};
