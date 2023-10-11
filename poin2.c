#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk menghitung jumlah kata dalam sebuah teks
int HitungJumlahKata(const char* teks) {
    int jumlahKata = 0;
    bool dalamKata = false;

    // Iterasi melalui setiap karakter dalam teks
    for (int i = 0; teks[i] != '\0'; i++) {
        // Cek apakah karakter saat ini adalah karakter whitespace (spasi, tab, newline)
        if (teks[i] == ' ' || teks[i] == '\t' || teks[i] == '\n') {
            dalamKata = false;
        } else if (!dalamKata) {
            // Jika bukan karakter whitespace dan sebelumnya bukan dalam kata, maka ini adalah awal kata baru
            dalamKata = true;
            jumlahKata++;
        }
    }

    return jumlahKata;
}

int main() {
    char teks[1000]; // Deklarasi array untuk menyimpan teks, dengan batasan maksimum 1000 karakter
    printf("Masukkan teks: "); // Menampilkan pesan kepada pengguna

    // Menggunakan fgets untuk membaca input pengguna dan menyimpannya dalam variabel teks
    fgets(teks, sizeof(teks), stdin);

    // Menghitung jumlah kata dalam teks
    int jumlahKata = HitungJumlahKata(teks);

    // Menampilkan hasil kepada pengguna
    printf("Jumlah kata dalam teks adalah: %d\n", jumlahKata);

    return 0;
}
