#include <stdio.h>
#include <string.h>

// Fungsi untuk meminta input dari pengguna dan mengembalikan string
char *inputString(const char *prompt) {
    static char buffer[256];
    printf("%s: ", prompt);
    scanf(" %[^\n]", buffer);
    return buffer;
}

int main() {
    char judul[256], namaPenulis[256], afiliasi[256], email[256], abstrak[256], kataKunci[256];
    char jurnal[1024]; // String untuk menggabungkan semua data jurnal

    printf("Selamat datang di program WriteJournal\n");

    // Meminta input dari pengguna untuk setiap bagian jurnal
    strcpy(judul, inputString("Masukkan Judul"));
    strcpy(namaPenulis, inputString("Masukkan Nama Penulis"));
    strcpy(afiliasi, inputString("Masukkan Afiliasi"));
    strcpy(email, inputString("Masukkan Email"));
    strcpy(abstrak, inputString("Masukkan Abstrak"));
    strcpy(kataKunci, inputString("Masukkan Kata Kunci"));

    // Menggabungkan semua data jurnal menjadi satu string
    snprintf(jurnal, sizeof(jurnal), "Judul: %s\nNama Penulis: %s\nAfiliasi: %s\nEmail: %s\nAbstrak: %s\nKata Kunci: %s", judul, namaPenulis, afiliasi, email, abstrak, kataKunci);

    // Menampilkan jurnal yang sudah digabungkan
    printf("\nJurnal yang dihasilkan:\n%s\n", jurnal);

    return 0;
}
