#include<iostream>
int main() {

	int n, k;
	std::cin >> n >> k;
    int mod = 1000000007;
    long** matr = new long* [n+1];
    for (int i = 0; i < n + 1; i++) {
        matr[i] = new long[n + 1];
    }
    
    for (int i = 0; i <= n; ++i) {
        matr[i][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        matr[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i-1; j++) {
            matr[i][j] = (matr[i - 1][j - 1] % mod + matr[i - 1][j] % mod) % mod;
        }
    }

    std::cout << matr[n][k];
    for (int i = 0; i < n + 1; i++) {
        delete[] matr[i];
    }
    delete[] matr;
	return 0;
}
