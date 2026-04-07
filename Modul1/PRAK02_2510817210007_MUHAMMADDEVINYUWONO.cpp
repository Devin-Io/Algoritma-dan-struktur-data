#include <iostream>
#include <cstring>
using namespace std;

struct Kendaraan {
    char plat[15];
    char jenis[20];
    char nama[30];
    char alamat[50];
    char kota[20];
};

int main() {
    Kendaraan k;

    strcpy(k.plat, "DA1234MK");
    strcpy(k.jenis, "RUSH");
    strcpy(k.nama, "Andika Hartanto");
    strcpy(k.alamat, "Jl. Kayutangi 1");
    strcpy(k.kota, "Banjarmasin");

    cout << "Plat Nomor Kendaraan : " << k.plat << endl;
    cout << "Jenis Kendaraan      : " << k.jenis << endl;
    cout << "Nama Pemilik         : " << k.nama << endl;
    cout << "Alamat Pemilik       : " << k.alamat << endl;
    cout << "Kota Pemilik         : " << k.kota << endl;

    return 0;
}