#include <iostream>
using namespace std;

const int MAX = 5;
int stack[MAX];
int top = -1;

bool kosong() {
    return top == -1;
}

bool penuh() {
    return top == MAX - 1;
}

void push(int x) {
    if (penuh())
        cout << "Stack penuh!\n";
    else {
        stack[++top] = x;
        cout << x << " masuk ke stack\n";
    }
}

void pop() {
    if (kosong())
        cout << "Stack sudah kosong!\n";
    else
        cout << stack[top--] << " dihapus dari stack\n";
}

void tampil() {
    if (kosong()) {
        cout << "Stack sudah kosong!\n";
    } else {
        cout << "Isi stack:\n";
        for (int i = top; i >= 0; i--) {
            cout << "Stack ke-" << i << " = " << stack[i] << endl;
        }
    }
}

int main() {
    push(10);
    push(20);
    tampil();

    pop();
    pop();
    tampil();  

    return 0;
}