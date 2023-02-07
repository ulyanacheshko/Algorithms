#include<iostream>
#include<vector>

int Find(int x, std::vector<int>& parent) {
    if (x == parent[x])
        return x;
    return Find(parent[x], parent);
}

int Union(int a, int b, std::vector<int>& parent, std::vector<int>& size, int c) {
    a = Find(a, parent);
    b = Find(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            std::swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        c--;
    }
    return c;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> matr;
	for (int i = 0; i < m; i++) {
        int a, b;
		std::cin >> a >> b;
        matr.push_back(std::make_pair(a-1, b-1));
	}
    std::vector<int> parent(n);
    std::vector<int> size(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int c = n;
    std::vector<int> result;
    int num_zero = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (c != 1)
            result.push_back(0);
        if (c == 1) {
            result.push_back(1);
            break;
        }
        c = Union(matr[i].first, matr[i].second, parent, size, c);
        num_zero++;
    }
    for (int i = 0; i < m - num_zero; i++)
        result.push_back(1);
    for (int i = m - 1, j = 1; i >= 0; i--, j++) {
        if (result[i] == 0) {
            std::cout << j;
            break;
        }
    }

	return 0;
}