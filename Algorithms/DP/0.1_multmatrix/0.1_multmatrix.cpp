#include <iostream>
#include <fstream>
#include<vector>

int min(int a, int b){
    if (a < b) return a;
    else return b;
}
int main(){
    std::ifstream in("input.txt");
    int size;
    in >> size;
    std::vector<std::pair<int, int>> v;
    while (!in.eof()) {
        for (int i = 0; i < size; i++) {
            int n, m;
            in >> n >> m;
            v.push_back(std::make_pair(n, m));
        }
    }
    int** matr = new int* [size];
    for (int i = 0; i < size; i++) {
        matr[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        matr[i][i] = 0;
    }
    for (int i = 0; i < size - 1; i++) {
        matr[i][i + 1] = v[i].first * v[i].second * v[i + 1].first;
    }
    for (int l = 1; l < size; ++l) {
        for (int i = 0; i < size - l; ++i) {
            int j = i + l;
            matr[i][j] = INT32_MAX;
            for (int k = i; k < j; ++k) {
                matr[i][j] = min(matr[i][j], matr[i][k] + matr[k+1][j] + v[i].first * v[k].second * v[j].second);
            }
        }
    }
    std::ofstream out("output.txt");
    out << matr[0][size - 1];
    for (int i = 0; i < size; i++) {
        delete[] matr[i];
    }
    delete[] matr;

    return 0;
}