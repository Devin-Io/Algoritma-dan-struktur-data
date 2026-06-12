#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int data) {
    Node* baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return buatNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int hitungTinggi(Node* root, int& jarakMaksimum) {
    if (root == NULL) {
        return -1;
    }

    int tinggiKiri = hitungTinggi(root->left, jarakMaksimum);
    int tinggiKanan = hitungTinggi(root->right, jarakMaksimum);

    int jarak = tinggiKiri + tinggiKanan + 2;

    if (jarak > jarakMaksimum) {
        jarakMaksimum = jarak;
    }

    if (tinggiKiri > tinggiKanan) {
        return tinggiKiri + 1;
    } else {
        return tinggiKanan + 1;
    }
}

int main() {
    int N;
    Node* root = NULL;

    cout << "Jumlah data: ";
    cin >> N;

    cout << "Input data: ";
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    int jarakMaksimum = 0;
    hitungTinggi(root, jarakMaksimum);

    cout << "Jarak terjauh: " << jarakMaksimum << endl;

    return 0;
}