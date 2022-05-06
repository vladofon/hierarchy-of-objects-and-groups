#pragma once
#include "Object.h"
#include "Container.h"

using namespace std;

/* U - unit, P - person */
template<class U, class P>
class unit : public object
{
public:

   unit()
   {
      this->name_ = "empty";
      this->subunits_ = new container<U>();
      this->people_ = new container<P>();
      this->depth_ = 0;
   }

   explicit unit(string name)
   {
      this->name_ = name;
      this->subunits_ = new container<U>();
      this->people_ = new container<P>();
      this->depth_ = 0;
   }

   void add_unit(const string name, const string existing = "")
   {
      if (existing == "")
      {
         subunits_->add(new U(name));
      }
      else
      {

      }
   }

   string get_name() const
   {
      return this->name_;
   }

   container<U>* get_subunits() const
   {
      return subunits_;
   }

   container<P>* get_people() const
   {
      return people_;
   }

   string to_string() override;

private:

   string name_;
   container<U>* subunits_;
   container<P>* people_;

   U find_unittttt(const string name)
   {
      U parent = this;
      auto steps = new container<int>();
      int unit_col_index = 0;
      int position_index = 0;
      bool depth_changed = true;

      while (true)
      {
         int unit_index = check_units(parent->get_subunits(), name);

         if (unit_index != -1)
         {
            return parent->get_subunits->get(unit_index);
         }
         else
         {
            if (depth_changed)
            {
               if (parent->get_subunits->get_size() != 0)
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

         parent = find_unit(steps);
      }
   }

   U find_unit(container<int>* steps)
   {
      U parent = this;

      for (int i = 0; i < steps->get_size(); i++)
      {
         parent = parent->get_subunits()->get(steps->get(i));
      }

      return parent;
   }

   static int check_units(container<U>* units, string identifier)
   {
      for (int i = 0; i < units->get_size(); i++)
      {
         if (units->get(i)->get_name() == identifier)
         {
            return i;
         }
      }

      return -1;
   }

   bool is_way_exist(container<int>* steps)
   {
      U parent = this;

      for (int i = 0; i < steps->get_size(); i++)
      {
         if (parent->get_subunits()->get_size() == 0 || parent->get_subunits()->get_size() < steps->get(i))
         {
            return false;
         }

         parent = parent->get_subunits()->get(steps->get(i));
      }

      return true;
   }

};