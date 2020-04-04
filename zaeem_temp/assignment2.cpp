#include <iostream>
using namespace std;
void sort(int *&, int );
// array, size
void make_set(int [], int, int * &,int &);
// duplicates, size, set, set_size
void fill_array(int *&,int );
// array, size
void Union(int const * const, int const * const, const int, const int, int *&, int &);
// A, B, Asize,Bsize, C, Csize
// least privilage provided
// read it from right to left
// costant pointer to constant integer

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
    //------------------
    const Set operator + (const Set &rhs){
        int *set_ptr; // its memory will be allocated in union function
        int set_size;
        Union(this->set, rhs.set, this->size, rhs.size, set_ptr, set_size);
        Set s3;
        s3.size = set_size;
        s3.set = set_ptr;

        return s3;

    }



    void fill_set(){
        delete []this->set; // delete previously set memory if any;
        cout << "enter size of set: ";
        cin >> this->size;
        if(size >0){
        int *temp = new int [this->size];
        fill_array(temp,size);
        make_set(temp,size,this->set,this->size);
        }
    }

    friend ostream &operator << (ostream &out, Set &obj){
        out << "{";
        if(obj.size >0){
            for(int i=0; i< obj.size-1; i++) out << obj.set[i] << ",";
            out << obj.set[obj.size-1] << "}";
        }
        else{
            out << "}";
        }
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
    cout << endl;
    Set C;
    C=B+A;
    cout << C;
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
        sort(unique_elements,new_size);
        delete []temp; // delete temp;
        // temp is local var, no need to fix dangling
        // it will die itself
}
//------------------------- fill array
void fill_array(int *&array,int size){
    cout << "enter elements space separated: ";
    for(int i=0; i< size; i++) cin >> array[i];
}

//-----------------
void sort(int *&arr, int size){
    //bubble sort
    for(int i=0; i< size-1; i++){
        bool swap=false;
        for(int j=0; j< (size-i-1);j++){
            if( *(arr+j) > *(arr+j+1)){
                int temp=*(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                swap = true;
            }
        }
        if(! swap) break;
    }
}
//-------------------
void Union(int const * const A, int const * const B, const int a_size, const int b_size, int *&C, int &size){
    // copy unique elements into C
    int c_index=0;
    int *u = new int [a_size+b_size]; // max possible size
    // it will be shrunk if needed at the end of function
    bool found;
    //----------------------copying array a into c
    for(int i=0; i< a_size; i++){
        found=false;
        //set contains only one occurance
        for(int j=0; j< c_index ; j++){
            if ( *(u+j) == *(A+i)) {
                found=true;break;
            }
        }
        if (! found) {
            // if it is unique element then insert
            //u[c_index++]=A[i];
            *(u+c_index++) = *(A+i);
        }
    }
    //----------------- copying array b
    for(int i=0; i< b_size; i++){
            found=false;
        for(int j=0; j< c_index ; j++){
            if ( *(u+j) == *(B+i)) {
                found=true;break;
            }
        }
        if (! found) {
            //u[c_index++]=B[i];
            *(u+c_index++) = *(B+i);
        }
    }
    size=c_index;

    int *final_arr = new int [size]; // shrinking array
    for(int i=0; i< size; i++) *(final_arr+i) = *(u+i);

    sort(final_arr,size);
    C=final_arr;
    delete u; //no need to NULL the ptr because it will die itself
}
