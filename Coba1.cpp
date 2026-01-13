#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_PESAN = 50;
    string chatLog[MAX_PESAN];
    int jumlahPesan = 0;
    int pilihan;

    do {
        cout << "\n=== APLIKASI CHAT & LOG PESAN ===\n";
        cout << "1. Kirim Pesan\n";
        cout << "2. Tampilkan Log Pesan\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer

        if (pilihan == 1) {
            if (jumlahPesan < MAX_PESAN) {
                cout << "Masukkan pesan: ";
                getline(cin, chatLog[jumlahPesan]);
                jumlahPesan++;
                cout << "Pesan berhasil dikirim!\n";
            } else {
                cout << "Log pesan penuh!\n";
            }
        }
        else if (pilihan == 2) {
            if (jumlahPesan == 0) {
                cout << "Belum ada pesan.\n";
            } else {
                cout << "\n--- LOG PESAN ---\n";
                for (int i = 0; i < jumlahPesan; i++) {
                    cout << i + 1 << ". " << chatLog[i] << endl;
                }
            }
        }
        else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan aplikasi.\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 3);

    return 0;
}

