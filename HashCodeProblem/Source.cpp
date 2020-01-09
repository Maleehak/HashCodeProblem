#include <iostream>
using namespace std;
void slicesOrdered(int, int, int*);  //actual function that prints out slices sum and which pizza to get
void swap(int&a, int& b);// helper function in sorting algorithm
void sortInDecresingOrder(int* slicesOfPizza,int typesOfPizzas); //sorts the pizza slices from max to min
int main() {
	int maxSlices = 17;
	int typesOfPizzas = 4;
	int slicesInPizzas[4] = { 2,5,6,8 };
	slicesOrdered(maxSlices, typesOfPizzas, slicesInPizzas);

}

void swap(int& a, int& b)
{
	int temp = 0;
	temp = b;
	b = a;
	a = temp;
}

void sortInDecresingOrder(int* slicesOfPizza,int typesOfPizzas) {
	//Bubble sort
	int i, j;
	for (i = 0; i < typesOfPizzas - 1; i++)
		for (j = 0; j < typesOfPizzas - i - 1; j++)
			if (slicesOfPizza[j] < slicesOfPizza[j + 1])
				swap(slicesOfPizza[j], slicesOfPizza[j + 1]);
}

void slicesOrdered(int maxSlices, int typeOfPizzas, int* slicesInPizzas) {
	int* orderedSlices = new int[typeOfPizzas]; //contains the slices of pizzas to include
	int* tempArray = new int[typeOfPizzas]; //temporary array to apply sorting algorithm to not affect the actual array
	//initializing both arrays
	for (int i = 0; i < typeOfPizzas; i++) {
		orderedSlices[i] = -1;
		tempArray[i] = slicesInPizzas[i];
	}
	//sorting tempArray
	sortInDecresingOrder(tempArray, typeOfPizzas);
	//takes the maximum
	int slicesSum = 0;
	int slicesSumTemp = 0;
	for (int i = 0; i < typeOfPizzas; i++) {
		slicesSumTemp =slicesSum+tempArray[i];
		if (slicesSumTemp <= maxSlices) {
			orderedSlices[i] = tempArray[i];
			slicesSum = slicesSumTemp;
		}

	}
	//match the values in orderedSlices and slicesInPizzas the print out the index of slicesInPizzas
	for (int i =  typeOfPizzas; i >=0; i--) {
		for (int j = 0; j < typeOfPizzas; j++) {
			if (orderedSlices[i]==slicesInPizzas[j] ) {
				cout << j;
			}
		}
	}
		
}