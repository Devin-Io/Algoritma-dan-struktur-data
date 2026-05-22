#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head = NULL;
TNode *tail = NULL;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void tampilkanH();
void tampilkanHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void clearH();
void clearHT();

void menuHead();
void menuHeadTail();
void pauseLayar();
vector<string> inputBanyakData();
TNode* buatNode(string isi);
void tambahDepanSatu(string isi);
void tambahBelakangSatu(string isi);
void hapusNode(TNode *hapus);
int hitungNode();
void hapusBelakangKeN();
void hapusTarget();
void tampilkanData();

int main() {
    int menu;
    initHT();

    do {
        cout << "Double Linked List Non Circular (DLLNC)" << endl;
        cout << "======================================" << endl;
        cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
        cout << "1. DLLNC dengan Head" << endl;
        cout << "2. DLLNC dengan Head dan Tail" << endl;
        cout << "3. Quit" << endl;
        cout << "Pilihan : ";
        cin >> menu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");

        if (menu == 1) {
            menuHead();
        } else if (menu == 2) {
            menuHeadTail();
        } else if (menu != 3) {
            cout << "Pilihan tidak tersedia." << endl;
            pauseLayar();
            system("cls");
        }
    } while (menu != 3);

    cout << "\nTERIMA KASIH" << endl;
    cout << "Program was made by Muhammad Devin Yuwono (2510817210007)." << endl;

    return 0;
}

void menuHead() {
    int pil;

    do {
        cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
        cout << "==============================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang ke-N" << endl;
        cout << "6. Hapus Berdasarkan Target" << endl;
        cout << "7. Clear / Reset" << endl;
        cout << "8. Kembali ke Menu" << endl;
        cout << "Pilihan : ";
        cin >> pil;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");

        switch (pil) {
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            case 8:
                cout << "Kembali ke menu utama." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia." << endl;
        }

        if (pil != 8) {
            pauseLayar();
            system("cls");
        }
    } while (pil != 8);

    system("cls");
}

void menuHeadTail() {
    int pil;

    do {
        cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
        cout << "=======================================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang ke-N" << endl;
        cout << "6. Hapus Berdasarkan Target" << endl;
        cout << "7. Clear / Reset" << endl;
        cout << "8. Kembali ke Menu" << endl;
        cout << "Pilihan : ";
        cin >> pil;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");

        switch (pil) {
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            case 8:
                cout << "Kembali ke menu utama." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia." << endl;
        }

        if (pil != 8) {
            pauseLayar();
            system("cls");
        }
    } while (pil != 8);

    system("cls");
}

void pauseLayar() {
    cout << "\n\nTekan ENTER untuk melanjutkan...";
    cin.get();
}

void initH() {
    head = NULL;
    tail = NULL;
}

void initHT() {
    head = NULL;
    tail = NULL;
}

int isEmptyH() {
    if (head == NULL) return 1;
    else return 0;
}

int isEmptyHT() {
    if (head == NULL && tail == NULL) return 1;
    else return 0;
}

TNode* buatNode(string isi) {
    TNode *baru = new TNode;
    baru->data = isi;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

vector<string> inputBanyakData() {
    vector<string> daftarData;
    string baris, kata;

    cout << "Masukkan data (boleh lebih dari satu, pisahkan dengan spasi): ";
    getline(cin, baris);

    stringstream ss(baris);
    while (ss >> kata) {
        daftarData.push_back(kata);
    }

    return daftarData;
}

void tambahDepanSatu(string isi) {
    TNode *baru = buatNode(isi);

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void tambahBelakangSatu(string isi) {
    TNode *baru = buatNode(isi);

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void tambahDepanH() {
    vector<string> daftarData = inputBanyakData();

    if (daftarData.size() == 0) {
        cout << "Data tidak boleh kosong.";
        return;
    }

    for (int i = (int)daftarData.size() - 1; i >= 0; i--) {
        tambahDepanSatu(daftarData[i]);
    }

    cout << "Data berhasil dimasukkan di bagian depan." << endl;
    cout << "Urutan data tetap mengikuti urutan input.";
}

void tambahDepanHT() {
    tambahDepanH();
}

void tambahBelakangH() {
    vector<string> daftarData = inputBanyakData();

    if (daftarData.size() == 0) {
        cout << "Data tidak boleh kosong.";
        return;
    }

    for (int i = 0; i < (int)daftarData.size(); i++) {
        tambahBelakangSatu(daftarData[i]);
    }

    cout << "Data berhasil dimasukkan di bagian belakang." << endl;
    cout << "Urutan data tetap mengikuti urutan input.";
}

void tambahBelakangHT() {
    tambahBelakangH();
}

void tampilkanData() {
    TNode *bantu = head;
    if (head == NULL) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    cout << "Isi Linked List:" << endl;
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void tampilkanH() {
    tampilkanData();
}

void tampilkanHT() {
    tampilkanData();
}

void hapusNode(TNode *hapus) {
    if (hapus == NULL) return;

    if (hapus == head && hapus == tail) {
        head = NULL;
        tail = NULL;
    } else if (hapus == head) {
        head = head->next;
        head->prev = NULL;
    } else if (hapus == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
}

void hapusDepanH() {
    if (isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    TNode *hapus = head;
    string data = hapus->data;
    hapusNode(hapus);

    cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
}

void hapusDepanHT() {
    hapusDepanH();
}

int hitungNode() {
    int jumlah = 0;
    TNode *bantu = head;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

void hapusBelakangKeN() {
    int n;

    if (head == NULL) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    cout << "Masukkan N, yaitu node ke-N dari belakang yang ingin dihapus: ";
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input N harus berupa angka.";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 0) {
        cout << "N harus lebih dari 0.";
        return;
    }

    int total = hitungNode();
    int nAwal = n;

    if (n > total) {
        n = ((n - 1) % total) + 1;
        cout << "N lebih besar dari jumlah node." << endl;
        cout << "Sistem mundur digunakan, sehingga N dihitung menjadi " << n << " dari belakang." << endl;
    }

    TNode *hapus = tail;
    for (int i = 1; i < n; i++) {
        hapus = hapus->prev;
    }

    string data = hapus->data;
    hapusNode(hapus);

    cout << "Data \"" << data << "\" berhasil dihapus." << endl;
    cout << "Data tersebut merupakan node ke-" << nAwal << " dari belakang berdasarkan proses hitung mundur.";
}

void hapusBelakangH() {
    hapusBelakangKeN();
}

void hapusBelakangHT() {
    hapusBelakangKeN();
}

void hapusTarget() {
    string target;
    int jumlahHapus = 0;

    if (head == NULL) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    cout << "Masukkan target data yang ingin dihapus: ";
    getline(cin, target);

    if (target == "") {
        cout << "Target tidak boleh kosong.";
        return;
    }

    TNode *bantu = head;
    while (bantu != NULL) {
        TNode *lanjut = bantu->next;

        if (bantu->data == target) {
            hapusNode(bantu);
            jumlahHapus++;
        }

        bantu = lanjut;
    }

    if (jumlahHapus > 0) {
        cout << "Semua data yang sama dengan target \"" << target << "\" berhasil dihapus." << endl;
        cout << "Jumlah node yang dihapus: " << jumlahHapus;
    } else {
        cout << "Data dengan target \"" << target << "\" tidak ditemukan.";
    }
}

void hapusTargetH() {
    hapusTarget();
}

void hapusTargetHT() {
    hapusTarget();
}

void clearH() {
    int nomor = 1;
    bool dariDepan = true;

    if (head == NULL) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    cout << "Proses clear dimulai:" << endl;

    while (head != NULL) {
        TNode *hapus;
        string data;

        if (dariDepan == true) {
            hapus = head;
            data = hapus->data;
            cout << nomor << ". Hapus dari depan    : " << data << endl;
        } else {
            hapus = tail;
            data = hapus->data;
            cout << nomor << ". Hapus dari belakang : " << data << endl;
        }

        hapusNode(hapus);
        dariDepan = !dariDepan;
        nomor++;
    }

    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT() {
    clearH();
}
