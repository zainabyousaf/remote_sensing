#include <iostream>
using namespace std;

int main(){
  cout << "enter array size: ";
  int size;
  cin >> size;
  int *array = new int [size];
  int search_index =0;
  for(int i=0; i< size; i++){
    cin >> array[i];
  }
  //-------------- input done
  int thresh;
  cout << "enter trhresh: ";
  cin >> thresh;
  int *searched = new int [size];
  for(int i=0; i< size; i++){
    int counter = 1;
    bool found = false; //dublicate found
 
      //----------- skip if serched
      for(int t=0; t < search_index; t++){
	// if found in searched array, skip it
	if(array[i] == searched[t]) {found = true; break;}
      }
      
      //-----------
      if(!found){
	// if not found in searched array then consider it
	
	for(int j=i+1; j< size; j++){
	  if(array[i] == array[j]) counter++;
	}
	if(counter > thresh) cout << array[i] << " ";
	searched [ search_index ++] = array[i];
      }
      
  }
  delete []array; //deleting dynamically allocated memory
  delete []searched;
  searched=0;
}
