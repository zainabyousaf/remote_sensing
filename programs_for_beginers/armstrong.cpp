#include <iostream>

using namespace std;

int main()
{
int Armstrong_no, fd, ds, sd, td, t;
cout<<"enter a no.";
cin>>Armstrong_no;
td = Armstrong_no%10;
sd = ((Armstrong_no/10)%10);
fd = Armstrong_no/100;
ds=fd*fd*fd+sd*sd*sd+td*td*td;
if(ds==Armstrong_no){
    cout<<ds<<" is Armstrong no.";
}
//this line prints prompts
//modified
else cout << "this is not Armstrong no. because sum of cubes of each digit is not equal to the original no";
}

