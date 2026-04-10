#include <iostream>
using namespace std;

const int n = 10;
char Q[n];
int F = -1, R = -1;

void INSERT();
void DELETEQ();
void CETAK();
void RESET();

bool kosong() {
    return F == -1;
}

bool penuh() {
    return R == n - 1;
}

int main() {
    int pil;
    do {
        cout << "\nQUEUE\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. CETAK\n";
        cout << "4. RESET\n";
        cout << "5. QUIT\n";
        cout << "Pilih: ";
        cin >> pil;

        switch (pil) {
            case 1: INSERT(); break;
            case 2: DELETEQ(); break;
            case 3: CETAK(); break;
            case 4: RESET(); break;
            case 5: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan salah\n";
        }
    } while (pil != 5);

    return 0; 
}

void INSERT() {
    char huruf;
    if (penuh()) {
        cout << "Queue penuh\n";
    } else {
        cout << "Masukkan data: ";
        cin >> huruf;
        if (kosong()) F = 0;
        Q[++R] = huruf;
        cout << "Data masuk ke queue\n";
    }
}

void DELETEQ() {
    if (kosong()) {
        cout << "Queue kosong\n";
    } else {
        cout << "Data " << Q[F] << " dihapus\n";
        if (F == R)
            F = R = -1;
        else
            F++;
    }
}

void CETAK() {
    if (kosong()) {
        cout << "Queue kosong\n";
    } else {
        cout << "Isi queue: ";
        for (int i = F; i <= R; i++)
            cout << Q[i] << " ";
        cout << endl;
    }
}

void RESET() {
    F = R = -1;
    cout << "Queue dikosongkan\n";
}