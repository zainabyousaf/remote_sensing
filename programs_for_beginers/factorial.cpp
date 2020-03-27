//factorial of any no.
#include <iostream>

using namespace std;

int main()
{
int i, no, factorial;
cout<<"enter a no: ";
cin>>no;
while(no>0){
factorial = 1;
for(i=no; i>0; i--){
factorial = factorial*i;
}
cout<<"the factorial of"<<no<<"is"<<factorial<<endl;
cout<<"enter a no: ";
cin>>no;
}
}

