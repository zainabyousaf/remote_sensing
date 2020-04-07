// Aggregation and composition
// l19-1196 CS-2E1
// zaeem Yousaf
// class point
//all_classes.cpp
#include "all_classes.h"
#include <iostream>
//---------------------- Exercise 1

Point::Point(int a=0,int b=0){
  x=a;
  y=b;
  std::cout << "Point() called\n";
}
void Point::print(){
  std::cout << "(" << x << "," << y << ")";
}

Point::~Point(){
  std::cout << "~Point() called\n";
}

//------------------------ Exercise 2

Circle::Circle(){

  std::cout << "Circle() called\n";
}
Circle::Circle(int a, int b, float c): center(a,b) {
  radius = c;
}

void Circle::print(){
  center.print();
  std::cout  << " and radius: " << radius << std::endl;
}

Circle::~Circle(){
  std::cout << "~Circle() Called\n";
}


//---------------------------- CD class Exercise 3

CompactDisc::CompactDisc(const char *t,int c){
  int index=0;
  while(t[index] != '\0') index++;
  for(int i=0; i< index; i++) title[i]=t[i];
  title[index]='\0';
  capacity = c;
  std::cout << "compactDics() called\n";
}
//-------------------- getter title
char* CompactDisc::get_title(){
  return this->title;
}
//-------------------- setter title
void CompactDisc::set_title(const char *t){
  int index=0;
  while(t[index] != '\0') index++;
  for(int i=0; i< index; i++) title[i]=t[i];
  title[index]='\0';
}
//---------------------- getter for capacity
int CompactDisc::get_capacity(){
  return capacity;
}
//---------------------- setter for capacity
void CompactDisc::set_capacity(int c){
  capacity = c;
}

CompactDisc::~CompactDisc(){
  std::cout << "~CompactDisc() called\n";
}


//--------------------- Exercise 4

CDDrive::CDDrive(const char *m, int s){
  aCompactDisc = 0;
  speed = s;
  int index=0;
  while(m[index]) manufacturer[index] = m[index++];
  manufacturer[index]='\0';
  std::cout << "CDDrive() called\n";
}
void CDDrive::InsertCD(CompactDisc *c){
  aCompactDisc = c;
}
void CDDrive::Play (){
  if(aCompactDisc != 0){
    std::cout << "title: " << aCompactDisc->get_title() << std::endl;
    std::cout << "Capacity: " << (aCompactDisc->get_capacity()) << std::endl;
  }
  std::cout << "please, Insert Disk.\n";

}
//-------------------------
CompactDisc * CDDrive::EjectCD(){
  return aCompactDisc;
}

//CDDrive::~CDDrive(){
//  std::cout << "~CDDrive() called\n";
//}
//-----------------------------------

Student::Student(const char r[7], const char *n, float cg){
  for(int i=0; i< 7; i++) rollNo[i]=r[i];
  rollNo[7]='\0';
  int index=0;
  while(n[index] != '\0')index++;
  for(int i=0; i< index; i++) name[i]=n[i];
  name[index]='\0';
  cgpa = cg;
}
void Student::print(){
  std::cout << "rollNo: " << rollNo << " Name: " << name << " cgpa: " << cgpa << std::endl;

}
char * Student::GetName(){
  return name;
}
float Student::get_cgpa(){
  return cgpa;
}

//-----------------------------
Society::Society(char *n){
  int index=0;
  noOfStudents =0;
  while(n[index++] != '\0');
  for(int i=0; i< index; i++) name[i] = n[i];
  name[index]='\0';

  //setting to null
  president=0;
  for(int i=0; i< 5; i++) members[i]=0;

}
//--------------------
void Society::AppointPresident(Student &s){
  if(president==0 && (s.get_cgpa()) > 3.0){
    president = &s;
  }
  else if(president !=0 && s.get_cgpa() >3){
    std::cout << s.GetName() << " can not be appointed as president,President is not vacant\n";
  }
  else{
    std::cout << s.GetName() << " cannot be appointed as president,gpa critaria is not met\n";

  }
}
//-----------------------
void Society::AddMember(Student &s){
  if(president==&s){
    std::cout << s.GetName() << " cannot be added, he is president\n";
  }
  else{
    bool found =false;
    for(int i=0; i< 5; i++){
      if(&s==members[i]) {found=true;break;}
    }
    if(found){
      std::cout << s.GetName() << " cannot be added as he is already memeber.\n";
    }
    else if( noOfStudents >=5){
      std::cout << s.GetName() << " cannot be added because there is not vacant.\n";
    }
    else{
      members[noOfStudents++] = &s;
    }
  }
}

void Society::PrintInfo(){
  std::cout << "Society Name: " << name << std::endl << std::endl;
  std::cout << "President: ";
  if(president != 0)
    std::cout << (president->GetName()) << std::endl;
  else{ std::cout << " Not Available.\n";}
  for(int i=0; i< 5; i++){
    std::cout << "Member " << i+1 <<": ";
    if(i < noOfStudents){
      std::cout << members[i]->GetName() << std::endl;
    }
    else{
      std::cout << "Not available.\n" << std::endl;
    }
  }
}

Society::~Society(){

}

