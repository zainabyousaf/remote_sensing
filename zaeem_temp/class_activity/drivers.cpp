
#include <iostream>
using namespace std;
class Student{
private:

    char name[50];
    char rollNo[8];
    float cgpa;
public:
Student(const char myroll[], const char *myname, float cg){
      cgpa = cg;
    for(int i=0; i< 7; i++) rollNo[i]=myroll[i];
  rollNo[7]='\0';
int ind=0;
  while(myname[ind] != '\0')ind++;
  for(int i=0; i< ind; i++) name[i]=myname[i];
name[ind]='\0';

}
void print(){
  cout << "rollNo: " << rollNo << " Name: " << name << " cgpa: " << cgpa << endl;

}
char * GetName(){
  return name;
}
float GetCGPA(){
  return cgpa;
}
};



using namespace std;
class Society{
    private:
    char name[50];
    Student* president;
    Student *members[5];
    int noOfStudents;

Society(char *myname){
  int ind=0;
  noOfStudents =0;
  while(myname[ind] != '\0') ind++;
  for(int i=0; i< ind; i++) name[i] = myname[i];
  name[ind]='\0';

  president=0;
  for(int i=0; i< 5; i++) members[i]=0;

}

void AppointPresident(Student &stu){
  if(president==0 && (stu.GetCGPA()) > 3.0){
    president = &stu;
  }
  else if(president !=0 && stu.GetCGPA() >3){
    cout << stu.GetName() << " can not be appointed as president,President is not vacant\n";
  }
  else{
    cout << stu.GetName() << " cannot be appointed as president,gpa critaria is not met\n";

  }
}

void AddMember(Student &s){
  if(president==&s){
    cout << s.GetName() << " cannot be added, he is president\n";
  }
  else{
    bool found =false;
    for(int i=0; i< 5; i++){
      if(&s==members[i]) {found=true;break;}
    }
    if(found){
      cout << s.GetName() << " cannot be added as he is already memeber.\n";
    }
    else if( noOfStudents >=5){
      cout << s.GetName() << " cannot be added because there is not vacant.\n";
    }
    else{
      members[noOfStudents++] = &s;
    }
  }
}

void PrintInfo(){
  cout << "Society Name: " << name << std::endl << std::endl;
  cout << "President: ";
  if(president != 0)
    cout << (president->GetName()) << std::endl;
  else{ cout << " Not Available.\n";}
  for(int i=0; i< 5; i++){
    cout << "Member " << i+1 <<": ";
    if(i < noOfStudents){
      cout << members[i]->GetName() << std::endl;
    }
    else{
      cout << "Not available.\n" << std::endl;
    }
  }
}

~Society(){

}

};

class Point{
    private:
    int x,y;
    public:
Point(int a=0,int b=0){
  x=a;
  y=b;

}
void print(){
  cout << "(" << x << "," << y << ")";
}

~Point(){
  cout << "~Point() called\n";
}
};

class Circle{
    private:
    float radius;
    Point center;
public:
Circle(){


}
Circle(int a, int b, float c): center(a,b) {
  radius = c;
}

void print(){
  center.print();
  cout  << " and radius: " << radius << endl;
}

~Circle(){

}
};


class CompactDisc{
    private:
    char title[20];
    int capacity;
public:
CompactDisc(const char *t,int c){
  int ind=0;
  while(t[ind] != '\0') ind++;
  for(int i=0; i< ind; i++) title[i]=t[i];
  title[ind]='\0';
  capacity = c;

}

char* GetTitle(){
  return this->title;
}

void SetTitle(const char *t){
  int ind=0;
  while(t[ind] != '\0') ind++;
  for(int i=0; i< ind; i++) title[i]=t[i];
  title[ind]='\0';
}

int get_capacity(){
  return capacity;
}

void set_capacity(int c){
  capacity = c;
}

~CompactDisc(){

}
};


