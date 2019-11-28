#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  facultyID = 0;
  name = "";
  level = "";
  department = "";
}

Faculty::Faculty(int id, string na, string le, string de){
  facultyID = id;
  name = na;
  level = le;
  department = de;
}

Faculty::~Faculty(){

}

void Faculty::printInfo(){
  cout << "Faculty ID: " << facultyID << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  cout << "Advisee IDs: ";
  if (stuIDs->isEmpty() == false){
    stuIDs->printList();
  }
  else{
    cout << "No advisees assigned to this faculty." << endl;
  }
}

int Faculty::getID(){
  return facultyID;
}

string Faculty::getName(){
  return name;
}

string Faculty::getLevel(){
  return level;
}

string Faculty::getDepartment(){
  return department;
}

void Faculty::setID(int id){
  facultyID = id;
}

void Faculty::setName(string na){
  name = na;
}

void Faculty::setLevel(string le){
  level = le;
}

void Faculty::setFacultyDepartment(string de){
  department = de;
}

void Faculty::addStuID(int id){
  stuIDs->insertFront(id);
}

bool Faculty::removeStuID(int id){
  int position = stuIDs->find(id);
  if(position == -1){
    return false;
  }else{
    stuIDs->removePosition(position);
    return true;
  }
}

bool Faculty::hasStuID(int id){
  int position = stuIDs->find(id);
  if(position == -1){
    return false;
  }else{
    return true;
  }
}

bool Faculty::operator==(Faculty &f){
  if (facultyID == f.getID()){
    return true;
  }
  else{
    return false;
  }
}

bool Faculty::operator!=(Faculty &f){
  if (facultyID != f.getID()){
    return true;
  }
  else{
    return false;
  }
}

bool Faculty::operator<(Faculty &f){
  if (facultyID < f.getID()){
    return true;
  }
  else{
    return false;
  }
}

bool Faculty::operator>(Faculty &f){
  if (facultyID > f.getID()){
    return true;
  }
  else{
    return false;
  }
}
