#include<iostream>
#include<fstream>
#include<vector>

int min(int a, int b, int c) {
	int min;
	if ((a <= b) && (a <= c)) min = a;
	else if ((b <= a) && (b <= c)) min = b;
	else min = c;
	return min;
}

int main() {
	std::ifstream in("in.txt");
	int x, y, z;
	in >> x >> y >> z;
	std::string str1,str2;
	in >> str1 >> str2;
	int n1 = str1.size();
	int n2 = str2.size();
	std::vector<std::vector<int>> matr(n1+1, std::vector<int>(n2 + 1));
	for (int i = 0; i < n1+1; i++) {
		matr[i][0] = i * x;
	}
	for (int j = 0; j < n2+1; j++) {
		matr[0][j] = j * y;
	}
	for (int i = 1; i < n1+1; i++) {
		for (int j = 1; j < n2+1; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				matr[i][j] = min(matr[i - 1][j] + x, matr[i][j - 1] + y, matr[i - 1][j - 1]);	
			}
			else {
				matr[i][j] = min(matr[i - 1][j] + x, matr[i][j - 1] + y, matr[i - 1][j - 1] + z);
			}
		}
	}
	std::ofstream out("out.txt");
	out << matr[n1][n2];
	return 0;
}