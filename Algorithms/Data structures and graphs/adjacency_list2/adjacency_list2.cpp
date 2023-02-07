#include<iostream>
#include<fstream>
#include<vector>

int main() {
	std::ifstream in("input.txt");
	int n, m;
	in >> n;
	in >> m;
	std::vector<std::pair<int, int>> v;
	for (int i = 1; i <= m; i++) {
		int a, b;
		in >> a >> b;
		v.push_back(std::make_pair(a, b));
	}
	std::vector< std::vector<int>> vec(n);
	for (int i = 0; i < m; i++) {
		vec[v[i].first-1].push_back(v[i].second);
		vec[v[i].second-1].push_back(v[i].first);
	}
	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		out << vec[i].size() << " ";
		for (int j = 0; j < vec[i].size(); j++)
			out  << vec[i][j] << " ";
		out << std :: endl;

	}
	return 0;
}