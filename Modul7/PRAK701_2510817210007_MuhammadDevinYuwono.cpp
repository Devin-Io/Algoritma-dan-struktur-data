#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int dataBaru)
{
    if (*root == NULL)
    {
        Node *baru;
        baru = new Node;

        baru->data = dataBaru;
        baru->kiri = NULL;
        baru->kanan = NULL;

        *root = baru;

        cout << "\nData berhasil ditambahkan.";
    }
    else if (dataBaru < (*root)->data)
    {
        tambah(&(*root)->kiri, dataBaru);
    }
    else if (dataBaru > (*root)->data)
    {
        tambah(&(*root)->kanan, dataBaru);
    }
    else
    {
        cout << "\nData sudah ada.";
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main()
{
    int pilihan, data;
    Node *pohon;

    pohon = NULL;

    do
    {
        system("cls");
        cout << "        PROGRAM BINARY TREE\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan PreOrder\n";
        cout << "3. Tampilkan InOrder\n";
        cout << "4. Tampilkan PostOrder\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "\nMasukkan data baru: ";
            cin >> data;

            tambah(&pohon, data);
            break;

        case 2:
            cout << "\nHasil Traversal PreOrder\n";
            cout << "------------------------------\n";

            if (pohon != NULL)
            {
                preOrder(pohon);
            }
            else
            {
                cout << "Tree masih kosong.";
            }
            break;

        case 3:
            cout << "\nHasil Traversal InOrder\n";
            cout << "------------------------------\n";

            if (pohon != NULL)
            {
                inOrder(pohon);
            }
            else
            {
                cout << "Tree masih kosong.";
            }
            break;

        case 4:
            cout << "\nHasil Traversal PostOrder\n";
            cout << "------------------------------\n";

            if (pohon != NULL)
            {
                postOrder(pohon);
            }
            else
            {
                cout << "Tree masih kosong.";
            }
            break;

        case 5:
            cout << "\nProgram selesai.";
            break;

        default:
            cout << "\nPilihan tidak tersedia.";
        }

        if (pilihan != 5)
        {
            cout << "\n\nTekan tombol apa saja untuk kembali...";
            getch();
        }

    } while (pilihan != 5);

    return 0;
}