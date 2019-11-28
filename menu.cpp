#include <iostream>
#include "menu.h"

using namespace std;

menu::menu(){

}

menu::~menu(){
  //destructor
}

void menu::Run(){
  cout << "Setting up database of students and faculty: " << endl;
  readFiles();
  playing = true;
  while (playing){
    cout << "Possible actions: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl; //changes student tree
    cout << "12. Remove an advisee from a faculty member given the ids" << endl; //changes faculty tree AND student tree (must change advisee as well)
    cout << "13. Rollback (or undo last change made)" << endl;
    cout << "14. Exit" << endl;

    /* //Bonus?
    students with same level
    students with same major
    students with same GPA
    faculty members with same academic level
    faculty members with same department
    */

    cout << "Please enter the number corresponding to your desired action: ";
    cin >> action;

    switch (action){
      case 1: {//1. Print all students and their information (sorted by ascending id #)
        StudentTree();
        break;
      }
      case 2: {//2. Print all faculty and their information (sorted by ascending id #)
        FacultyTree();
        break;
      }
      case 3: {// 3. Find and display student information given the students id
        cout << "Please enter the  student ID: ";
        cin >> studentID;
        Student Y(studentID, "", "", "", 0.00, 0);
        if (studentTree.size == 0 || studentTree.search(Y.getID()) == false){
          cout << "Student not found." << endl;
        }
        else if (studentTree.search(Y.getID())){
          Y.printInfo();
        }
        break;
      }
      case 4: {// 4. Find and display faculty information given the faculty id
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;
        Faculty X(facultyID, "", "", "");
        if (facultyTree.size == 0 || facultyTree.search(X.getID()) == false){
          cout << "Faculty not found." << endl;
        }
        else if (facultyTree.search(X.getID())){
          X.printInfo();
        }
        break;
      }
      case 5: {// 5. Given a student’s id, print the name and info of their faculty advisor
        cout << "Please enter the student ID: ";
        cin >> studentID;
        Student Y1(studentID, "", "", "", 0.00, 0);
        if (studentTree.size == 0 || studentTree.search(Y1.getID()) == false){
          cout << "Student not found." << endl;
        }
        else if (studentTree.search(Y1.getID())){
          int fID = Y1.getFID();
          Faculty X1(facultyID, "","","");
          if (facultyTree.size == 0 || facultyTree.search(X1.getID()) == false){
            cout << "Faculty not found." << endl;
          }
          else if (facultyTree.search(X1.getID())){
            X1.printInfo();
          }
        }
        break;
      }
      case 6: {// 6. Given a faculty id, print ALL the names and info of his/her advisees.
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;
        Faculty X2(facultyID, "","","");
        if (facultyTree.size == 0 || facultyTree.search(X2.getID()) == false){
          cout << "Faculty not found." << endl;
        }
        else if (facultyTree.search(X2.getID())){ //FIX NOT DONE
          cout << "Printing advisees" << endl;
          cout << "Faculty has no advisees." << endl;
        }
        break;
      }
      case 7: {// 7. Add a new student
        cout << "Please enter the student ID: ";
        cin >> studentID;
        AddStudent(studentID);
        break;
      }
      case 8: {// 8. Delete a student given the id
        cout << "Please enter the student ID: ";
        cin >> studentID;
        DeleteStudent(studentID);
        break;
      }
      case 9: {// 9. Add a new faculty member
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;
        AddFaculty(facultyID);
        break;
      }
      case 10: {// 10. Delete a faculty member given the id.
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;
        DeleteFaculty(facultyID);
        break;
      }
      case 11: {// 11. Change a student’s advisor given the student id and the new faculty id.
        cout << "Please enter the student ID: ";
        cin >> studentID;
        //ChangeAdvisor(studentID, 0); //fix
        break;
      }
      case 12: {// 12. Remove an advisee from a faculty member given the ids
        cout << "Please enter the faculty ID: ";
        cin >> facultyID;
        //RemoveAdvisee(facultyID); //fix
        break;
      }
      case 13: {// 13. Rollback (or undo last change made)
        cout << "Rolling back to previous state: " << endl;
        Rollback();
        break;
      }
      case 14: { // 14. Exit
        writeFiles();
        cout << "Databases saved" << endl;
        cout << "Exiting database. " << endl;
        playing = false;
        break;
      }
      default: {
        cout << "Improper input." << endl;
      }
    }
  }
}




void menu::readFiles()
{
  input.open("studentTable.txt");
  if (input.fail()){
    cout << "File 'studentTable.txt' not found. Making a new database of students." << endl;
  }
  else{
    cout << "Existing file 'studentTable.txt' found." << endl;
    int numS; //num students
    input >> numS;

    if (numS > 0){
      int studentID;
      string name;
      string level;
      string major;
      double gPA;
      int studentFID;

      for (int i = 0; i < numS; i++){
        input >> studentID;
        getline(input, name);
        getline(input, level);
        getline(input, major);
        input >> gPA;
        input >> studentFID;
        Student S(studentID, name, level, major, gPA, studentFID);
        studentTree.insert(S);
        studentIDs.insertFront(studentID);
      }
    }
  }
  changeRollback();
  input.close();

  input.open("facultyTable.txt");
  if (input.fail()){
    cout << "File 'facultyTable.txt' not found. Making a new database of faculty." << endl;
  }
  else{
    cout << "Existing file 'facultyTable.txt' found." << endl;
    int numF;
    input >> numF;

    if (numF > 0){
      int facultyID;
      string fName;
      string fLevel;
      string department;
      int numA; //advisees
      int adviseeID;

      for (int i = 0; i < numF; i++){
        input >> facultyID;
        getline(input, fName);
        getline(input, fLevel);
        getline(input, department);
        Faculty F(facultyID, fName, fLevel, department);
        input >> numA;

        if (numA > 0){
          for (int j = 0; j < numA; j++){
            input >> adviseeID;
            F.addStuID(adviseeID);
          }
        }
        facultyTree.insert(F);
        facultyIDs.insertFront(facultyID);
      }
    }
  }
  changeRollback();
  input.close();
}


void menu::writeFiles(){
  output.open("studentTable.txt");
  output << studentTree.size << endl;

  if (studentTree.size != 0){
    int idNum;

    for (int i = 0; i < studentTree.size; i++){
      int idNum = studentIDs.peekPosition(i);
      Student Y(idNum, "", "", "", 0.00, 0);
      output << Y.getID() << endl;
      output << Y.getName() << endl;
      output << Y.getLevel() << endl;
      output << Y.getMajor() << endl;
      output << Y.getGPA() << endl;
      output << Y.getFID() << endl;
    }
  }
  output.close();

  output.open("facultyTable.txt");
  output << facultyTree.size << endl;

  if (facultyTree.size != 0){
    int idNum = facultyIDs.peekPosition(0);

    for (int i = 0; i < facultyTree.size; i++){
      int idNum = facultyIDs.peekPosition(i);
      Faculty X(idNum, "", "", "");
      output << X.getID() << endl;
      output << X.getName() << endl;
      output << X.getLevel() << endl;
      output << X.getDepartment() << endl;
      output << X.stuIDSize << endl;

      if (X.stuIDSize > 0){
        int k = 0;
        while (k < X.stuIDSize){
          int idNum2 = studentIDs.peekPosition(k);
          output << idNum2 << endl;
          k++;
        }
      }
      //currFID = currFID->next;
    }
  }
  output.close();
}

void menu::StudentTree(){
  if(studentTree.size == 0){
    cout << "No students in the student tree." << endl;
  }
  else{
    RecStudentPrint(studentTree.getRoot());
  }
}

void menu::FacultyTree(){
  if(facultyTree.size == 0){
    cout << "No faculty in the faculty tree." << endl;
  }
  else{
    RecFacultyPrint(facultyTree.getRoot());
  }
}

void menu::RecStudentPrint(TreeNode<Student> * node) //modify rec print
{
  if(node == NULL)
    return;
  RecStudentPrint(node->left);
  int idd = node->key;
  Student ss(idd,"","","",0.00,0);
  ss.printInfo();
  RecStudentPrint(node->right);
}

void menu::RecFacultyPrint(TreeNode<Faculty> * node) //modify rec print
{
  if(node == NULL)
    return;
  RecFacultyPrint(node->left);
  int idd = node->key;
  Faculty ff(idd,"","","");
  ff.printInfo();
  RecFacultyPrint(node->right);
}

void menu::AddStudent(int studentID){
  string name;
  string level;
  string major;
  double gPA;
  int fID;

  cout << "Enter the student's name: ";
  getline(cin, name);
  cout << "Enter the student's academic level: ";
  getline(cin, level);
  cout << "Enter the student's major: ";
  getline(cin, major);
  cout << "Enter the student's GPA: ";
  cin >> gPA;
  cout << "Enter the faculty advisor (of your student)'s ID: ";
  cin >> fID;
  Faculty X(fID,"","","");
  Student Y(studentID, name, level, major, gPA, fID);

  if(studentTree.search(Y.getID()) == true){ // student ID already in tree
    cout << "Student ID already in tree." << endl;
  }
  else if (facultyTree.size == 0 || !(facultyTree.search(X.getID()))){ //faculty not found, can't add
      cout << "Faculty member not in the faculty database." << endl;
  }
  else{ //faculty found, add student to list of advisees
    changeRollback();
    X.addStuID(studentID);
    studentTree.insert(Y);
    studentIDs.insertBack(studentID);
    cout << "Student Added." << endl;
  }
}


void menu::DeleteStudent(int studentID){
  Student Y(studentID, "", "", "", 0.00, 0);
  if (studentTree.size == 0 || studentTree.search(Y.getID()) == false){
    cout << "Student not found." << endl;
  }
  else{
    int facultyID = Y.getFID();
    Faculty X(facultyID,"","","");
    if (facultyTree.size == 0 || facultyTree.search(X.getID()) == false)
    {
      cout << "Faculty advisor doesn't exist. This... shouldn't happen." << endl;
    }
    else{
      changeRollback();
      X.removeStuID(studentID);
      studentIDs.removePosition(Y.getID());
      studentTree.deleteNode(Y.getID());
      cout << "Student has been deleted." << endl;
    }
  }
}

void menu::AddFaculty(int facultyID)
{
  string fName;
  string fLevel;
  string department;

  cout << "Enter the faculty member's name: ";
  getline(cin, fName);
  cout << "Enter the faculty member's academic level: ";
  getline(cin, fLevel);
  cout << "Enter the faculty member's department: ";
  getline(cin, department);
  Faculty X(facultyID, fName, fLevel, department);

  if(facultyTree.search(X.getID())){
    cout << "Faculty ID already in tree." << endl;
  }
  else{
    changeRollback();
    facultyTree.insert(X);
    facultyIDs.insertBack(facultyID);
    cout << "Faculty member added." << endl;
  }
}


void menu::DeleteFaculty(int facultyID){
  Faculty X(facultyID, "", "", "");
  if (facultyTree.size == 0 || facultyTree.search(X.getID()) == false){
    cout << "Faculty ID not found." << endl;
  }
  else{
    if (facultyTree.size > 1){ // 2+ faculty exist. Rearrange students.
      changeRollback();
      int newF = facultyIDs.getFront();
      if (newF == facultyID){ //make sure it's different (the substitute faculty)
        newF = facultyIDs.peekPosition(1);
      }
      Faculty newFac(newF,"","","");

      int stu;
      int num2 = 0;
      while (num2 <= studentIDs.getSize()){
        stu = studentIDs.peekPosition(num2);
        Student Y(stu, "", "", "", 0.00, 0);
        if(studentTree.search(Y.getID())){
          Y.setFID(newFac.getID());
          newFac.addStuID(stu);
        }
        num2++;
      }
      facultyIDs.removePosition(X.getID());
      facultyTree.deleteNode(X.getID());
      cout << "Faculty has been deleted." << endl;
      cout << "Advisees reassigned to " << newFac.getID() << endl;
    }
    else{
      cout << "There is only 1 faculty member in your database. Unable to remove at the risk of mucking up advisees." << endl;
    }
  }
}

void menu::Rollback(){
  if (rollAvailable == true){
    facultyTree = rollFacultyTree;
    rollAvailable = false;
  }
  else{
    cout << "Rollback not available, no changes to undo." << endl;
  }
}

void menu::changeRollback(){ //once safe, change rollTrees before changes are made to trees
  rollAvailable = true;
  rollFacultyTree = facultyTree;
  rollStudentTree = studentTree;
}
