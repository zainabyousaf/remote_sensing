#include <iostream>
using namespace std;
void make_set(int [], int, int * &,int &);
// duplicates, size, set, set_size
void fill_array(int *&,int );
// array, size
class Set{
private:
    int size,*set; // first small letter
public:
    Set(){size=0;set = 0; // nullptr
    }

    Set(int elements[], int size){
        make_set(elements,size,this->set,this->size);
        // size and set has been modified as passed by reference
    }

    Set(const Set &obj){
        this->size = obj.size;
        this->set = new int [this->size];
        for(int i=0; i< size; i++) this->set[i] = obj.set[i];
        // no need to check duplicates as set always contains unique
    }

    Set &operator = (const Set &rhs){
        if(this != &rhs){ //testing self-assignment
            delete []this->set; // delete previous if any

            this->size = rhs.size;
            this->set = new int [this->size];
            for(int i=0; i< size; i++) this->set[i] = rhs.set[i];

            return *this;
        }
    }



    void fill_set(){
        delete []this->set; // delete previously set memory if any;
        cout << "enter size of set: ";
        cin >> this->size;
        int *temp = new int [this->size];
        fill_array(temp,size);
        make_set(temp,size,this->set,this->size);
    }

    friend ostream &operator << (ostream &out, Set &obj){
        out << "{";
        for(int i=0; i< obj.size-1; i++) out << obj.set[i] << ",";
        out << obj.set[obj.size-1] << "}";
        return out;
    }
    friend istream &operator >> (istream &in,Set &obj){
        //delete []obj.set; // delete previously set memory if any;
        obj.fill_set();
        return in;
    }
};
// ==================================== main
int main(){
    Set A;
    Set B;
    A.fill_set();
    B.fill_set();
    cout << A;
    cout << B;
    Set C(B);
    cout << C;
    A=A;
    cout << A;
    return 0;
}
// =================================== end of main

//------------------ make_set function definition
void make_set(int elements[], int size, int * &unique_elements,int &new_size){
    int *temp =new int [size];
    int index = 0;
    bool found;
    for(int i=0; i< size; i++){
        found=false;
        //set contains only one occurrence
        for(int j=0; j< index ; j++){
            if ( temp[j] == elements[i]) {
                found=true;break;
            }
        }
        if (! found) {
            // if it is unique element then insert
            temp[index++] = elements[i];
        }
        }
        // there are some empty spaces in set
        // because some duplicates have been removed
        unique_elements = new int [index];
        for(int i=0; i< index; i++) unique_elements[i] = temp[i];
        // reset the new size
        new_size = index;
        delete []temp; // delete temp;
        // temp is local var, no need to fix dangling
        // it will die itself
}
//------------------------- fill array
void fill_array(int *&array,int size){
    cout << "enter elements space separated: ";
    for(int i=0; i< size; i++) cin >> array[i];
}
