#include<iostream>
#include<fstream>
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
    std::ifstream in("input.txt");
    int n, m, q;
    in >> n >> m >> q;

    std::vector<std::pair<int, int>> v_matr;
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        v_matr.push_back(std::make_pair(a-1, b-1));
    }

    std::vector<bool> destroy_flag(m);
    for (int i = 0; i < m; i++) {
        destroy_flag[i] = false;
    }

    std::vector<int> destroy(q);
    for (int i = 0; i < q; ++i) {
        in >> destroy[i];
        destroy_flag[destroy[i]-1] = true;
    }

    std::vector<int> parent(n);
    std::vector<int> size(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    int c = n;
    for (int i = 0; i < m; i++) {
        if (!destroy_flag[i]) {
               c = Union(v_matr[i].first, v_matr[i].second, parent, size, c);
        }

    }

   std::ofstream out("output.txt");
   std::vector<int> result;
   int num_zero = 0;
    for(int i = q-1; i>=0; i--){
        if (c != 1)
            result.push_back(0);
        if (c == 1) {
            result.push_back(1);
            break;
        }
       c =  Union(v_matr[destroy[i]-1].first, v_matr[destroy[i]-1].second , parent, size,c);
        num_zero++;
    }
    for (int i = 0; i < q - num_zero; i++)
        result.push_back(1);

    for (int i = q - 1;i >= 0 ; i--) 
        out <<  (result[i]);

    return 0;

}