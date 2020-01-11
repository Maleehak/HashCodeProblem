#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void slicesOrdered( ifstream&);
int main() {
	ifstream f;
	f.open("c_medium .txt");
	slicesOrdered(f);

}
void slicesOrdered( ifstream& fin) {
	vector<pair<int, int>>slicesInPizzas;
	if (fin.is_open()) {
		int maxSlices = 0;
		int getValue = 0;
		int typeOfPizzas = 0;
		fin >> maxSlices;
		fin >> typeOfPizzas;
		int i = 0;
		while (fin >> getValue) {
			slicesInPizzas.push_back(make_pair(getValue, i));
			i++;
		}
		fin.close();
		vector<pair<int, int>>orderedSlices;
		int slicesSum = 0;
		int pizzaTypes = 0;
		int slicesSumTemp = 0;
		int temp1, temp2;
		for (int i = slicesInPizzas.size() - 1; i >= 0; i--) {
			slicesSumTemp = slicesSum + slicesInPizzas[i].first;
			if (slicesSumTemp <= maxSlices) {
				temp1 = slicesInPizzas[i].first;
				temp2 = slicesInPizzas[i].second;
				slicesSum = slicesSumTemp;
				pizzaTypes++;
				orderedSlices.push_back(make_pair(temp1, temp2));
			}
		}
		ofstream fout;
		fout.open("c_medium_output.txt");
		fout <<pizzaTypes << endl;
		if (fout.is_open()) {
			for (int i = orderedSlices.size() - 1; i >= 0; i--) {
				fout << orderedSlices[i].second << " ";
			}
			fout.close();
		}
		else {
			cout << "Error creating output file";
		}
		

		
	}
	else {
		cout << "Error reading file";
	}
}

