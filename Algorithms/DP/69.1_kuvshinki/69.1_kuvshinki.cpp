#include <iostream>
#include <fstream>
#include <vector>
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

using namespace std;
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int* values_of_kuvsh = new int[n];
    int* value = new int[n];
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int k;
        fin >> k;
        values_of_kuvsh[i] = k;
    }

    if (n >= 1) {
        value[0] = values_of_kuvsh[0];
    }
    if (n >= 2) {
        value[1] = -1;
    }

    for (int i = 2; i < n; ++i) {
        value[i] = max(value[i - 2], value[i - 3]) + values_of_kuvsh[i];
    }
    fout << value[n - 1];
}