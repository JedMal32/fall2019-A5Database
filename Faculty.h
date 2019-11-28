#include <iostream>
#include "Student.h"
#include "GenLinkedList.cpp"

using namespace std;

class Faculty : public Affiliate{
private:
   int facultyID;
   string name;
   string level;
   string department;

public:
   Faculty();
   Faculty(int id, string na, string le, string de);
   ~Faculty();

   void printInfo();

   int getID();
   string getName();
   string getLevel();
   string getDepartment();

   void setID(int id);
   void setName(string na);
   void setLevel(string le);
   void setFacultyDepartment(string de);

   void addStuID(int id);
   bool removeStuID(int id);
   bool hasStuID(int id);
   GenLinkedList<int> * stuIDs = new GenLinkedList<int>();
   int stuIDSize = stuIDs->getSize(); //fix?

   bool operator==(Faculty &f);
   bool operator!=(Faculty &f);
   bool operator<(Faculty &f);
   bool operator>(Faculty &f);

};
