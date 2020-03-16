/* write a program to find the location of a given number in array*/
#include <iostream>

using namespace std;

int main()
{
  int A[50],size,search;
  bool found =false;
  cout << "enter size of an array: ";
  cin >> size;
  for(int i=0; i< size; i++){
   cin >>A[i]; 
  }
  cout << "enter to search: ";
  cin >> search;
  for(int i=0; i< size; i++){
   if(A[i] == search) {cout << i; found=true; break;}
    
  }
  if(! found) cout << "nill";
  
}
