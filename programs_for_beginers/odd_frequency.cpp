#include <iostream>
#define deleted -12345
using namespace std;

int main()
{
    int size,counter, j;
    do{
        cout << "enter size: ";
        cin>>size;
    }while(size <0);

    int *A=new int [size];
    int *B=new int [size];
    for(int i=0; i<size; i++){
    cin>>A[i];
    }
    j=0;
    for(int i=0; i<size; i++){
        if(A[i]%2==1){
        B[j]=A[i];
        j++;
        }

    }
    //for(int l=0; l<j; l++)
    //cout<<B[l]<<" ";
    //--------------
    for(int i=0; i< j; i++){
        int counter=0;
        int cnum = B[i];

        if( cnum != deleted){
        for(int k=0; k< j; k++){
            if(cnum==B[k]&& cnum != deleted) {counter++; B[k]=deleted;}
        }
        cout << cnum << " :" << counter << endl;
    }
    }
}
