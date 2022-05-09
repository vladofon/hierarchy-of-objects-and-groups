#pragma once
#include "Student.h"
#include "Unit.h"


class group : public unit
{
public:

   group()
      :unit()
   {
      set_subunits(new container<unit*>());
      set_people(new container<person*>());
   }

   explicit group(const string& name)
      : unit(name)

   {
      set_subunits(new container<unit*>());
      set_people(new container<person*>());
   }

   void add_unit(const string name, const string existing = "") override
   {
      if (existing.empty())
      {
         subunits_->add(new group(name));
      }
      else
      {
         find_unit(existing)->add_unit(name);
      }
   }

   void add_person(const string name) override
   {
      people_->add(new student(name));
   }

   string to_string() override
   {
      string dump = "Group [\n  name=\"" + name_ + "\", \n  subunits={" + subunits_->to_string() + "}, \n  people={" + people_->to_string() + "}\n]";

      return dump;
   }

   bool is_exist() override
   {
      if (subunits_->get_size() == 0 && people_->get_size() == 0)
      {
         return false;
      }

      return true;
   }
};
