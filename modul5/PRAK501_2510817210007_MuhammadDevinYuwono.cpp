#include <iostream>
#include <cstring>
using namespace std;


char namaAwal[] = "MUHAMMADDEVINYUWONO";
int nimAwal[] = {2,5,1,0,8,1,7,2,1,0,0,0,7};

int jumlahNama = 19;
int jumlahNIM = 13;


void tampilNama(char data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void tampilNIM(int data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}


void insertionSort(char data[], int n) {
    for (int i = 1; i < n; i++) {
        char key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}


void gabung(char data[], int kiri, int tengah, int kanan) {
    char temp[50];
    int i = kiri;
    int j = tengah + 1;
    int k = 0;

    while (i <= tengah && j <= kanan) {
        if (data[i] < data[j]) {
            temp[k] = data[i];
            i++;
        } else {
            temp[k] = data[j];
            j++;
        }
        k++;
    }

    while (i <= tengah) {
        temp[k] = data[i];
        i++;
        k++;
    }

    while (j <= kanan) {
        temp[k] = data[j];
        j++;
        k++;
    }

    for (int a = 0; a < k; a++) {
        data[kiri + a] = temp[a];
    }
}

void mergeSort(char data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;

        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah + 1, kanan);
        gabung(data, kiri, tengah, kanan);
    }
}


void shellSort(char data[], int n) {
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j = i;

            while (j >= gap && data[j - gap] > temp) {
                data[j] = data[j - gap];
                j = j - gap;
            }

            data[j] = temp;
        }
    }
}

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partisi(int data[], int awal, int akhir) {
    int pivot = data[akhir];
    int i = awal - 1;

    for (int j = awal; j < akhir; j++) {
        if (data[j] < pivot) {
            i++;
            tukar(data[i], data[j]);
        }
    }

    tukar(data[i + 1], data[akhir]);
    return i + 1;
}

void quickSort(int data[], int awal, int akhir) {
    if (awal < akhir) {
        int posisiPivot = partisi(data, awal, akhir);

        quickSort(data, awal, posisiPivot - 1);
        quickSort(data, posisiPivot + 1, akhir);
    }
}


void bubbleSort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukar(data[j], data[j + 1]);
            }
        }
    }
}


void selectionSort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int posisiTerkecil = i;

        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[posisiTerkecil]) {
                posisiTerkecil = j;
            }
        }

        tukar(data[i], data[posisiTerkecil]);
    }
}


int main() {
    int pilihan;

    do {
        cout << "======================================" << endl;
        cout << "              SORTING                 " << endl;
        cout << "======================================" << endl;
        cout << "Nama : Muhammad Devin Yuwono" << endl;
        cout << "NIM  : 2510817210007" << endl;
        cout << "======================================" << endl;
        cout << "1. Insertion Sort --Nama" << endl;
        cout << "2. Merge Sort --Nama" << endl;
        cout << "3. Shell Sort --Nama" << endl;
        cout << "4. Quick Sort --NIM" << endl;
        cout << "5. Bubble Sort --NIM" << endl;
        cout << "6. Selection Sort --NIM" << endl;
        cout << "7. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        cout << endl;

        char nama[30];
        int nim[20];

        strcpy(nama, namaAwal);

        for (int i = 0; i < jumlahNIM; i++) {
            nim[i] = nimAwal[i];
        }

        switch (pilihan) {
            case 1:
                cout << "Nama sebelum diurutkan:" << endl;
                tampilNama(nama, jumlahNama);

                insertionSort(nama, jumlahNama);

                cout << "Nama setelah Insertion Sort:" << endl;
                tampilNama(nama, jumlahNama);
                break;

            case 2:
                cout << "Nama sebelum diurutkan:" << endl;
                tampilNama(nama, jumlahNama);

                mergeSort(nama, 0, jumlahNama - 1);

                cout << "Nama setelah Merge Sort:" << endl;
                tampilNama(nama, jumlahNama);
                break;

            case 3:
                cout << "Nama sebelum diurutkan:" << endl;
                tampilNama(nama, jumlahNama);

                shellSort(nama, jumlahNama);

                cout << "Nama setelah Shell Sort:" << endl;
                tampilNama(nama, jumlahNama);
                break;

            case 4:
                cout << "NIM sebelum diurutkan:" << endl;
                tampilNIM(nim, jumlahNIM);

                quickSort(nim, 0, jumlahNIM - 1);

                cout << "NIM setelah Quick Sort:" << endl;
                tampilNIM(nim, jumlahNIM);
                break;

            case 5:
                cout << "NIM sebelum diurutkan:" << endl;
                tampilNIM(nim, jumlahNIM);

                bubbleSort(nim, jumlahNIM);

                cout << "NIM setelah Bubble Sort:" << endl;
                tampilNIM(nim, jumlahNIM);
                break;

            case 6:
                cout << "NIM sebelum diurutkan:" << endl;
                tampilNIM(nim, jumlahNIM);

                selectionSort(nim, jumlahNIM);

                cout << "NIM setelah Selection Sort:" << endl;
                tampilNIM(nim, jumlahNIM);
                break;

            case 7:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia." << endl;
        }

        cout << endl;

    } while (pilihan != 7);

    return 0;
}