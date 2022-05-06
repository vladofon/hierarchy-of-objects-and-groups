#pragma once

template<class T>
class container
{
public:
   container()
      : head_(nullptr),
      size_(0)
   {
   }

   void add(T item)
   {
      add_node(get_last_node(), item);
   }

   void set(T item, const int index)
   {
      set_node(get_node(index), item);
   }

   T get(const int index)
   {
      return get_node(index)->item;
   }

   int get_size() const
   {
      return this->size_;
   }

private:

   class node
   {
   public:
      T item;
      node* p_next;

      explicit node(T item, node* p_next = nullptr)
      {
         this->item = item;
         this->p_next = p_next;
      }
   };

   node* head_;
   int size_;

   node* get_node(const int index)
   {
      if (index == 0 || index == -1)
      {
         if (head_ == nullptr) head_ = new node(T());
         return head_;
      }

      node* current = head_;
      int counter = 0;

      while (counter != index)
      {
         current = current->p_next;
         counter++;
      }

      return current;
   }

   node* get_last_node()
   {
      return get_node(size_ - 1);
   }

   void add_node(node* n, T item)
   {
      if (size_ == 0)
      {
         n->item = item;
      }
      else
      {
         n->p_next = new node(item);
      }

      size_++;
   }

   void set_node(node* n, T item)
   {
      n->item = item;
   }
};