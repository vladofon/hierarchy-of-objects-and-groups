#pragma once
#include "Unit.h"
#include "Person.h"


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

   string to_string() override
   {
      return "cathedra";
   }

   unit* find_unit(const string name) override
   {
      unit* parent = this;
      auto steps = new container<int>();
      int unit_col_index = -1;
      int position_index = 0;
      bool depth_changed = true;

      while (true)
      {
         const int unit_index = check_units(parent->get_subunits(), name);

         if (unit_index != -1)
         {
            return parent->get_subunits()->get(unit_index);
         }
         else
         {
            if (depth_changed)
            {
               if (parent->get_subunits()->get_size() != 0)
               {
                  steps->add(unit_col_index);
                  position_index++;
                  unit_col_index = 0;
                  depth_changed = false;
               }

            }
            else
            {
               unit_col_index++;
               steps->set(unit_col_index, position_index);
            }
         }

         const int last_member = steps->peek() - 1;
         if (is_way_exist(steps))
         {
            parent = find_unit_by_steps(steps);
         }
         else
         {
            depth_changed = true;
            steps->cancel();

            bool is_way_found = false;
            int parent_counter = 0;
            while (parent_counter <= last_member)
            {
               steps->add(parent_counter);
               steps->add(0);

               if (is_way_exist(steps))
               {
                  is_way_found = true;
                  break;
               }
               else
               {
                  steps->cancel();
                  steps->cancel();

                  parent_counter++;
               }
            }

            if (!is_way_found)
            {
               return new cathedra();
            }
         }
      }
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