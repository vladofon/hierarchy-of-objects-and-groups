#pragma once
#include "Object.h"
#include "Person.h"
#include "Container.h"


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

   virtual void add_unit(const string name, const string existing = "") = 0;

   virtual unit* find_unit(const string name) = 0;

   virtual bool is_exist() = 0;

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
      return "unit";
   }

protected:

   string name_;
   container<unit*>* subunits_;
   container<person*>* people_;

   unit* find_unit_by_steps(container<int>* steps)
   {
      auto parent = this;

      for (int i = 0; i < steps->get_size(); i++)
      {
         parent = parent->get_subunits()->get(steps->get(i));
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

   bool is_way_exist(container<int>* steps) const
   {
      auto parent = this;

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
