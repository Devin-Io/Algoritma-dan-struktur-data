#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseProgram() {
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void sequentialSearching() {
    clearScreen();

    int data[100];
    int cari;
    int counter = 0;
    bool flag = false;
    int save = -1;

    srand((unsigned)time(NULL));

    cout << "=== Sequential Searching ===\n";
    cout << "Generating 100 number...\n\n";

    for (int i = 0; i < 100; i++) {
        data[i] = (rand() % 100) + 1;
        cout << data[i] << " ";
    }

    cout << "\n\nMasukkan angka yang dicari: ";
    cin >> cari;

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = true;
            save = i;
        }
    }

    cout << endl;
    if (flag) {
        cout << "Data ada, sebanyak " << counter << "!\n";
        cout << "Pada indeks ke-" << save << endl;
    } else {
        cout << "Data tidak ditemukan! Mohon coba lagi!\n";
    }

    pauseProgram();
}

void binarySearching() {
    clearScreen();

    int n, key;
    bool ketemu = false;

    cout << "=== Binary Searching ===\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> angka(n);

    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << i + 1 << " = ";
        cin >> angka[i];
    }

    sort(angka.begin(), angka.end());

    cout << "\n============================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n============================================================\n";

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    int kiri = 0;
    int kanan = n - 1;
    int tengah;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    cout << endl;
    if (ketemu) {
        cout << "Angka ditemukan!\n";
        cout << "Angka berada pada indeks ke-" << tengah << " setelah data diurutkan.\n";
    } else {
        cout << "Angka tidak ditemukan!\n";
    }

    pauseProgram();
}

void penjelasanPerbedaan() {
    clearScreen();

    cout << "=== Perbedaan Sequential Searching dan Binary Searching ===\n\n";

    cout << "1. Sequential Searching\n";
    cout << "   Sequential Searching adalah metode pencarian data secara berurutan\n";
    cout << "   dari elemen pertama sampai elemen terakhir.\n\n";

    cout << "   Kelebihan:\n";
    cout << "   - Algoritmanya sederhana dan mudah dipahami.\n";
    cout << "   - Data tidak harus diurutkan terlebih dahulu.\n";
    cout << "   - Cocok untuk jumlah data yang sedikit.\n\n";

    cout << "   Kekurangan:\n";
    cout << "   - Proses pencarian lebih lambat jika jumlah data banyak.\n";
    cout << "   - Harus memeriksa data satu per satu sampai data ditemukan.\n\n";

    cout << "2. Binary Searching\n";
    cout << "   Binary Searching adalah metode pencarian dengan cara membagi data\n";
    cout << "   menjadi dua bagian, lalu menentukan apakah data yang dicari berada\n";
    cout << "   di bagian kiri atau kanan.\n\n";

    cout << "   Kelebihan:\n";
    cout << "   - Proses pencarian lebih cepat untuk data yang jumlahnya banyak.\n";
    cout << "   - Tidak perlu memeriksa semua data satu per satu.\n\n";

    cout << "   Kekurangan:\n";
    cout << "   - Data harus diurutkan terlebih dahulu.\n";
    cout << "   - Algoritmanya sedikit lebih rumit dibanding Sequential Searching.\n\n";

    cout << "Kesimpulan:\n";
    cout << "Sequential Searching cocok digunakan untuk data kecil atau data yang belum terurut.\n";
    cout << "Binary Searching cocok digunakan untuk data yang sudah terurut dan jumlahnya banyak.\n";

    pauseProgram();
}

int main() {
    int pilih;

    do {
        clearScreen();

        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilih = 0;
        }

        switch (pilih) {
            case 1:
                sequentialSearching();
                break;
            case 2:
                binarySearching();
                break;
            case 3:
                penjelasanPerbedaan();
                break;
            case 4:
                clearScreen();
                cout << "Program telah selesai. Terima kasih banyak!\n";
                break;
            default:
                cout << "\nPilihan tidak tersedia!\n";
                pauseProgram();
                break;
        }

    } while (pilih != 4);

    return 0;
}