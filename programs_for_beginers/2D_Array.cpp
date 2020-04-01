#include <iostream>

using namespace std;

int main()
{
    int Array[30][30], rows, clm;
    cout<<"enter rows: ";
    cin>>rows;
    cout<<"enter coulmns: ";
    cin>>clm;
    cout<<"enter array elements: ";
    for(int i=0; i<rows; i++){
        for(int j=0; j<clm; j++){
            cin>>Array[i][j];
            }
    }
    int a,b;
   for(int i=0; i<rows; i++){
        for(int j=0; j<clm; j++){
           cout<<Array[i][j]<<" ";}
           cout<<endl; }
    cout<<"enter row & column to search element: ";
    cin>>a>>b;
    cout << Array[a-1][b-1];

}
