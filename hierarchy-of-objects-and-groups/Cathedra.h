#pragma once
#include "Unit.h"
#include "Person.h"
#include "Teacher.h"


class cathedra : public unit
{
public:

   cathedra()
      :unit()
   {
      set_subunits(new container<unit*>());
      set_people(new container<person*>());
   }

   explicit cathedra(const string& name)
      : unit(name)

   {
      set_subunits(new container<unit*>());
      set_people(new container<person*>());
   }

   void add_unit(const string name, const string existing = "") override
   {
      if (existing.empty())
      {
         subunits_->add(new cathedra(name));
      }
      else
      {
         find_unit(existing)->add_unit(name);
      }
   }

   void add_person(const string name) override
   {
      people_->add(new teacher(name));
   }

   string to_string() override
   {
      string dump = "Cathedra [\n  name=\"" + name_ + "\", \n  subunits={" + subunits_->to_string() + "}, \n  people={" + people_->to_string() + "}\n]";

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
