#include <iostream>
//write a program that keeps on taking integers until user enters 9999
//then after entering 9999 ask user what he wants to search in array
//if you find then print the location otherwise print not found
using namespace std;
int main()
{
int Sno, i=0, no;
cout<<"enter a no: ";
cin>>no;
int A[50], j;
while(no!=9999){
A[i]=no;
cout<<"enter a no: ";
cin>>no;
i++;
}
cout<<"what do you want to search? ";
cin>>Sno; //searching no
bool found=false;
for(j=0; j<i; j++){
if(Sno==A[j]){
    cout<<j; found=true;break;}
}
if(found==false) cout << "not found !\n";
cout << "the element at " << j << " is " << A[j] << endl;
}
