#include <iostream>
#include "Affiliate.h"

using namespace std;

class Student : public Affiliate{
private:
   int studentID;
   string name;
   string level;
   string major;
   double gPA;
   int facultyID;

public:
   Student();
   Student(int id, string na, string le, string ma, double gp, int fa);
   ~Student();

   void printInfo();

   //acccess
   int getStudentID();
   string getName();
   string getLevel();
   string getMajor();
   double getGPA();
   int getFID();

   //mutate
   void setStudentID(int id);
   void setName(string na);
   void setLevel(string le);
   void setMajor(string ma);
   void setGPA(double gp);
   void setFID(int fa);

   //operators for comparison
   bool operator==(Student &s); // &s, if pointer
   bool operator!=(Student &s);
   bool operator<(Student &s);
   bool operator>(Student &s);

};
