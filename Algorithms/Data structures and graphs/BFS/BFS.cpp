#include<iostream>
#include<fstream>
#include<vector>
#include<queue>


int main() {
	std::ifstream in ("input.txt");
	int n;
	in >> n;
	std::vector<std::vector<int>> matr(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> matr[i][j];
		}
	}
	std::queue<int> q;
	std::vector<int> num(n);
	std::vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	int index = 0;
	for (int i = 0; i < n; i++){
		if (visited[i] == false) {
			q.push(i);
			visited[i] = true;
			num[i] = index;
			index++;
			while (!q.empty()) {
				int k = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (matr[k][j] == 1 && visited[j] == false) {
						visited[j] = true;
						q.push(j);
						num[j] = index;
						index++;
					}
				}
			}
		}
	}
	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++) 
		out << num[i] + 1 << " ";
	return 0;
}