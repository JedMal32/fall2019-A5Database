#include <iostream>
#include "Affiliate.h"

using namespace std;

void Affiliate::setName(string s){
  name = s;
}

string Affiliate::getName(){
  return name;
}

void Affiliate::setID(int i){
  iD = i;
}

int Affiliate::getID(){
  return iD;
}
