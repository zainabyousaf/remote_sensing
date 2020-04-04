#include <iostream>
using namespace std;

//void make_set(int elements, int size, Set &obj){
//
//}

class Set{
private:
    int size;
    int *set; // first small letter
public:
    Set(){
        size=0;
        set = 0; // nullptr
    }
    Set(int elements[], int size){
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
                //cout << "----\n";
            }
        }
        // there are some empty spaces in set
        // because same occurrences have been removed
        set = new int [index];
        for(int i=0; i< index; i++) set[i] = temp[i];
        // reset the new size
        this->size = index;

        delete []temp; // delete temp;
        // temp is local var, no need to fix dangling
        // it will die itself
    }

    friend ostream &operator << (ostream &out, Set &obj){
        out << "{";
        for(int i=0; i< obj.size-1; i++) out << obj.set[i] << ",";
        out << obj.set[obj.size-1] << "}";
        return out;
    }
    friend istream &operator >> (istream &in,Set &obj){
        delete []obj.set; // delete previously set memory
        cout << "enter size: ";
        in >> obj.size;
        int *buffer = new int [obj.size];
        for(int i=0; i< obj.size; i++){
            in >> buffer[i];
        }


        //make_set(temp,size,obj);
        int *temp=new int[obj.size];
        int index = 0;
        bool found;
        for(int i=0; i< obj.size; i++){
            found=false;
            //set contains only one occurrence
            for(int j=0; j< index ; j++){
                if ( temp[j] == buffer[i]) {
                    found=true;break;
                }
            }
            if (! found) {
                // if it is unique element then insert
                temp[index++] = buffer[i];
            }
        }

        // there are some empty spaces in set
        // because same occurrences have been removed
        delete []buffer;
        obj.set = new int [index];

        for(int i=0; i< index; i++) obj.set[i] = temp[i];

        // reset the new size
        obj.size = index;
        delete []temp; // delete temp;
        // temp is local var, no need to fix dangling
        // it will die itself
        return in;
    }
};

int main(){
    Set A;
    int x[3]={1,1,2};
    Set B(x,3);
    cout << B;
    Set C;
    cin >> C;
    cout << C;
    return 0;
}
