#include <iostream>

using namespace std;

int main()
{
int A[5]={5,-6,1,-9,0};
int i=1, temp=A[0];
while(i<5){
    if(A[i]<temp) {temp=A[i];}
    i++;
}
cout<<temp;
}
