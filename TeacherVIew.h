#include <iostream>
#include "TeacherOptions.h"
using namespace std;
int TeacherView(){
  cout<<"Please select one of the options:"<<endl;
  
  cout<<"Press 1 to view students:"<<endl;
  cout<<"Press 2 to view arithmetic subject mean:"<<endl;
  cout<<"Press 3 to view student mean:"<<endl;
  cout<<"Press 4 to insert grade:"<<endl;
  cout<<"Press any other button to exit for:"<<endl;
  int cmd;cin>>cmd;
return cmd;
}
Node<teacher>* TeacherExists(string user,string pass,List<teacher> TeacherDB){
  Node<teacher> *temp=TeacherDB.head;
  while(temp!=nullptr){
if(temp->data->user==user&&temp->data->pass==pass){
cout<<"Welcome teacher "<<temp->data->name<<" "<<temp->data->surname<<endl;
break;}
    temp=temp->next;
    
  }
  if(temp==nullptr)
  cout<<"Login not possible \n Wrong username or password!!\n";
  return temp;
}
TeacherButtons teacherChoice(int cmd){
  TeacherButtons c;
  switch(cmd){
  case 1:
  c=teacherViewStudents;
  break;
  case 2:
  c=teacherViewArithmeticSubjectMean;
  break;
  case 3:
  c=teacherViewStudentMean;
  break;
  case 4:
  c=teacherInsertGrade;
  break;
  
  default:
  c=teacherExit;
  }return c;
}