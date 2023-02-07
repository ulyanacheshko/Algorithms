#include <iostream>
#include<vector>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        int x1;
        std::cin >> x1;
        a[i] = x1;
    }
    for (int i = 1; i <= n; i++) {
        int x2;
        std::cin >> x2;
        b[i] = x2;
    }
    std::vector<std::vector<int>> matr(n + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= n; i++) {
        matr[i][0] = 0;
        matr[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                matr[i][j] = matr[i - 1][j - 1] + 1;
            else
                matr[i][j] = max(matr[i - 1][j], matr[i][j - 1]);
        }
    }

    int k = matr[n][n];
    std::cout << k;
    std::cout << std::endl;

    std::vector<int> in(k);
    std::vector<int> jn(k);
    int c = 0;
    for (int i = n, j = n; i >= 1 && j >= 1;) {
        if (a[i] == b[j]) {
            in[c] = i - 1;
            jn[c] = j - 1;
            i--;
            j--;
            c++;
        }
        else if (matr[i - 1][j] >= matr[i][j - 1])
            i--;
        else j--;
    }
    for (int i = k - 1; i >= 0; i--) {
        std::cout << in[i] << " ";
    }
    std::cout << std::endl;
    for (int i = k - 1; i >= 0; i--) {
        std::cout << jn[i] << " ";
    }

    return 0;
}