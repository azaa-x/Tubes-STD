#include "Product.h"
#include <iostream>"

using namespace std;

adrNode createNode(string name, int jumlah) {
    adrNode p = new Product;
    p->name = name;
    p->jumlah = jumlah;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertProduct(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->jumlah < root->jumlah) {
        insertProduct(root->left, p);
    } else {
        insertProduct(root->right, p);
    }
}

adrNode searchProduct(adrNode root, int jumlah) {
    if (root == nullptr || root->jumlah == jumlah) {
        return root;
    } else if (jumlah < root->jumlah) {
        return searchProduct(root->left, jumlah);
    } else {
        return searchProduct(root->right, jumlah);
    }
}

void inOrder(adrNode root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->name << " (" << root->jumlah << ")\n";
        inOrder(root->right);
    }
}

void preOrder(adrNode root) {
    if (root != nullptr) {
        cout << root->name << " (" << root->jumlah << ")\n";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(adrNode root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->name << " (" << root->jumlah << ")\n";
    }
}

int getMinValue(adrNode root) {
    if (root == nullptr) {
        return -1;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->jumlah;
}

int getMaxValue(adrNode root) {
    if (root == nullptr) {
        return -1;
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->jumlah;
}

adrNode deleteNode(adrNode root, int jumlah) {
    if (root == nullptr) {
        return nullptr;
    }

    if (jumlah < root->jumlah) {
        root->left = deleteNode(root->left, jumlah);
    }
    else if (jumlah > root->jumlah) {
        root->right = deleteNode(root->right, jumlah);
    }
    else {
        // node tidak memiliki anak
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // node memiliki satu anak kanan
        else if (root->left == nullptr) {
            adrNode temp = root->right;
            delete root;
            return temp;
        }
        // node memiliki satu anak kiri
        else if (root->right == nullptr) {
            adrNode temp = root->left;
            delete root;
            return temp;
        }
        // node memiliki dua anak
        else {
            int successor = getMinValue(root->right);
            root->jumlah = successor;
            root->right = deleteNode(root->right, successor);
        }
    }

    return root;
}
