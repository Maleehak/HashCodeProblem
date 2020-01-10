#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void slicesOrdered(int, int, int*);  //actual function that prints out slices sum and which pizza to get
void slicesOrdered( ifstream&);
//void swap(int&a, int& b);// helper function in sorting algorithm
void sortInDecreasingOrder(vector<pair<int,int>> &slicesOfPizza, int&typesOfPizzas);
int main() {
	ifstream f;
	f.open("Input.txt");
	if (f.is_open()) {
		slicesOrdered(f);
		f.close();
	}
	else {
		cout << "Errror";
	}
	int maxSlices = 17;
	int typesOfPizzas = 4;
	int slicesInPizzas[4] = { 2,5,6,8 };
	//slicesOrdered(maxSlices, typesOfPizzas, slicesInPizzas);

}

void slicesOrdered( ifstream& fin) {
	vector<pair<int, int>>slicesInPizzas;
	int maxSlices = 0;
	int getValue=0;
	int typeOfPizzas = 0;
	fin >> maxSlices;
	fin >> typeOfPizzas;
	int i = 0;
	while(!(fin.eof())) {
		fin>> getValue;
		slicesInPizzas.push_back(make_pair(getValue,i));
		i++;
	}
	vector<pair<int, int>>orderedSlices;
	int slicesSum = 0;
	int slicesSumTemp = 0;
	int temp1, temp2;
	for (int i = typeOfPizzas-1; i >=0; i--) {
		slicesSumTemp = slicesSum + slicesInPizzas[i].first;
		if (slicesSumTemp <= maxSlices) {
			temp1 = slicesInPizzas[i].first;
			temp2 = slicesInPizzas[i].second;
			slicesSum = slicesSumTemp;
			orderedSlices.push_back(make_pair(temp1,temp2));
		}
		
	}
	for (int i = orderedSlices.size()-1; i >= 0; i--) {
		cout << "S"<<orderedSlices[i].second<<endl;
	}

	
	
}

