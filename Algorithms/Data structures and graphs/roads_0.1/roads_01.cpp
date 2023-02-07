#include<iostream>
#include<fstream>
#include<vector>

int Find(int x, std::vector<int>& parent) {
	if (x == parent[x])
		return x;
	return Find(parent[x], parent);
}
int Union(int a, int b, std::vector<int>& parent, std::vector<int>& size, int &n) {
	a = Find(a, parent);
	b = Find(b, parent);
	if (a != b) {
		if (size[a] < size[b])
			std::swap(a, b);
		parent[b] = a;
		size[a] += size[b];
		n--;
	}
	return n;
}

int main() {
	std::ifstream in("input.txt");
	int n, q;
	in >> n >> q;
	std::vector <std::pair<int, int>> v_matr;
	for (int i = 0; i < q; i++) {
		int a, b;
		in >> a >> b;
		v_matr.push_back(std::make_pair(a, b));
	}
	std::vector<int> parent(n);
	std::vector<int> size(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	std::ofstream out("output.txt");
	for(int i = 0; i < q; i++){
		int a = v_matr[i].first - 1;
		int b = v_matr[i].second - 1;
		out << Union(a,b, parent,size, n) << std::endl;
	}
	return 0;
}
