#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(){

}

Faculty::Faculty(int i, string n, string l){
  setID(i);
  setName(n);
  level = l;
}

Faculty::~Faculty(){

}

void Faculty::setLevel(string s){
  level = s;
}

string Faculty::getLevel(){
  return level;
}

void Faculty::addStuID(int i){
  stuIDs->insertFront(i);
}

bool Faculty::removeStuID(int i){
  int position = stuIDs->find(i);
  if(position == -1){
    return false;
  }else{
    stuIDs->removePosition(position);
    return true;
  }
}

bool Faculty::hasStuID(int i){
  int position = stuIDs->find(i);
  if(position == -1){
    return false;
  }else{
    return true;
  }
}
