#include <iostream>

using namespace std;

int main()
{
int i, no, fictorial;
cout<<"enter a no: ";
cin>>no;
while(no>0){
fictorial = 1;
for(i=no; i>0; i--){
fictorial = fictorial*i;
}
cout<<"the fictorial of"<<" "<<no<<" "4<<"is"<<" "<<fictorial<<endl;
cout<<"enter a no: ";
cin>>no;
}
}

