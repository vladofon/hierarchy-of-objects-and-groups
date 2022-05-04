#pragma once


class entity
{
public:

   explicit entity(const int id)
      : id_(id)
   {
   }

   int get_id() const
   {
      return id_;
   }

   void set_id(const int id)
   {
      this->id_ = id;
   }

protected:
   int id_;
};