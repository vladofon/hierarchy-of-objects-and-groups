#pragma once
#include "Object.h"

using namespace std;

class person : public object
{
public:

   string get_name() const
   {
      return name_;
   }

   void set_name(string name)
   {
      this->name_ = std::move(name);
   }

   string to_string() override
   {
      return "Person [name=\"" + name_ + "\"];";
   }

   string get_course() const
   {
      return course_;
   }

   void set_course(string course)
   {
      course_ = std::move(course);
   }

protected:

   string name_;
   string course_;
};