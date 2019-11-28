#include <iostream>
#include "BST.cpp"
#include <fstream>

using namespace std;

class menu{
  private:

    ifstream input;
    ofstream output;

    BST<Student> studentTree; //student tree
    BST<Student> rollStudentTree; //backup for rollback
    BST<Faculty> facultyTree; //faculty tree
    BST<Faculty> rollFacultyTree; //backup for roll back

    GenLinkedList<int> studentIDs;
    GenLinkedList<int> facultyIDs;

    bool playing;
    int action;
    int studentID;
    int facultyID;
    bool rollAvailable;

  public:
    menu();
    ~menu();

    void Run();
    void readFiles();
    void writeFiles();
    void StudentTree();
    void FacultyTree();
    void RecStudentPrint(TreeNode<Student> * node);
    void RecFacultyPrint(TreeNode<Faculty> * node);
    void AddStudent(int studentID);
    void DeleteStudent(int studentID);
    void AddFaculty(int facultyID);
    void DeleteFaculty(int facultyID);
    void Rollback();
    void changeRollback();
};
