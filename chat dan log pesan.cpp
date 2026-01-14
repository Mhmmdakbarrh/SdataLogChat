#include <iostream>
#include <string>
using namespace std;

/* ===== STRUCT NODE CHAT ===== */
struct ChatNode {
    string pengirim;
    string pesan;
    ChatNode* next;
};

ChatNode* head = NULL;

/* ===== TAMBAH PESAN ===== */
void kirimPesan(string pengirim, string pesan) {
    ChatNode* baru = new ChatNode;
    baru->pengirim = pengirim;
    baru->pesan = pesan;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        ChatNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

/* ===== TAMPIL LOG PESAN ===== */
void tampilLogPesan() {
    ChatNode* temp = head;
    int index = 1;

    cout << "\n=== LOG CHAT ===\n";
    if (temp == NULL) {
        cout << "Belum ada pesan.\n";
        return;
    }

    while (temp != NULL) {
        cout << index << ". "
             << temp->pengirim << ": "
             << temp->pesan << endl;
        temp = temp->next;
        index++;
    }
}

/* ===== SEARCH PESAN ===== */
void cariPesan(string keyword) {
    ChatNode* temp = head;
    int index = 1;
    bool ditemukan = false;

    cout << "\n=== HASIL PENCARIAN ===\n";

    while (temp != NULL) {
        if (temp->pesan.find(keyword) != string::npos ||
            temp->pengirim.find(keyword) != string::npos) {
            cout << index << ". "
                 << temp->pengirim << ": "
                 << temp->pesan << endl;
            ditemukan = true;
        }
        temp = temp->next;
        index++;
    }

    if (!ditemukan) {
        cout << "Pesan tidak ditemukan.\n";
    }
}

/* ===== DELETE PESAN ===== */
void hapusPesan(int posisi) {
    if (head == NULL) {
        cout << "Chat kosong.\n";
        return;
    }

    if (posisi == 1) {
        ChatNode* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Pesan berhasil dihapus.\n";
        return;
    }

    ChatNode* temp = head;
    for (int i = 1; i < posisi - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Posisi tidak valid.\n";
        return;
    }

    ChatNode* hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
    cout << "Pesan berhasil dihapus.\n";
}

/* ===== MENU UTAMA ===== */
int main() {
    int pilihan, posisi;
    string nama, pesan, keyword;

    do {
        cout << "\n===== MENU CHAT =====\n";
        cout << "1. Kirim Pesan\n";
        cout << "2. Lihat Log Pesan\n";
        cout << "3. Cari Pesan\n";
        cout << "4. Hapus Pesan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Nama Pengirim: ";
            getline(cin, nama);
            cout << "Isi Pesan: ";
            getline(cin, pesan);
            kirimPesan(nama, pesan);
            break;

        case 2:
            tampilLogPesan();
            break;

        case 3:
            cout << "Masukkan kata kunci: ";
            getline(cin, keyword);
            cariPesan(keyword);
            break;

        case 4:
            tampilLogPesan();
            cout << "Masukkan nomor pesan yang akan dihapus: ";
            cin >> posisi;
            hapusPesan(posisi);
            break;

        case 0:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}

