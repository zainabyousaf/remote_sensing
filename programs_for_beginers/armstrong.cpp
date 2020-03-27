//A no 'n' is Armstrong_no if sum of it's all digit is equal to 'n'.
#include <iostream>
using namespace std;
// this is committed by new_brach

int main(){
int Armstrong_no;
cout<<"enter a no.";
cin>>Armstrong_no;
int commulative_sum =0, n=Armstrong_no;
while(n !=0){
	int digit = n %10;
    commulative_sum = commulative_sum + digit*digit*digit;
    n=n/10;
}

if(commulative_sum == Armstrong_no) cout << "is Armstrong no." << endl;
else cout << "not armstrong number" << endl;
}
