#include <iostream>
#include "Affiliate.h"

using namespace std;

class Student : public Affiliate{
private:
   int studentID = 0;
   string name;
   string level;
   string major;
   double gPA = 0;
   int facultyID = 0;

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
   bool operator==(const Student &s); // &s, if pointer
   bool operator!=(const Student &s);
   bool operator<(const Student &s);
   bool operator>(const Student &s);

};
