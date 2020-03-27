//maximum contiguous sum of of any array
//e.g; the max sum of {-1,-2,6,-3,4,1,-3} is 8.
#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"enter an array size: ";
    cin>>size;
    int *A=new int [size];
    for(int i =0; i<size; i++){
        cin>>A[i];
    }
    int max_no=0, max_sum=0;
    for(int i=0; i<size; i++){
            max_sum=max_sum+A[i];
        if(max_no<max_sum)
            max_no=max_sum;
        if(max_sum<0)
            max_sum=0;
    }
        cout<<max_no;
}
