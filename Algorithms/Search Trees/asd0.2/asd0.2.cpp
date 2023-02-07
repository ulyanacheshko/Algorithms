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
Node* min(Node* root) {
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int x) {
    if (root == nullptr) return root;
    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root-> key) {
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
        root->right = deleteNode (root->right, root->key);
        return root;

    }
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
    int x;
    in >> x;
    while (!in.eof()) {
        int a;
        in >> a;
        node = insert(node, a);
    }
    node = deleteNode(node, x);
    output(node);
    return 0;
}



/*
    if (root == nullptr) return root;
    if (x < root->key)
        root->left = delete(root->left, x);
    if (x > root->key)
        root->right = delete(root->right, x);
    if (x == root->key) {
        if (root->left == nullptr)
            root = root->right;
        else if (root->right = nullptr)
            root = root->left;
        else {
            Node* t = root->right;
            while (t->left != nullptr)
                root->key = t->key;
            root->key = t->key;
        }
    }
    return root;*/


/*Node* deleteNode(Node* root, int x) {
    if (root == nullptr) return root;
    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root-> key) {
        root->right = deleteNode(root->right, x);
    }
    else if (root->left && root->right) {
        root->key = min(root->right)->key;
        root->right = deleteNode(root->right, min(root->right)->key);
        
    }
    else if (root->left)
        root = root->left;
    else if (root->right)
        root = root->right;
    else if (!root->left && !root->right)
        root = NULL;
    return root;
}*/