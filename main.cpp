#include <iostream>
#include "menu.h"

using namespace std;

int main (int argc, char **argv){

  menu m;
  m.Run();
  //***USE ALL THE COMMANDS BELOW AS A GUIDE, I WOULD RECCOMENDED COMMENTING THEM OUT AND USING THEM AS A REFERENCE AT THE BOTTOM

  //STUDENT COMMANDS;
  /*
  Student sAll = Student(99, "Billy", "Sophomore", "Biology", 3.5, 98); //constructor- ID, Name, grade level, major, GPA (does not set advisor)
  Student s = Student(); //default constructor
  s.setID(1234); //sets student's ID
  s.setName("Joe"); //sets student's name
  s.setFID(4321); //sets student's faculty advisor's ID
  s.setGPA(4.2); //sets student's GPA (must be double!)
  cout << s.getID() << " - "<< s.getName() << " - " << s.getFID() << " - " << s.getGPA() << endl;

  //FACULTY COMMANDS
  Faculty fAll = Faculty(98, "Jake", "Lecturer", "Art"); //constructor- ID, Name, Level, deptartment (does not set advisees)
  Faculty fa = Faculty(); //default constructor
  fa.setID(4321); //sets faculty's ID
  fa.setName("Bob"); //sets faculty's name
  fa.setLevel("Assistant Professor"); //sets faculty's level
  fa.addStuID(1234); //adds student's ID to faculty's advisee list
  fa.removeStuID(1234); //removes student's ID to faculty's advisee list *RETURNS BOOL FOR WHETHER OR NOT OPERATION IS COMPLETED!
  cout << fa.getID() << " - "<< fa.getName() << " - " << fa.getLevel() << " - " << fa.hasStuID(1234) << endl; //.hasStuID() returns a bool for whether or not a student ID is in the list!

  //BST COMMANDS
  Student s1 = Student(1,"A","Freshman","Undeclared",3.5,1); //***student generation
  Student s2 = Student(2,"B","Freshman","Undeclared",3.5,2); //***student generation
  Student s3 = Student(3,"C","Freshman","Undeclared",3.5,3); //***student generation
  Student s4 = Student(4,"D","Freshman","Undeclared",3.5,4); //***student generation

//BST does not ppear to be working, all values are 0 (false)

  BST<Student> *students = new BST<Student>(); //creates a BST for students (SHOULD BE USED FOR FACULTY TOO)
  students->insert(s1); //inserts a student into the BST
  students->insert(s2);
  students->insert(s3);
  students->insert(s4);

  cout << "Deletion bools:" << endl;
  cout << students->deleteNode(1) << endl; //deletes a student from the BST based upon ID, returns bool
  cout << students->deleteNode(4) << endl;

  cout << "Search bools:" << endl;
  cout << students->search(1) << endl; //searches for a student based on ID, returns bool
  cout << students->search(2) <<endl;

  cout << "Print tree:" << endl;
  students->printTree(); //prints all student ID's in the tree
  //NOTE: getSuccessor, getMax, getMin are all commands that do not work for this program
  */
}
