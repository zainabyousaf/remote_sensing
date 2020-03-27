#include <iostream>

using namespace std;

int main()
{
int line, no1, no2, space;
// this is just a simple comment for experiment
for(line=1; line<=5; line++){
    for(no1=1; no1<=6-line; no1++){cout<<no1;}
    for(space=1; space<= 2*line-3; space++){cout<<"_";}
    for(no2= 6-line; no2>0; no2-- ){if(no2!=5) cout<<no2;}
    cout<<endl;
}
}
