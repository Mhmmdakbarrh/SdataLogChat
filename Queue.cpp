#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Pesan {
    int id;
    string isi;
};

Pesan queuePesan[MAX];
int frontQ = -1;
int rearQ = -1;
int nextID = 1;

// Mengecek queue penuh
bool isFull() {
    return (rearQ == MAX - 1);
}

// Mengecek queue kosong
bool isEmpty() {
    return (frontQ == -1 || frontQ > rearQ);
}

// CREATE ? ENQUEUE
void createPesan() {
    if (isFull()) {
        cout << "Queue penuh! Tidak dapat menambah pesan.\n";
        return;
    }

    string teks;
    cout << "Masukkan isi pesan: ";
    cin.ignore();
    getline(cin, teks);

    if (isEmpty()) {
        frontQ = rearQ = 0;
    } else {
        rearQ++;
    }

    queuePesan[rearQ].id = nextID++;
    queuePesan[rearQ].isi = teks;

    cout << "Pesan berhasil ditambahkan!\n";
}

// DELETE ? DEQUEUE
void deletePesan() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada pesan untuk dihapus.\n";
        return;
    }

    cout << "Menghapus pesan ID: " << queuePesan[frontQ].id << endl;
    frontQ++;

    if (frontQ > rearQ) {
        frontQ = rearQ = -1; // reset queue jika kosong
    }
}

// TAMPIL ? MENAMPILKAN SEMUA PESAN
void tampilPesan() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada pesan.\n";
        return;
    }

    cout << "\n=== Daftar Pesan dalam Queue ===\n";
    for (int i = frontQ; i <= rearQ; i++) {
        cout << "ID: " << queuePesan[i].id
             << " | Pesan: " << queuePesan[i].isi << endl;
    }
}

// SEARCHING ? MENCARI PESAN
void searchPesan() {
    if (isEmpty()) {
        cout << "Queue kosong! Tidak ada pesan untuk dicari.\n";
        return;
    }

    string key;
    cout << "Masukkan keyword pencarian: ";
    cin.ignore();
    getline(cin, key);

    bool ditemukan = false;

    cout << "\n=== Hasil Pencarian ===\n";
    for (int i = frontQ; i <= rearQ; i++) {
        if (queuePesan[i].isi.find(key) != string::npos) {
            cout << "ID: " << queuePesan[i].id
                 << " | Pesan: " << queuePesan[i].isi << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada pesan yang cocok dengan keyword.\n";
    }
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU CHAT LOG ===\n";
        cout << "1. Create Pesan \n";
        cout << "2. Delete Pesan \n";
        cout << "3. Tampil Pesan\n";
        cout << "4. Searching Pesan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: createPesan(); break;
            case 2: deletePesan(); break;
            case 3: tampilPesan(); break;
            case 4: searchPesan(); break;
            case 5: cout << "Keluar dari program...\n"; break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 5);

    return 0;
}

