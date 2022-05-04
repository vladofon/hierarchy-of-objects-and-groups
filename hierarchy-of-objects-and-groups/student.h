#pragma once
#include "entity.h"
#include <string>

using namespace std;

class student : public entity
{
public:
   student(const int id, string name, const int course_id)
      : entity(id),
      name_(std::move(name)),
      course_id_(course_id)
   {
   }

   string get_name() const
   {
      return name_;
   }

   void set_name(string name)
   {
      this->name_ = std::move(name);
   }

   int get_course_id() const
   {
      return course_id_;
   }

   void set_course_id(const int course_id)
   {
      this->course_id_ = course_id;
   }

private:
   string name_;
   int course_id_;
};