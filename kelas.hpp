#include <iostream>

using namespace std;

// Struktur untuk graf (Ruang Kelas)
struct RuangKelas
{
    string namaRuang;
    RuangKelas *next;
};

// Struktur untuk adjacency list
struct AdjacencyList
{
    RuangKelas *head;
};

// Kelas Graph
class Graph
{
public:
    int numVertices; // Ubah ini menjadi public
    AdjacencyList *adjLists;

    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists = new AdjacencyList[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjLists[i].head = nullptr;
        }
    }

    void addEdge(int src, string dest)
    {
        RuangKelas *newNode = new RuangKelas;
        newNode->namaRuang = dest;
        newNode->next = adjLists[src].head;
        adjLists[src].head = newNode;
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            RuangKelas *temp = adjLists[i].head;
            cout << "Ruang " << i << " terhubung dengan jadwal kuliah: ";
            while (temp)
            {
                cout << temp->namaRuang;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Fungsi manajemen ruang kelas
void manajemenRuangKelas(Graph &g)
{
    while (true)
    {
        int pilihan;
        cout << "---- Manajemen Ruang Kelas ----" << endl;
        cout << "1. Tambah Ruang Kelas" << endl;
        cout << "2. Tampilkan Ruang Kelas" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            int src;
            string dest;
            system ("cls");
            cout << "---- Manajemen Ruang Kelas ----" << endl;
            cout << "Masukkan nomor ruang (0 - " << g.numVertices - 1 << ") : ";
            cin >> src;
            cin.ignore(); // Membersihkan buffer
            cout << "Masukkan jadwal kuliah yang terhubung: ";
            getline(cin, dest);
            g.addEdge(src, dest);
            system("cls");
            cout << "Koneksi ruang kelas berhasil ditambahkan!" << endl;
        }
        else if (pilihan == 2)
        {
            system ("cls");
            cout << "---- Manajemen Ruang Kelas ----" << endl;
            g.printGraph();
            cin.ignore();
            cout << "Tekan enter untuk kembali";
            cin.get();
            system ("cls");
        }
        else if (pilihan == 3)
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