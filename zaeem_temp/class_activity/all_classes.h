#ifndef ALL_CLASSES_H
#define ALL_CLASSES_H
// pragma is not working in my environment

//---------------------- Exercise 1
class Point{
private:
    int x,y;
public:
    Point(int,int b);
    void print();
    ~Point();
};

//------------------------ Exercise 2
class Circle: public Point{
private:
    float radius;
    Point center;
public:
    Circle();
    Circle(int, int, float);//: center(int, int);
    //Circle(int, int, float): Point(int, int);

    void print();

    ~Circle();
};

//---------------------------- CD class Exercise 3
class CompactDisc{
private:
    char title[20];
    int capacity;
public:
    CompactDisc(const char *,int );
    //-------------------- getter title
    char* get_title();
    //-------------------- setter title
    void set_title(const char *);
    //---------------------- getter for capacity
    int get_capacity();
    //---------------------- setter for capacity
    void set_capacity(int );

    ~CompactDisc();
};

//--------------------- Exercise 4
class CDDrive{
private:
    char manufacturer[20];
    CompactDisc *aCompactDisc;
    int speed;
public:
    CDDrive(const char *, int );
    //-------------------------
    void InsertCD(CompactDisc *);
    //--------------------------
    void Play ();
    //--------------------------
    CompactDisc * EjectCD();
};
//------------------------------
//============================== aggregation

class Student {
private:

    char name[50];
    char rollNo[8]; // 1 for nullptr
    float cgpa;
public:
    Student(const char [7], const char *, float );
    void print();

    char *GetName();

    float get_cgpa();
};
//-----------------------------
class Society{
private:
    char name[50];
    Student* president;
    Student *members[5];
    int noOfStudents;
    // members have been added yet
    // therefore, no need to make object
    // it is done to make efficient use of memory

public:
    Society(char *);
    //--------------------
    void AppointPresident(Student &);
    //--------------------
    void AddMember(Student &s);

    void PrintInfo();

    ~Society();
};

#endif
