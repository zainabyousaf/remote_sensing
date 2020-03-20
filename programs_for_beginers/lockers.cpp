#include <iostream>
int nDivisors(int x, int s, int e){
    // it is on master branch
    // this line is being added by master
    // how many divisors of x over domain [s,e]
    int n=0;
    for(int i=s; i<=e; i++){
        if(x%i==0) n++;
    }
    return n;
}

using namespace std;

int main()
{

int students;
    int lockers;
    do{
    // validation checks
    cout << "enter number of lockers: ";
    cin >> lockers;
    cout << "enter student: ";

    cin >> students;
    } while( lockers > 5000 && students > lockers);

int total_open;
    for(int s=1; s <= students; s++){
        total_open = 0;
        cout << s << ": student ";
        for(int l=1; l<= lockers; l++){
            if(nDivisors(l,1,s) %2==0) {cout << "0 ";}
            else{total_open++; cout << "1 ";}
        }

       cout << total_open << endl;
        cout << endl;
    }
    cout << "Total Open Lockers: " << total_open << endl;
}
