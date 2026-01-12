#include <iostream>
using namespace std;

string chat[5];
int top = -1;

// fungsi tambah chat (push)
void tambahChat() {
    if (top < 4) {
        top++;
        cout << "Masukkan chat: ";
        cin.ignore();
        getline(cin, chat[top]);
    } else {
        cout << "Stack penuh\n";
    }
}

// fungsi hapus chat (pop)
void hapusChat() {
    if (top >= 0) {
        cout << "Chat dihapus: " << chat[top] << endl;
        top--;
    } else {
        cout << "Stack kosong\n";
    }
}

// fungsi lihat chat terakhir (peek)
void lihatChatTerakhir() {
    if (top >= 0) {
        cout << "Chat terakhir: " << chat[top] << endl;
    } else {
        cout << "Stack kosong\n";
    }
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU STACK CHAT ===\n";
        cout << "1. Tambah Chat\n";
        cout << "2. Hapus Chat Terakhir\n";
        cout << "3. Lihat Chat Terakhir\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            tambahChat();
        } else if (pilih == 2) {
            hapusChat();
        } else if (pilih == 3) {
            lihatChatTerakhir();
        }

    } while (pilih != 4);

    return 0;
}
