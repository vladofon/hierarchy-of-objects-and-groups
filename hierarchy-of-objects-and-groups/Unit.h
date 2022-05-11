#pragma once
#include "Object.h"
#include "Person.h"
#include "Container.h"
#include "Integer.h"


class unit : public object
{
public:

   unit()
   {
      this->name_ = "";
      this->people_ = nullptr;
      this->subunits_ = nullptr;
   }

   explicit unit(const string& name)
   {
      this->name_ = name;
      this->people_ = nullptr;
      this->subunits_ = nullptr;
   }

   virtual void add_unit(unit* new_unit, const string existing = "") = 0;
   virtual void add_person(const string name, const string course) = 0;

   virtual bool is_exist() = 0;
   virtual bool is_unit_permitted(string new_unit) = 0;

   virtual void for_each_person(void(*function)(const void*)) = 0;
   virtual void for_each_unit() = 0;

   unit* find_unit(const string& name)
   {
      unit* parent = this;
      auto steps = new container<integer*>();
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
                  steps->add(new integer(unit_col_index));
                  position_index++;
                  unit_col_index = 0;
                  depth_changed = false;
               }

            }
            else
            {
               unit_col_index++;
               steps->set(new integer(unit_col_index), position_index);
            }
         }

         const int last_member = steps->peek()->value - 1;
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
               steps->add(new integer(parent_counter));
               steps->add(new integer(0));

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
               return nullptr;
            }
         }
      }
   }

   string get_name() const
   {
      return name_;
   }

   void set_name(string name)
   {
      name_ = std::move(name);
   }

   container<unit*>* get_subunits() const
   {
      return subunits_;
   }

   void set_subunits(container<unit*>* const subunits)
   {
      subunits_ = subunits;
   }

   container<person*>* get_people() const
   {
      return people_;
   }

   void set_people(container<person*>* const people)
   {
      people_ = people;
   }

   string to_string() override
   {
      string dump = "Unit [name=\"" + name_ + "\", subunits={" + subunits_->to_string() + "}, people={" + people_->to_string() + "}];";

      return dump;
   }

protected:

   string name_;
   container<unit*>* subunits_;
   container<person*>* people_;

   unit* find_unit_by_steps(container<integer*>* steps)
   {
      auto parent = this;

      for (int i = 0; i < steps->get_size(); i++)
      {
         parent = parent->get_subunits()->get(steps->get(i)->value);
      }

      return parent;
   }

   static int check_units(container<unit*>* units, const string& identifier)
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

   bool is_way_exist(container<integer*>* steps) const
   {
      auto parent = this;

      for (int i = 0; i < steps->get_size(); i++)
      {
         if (parent->get_subunits()->get_size() == 0 || parent->get_subunits()->get_size() < steps->get(i)->value)
         {
            return false;
         }

         parent = parent->get_subunits()->get(steps->get(i)->value);
      }

      return true;
   }
};
