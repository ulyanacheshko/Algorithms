#include<iostream>
#include<fstream>

int main() {
	std::ifstream in("input.txt");
	int n;
	in >> n;
	int** matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			in >> matr[i][j];
	}
	
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matr[i][j] == 1) {
				arr[j] = i+1;
			}
		} 
	}
	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		out << arr[i] << " ";
	}
	return 0;
}