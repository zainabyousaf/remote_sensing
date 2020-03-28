//If the no you entered to search from the "sum of two pairs" is present then give\
the numbers and their locations.

#include <iostream>

using namespace std;

int main(){
    int size, no;
    int *A= new int [size];
    cout<<"enter size of an array: ";
    cin>>size;
    for(int i=0; i<size; i++){
        cin>>A[i];
    }
    cout<<"enter a no which you want to search: ";
    cin>>no;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(A[i]+A[j]==no)
    cout<<"no"<<"="<<A[i]<<"location"<<"="<<i<<" "<<"no"<<"="<<A[j]<<"location"<<"="<<j;

        }
    }
}
