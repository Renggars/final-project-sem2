#include <iostream>

using namespace std;

struct Jadwal
{
    string mataKuliah;
    string hari;
    string waktu;
    Jadwal *next;

    Jadwal(string mataKuliah, string hari, string waktu)
        : mataKuliah(mataKuliah), hari(hari), waktu(waktu), next(nullptr) {}
};

// Struktur Queue untuk jadwal kuliah
struct Queue
{
    Jadwal *front;
    Jadwal *rear;

    Queue() : front(nullptr), rear(nullptr) {}
};

// Fungsi untuk menambah jadwal kuliah ke dalam queue
void enqueue(Queue &q, string mataKuliah, string hari, string waktu)
{
    Jadwal *newJadwal = new Jadwal(mataKuliah, hari, waktu);
    if (q.rear == nullptr)
    {
        q.front = q.rear = newJadwal;
        return;
    }
    q.rear->next = newJadwal;
    q.rear = newJadwal;
}

// Fungsi untuk menghapus jadwal kuliah dari queue
void dequeue(Queue &q)
{
    if (q.front == nullptr)
        return;
    Jadwal *temp = q.front;
    q.front = q.front->next;

    if (q.front == nullptr)
        q.rear = nullptr;

    delete temp;
}

// Fungsi untuk menampilkan semua jadwal kuliah
void tampilkanJadwal(Queue q)
{
    if (q.front == nullptr)
    {
        cout << "Tidak ada jadwal kuliah!" << endl;
        return;
    }

    Jadwal *temp = q.front;
    cout << "      Jadwal Kuliah   " << endl;
    cout << "-------------------------" << endl;
    while (temp != nullptr)
    {
        cout << "Mata Kuliah : " << temp->mataKuliah << endl;
        cout << "Hari        : " << temp->hari << endl;
        cout << "Waktu       : " << temp->waktu << endl;
        cout << "-------------------------" << endl;
        temp = temp->next;
    }
}

// Fungsi manajemen jadwal kuliah
void jadwalKuliah(Queue &q)
{
    while (true)
    {   
        int pilihan;
        system ("cls");
        cout << "---- Manajemen Jadwal Kuliah ----" << endl;
        cout << "1. Tambah Jadwal Kuliah" << endl;
        cout << "2. Hapus Jadwal Kuliah" << endl;
        cout << "3. Tampilkan Semua Jadwal Kuliah" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1)
        {   
            
            system ("cls");
            string mataKuliah, hari, waktu;
            cin.ignore(); // Membersihkan buffer
            cout << "---- Manajemen Jadwal Kuliah ----" << endl;
            cout << "Masukkan mata kuliah : ";
            getline(cin, mataKuliah);
            cout << "Masukkan hari        : ";
            getline(cin, hari);
            cout << "Masukkan waktu       : ";
            getline(cin, waktu);
            enqueue(q, mataKuliah, hari, waktu);
            system("cls");
            cout << "Jadwal kuliah berhasil ditambahkan!" << endl;
        }
        else if (pilihan == 2)
        {
            dequeue(q);
            system("cls");
            cout << "Jadwal kuliah berhasil dihapus!" << endl;
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
        }
        else if (pilihan == 3)
        {
            system ("cls");
            tampilkanJadwal(q);
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
        }
        else if (pilihan == 4)
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