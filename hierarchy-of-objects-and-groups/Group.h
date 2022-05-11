#pragma once
#include "Student.h"
#include "Unit.h"
#include <typeinfo>


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

   void add_unit(unit* new_unit, const string existing = "") override
   {
      if (!is_unit_permitted(string(typeid(*new_unit).name()).substr(6)))
      {
         return;
      }

      if (existing.empty())
      {
         subunits_->add(new_unit);
      }
      else
      {
         find_unit(existing)->add_unit(new_unit);
      }
   }

   void add_person(const string name, const string course) override
   {
      people_->add(new student(name, course));
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

   bool is_unit_permitted(const string new_unit) override
   {
      constexpr int permitted_units_count = 0;
      const auto permitted_units = new string[permitted_units_count];

      for (int i = 0; i < permitted_units_count; i++)
      {
         if (permitted_units[i] == new_unit)
         {
            return true;
         }
      }

      return false;
   }

   void for_each_person(void(*function)(const void*)) override
   {
      for (int i = 0; i < people_->get_size(); i++)
      {
         function(people_->get(i));
      }
   }

   void for_each_unit() override
   {

   }
};
