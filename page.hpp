#include <iostream>
#include "hash.hpp"
#include "mahasiswa.hpp"
#include "dosen.hpp"
#include "jadwal.hpp"
#include "kelas.hpp"

using namespace std;

Dosen *root = nullptr;
Queue q;
Graph g(0); 


bool loginpage() {
    // Menambahkan beberapa user
    addUser({"admin", "admin123", "admin"});
   
    string username;
    string password;
    cout << "(username = admin || password = admin123)" << endl;
    cout << "=== Login ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (checkLogin(username, password)) {
        cout << "Login berhasil!\n";
        return true;
    } else {
        return false;
}
}

void menumhs(){
int pilihan;
    do {
        system ("cls");
        cout << "---------Aplikasi Manajemen Kampus---------\n";
        cout << "1. Tampilkan Daftar Mahasiswa\n";
        cout << "2. Tambah Data Mahasiswa\n";
        cout << "3. Hapus Mahasiswa\n";
        cout << "4. Tambah Tugas\n";
        cout << "5. Kembali ke Main Menu\n";
        cout << "-------------------------------------------\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampil();
        } else if (pilihan == 2) {
            tambah();
        } else if (pilihan == 3) {
            hapus();
        } else if (pilihan == 4) {
            tambahtugas();
        } else if (pilihan == 5){
            system("cls");
        } else {
            cout << "Pilihan tidak valid";
        }
    } while (pilihan != 5);
}

void menudosen(){
    int pilihan;
    Dosen *root = nullptr;
}


void mainmenu(){
    int pilihan;
    do{
        cout << "---------Aplikasi Manajemen Kampus---------" << endl;
        cout << "1. Menu Manajemen Mahasiswa" << endl;
        cout << "2. Menu Manajemen Dosen" << endl;
        cout << "3. Menu Manajemen Jadwal Kuliah" << endl;
        cout << "4. Menu Manajemen Kelas" << endl;
        cout << "5. Keluar dari program " << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        cout << "-------------------------------------------" << endl;

        if(pilihan == 1){
            system("cls");
            menumhs();
        } else if (pilihan == 2){
            cariAtauTampilkanDosen(root);
        } else if (pilihan == 3){
            jadwalKuliah(q);
        } else if (pilihan == 4){
            system("cls");
             // Meminta pengguna untuk memasukkan jumlah ruang kelas
            int numVertices;
            cout << "Masukkan jumlah ruang kelas: ";
            cin >> numVertices;
            g = Graph(numVertices); // Membuat objek Graph baru dengan jumlah verteks yang dimasukkan pengguna
            manajemenRuangKelas(g); // Memanggil fungsi manajemen ruang kelas dengan objek Graph yang baru
        } else if (pilihan == 5){
            system("cls");
            cout << "Terima Kasih!" << endl;
        }
        else{
            cout << "pilihan tidak valid" << endl;
        }    
    } while(pilihan !=5);
}