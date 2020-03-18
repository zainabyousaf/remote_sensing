#include <iostream>
using namespace std;

int main(){
  cout << "enter size of an array: ";
  int size;
  cin >> size;
  int *array = new int [size];
  for(int i=0; i< size; i++){
    cin >> array[i];
  }
  //----------- array has been filled
  cout << "enter threshold: ";
  int thresh;
  cin >> thresh;
  int thresh_index=0;
  int *found_array= new int [size]; // for storing searched elements
  for(int i=0; i< size; i++){
    // weather array[i] has been searched
    bool found=false;
    int counter = 1;
    for(int t=0;t < thresh_index; t++){
      if(array[i] == found_array[t]) {found=true;break;}
    }
    if(!found){
    for(int j=i+1; j < size; j++){

      if(array[i] == array[j]) counter++;
    }
    }
    else{
      // add element to found
      found_array[thresh_index++] = array[i];
    }
  if(counter > thresh) cout << array[i] << " ";
  }

}
