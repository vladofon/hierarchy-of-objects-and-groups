#pragma once
#include "entity.h"


class group_iterator
{
public:

   explicit group_iterator()
      : size_(0),
      head_(nullptr)
   {
   }

   virtual entity* get(int index) = 0;

   virtual void create(entity e) = 0;

   virtual void update(entity e) = 0;

   virtual void remove(int index) = 0;

protected:

   class node
   {
   public:
      entity* item;
      node* p_next;

      explicit node(entity* item, node* p_next = nullptr)
         : item(item),
         p_next(p_next)
      {
      }
   };

   int size_;
   node* head_;

   int node_count() const
   {
      node* current = this->head_;
      int counter = 0;

      while (current->p_next != nullptr)
      {
         counter++;
         current = current->p_next;
      }

      return counter;
   }



};