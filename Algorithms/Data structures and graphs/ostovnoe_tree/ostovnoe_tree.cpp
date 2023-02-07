#include<iostream>
#include<fstream>
#include<vector>
#include<queue>


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
	std::queue<int> q;
	std::vector<std::pair<int, int>> res;
	std::vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int k = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (matr[k][j] == 1 && visited[j] == false){
						visited[j] = true;
						q.push(j);
						res.push_back(std::make_pair(k + 1, j + 1));
					}
				}
			}
		}
	}
	std::ofstream out("output.txt");
	if (res.size() != n - 1) {
		out << -1;
	}
	else {
		out << res.size() << std::endl;
		for (int i = 0; i < res.size(); i++) {
			out << res[i].first << " " << res[i].second;
			out << std::endl;
		}
	}
	return 0;
}