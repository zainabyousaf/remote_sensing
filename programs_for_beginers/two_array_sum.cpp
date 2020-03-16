#include <iostream>

using namespace std;

int main()
{
int A[]={1,3,5,7,8,9,2};
int B[7]= {-2,-3,-4,-6,-7,-9,-10};
int C[7];
for(int i=0; i<7; i++){
C[i]=A[i]+B[i];

}
for(int j=0; j<7; j++)
cout<<C[j]<<" ";
}
