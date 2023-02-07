#include <iostream>

long long binarypow(long long a, long long n, long long mod) {
	long long result = 1;
	while (n > 0) {
		if (n % 2 == 1)
			return ((binarypow (a, n - 1, mod)) * a ) % mod;
		else {
			long long b = binarypow(a, n / 2, mod);
			return (b * b) % mod;
		}
	}
	return result;
}

int main(){
	int n,k;
	int mod = 1000000007;
	std::cin >> n >> k;
	long long num = 1, denom = 1;
	for (int i = n; i > n-k; i--) {
		num = (num * i) % mod;
	}
	for (int i = 1; i < k + 1; i++) {
		denom = (denom * i) % mod;
	}
	std::cout << (binarypow(denom, mod - 2, mod) * num) % mod;
	return 0;
}