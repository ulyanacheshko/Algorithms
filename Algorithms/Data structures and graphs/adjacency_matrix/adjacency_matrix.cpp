#include<iostream>
#include<fstream>
#include<vector>
int main() {
	
	std::ifstream in("input.txt");
	int n, m;
	in >> n;
	in >> m;
	std::vector<std::pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		in >> a >> b;
		v.push_back(std::make_pair(a, b));
	}
	int** matr = new int* [n+1];
	for (int i = 1; i <= n; i++) {
		matr[i] = new int[n+1];
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 0; j <= n ; j++)
		matr[i][j] = 0;
	}
	for (int i = 0; i < m; ++i) {
		matr[v[i].first ][v[i].second ] = 1;
        matr[v[i].second ][v[i].first ] = 1;
	}
	std::ofstream out("output.txt");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			out << matr[i][j] << " ";
		}
		out << std::endl;
	}
	return 0;
}