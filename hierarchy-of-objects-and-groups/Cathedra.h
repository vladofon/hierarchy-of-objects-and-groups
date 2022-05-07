#pragma once
#include "Unit.h"
#include "Person.h"


class cathedra : public unit<cathedra, person>
{
public:
   explicit cathedra(const string name)
      : unit(name)
   {
   }

   void add_unit(const string name, const string existing = "") override
   {
      if (existing.empty())
      {
         subunits_->add(cathedra(name));
      }
      else
      {
         find_unit(existing).add_unit(name);
      }
   }

   string to_string() override
   {
      return "cathedra";
   }
};