#include <iostream>

#define ARRAYSIZE 5

using namespace std;

int maximum(int[], int);
void oddSwap(int * x, int * y);
int * expand(int[], int);
int * concatenate(int[],int,int[],int);
void printArray(int*,int);

int main(){
	int * test1 = new int[ARRAYSIZE];
	test1[0] = 2;
	test1[1] = 10;
	test1[2] = -2;
	test1[3] = -100;
	test1[4] = 0;

	cout << "ARRAY:" << endl;
	printArray(test1, ARRAYSIZE);

	cout << endl << "Maximum Test: " << endl;
	cout << maximum(test1, ARRAYSIZE) << endl;

	cout << endl << "oddSwap test:" << endl;
	cout << "Before oddSwap: " << test1[0] << " " << test1[1] << endl;
	oddSwap(test1, (test1+1));
	cout << "After oddSwap: " << test1[0] << " " << test1[1] << endl << endl;

	

	cout << "Expand:\n" <<endl << "Before:\n";
	printArray(test1,ARRAYSIZE);
	int * test2 = expand(test1, ARRAYSIZE);
	cout << endl << "After:\n";
	printArray(test2, ARRAYSIZE*2);
	cout << endl;

	cout << "Concatenate:\nArray1:\n";
	printArray(test1, ARRAYSIZE);
	cout << "\nArray2:\n";
	printArray(test2, ARRAYSIZE*2);
	cout<<"\nAfter:\n";
	int * test3 = concatenate(test1, ARRAYSIZE, test2, ARRAYSIZE*2);
	printArray(test3, ARRAYSIZE*3);

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
	int * temp = new int[size*2];
	for(int i = 0; i <size; i++){
		*(temp+i) = *(array+i);
	}
	for(int i = size; i < size*2; i++){
		*(temp+i) = -1;
	}
	return (temp);
}

int * concatenate(int * array1, int array1size, int * array2, int array2size){
	int * temp = new int[array1size+array2size];
	for(int i = 0; i < array1size+array2size; i++){
		if(i < array1size){
			*(temp+i) = *(array1+i);
		}else{
			*(temp+i) = *(array2+i-array1size);
		}
	}

	return temp;
}

void printArray(int * array, int size){
	for(int i = 0; i < size; i++){
		cout << i << "\t" << array+i << "\t" << *(array+i) << endl;
	}
}