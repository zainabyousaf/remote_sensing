#include <iostream>

using namespace std;

int main()
{
    int size, T_H,P_C=0; //T_H is threashhold & P_C is previous counter
    cout<<"enter size of array: ";
    cin>>size;
    int *A = new int [size];
    for(int i=0; i< size; i++ ){
        cin >> A[i];
    }
    cout<<"enter threashhold: ";
    cin>>T_H;
    for(int i=0; i<size; i++){
        int counter=1;
        for(int j=i+1; j<size; j++){
        if(A[i]==A[j]){
            counter++;
        }
        }
         if(counter>T_H)P_C=0;
         if(counter>T_H && counter>P_C){
                P_C=counter;
            cout<< " output: " << A[i] << " " << P_C<<endl; }
    }
}

