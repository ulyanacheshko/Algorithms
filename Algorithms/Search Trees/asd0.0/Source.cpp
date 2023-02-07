//#include <iostream>
//#include <set>
//#include <fstream>;
//
//int main() {
//	std::set <long long> set1;
//	long long temp = 0; 
//	long long sum = 0;
//	std::ifstream in;
//	in.open("input.txt");
//	while (!in.eof()) {
//		in >> temp;
//		set1.insert(temp);
//	}
//	auto it = set1.begin();
//	while (it != set1.end()) {
//		sum += *it;
//		auto curr = it++;
//		if (*curr) {
//			set1.erase(curr);
//		}
//	}
//	std::ofstream out;
//	out.open("output.txt");
//	if (out.is_open()){
//		out << sum;
//	}
//    return 0;
//}

#include<iostream>
#include<fstream>

class Node {
public:
    Node(int key) : key(key), left(0), right(0) {
    }
    int key;
    Node* left;
    Node* right;
};

class Tree {
public:
    Tree() : root(0) {
    }
    ~Tree() {
        DeleteNode(root);
    }
    void insert(int x);
    void print(Node* root, std::ofstream& out);
private:
    static void DeleteNode(Node* node) {
        if (node) {
            DeleteNode(node->left);
            DeleteNode(node->right);
            delete node;
        }
    }

private:
    Node* root;
};

void Tree::insert(int x) {
    Node** cur = &root;
    while (*cur) {
        Node& node = **cur;
        if (x < node.key) {
            cur = &node.left;
        }
        else if (x > node.key) {
            cur = &node.right;
        }
        else {
            return;
        }
    }
    *cur = new Node(x);
}

std::ofstream out("output.txt");
void print(Node* root, std::ofstream& out) {
    if (!root) return;
    out << root->key << std::endl;
    print(root->left, out);
    print(root->right, out);
}


int main() {
    std::ifstream in("input.txt");
    Tree* tree = new Tree();
    Node* root = nullptr;
    int x;
    while (!in.eof())
    {
        in >> x;
        tree->insert(x);
        tree->print(root, out);
    }


}