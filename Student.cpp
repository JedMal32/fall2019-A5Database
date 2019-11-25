#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){
  studentID = 0;
  name = "";
  level = "";
  major = "";
  gPA = 0.00;
  facultyID = 0;
}

Student::Student(int id, string na, string le, string ma, double gp, int fa){
  setStudentID(id);
  setName(na);
  setLevel(le);
  setMajor(ma);
  setGPA(gp);
  setFID(fa);
}

Student::~Student(){

}

void Student::printInfo(){
  cout << "Student ID: " << studentID << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gPA << endl;
  cout << "Faculty Advisor ID: " << facultyID << endl;
}

int Student::getStudentID(){
  return studentID;
}

string Student::getName(){
  return name;
}

string Student::getLevel(){
  return level;
}

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gPA;
}

int Student::getFID(){
  return facultyID;
}

void Student::setStudentID(int id){
  studentID = id;
}

void Student::setName(string na){
  name = na;
}

void Student::setLevel(string le){
  level = le;
}

void Student::setMajor(string ma){
  major = ma;
}

void Student::setGPA(double gp){
  gPA = d;
}

void Student::setFID(int fa){
  facultyID = fa;
}

bool Student::operator==(const Student &s){
  if (studentID == s.getStudentID()){
    return true;
  }
  else{
    return false;
  }
}

bool Student::operator!=(const Student &s){
  if (studentID != s.getStudentID()){
    return true;
  }
  else{
    return false;
  }
}

bool Student::operator<(const Student &s){
  if (studentID < s.getStudentID()){
    return true;
  }
  else{
    return false;
  }
}

bool Student::operator>(const Student &s){
  if (studentID > s.getStudentID()){
    return true;
  }
  else{
    return false;
  }
}
