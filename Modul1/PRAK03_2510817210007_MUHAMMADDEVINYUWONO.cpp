#include <iostream>
#include <string>
using namespace std;

int main() {
    char huruf;
    string kata;
    int angka;

    cout << "Masukkan sebuah huruf = ";
    cin >> huruf;

    cout << "Masukkan sebuah kata = ";
    cin >> kata;

    cout << "Masukkan sebuah angka = ";
    cin >> angka;

    cout << "Huruf yang Anda masukkan adalah " << huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << kata << endl;
    cout << "Angka yang Anda masukkan adalah " << angka << endl;

    return 0;
}