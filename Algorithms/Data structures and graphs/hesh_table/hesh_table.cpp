#include<iostream>
#include<fstream>
#include<vector>
int main() {

	int m, c, n;
	std::ifstream in("input.txt");
	in >> m >> c >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		in >> vec[i];
	}
	std::vector<int> hash(m);
	for (int i = 0; i < m; i++) {
		hash[i] = -1;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			int ind = ((vec[j] % m) + c * i) % m;
			while (hash[ind] == -1) {
				hash[ind] = vec[j];
			}
			if(hash[ind] == vec[j]) { 
				break;
			}
		}
	}
	std::ofstream out("output.txt");
	for (int i = 0; i < m; i++) {
		out << hash[i] << " ";
	}
	return 0;
}

