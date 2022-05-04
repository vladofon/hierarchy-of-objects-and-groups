#pragma once
#include "iterator.h"
#include "student.h"


class student_iterator : public group_iterator
{
public:
   entity* get(const int index) override
   {
      if (index == 0)
      {
         return this->head_->item;
      }
      else
      {
         node* current = this->head_;
         int counter = 0;

         while (index != counter)
         {
            current = current->p_next;
            counter++;
         }

         return current->item;
      }
   }

   void create(entity e) override;
   void update(entity e) override;
   void remove(int index) override;
};