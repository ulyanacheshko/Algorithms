#include<iostream>
#include<fstream>
#include<vector>
void DFS(int v, std::vector<std::vector<int>> matr, std::vector<bool>& visited, int n, std::vector<int>& num,int& index) {
	visited[v] = true;
	num[v] = index;
	index++;
	for (int j = 0; j < n; j++) 
		if (matr[v][j] == 1 && visited[j] == false) 
			DFS(j, matr, visited, n, num, index);
	
}
int main() {
	std::ifstream in("input.txt");
	int n;
	in >> n;
	std::vector<std::vector<int>> matr(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> matr[i][j];
		}
	}
	std::ofstream out("output.txt");
	std::vector<int> num(n);
	std::vector<bool> visited(n);
	int index = 1;
	for (int i = 0; i < n; i++)
		visited[i] = false;
	for (int i = 0; i < n; i++) 
		if (visited[i] == false) 
			DFS(i, matr, visited, n, num,index);
	for (int i = 0; i < n; i++)
		out << num[i] << " ";

	return 0;
}