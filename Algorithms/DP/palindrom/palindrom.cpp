#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	std::ifstream in("input.txt");
	std::string str;
	in >> str;
	int** arr = new int* [str.size()];
	for (int i = 0; i < str.size(); i++) {
		arr[i] = new int[str.size()];
	}
	int n = str.length();
	std::vector<std::vector<int>> matr(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		matr[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1])
			matr[i][i + 1] = 2;
		else
			matr[i][i + 1] = 1;
	}

	int j = 0;
	while (j < n) {
		for (int i = j - 1; i >= 0; i--) {
			if (str[i] == str[j])
				matr[i][j] = matr[i + 1][j - 1] + 2;
			else
				matr[i][j] = max(matr[i + 1][j], matr[i][j - 1]);
		}
		j++;
	}

	int k = matr[0][n - 1];
	std::ofstream out("output.txt");
	out << k;
	std::string palindrom;
	palindrom.resize(k);
	int rows = 0, cols = n - 1;
	for (int i1 = 0, j1 = k - 1; k >= k / 2; i1++, j1--) {
		if (str[rows] == str[cols]) {
			k = k - 2;
			palindrom[i1] = str[rows];
			palindrom[j1] = str[rows];
			rows++;
			cols--;
		}
		else if (matr[rows][cols] != matr[rows + 1][cols]) {
			cols--;
			i1--;
			j1++;
		}
		else {
			rows++;
			i1--;
			j1++;
		}
	}
	out << std::endl << palindrom;
	return 0;
}