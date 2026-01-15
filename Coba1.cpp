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
        cout << "2. Tampilkan pesan\n";
        cout << "3. Hapus Pesan\n";
        cout << "4. Cari Pesan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        // ================= kirim pesan =================
        if (pilihan == 1) {
            if (jumlahPesan < MAX_PESAN) {
                cout << "Masukkan pesan: ";
                getline(cin, chatLog[jumlahPesan]);
                jumlahPesan++;
                cout << "Pesan berhasil ditambahkan!\n";
            } else {
                cout << "Log pesan penuh!\n";
            }
        }

        // ================= tampilkan pesan =================
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

        // ================= hapus pesan =================
        else if (pilihan == 3) {
            if (jumlahPesan == 0) {
                cout << "Tidak ada pesan yang bisa dihapus.\n";
            } else {
                int hapus;
                cout << "Masukkan nomor pesan yang ingin dihapus: ";
                cin >> hapus;

                if (hapus < 1 || hapus > jumlahPesan) {
                    cout << "Nomor pesan tidak valid!\n";
                } else {
                    for (int i = hapus - 1; i < jumlahPesan - 1; i++) {
                        chatLog[i] = chatLog[i + 1];
                    }
                    jumlahPesan--;
                    cout << "Pesan berhasil dihapus!\n";
                }
            }
        }

        // ================= cari pesan =================
        else if (pilihan == 4) {
            if (jumlahPesan == 0) {
                cout << "Belum ada pesan untuk dicari.\n";
            } else {
                string keyword;
                bool ditemukan = false;

                cout << "Masukkan kata kunci: ";
                getline(cin, keyword);

                cout << "\nHasil pencarian:\n";
                for (int i = 0; i < jumlahPesan; i++) {
                    if (chatLog[i].find(keyword) != string::npos) {
                        cout << i + 1 << ". " << chatLog[i] << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    cout << "Pesan tidak ditemukan.\n";
                }
            }
        }

        // ================= KELUAR =================
        else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan aplikasi.\n";
        }

        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
