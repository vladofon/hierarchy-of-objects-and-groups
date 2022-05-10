#include <iostream>
#include "Container.h"
#include <string>
#include <typeinfo>

#include "Cathedra.h"
#include "Faculty.h"
#include "Group.h"

using namespace std;

int main()
{
   unit* c = new faculty("test");
   c->add_unit(new group("first"));
   c->add_unit(new group("second"));
   c->add_unit(new cathedra("third"));

   // Person: director
   c->add_person("first_d");

   // Person: student
   c->find_unit("first")->add_person("first_s");
   c->find_unit("first")->add_person("second_s");
   c->find_unit("first")->add_person("third_s");

   // Person: student
   c->find_unit("second")->add_person("first_s");
   c->find_unit("second")->add_person("second_s");
   c->find_unit("second")->add_person("third_s");

   // Person: teacher
   c->find_unit("third")->add_person("first_t");

   // Print all object tree
   cout << c->to_string() << endl;
}

