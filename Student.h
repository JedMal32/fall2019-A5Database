#include <iostream>
#include "Affiliate.h"

using namespace std;

class Student : public Affiliate{
private:
   double gPA = 0;
   int facultyID = 0;

public:
   Student();
   Student(int i, string n, double g);
   ~Student();

   void setFID(int i);
   int getFID();
   void setGPA(double d);
   double getGPA();

};
