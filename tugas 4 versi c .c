#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Fungsi untuk menghitung jumlah karakter dalam sebuah teks
int HitungJumlahKarakter(const char* teks) {
    return strlen(teks);
}

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

// Fungsi untuk mencari kata tertentu dalam sebuah teks
bool CariKata(const char* teks, const char* kataDicari) {
    char* pos = strstr(teks, kataDicari);
    return pos != NULL;
}

// Fungsi untuk menghitung jumlah kata tertentu dalam sebuah teks
int HitungJumlahKataTertentu(const char* teks, const char* kataTertentu) {
    int jumlah = 0;
    char teksSalin[1000]; // Maksimum 1000 karakter

    // Salin teks ke teksSalin
    strcpy(teksSalin, teks);

    // Ubah teksSalin menjadi huruf kecil
    for (int i = 0; teksSalin[i]; i++) {
        teksSalin[i] = tolower(teksSalin[i]);
    }

    char* token = strtok(teksSalin, " ");
    while (token != NULL) {
        if (strcmp(token, kataTertentu) == 0) {
            jumlah++;
        }
        token = strtok(NULL, " ");
    }

    return jumlah;
}

int main() {
    char tulisan[10000]; // Deklarasi array untuk menyimpan teks, dengan batasan maksimum 1000 karakter
    int pilihan;

    printf("Masukkan teks: "); // Menampilkan pesan kepada pengguna
    // Menggunakan fgets untuk membaca input pengguna dan menyimpannya dalam variabel tulisan
    fgets(tulisan, sizeof(tulisan), stdin);

    // Menghapus karakter newline dari akhir teks jika ada
    int panjangTeks = strlen(tulisan);
    if (panjangTeks > 0 && tulisan[panjangTeks - 1] == '\n') {
        tulisan[panjangTeks - 1] = '\0';
    }

    printf("Pilih tindakan yang ingin Anda lakukan:\n");
    printf("1. Hitung jumlah karakter dalam teks\n");
    printf("2. Hitung jumlah kata dalam teks\n");
    printf("3. Cari kata tertentu dalam teks\n");
    printf("4. Hitung jumlah kata tertentu dalam teks\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);

    fflush(stdin); // Membersihkan buffer stdin

    if (pilihan == 1) {
        printf("Jumlah karakter dalam tulisan: %d\n", HitungJumlahKarakter(tulisan));
    } else if (pilihan == 2) {
        printf("Jumlah kata dalam tulisan: %d\n", HitungJumlahKata(tulisan));
    } else if (pilihan == 3) {
        char kataCari[1000]; // Maksimum 1000 karakter
        printf("Masukkan kata yang ingin dicari: ");
        scanf(" %[^\n]", kataCari);

        if (CariKata(tulisan, kataCari)) {
            printf("Kata ditemukan dalam tulisan.\n");
        } else {
            printf("Kata tidak ditemukan dalam tulisan.\n");
        }
    } else if (pilihan == 4) {
        char kataHitung[1000]; // Maksimum 1000 karakter
        printf("Masukkan kata yang ingin dihitung: ");
        scanf(" %[^\n]", kataHitung);

        printf("Jumlah kata '%s' dalam tulisan: %d\n", kataHitung, HitungJumlahKataTertentu(tulisan, kataHitung));
    } else {
        printf("Pilihan tidak valid. Silakan pilih yang sesuai.\n");
    }

    return 0;
}
