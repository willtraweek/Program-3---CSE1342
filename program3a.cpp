#include <iostream>

#define ARRAYSIZE 5

using namespace std;

int maximum(int[], int);
void oddSwap(int * x, int * y);
int * expand(int[], int);

int main(){
	int test1[ARRAYSIZE];
	test1[0] = 2;
	test1[1] = 10;
	test1[2] = -2;
	test1[3] = -100;
	test1[4] = 0;

	cout << "Maximum Test: " << test1 << endl;
	cout << maximum(test1, ARRAYSIZE) << endl;

	cout << endl << "oddSwap test:" << endl;
	cout << "Before: " << test1[0] << " " << test1[1] << endl;
	oddSwap(test1, (test1+1));
	cout << "After: " << test1[0] << " " << test1[1] << endl;

    return 0;
}

int maximum(int array[], int size){
	int temp = * array;
	for(int i = 1; i < size; i++){
		if(* (array+i) > temp){
			temp = *(array+i);
		}
	}
	return temp;
}

void oddSwap(int * x, int * y){
	int temp = * x;
	* x = * y;
	* y = temp;
}

int * expand(int array[], int size){
	int temp[(size*2)];

	for(int i = 0; i <size; i++){
		*(temp+i) = *(array+i);
	}
	return (temp);
}