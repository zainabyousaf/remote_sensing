//find dividers of a no.
#include <iostream>

using namespace std;

int main()
{
    int Div[50], no, i, counter = 0;
    cout<<"enter a no: ";
    cin>>no;
    for(i=1; i<=no; i++){
        if(no%i==0){
            Div[counter]=i;
            counter++;}
    }
    for(int j=0; j<counter; j++)
    cout<<Div[j]<<" ";
}
