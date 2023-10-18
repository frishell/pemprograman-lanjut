#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk memvalidasi email menggunakan regular expression
bool isValidEmail(const char *email) {
    int atCount = 0;
    int dotCount = 0;
    int atIndex = -1;
    int dotIndex = -1;

    // Validasi format email
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atIndex = i;
        } else if (email[i] == '.') {
            dotCount++;
            dotIndex = i;
        }
    }

    // Pastikan hanya ada satu '@' dan satu '.'
    if (atCount != 1 || dotCount < 1) {
        return false;
    }

    // Pastikan bahwa '@' muncul sebelum '.'.
    if (atIndex >= dotIndex) {
        return false;
    }

    // Validasi domain yang diharapkan
    const char *expectedDomain = "upnjatim.ac.id";
    const char *actualDomain = email + atIndex + 1;

    if (strcmp(actualDomain, expectedDomain) != 0) {
        return false;
    }

    return true;
}



// Fungsi untuk memeriksa jumlah kata dalam sebuah teks
int countWords(const char *text) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && text[i] != '\n' && text[i] != '\t') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

// Fungsi untuk menggabungkan semua bagian jurnal menjadi satu string
void createJournal(char *journal, const char *judul, const char *penulis, const char *email, const char *abstrak, const char *kataKunci) {
    strcpy(journal, "Judul: ");
    strcat(journal, judul);
    strcat(journal, "\nNama Penulis: ");
    strcat(journal, penulis);
    strcat(journal, "\nEmail: ");
    strcat(journal, email);
    strcat(journal, "\nAbstrak: ");
    strcat(journal, abstrak);
    strcat(journal, "\nKata Kunci: ");
    strcat(journal, kataKunci);
}

int main() {
    char judul[1000];
    char penulis[300];
    char email[100];
    char abstrak[1000];
    char kataKunci[200];

    printf("Masukkan data jurnal:\n");

    // Memasukkan Judul
    do {
        printf("1. Judul (5-14 kata): ");
        fgets(judul, sizeof(judul), stdin);
    } while (countWords(judul) < 5 || countWords(judul) > 14);

    // Memasukkan Nama Penulis
    printf("2. Nama Penulis (Maksimal 3 penulis, dipisahkan dengan koma): ");
    fgets(penulis, sizeof(penulis), stdin);

    // Memasukkan Email
   do {
        printf("3. Email (Format: user@student.upnjatim.ac.id): ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0; // Menghilangkan karakter newline dari inputan
    } while (!isValidEmail(email)); 
    // Memasukkan Abstrak
    do {
        printf("4. Abstrak (Maksimal 200 kata): ");
        fgets(abstrak, sizeof(abstrak), stdin);
    } while (countWords(abstrak) > 200);

    // Memasukkan Kata Kunci
    do {
        printf("5. Kata Kunci (3-5 kata, dipisahkan dengan koma): ");
        fgets(kataKunci, sizeof(kataKunci), stdin);
    } while (countWords(kataKunci) < 3 || countWords(kataKunci) > 5);

    // Menghilangkan karakter newline dari inputan
    judul[strcspn(judul, "\n")] = 0;
    penulis[strcspn(penulis, "\n")] = 0;
    abstrak[strcspn(abstrak, "\n")] = 0;
    kataKunci[strcspn(kataKunci, "\n")] = 0;

    char journal[4000]; // Ukuran string jurnal

    createJournal(journal, judul, penulis, email, abstrak, kataKunci);

    printf("\nJurnal yang telah dibuat:\n%s\n", journal);

    return 0;
}
