#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){

}

Student::Student(int i, string n, double g){
  setID(i);
  setName(n);
  gPA = g;
}

Student::~Student(){

}

void Student::setFID(int i){
  facultyID = i;
}

int Student::getFID(){
  return facultyID;
}

void Student::setGPA(double d){
  gPA = d;
}

double Student::getGPA(){
  return gPA;
}
