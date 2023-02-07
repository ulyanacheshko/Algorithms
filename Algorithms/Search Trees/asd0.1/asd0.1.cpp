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

Node* insert(Node * root, int x) {
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
            return root;
        }
    }
    *cur = new Node(x);
    return root;
}

std::ofstream out("output.txt");
void output(Node* root)
{
    if (root == NULL) { return; }
    out << root->key << std::endl;
    output(root->left);
    output(root->right);
}

int main() {
    std::ifstream in("input.txt");
    Node* node = nullptr;
    while (!in.eof()) {
        int x;
        in >> x;
        node = insert(node, x);
    }
    output(node);
    return 0;
}
