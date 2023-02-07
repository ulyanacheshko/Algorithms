#include<iostream>
#include<fstream>
int maxim(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	std::ifstream in("input.txt");
	int k;
	in >> k;
	int** matr = new int* [k];
	for (int i = 0; i < k; i++) {
		matr[i] = new int[k];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			matr[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			in >>matr[i][j];
		}
	}
	std::ofstream out("output.txt");
	int max = 0;
	if (k == 1) {
		max = matr[0][0];
	}
	if (k == 2) {
		max = maxim(matr[0][0] + matr[0][1], matr[0][0] + matr[1][1]);
	} 
	else {
		for (int i = k - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				matr[i][j] += maxim(matr[i + 1][j], matr[i + 1][j + 1]);
			}
		}
		max = matr[0][0];
	}
	out << max;
	return 0;
}

