#include <iostream>
#include "Container.h"
#include <string>
#include <typeinfo>

#include "Cathedra.h"
#include "Faculty.h"
#include "Group.h"

using namespace std;

void show_by_course(const void* uncasted_student)
{
   const auto current_student = (student*)uncasted_student;

   if (current_student->get_course() == "programing")
   {
      cout << current_student->to_string() << endl;
   }
}

int main()
{
   unit* c = new faculty("test");
   c->add_unit(new group("first"));
   c->add_unit(new group("second"));
   c->add_unit(new cathedra("third"));

   // Person: director
   c->add_person("first_d", "math");

   // Person: student
   c->find_unit("first")->add_person("first_s", "math");
   c->find_unit("first")->add_person("second_s", "biology");
   c->find_unit("first")->add_person("third_s", "math");

   // Person: student
   c->find_unit("second")->add_person("first_s", "programing");
   c->find_unit("second")->add_person("second_s", "programing");
   c->find_unit("second")->add_person("third_sf", "business");

   // Person: teacher
   c->find_unit("third")->add_person("first_t", "business");

   // Print all object tree
   cout << c->to_string() << endl;

   c->find_unit("second")->for_each_person(&show_by_course);
}

