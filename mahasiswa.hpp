#include <iostream>

using namespace std;

struct Tugas{
    string nama;
    double nilai;
    Tugas* next;

    Tugas(const string& n, double g): nama(n), nilai(g), next(nullptr) {}
};

class Stack{
private:
    Tugas* top;
    double hitungnilaitot(Tugas* node){
        if(node == nullptr) return 0.0;
        return node->nilai + hitungnilaitot(node->next);
    }

public:
    Stack() : top(nullptr){}

    void push(const string& name, double nilai){
        Tugas* newTugas = new Tugas(name, nilai);
        newTugas->next = top;
        top = newTugas;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    bool pop(){
        if(isEmpty()) return false;
        Tugas* temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    double totalnilai(){
        return hitungnilaitot(top);
    }

    void displaytugas(){
        Tugas* current = top;
        while(current != nullptr){
            cout << "Tugas: "<< current->nama << "- Nilai: " << current->nilai << endl;
            current = current->next;
        }
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

};


struct Mahasiswa {
    int id;
    string nama;
    Mahasiswa* next;
    Stack Stacktugas;

    Mahasiswa(int i, const string& n) : id(i), nama(n), next(nullptr) {}
};

class LinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    
    void tambahMahasiswa(int id, const string& nama) {
        Mahasiswa* mahasiswaBaru = new Mahasiswa{id, nama};
        if (head == nullptr) {
            head = mahasiswaBaru;
            tail = mahasiswaBaru;
        } else {
            tail->next = mahasiswaBaru;
            tail = mahasiswaBaru;
        }
    }

    bool hapusMahasiswa(int id) {
        if (head == nullptr) return false;
        if (head->id == id) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr;
            return true;
        }
        Mahasiswa* current = head;
        while (current->next != nullptr && current->next->id != id) {
            current = current->next;
        }
        if (current->next == nullptr) return false;
        Mahasiswa* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current;
        delete temp;
        return true;
    }

    Mahasiswa* cariMahasiswa(int id){
        Mahasiswa* temp = head;
        while (temp != nullptr){
            if(temp->id == id) return temp;
            temp = temp->next;
        }
        return nullptr;        
    }

    void tampilkanMahasiswa() {
        Mahasiswa* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "Tugas dan Ujian: " << endl;
            temp->Stacktugas.displaytugas();
            cout << "Total Nilai: " << temp->Stacktugas.totalnilai() << endl;
            temp = temp->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

LinkedList daftarMahasiswa;

void tambah() {
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        int id;
        string nama;
        system("cls");
        cout << "---- Manajemen Mahasiswa ----" << endl;
        cout << "Masukkan ID mahasiswa ke-" << i + 1 << ": ";
        cin >> id;
        cin.ignore();
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, nama);
        daftarMahasiswa.tambahMahasiswa(id, nama);
        cout << "Data telah ditambahkan\n";
        cout << "Tekan enter untuk kembali";
        cin.get();
        system("cls");
    }
}

void tampil() {
    system ("cls");
    cout << "-----Daftar Mahasiswa-----" << endl;
    daftarMahasiswa.tampilkanMahasiswa();
    cout << "--------------------------"<< endl;
    cin.ignore();
    cout << "Enter untuk kembali";
    cin.get();
}

void hapus() {
    int id;
    system ("cls");
    cout << "---- Manajemen Mahasiswa ----" << endl;
    cout << "Masukkan ID mahasiswa yang akan dihapus: ";
    cin >> id;
    if (daftarMahasiswa.hapusMahasiswa(id)) {
        cout << "Mahasiswa dengan ID " << id << " telah dihapus.\n";
        cin.ignore();
        cout << "Enter untuk kembali";
    cin.get();
    } else {
        cout << "Mahasiswa dengan ID " << id << " tidak ditemukan.\n";
        cin.ignore();
        cout << "Enter untuk kembali";
        cin.get();
    }
}

void tambahtugas(){
    int id;
    system ("cls");
    cout << "---- Manajemen Mahasiswa ----" << endl;
    cout << "Masukkan ID mahasiswa: ";
    cin >> id;
    Mahasiswa* mahasiswa = daftarMahasiswa.cariMahasiswa(id);
    if(mahasiswa){
        string namaTugas;
        double nilai;
        cin.ignore();
        cout << "Masukkan nama tugas: ";
        getline(cin, namaTugas);
        cout << "Masukkan nilai: ";
        cin >> nilai;
        mahasiswa->Stacktugas.push(namaTugas, nilai);
        cout << "Tugas telah ditambahkan\n";
        cout << "Tekan tombol apapun untuk kembali!";
        cin.ignore();
        cin.get();
    } else{
        cout << "Mahasiswa dengan ID " << id << " tidak ditemukan\n";
        cin.ignore();
        cout << "Enter untuk kembali";
        cin.get();
    }
}