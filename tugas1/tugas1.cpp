#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[3];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode();
bool hapusPosisiDariDepan(int posisi);

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();

    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            hapusDepan();
            break;
        case 4:
            hapusBelakang();
            break;
        case 5:
            tampilkan();
            break;
        case 6:
            reset();
            break;
        case 7:
            cariData();
            break;
        case 8:
            hapusData();
            break;
        case 9:
            sisipkanSebelum();
            break;
        case 10:
            sisipkanSetelah();
            break;
        default:
            cout << "\nTERIMA KASIH" << endl;
            cout << "Program was made by Muhammad Devin Yuwono (2510817210007)." << endl;
        }

        cout << "\nPress any key to continue!" << endl;
        getch();
        system("cls");

    } while (pil < 11);

    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    return (head == NULL);
}

int hitungNode() {
    if(isEmpty()) {
        return 0;
    }

    int jumlah = 0;
    TNode *bantu = head;

    do {
        jumlah++;
        bantu = bantu->next;
    } while(bantu != head);

    return jumlah;
}

bool hapusPosisiDariDepan(int posisi) {
    int jumlah = hitungNode();

    if(jumlah == 0 || posisi < 1 || posisi > jumlah) {
        return false;
    }

    TNode *hapus;

    if(jumlah == 1) {
        hapus = head;
        dataHapus = hapus->data;
        init();
        delete hapus;
        return true;
    }

    if(posisi == 1) {
        hapus = head;
        dataHapus = hapus->data;
        head = head->next;
        tail->next = head;
        delete hapus;
        return true;
    }

    TNode *sebelum = head;

    for(int i = 1; i < posisi - 1; i++) {
        sebelum = sebelum->next;
    }

    hapus = sebelum->next;
    dataHapus = hapus->data;

    sebelum->next = hapus->next;

    if(hapus == tail) {
        tail = sebelum;
    }

    tail->next = head;
    delete hapus;

    return true;
}

void tambahDepan() {
    string barisInput, isiData;
    TNode *awalBaru = NULL;
    TNode *akhirBaru = NULL;
    int banyakData = 0;

    cout << "Masukkan beberapa data dalam satu baris" << endl;
    cout << "Pisahkan setiap data dengan spasi" << endl;
    cout << "Input : ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, barisInput);

    stringstream pecah(barisInput);

    while(pecah >> isiData) {
        TNode *baru = new TNode;
        baru->data = isiData;
        baru->next = NULL;

        if(awalBaru == NULL) {
            awalBaru = baru;
            akhirBaru = baru;
        } else {
            akhirBaru->next = baru;
            akhirBaru = baru;
        }

        banyakData++;
    }

    if(banyakData == 0) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    if(isEmpty()) {
        head = awalBaru;
        tail = akhirBaru;
        tail->next = head;
    } else {
        akhirBaru->next = head;
        head = awalBaru;
        tail->next = head;
    }

    cout << banyakData << " data berhasil ditambahkan di depan." << endl;
    cout << "Urutan data pada Linked List tetap sama dengan urutan input." << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru;
    baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty()) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }

    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepan() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int n, jumlah, posisiHapus;
    cout << "Masukkan posisi node yang ingin dihapus dari depan : ";
    cin >> n;

    if(n <= 0) {
        cout << "Posisi harus lebih besar dari 0." << endl;
        return;
    }

    jumlah = hitungNode();

    if(n > jumlah) {
        posisiHapus = jumlah;
        cout << "N lebih besar dari jumlah node." << endl;
        cout << "Maka node yang dihapus adalah tail." << endl;
    } else {
        posisiHapus = n;
    }

    hapusPosisiDariDepan(posisiHapus);

    cout << "Data \"" << dataHapus << "\" pada posisi ke-" << posisiHapus
         << " dari depan berhasil dihapus." << endl;
}

void hapusBelakang() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int n, jumlah, posisiHapus;
    cout << "Masukkan posisi node yang ingin dihapus dari belakang : ";
    cin >> n;

    if(n <= 0) {
        cout << "Posisi harus lebih besar dari 0." << endl;
        return;
    }

    jumlah = hitungNode();

    if(n > jumlah) {
        posisiHapus = 1;
        cout << "N lebih besar dari jumlah node." << endl;
        cout << "Maka node yang dihapus adalah head." << endl;
    } else {
        posisiHapus = jumlah - n + 1;
    }

    hapusPosisiDariDepan(posisiHapus);

    cout << "Data \"" << dataHapus << "\" pada posisi ke-" << n
         << " dari belakang berhasil dihapus." << endl;
}

void tampilkan() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    TNode *bantu;
    bantu = head;

    cout << "Isi Linked List : ";

    do {
        cout << bantu->data << ' ';
        bantu = bantu->next;
    } while(bantu != head);

    cout << endl;
}

void reset() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int nomor = 1;

    cout << "Proses penghapusan seluruh node:" << endl;

    while(!isEmpty()) {
        cout << "Node ke-" << nomor << " berisi \"" << head->data << "\" dihapus." << endl;
        hapusPosisiDariDepan(1);
        nomor++;
    }

    cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
}

void cariData() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    string cari;
    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;

    TNode *bantu, *bantuTampilkan;
    bool apaDitemukan = false;

    bantu = head;

    do {
        if(cari == bantu->data) {
            cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) "
                 << "merupakan data yang anda cari." << endl;
            cout << "Linked List : ";
            bantuTampilkan = head;

            do {
                if(cari == bantuTampilkan->data) {
                    cout << "[" << bantuTampilkan->data << "] ";
                } else {
                    cout << bantuTampilkan->data << ' ';
                }

                bantuTampilkan = bantuTampilkan->next;
            } while(bantuTampilkan != head);

            apaDitemukan = true;
            cout << endl;
            break;
        }

        bantu = bantu->next;
    } while(bantu != head);

    if(!apaDitemukan) {
        cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    }
}

void hapusData() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    string cari;
    cout << "Masukkan data yang ingin dihapus : ";
    cin >> cari;

    int jumlahAwal = hitungNode();
    int terhapus = 0;

    for(int i = 1; i <= jumlahAwal; i++) {
        if(!isEmpty() && head->data == cari) {
            hapusPosisiDariDepan(1);
            terhapus++;
        } else if(!isEmpty()) {
            tail = head;
            head = head->next;
        }
    }

    if(!isEmpty()) {
        tail->next = head;
    }

    if(terhapus > 0) {
        cout << "Sebanyak " << terhapus << " data \"" << cari
             << "\" telah dihapus dari Linked List." << endl;
    } else {
        cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    }
}

void sisipkanSebelum() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    TNode *bantu, *sebelum;
    string nextData;
    bool apaAda = false;

    bantu = head;
    sebelum = tail;

    cout << "Sisipkan data baru sebelum data : ";
    cin >> nextData;

    do {
        if(nextData == bantu->data) {
            apaAda = true;
            break;
        } else {
            sebelum = bantu;
            bantu = bantu->next;
        }
    } while(bantu != head);

    if(apaAda) {
        cout << "Masukkan data yang ingin ditambahkan : ";
        cin >> dataBaru;

        TNode *baru;
        baru = new TNode;

        baru->data = dataBaru;
        baru->next = bantu;
        sebelum->next = baru;

        if(bantu == head) {
            head = baru;
        }

        tail->next = head;

        cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \""
             << nextData << "\"." << endl;
    } else {
        cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
    }
}

void sisipkanSetelah() {
    if(isEmpty()) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    TNode *bantu;
    string prevData;
    bool apaAda = false;

    bantu = head;

    cout << "Sisipkan data baru setelah data : ";
    cin >> prevData;

    do {
        if(prevData == bantu->data) {
            apaAda = true;
            break;
        } else {
            bantu = bantu->next;
        }
    } while(bantu != head);

    if(apaAda) {
        cout << "Masukkan data yang ingin ditambahkan : ";
        cin >> dataBaru;

        TNode *baru;
        baru = new TNode;

        baru->data = dataBaru;
        baru->next = bantu->next;
        bantu->next = baru;

        if(bantu == tail) {
            tail = baru;
        }

        tail->next = head;

        cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \""
             << prevData << "\"." << endl;
    } else {
        cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
    }
}
