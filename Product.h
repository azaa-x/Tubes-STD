#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Product* adrNode;

struct Product {
    string name;
    int jumlah;
    Product *left;
    Product *right;
};

adrNode createNode(string name, int jumlah);
void insertProduct(adrNode &root, adrNode p);
adrNode searchProduct(adrNode root, int jumlah);
void preOrder(adrNode root);
void inOrder(adrNode root);
void postOrder(adrNode root);
int getMinValue(adrNode root);
int getMaxValue(adrNode root);
adrNode deleteNode(adrNode root, int jumlah);

#endif
