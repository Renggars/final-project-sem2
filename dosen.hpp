#include <iostream>
#include <string>
using namespace std;

// Menu manajemen Dosen Start


// Struktur Node untuk pohon binary search tree
struct Dosen
{
    int id;
    string nama;
    string mataKuliah;
    string fakultas;
    Dosen *left;
    Dosen *right;

    Dosen(int id, string nama, string mataKuliah, string fakultas)
        : id(id), nama(nama), mataKuliah(mataKuliah), fakultas(fakultas), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambah dosen ke dalam pohon
Dosen *tambahDosen(Dosen *root, int id, string nama, string mataKuliah, string fakultas)
{
    if (root == nullptr)
    {
        return new Dosen(id, nama, mataKuliah, fakultas);
    }

    if (nama < root->nama)
    {
        root->left = tambahDosen(root->left, id, nama, mataKuliah, fakultas);
    }
    else
    {
        root->right = tambahDosen(root->right, id, nama, mataKuliah, fakultas);
    }

    return root;
}

// Fungsi untuk mencari dosen di dalam pohon
Dosen *cariDosen(Dosen *root, int id)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->id == id)
    {
        return root;
    }
    else if (id < root->id)
    {
        return cariDosen(root->left, id);
    }
    else
    {
        return cariDosen(root->right, id);
    }
}

// Fungsi inorder traversal untuk mengumpulkan semua dosen dalam array
void inorderTraversal(Dosen *root, Dosen *dosenArray[], int &index)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left, dosenArray, index);
    dosenArray[index++] = root;
    inorderTraversal(root->right, dosenArray, index);
}

// Fungsi untuk menampilkan semua dosen
void tampilkanDosen(Dosen *dosenArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "ID          : " << dosenArray[i]->id << endl;
        cout << "Nama        : " << dosenArray[i]->nama << endl;
        cout << "Mata Kuliah : " << dosenArray[i]->mataKuliah << endl;
        cout << "Fakultas    : " << dosenArray[i]->fakultas << endl
             << endl;
    }
}

// Fungsi untuk mengurutkan dosen berdasarkan nama
void urutkanDosen(Dosen *dosenArray[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (dosenArray[i]->id > dosenArray[j]->id)
            {
                Dosen *temp = dosenArray[i];
                dosenArray[i] = dosenArray[j];
                dosenArray[j] = temp;
            }
        }
    }
}

// Fungsi manajemen dosen
void manajemenDosen(Dosen *&root)
{
    while (true)
    {   
        system ("cls");
        int pilihan;
        cout << "---- Manajemen Dosen ----" << endl;
        cout << "1. Tambah Dosen" << endl;
        cout << "2. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            int id;
            string nama, mataKuliah, fakultas;
            system ("cls");
            cout << "---- Manajemen Dosen ----" << endl;
            cout << "Masukkan ID dosen    : ";
            cin >> id;
            cin.ignore(); // Membersihkan buffer
            cout << "Masukkan nama dosen  : ";
            getline(cin, nama);
            cout << "Masukkan mata kuliah : ";
            getline(cin, mataKuliah);
            cout << "Masukkan fakultas    : ";
            getline(cin, fakultas);
            root = tambahDosen(root, id, nama, mataKuliah, fakultas);
            system("cls");
            cout << "Dosen berhasil ditambahkan!" << endl;
        }
        else if (pilihan == 2)
        {
            system("cls");
            break;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

// End menu manajemen dosen


// Fungsi pencarian dan penampilan dosen
void cariAtauTampilkanDosen(Dosen *root)
{
    int pilihan;

    while (true)
    {   
        system ("cls");
        cout << "---------Aplikasi Manajemen Kampus---------" << endl;
        cout << "1. Manajemen Dosen" << endl;
        cout << "2. Cari Dosen" << endl;
        cout << "3. Tampilkan Semua Dosen" << endl;
        cout << "4. Urutkan dan Tampilkan Semua Dosen" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        if (pilihan == 1){
            manajemenDosen(root);
        } else if (pilihan == 2)
        {
            system("cls");
            int id;
            cout << "---- Manajemen Dosen ----" << endl;
            cout << "Masukkan ID dosen: ";
            cin.ignore(); // Membersihkan buffer
            cin >> id;
            Dosen *dosen = cariDosen(root, id);
            if (dosen)
            {
                cout << "Dosen ditemukan!" << endl;
                cout << "ID          : " << dosen->id << endl;
                cout << "Nama        : " << dosen->nama << endl;
                cout << "Mata Kuliah : " << dosen->mataKuliah << endl;
                cout << "Fakultas    : " << dosen->fakultas << endl
                     << endl;
            }
            else
            {
                cout << "Dosen tidak ditemukan!" << endl;
            }
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
        }
        else if (pilihan == 3)
        {   
            system ("cls");
            cout << "      Daftar Dosen      " << endl;
            cout << "------------------------" << endl;
            Dosen *dosenArray[100];
            int index = 0;
            inorderTraversal(root, dosenArray, index);
            tampilkanDosen(dosenArray, index);
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
        }
        else if (pilihan == 4)
        {
            system ("cls");
            cout << "      Daftar Dosen (Urut)      " << endl;
            cout << "------------------------------" << endl;
            Dosen *dosenArray[100];
            int index = 0;
            inorderTraversal(root, dosenArray, index);
            urutkanDosen(dosenArray, index);
            tampilkanDosen(dosenArray, index);
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
        }
        else if (pilihan == 5)
        {
            system("cls");
            break;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}