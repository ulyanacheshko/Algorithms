#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
using namespace std;
class Node {
public:
    Node(int key) : key(key), left(0), right(0) {
    }
    int key;
    Node* left;
    Node* right;
    int difference = 0;

};

Node* insert(Node* root, int x) {
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

int keys_count(Node* root) {
    if (root == nullptr)
        return 0;
    else {
        return keys_count(root->left) + keys_count(root->right) + 1;
    }
}

int left_count(Node* root) {
    if (root->left == nullptr) return 0;
    else
        return keys_count(root->left);
}

int right_count(Node* root) {
    if (root->right == nullptr) return 0;
    else
        return keys_count(root->right);
}

int getDifference(Node* node) {
    int left_c = left_count(node);
    int right_c = right_count(node);
    int difference = abs(right_c - left_c);
    return difference;
}

int max_dif = 0;
void PostOrderTravers(Node* root) {
    if (NULL == root) return;
    PostOrderTravers(root->left);
    PostOrderTravers(root->right);
    root->difference = getDifference(root);
    if (root->difference > max_dif) {
        max_dif = root->difference;
    }
}

Node* new_node;
int i = 0;
int Find(Node* root) {
    if (root != nullptr) {
        if (root->difference == max_dif) {
            ++i;
            new_node = insert(new_node, root->key);
        }
        Find(root->left);
        Find(root->right);
    }
    return i;
}


Node* min(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == nullptr) return root;
    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->key) {
        root->right = deleteNode(root->right, x);
    }
    if (root->key == x) {
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        if (root->right == nullptr) {
            return root->left;
        }
        if (root->left == nullptr) {
            return root->right;
        }
        root->key = min(root->right)->key;
        root->right = deleteNode(root->right, root->key);
        return root;
    }
    return root;
}

int c = 0;
int inOrderTravers(Node* root, int k) {
    if (root == nullptr) return -1;
    else {
        int left = inOrderTravers(root->left, k);
        if (left != -1)
            return left;
        c++;
        if (c == k / 2 + 1)
            return root->key;
    }
    return inOrderTravers(root->right, k);
}

ofstream out("tst.out");
void output(Node* root) {
    if (root == nullptr) { return; }
    out << root->key << std::endl;
    output(root->left);
    output(root->right);
}

int main() {

    std::ifstream in("tst.in");
    Node* node = nullptr;
    while (!in.eof()) {
        int a;
        in >> a;
        node = insert(node, a);
    }
    PostOrderTravers(node);

    int k = Find(node);
    if (k % 2 == 0) {
        output(node);
    }
    else {
        int to_delete = inOrderTravers(new_node, k);
        node = deleteNode(node, to_delete);
        output(node);
    }
    return 0;
}