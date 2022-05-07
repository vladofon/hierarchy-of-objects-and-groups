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
   }

   explicit unit(string name)
   {
      this->name_ = name;
      this->subunits_ = new container<U>();
      this->people_ = new container<P>();
   }

   virtual void add_unit(const string name, const string existing = "")
   {
      if (existing.empty())
      {
         subunits_->add(U(name));
      }
      else
      {
         find_unit(existing).add_unit(name);
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

   bool is_exist() const
   {
      if (subunits_->get_size() == 0 && people_->get_size() == 0)
      {
         return false;
      }

      return true;
   }

   string to_string() override
   {
      return "unit";
   }

protected:

   string name_;
   container<U>* subunits_;
   container<P>* people_;

   U find_unit(const string name)
   {
      U parent = this;
      auto steps = new container<int>();
      int unit_col_index = -1;
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

         int last_member = steps->peek() - 1;
         if (is_way_exist(steps))
         {
            parent = find_unit(steps);
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
               return U();
            }
         }
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