#include <iostream>
#include <cstring>
#include <cmath>

// Fungsi perpangkatan dengan return value
int pangkat(int base, int exponent) {
    return pow(base, exponent);
}

// Fungsi void buat menggabungkan nama depan dan belakang dengan menggunakan return value
void gabungNama(const char* namaDepan, const char* namaBelakang, char* namaLengkap) {
    sprintf(namaLengkap, "%s %s", namaDepan, namaBelakang);
}

// Fungsi void untuk pengecekan validitas password dengan return value
void cekPassword(const char* password, bool& valid) {
    valid = (strlen(password) >= 8);
}

int main() {
    int choice;
    int hasilPangkat; // Pindah deklarasi di sini
    do {
        std::cout << "Pilih Operasi Yang Ingin Dilakukan:" << std::endl;
        std::cout << "1. Perpangkatan" << std::endl;
        std::cout << "2. Penggabungan Nama" << std::endl;
        std::cout << "3. Cek Validitas Password" << std::endl;
        std::cout << "4. Keluar" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int base, exponent;
                std::cout << "Masukkan angka : ";
                std::cin >> base;
                std::cout << "Masukkan Nilai pangkat : ";
                std::cin >> exponent;
                hasilPangkat = pangkat(base, exponent); 
                std::cout << base << " Pangkat " << exponent << " Adalah " << hasilPangkat << std::endl;
                break;

            case 2:
			    char namaDepan[100], namaBelakang[100], namaLengkap[200];
			    std::cout << "Masukkan Nama Depan anda: ";
			    std::cin >> namaDepan;
			    std::cout << "Masukkan Nama Belakang anda: ";
			    std::cin.ignore(); // Mengabaikan karakter newline sebelum memasukkan nama belakang
			    std::cin.getline(namaBelakang, sizeof(namaBelakang));
			    gabungNama(namaDepan, namaBelakang, namaLengkap);
			    std::cout << "Nama Lengkap: " << namaLengkap << std::endl;
			    break;


            case 3:
                char password[100];
                bool passwordValid;
                std::cout << "Masukkan Password: ";
                std::cin >> password;
                cekPassword(password, passwordValid);
                std::cout << "Password yang anda tulis  Valid: " << (passwordValid ? "Ya" : "Tidak") << std::endl;
                break;

            case 4:
                std::cout << "Terima Kasih!! karena telah menggunakan programkuu" << std::endl;
                break;

            default:
                std::cout << "Pilihan Tidak valid. Silakan anda mencoba lagi." << std::endl;
                break;
        }
    } while (choice != 4);
    return 0;
}

