#include <iostream>
using namespace std;

void sort(int *&, int );
// array, size
void make_set(int [], unsigned int, int * &,unsigned int &);
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
    unsigned int size;
    int *set; // first small letter
public:
    Set(){size=0;set = 0; // nullptr
    }

    Set(int elements[], unsigned int size){
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
    bool isElement(int key){
        bool found=false;
        for(int i=0; i< size; i++){
            if(key == set[i]) found=true;
        }
        if(found) return true;
        return false;
    }
    //------------------ operator + for union
    const Set operator + (const Set &rhs){
        int *set_ptr; // its memory will be allocated in union function
        int set_size;
        Union(this->set, rhs.set, this->size, rhs.size, set_ptr, set_size);
        Set s3;
        s3.size = set_size;
        s3.set = set_ptr;

        return s3;

    }
    //------------------------- s3 += s2
    // left hand side is not constant
    Set &operator +=(const Set &obj){
        int *set_ptr;
        int set_size;
        Union(this->set,obj.set,this->size,obj.size,set_ptr,set_size);
        // now delete this->set because it has been copied
        delete []this->set;
        this->set = set_ptr;
        this->size=set_size;

        return *this;

    }
    //------------------ s3 = s2 +4
    Set operator +(int val){
        int *set_ptr;
        unsigned int set_size = this->size+1;
        set_ptr = new int [set_size];
        set_ptr[0]=val;
        for(int i=0; i< set_size-1; i++) set_ptr[i+1] = this->set[i];
        sort(set_ptr,set_size);
        Set temp(set_ptr,set_size);
        return temp;

    }
    //------------------------ += operator
        Set &operator +=(int val){
        int *set_ptr;
        int set_size;
        this->size=this->size+1;
        set_ptr = new int [this->size];
        set_ptr[0]=val;
        for(int i=0; i< this->size; i++) set_ptr[i+1] = this->set[i];

        delete this->set;
        this->set = set_ptr;
        sort(this->set,this->size);
        return *this;

    }
    //---------------------
    void fill_set(){
        delete []this->set; // delete previously set memory if any;
        cout << "enter size of set: ";
        unsigned int array_size;
        cin >> array_size;
        if(array_size > 0){
        int *temp = new int [array_size];
        fill_array(temp,array_size);
        make_set(temp,array_size,this->set,this->size);
        }
    }
    //-------------------- pre inrement
    Set &operator ++(){
        for(int i=0; i< this->size; i++){
            ++(this->set[i]);
        }
        return *this;
    }
    //-------------------- post increment
        Set &operator ++(int){
            static Set temp(*this);
            // it will remain alive when cout will call
            for(int i=0; i< this->size; i++){
            //temp.set[i]=this->set[i]; // copy before updating
                ++(this->set[i]);
        }
        return temp;
    }
    //-------------------- pre decrement
        Set &operator --(){
            for(int i=0; i< this->size; i++){
                --(this->set[i]);
            }
        return *this;
    }
    //------------------- -- post decrement
        Set &operator --(int){
            static Set temp(*this); // create temp obj
        for(int i=0; i< this->size; i++){
            --(this->set[i]);
        }
        return temp;
    }
    //-------------------- int iVal = A
    operator int(){
        if(size >0){
        if(size % 2==1) {return set[size/2];}
        else{return (set[size/2]+set[size/2 -1])/2;}
        }
        else return 0;
    }
    //-------------------- float ival = A
        operator float(){
        if(size >0){
        if(size % 2==1) {return (float)set[size/2];}
        else{return (float)(set[size/2]+set[size/2 -1])/2.0;}
        }
        else return 0.0;
    }

    //-------------------- cout << A
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
    //-------------------- s1 - s2
    Set &operator -(const Set &rhs){
        if(this->size > 0){
            int *temp_set = new int [this->size];
            int temp_index=0;
            bool found;
            for(int i=0; i< this->size; i++){
                found =false;
                for(int j=0; j < rhs.size; j++){
                    if(this->set[i]==rhs.set[j]) {found=true;break;}
                }
                if(!found){
                    temp_set[temp_index++] = rhs.set[i];
                }

            }

            delete []this->set;
            this->set = new int [temp_index];
            this->size = temp_index;
            for(int i=0; i< this->size; i++) this->set[i]=temp_set[i];
            delete []temp_set;
        }
            return *this;
    }
    //---------------------- !A empty test operator over loader
    bool operator !(){
        if(this->size > 0) return false;
        else return true;
    }
    //----------------------- A||B
    bool operator ||(const Set &rhs){
        if(this->size > 0 || rhs.size >0) return true;
        else return false;
    }
    //------------------ A && B
    bool operator &&(const Set &rhs){
        if(this->size > 0 && rhs.size >0) return true;
        else return false;
    }

    //------------------- A==B
    bool operator ==(const Set &rhs){
        for(int i=0; i< this->size; i++){
            if(this->set[i] != rhs.set[i]) return false;
        }
        return true;
    }
    //-------------------operator A -5
    Set &operator -(int val){
        if(isElement(val)){
            unsigned int set_size=this->size-1;
            int *set_ptr = new int [set_size];
            int index=0;
            for(int i=0; i< this->size; i++){
                if(this->set[i] != val){
                    set_ptr[index++]=this->set[i];
                }
            }
        delete []this->set;
        Set temp(set_ptr,set_size);
        //cout << temp << "--------";
        this->set = temp.set;
        this->size = set_size;
            }
        return *this;

    }
    //----------------- A -= B
    Set &operator -=(const Set &rhs){
        if(this->size > 0){
            int *temp_set = new int [this->size];
            int temp_index=0;
            bool found;
            for(int i=0; i< this->size; i++){
                found =false;
                for(int j=0; j < rhs.size; j++){
                    if(this->set[i]==rhs.set[j]) {found=true;break;}
                }
                if(!found){
                    temp_set[temp_index++] = rhs.set[i];
                }

            }

            delete []this->set;
            this->set = new int [temp_index];
            this->size = temp_index;
            for(int i=0; i< this->size; i++) this->set[i]=temp_set[i];
            delete []temp_set;
        }
            return *this;
    }

};
// ==================================== main
int main(){
    //cout << "Set A\n";
    //Set A;
    const int size=3;
    int array[size] = {1,2,7};
    //cout << "Set B(array,size)\n";
    Set B(array,size);
    //cout << "cin >> A\n";
    Set C = (B-2);
    cout << C;
    cout << B;
    B+=C;
    cout << B;
    B-=C;
    cout << B;
    //cout << "cout << A << endl\n";
    //cout << "printing A";
    //cout << A << endl;
    //cout << "has printed A";
    //cout << "Set C(A)\n";
    //Set C(A);

    //cout << "cout << C << endl";
    //cout << C;

    //Set D = A+B;
    //cout << "A-B";
    //Set E = A-B;

    //Set F = A++;

    //Set G = --A;

    //Set H = A+10;
    //cout << "cout << C";
    //Set I = --H++;
    //Set empt;
    //cout << !empt;
    //cout << (A || B);
    //cout << (A && B);
    //cout << "==";
    //cout << (A==C);
//    A = (A-5);
//    cout << A;
    return 0;
}
// =================================== end of main

//------------------ make_set function definition
void make_set(int elements[], unsigned int size, int * &unique_elements,unsigned int &new_size){
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
