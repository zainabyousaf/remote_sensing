#include <iostream>

using namespace std;

int main()
{   int temp, j, i;
    int A[5]={5,3,7,1,8};
for(i=0; i<5; i++){
    for(j=0; j<5-i; j++){
        if(A[j+1]<A[j]){temp=A[j];
                        A[j]=A[j+1];
                        A[j+1]=temp;}

    }
    cout<<A[i]<<" ";
}
}
