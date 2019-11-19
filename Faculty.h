#include <iostream>
#include "Student.h"
#include "GenLinkedList.cpp"

using namespace std;

class Faculty : public Affiliate{
private:
   string level = "";
   GenLinkedList<int> * stuIDs = new GenLinkedList<int>();

public:
   Faculty();
   Faculty(int i, string n, string l);
   ~Faculty();

   void setLevel(string s);
   string getLevel();
   void addStuID(int i);
   bool removeStuID(int i);
   bool hasStuID(int i);

};
