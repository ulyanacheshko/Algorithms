#include<iostream>
#include<fstream>
#include<vector>

int main() {
	std::ifstream in("input.txt");
	int n, m; 
	in >> n >> m;

	std::vector <std::pair<int, int>> v_matr;
	for (int i = 0; i < n; i++) {
		int a, b;
		in >> a >> b;
		v_matr.push_back(std::make_pair(a, b));
	}

	int** matr = new int* [n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matr[i][j] = 0;
		}
	}
	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matr[v_matr[i].first][j] =  v_matr[i].second;
			matr[v_matr[i].second][j] = v_matr[i].first;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << matr[i][j] << " ";
		}
		out << std::endl;
	}
	return 0;
}

//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//ifstream fin("input.txt");
//ofstream fout("output.txt");
//
//int main()
//{
//	int n = 0, m = 0;
//	fin >> n >> m;
//	vector<vector<int>> a(n);
//	for (int i = 0; i < m; i++){
//		int p, q;
//		fin >> p >> q;
//		a[p - 1].push_back(q);
//		a[q - 1].push_back(p);
//	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < a[i].size(); j++){
//			fout << " " << a[i][j];
//		}
//		fout << endl;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		fout << a[i].size();
//		for (int j = 0; j < a[i].size(); j++)
//		{
//			fout << " " << a[i][j];
//		}
//		fout << endl;
//	}
//}