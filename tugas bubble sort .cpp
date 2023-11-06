#include <iostream>
#include <vector>
#include <algorithm>

class Mahasiswa {
public:
    std::string npm;
    std::string nama;
    std::string prodi;
    double ipk;

    Mahasiswa(const std::string& npm, const std::string& nama, const std::string& prodi, double ipk)
        : npm(npm), nama(nama), prodi(prodi), ipk(ipk) {}
};

std::vector<Mahasiswa> mahasiswa_list;

void tambah_mahasiswa() {
    std::string npm, nama, prodi;
    double ipk;

    std::cout << "Masukkan NPM: ";
    std::cin >> npm;
    std::cout << "Masukkan Nama: ";
    std::cin >> nama;
    std::cout << "Masukkan Prodi: ";
    std::cin >> prodi;
    std::cout << "Masukkan IPK: ";
    std::cin >> ipk;

    Mahasiswa mahasiswa(npm, nama, prodi, ipk);
    mahasiswa_list.push_back(mahasiswa);
    std::cout << "Data mahasiswa berhasil ditambahkan." << std::endl;
}

void tampilkan_mahasiswa() {
    if (mahasiswa_list.empty()) {
        std::cout << "Belum ada data mahasiswa." << std::endl;
        return;
    }

    std::cout << "Daftar Mahasiswa:" << std::endl;
    for (const Mahasiswa& mahasiswa : mahasiswa_list) {
        std::cout << "NPM: " << mahasiswa.npm << ", Nama: " << mahasiswa.nama << ", Prodi: " << mahasiswa.prodi << ", IPK: " << mahasiswa.ipk << std::endl;
    }
}

void bubble_sort() {
    int n = mahasiswa_list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mahasiswa_list[j].npm > mahasiswa_list[j + 1].npm) {
                std::swap(mahasiswa_list[j], mahasiswa_list[j + 1]);
            }
        }
    }
    std::cout << "Data mahasiswa berhasil diurutkan berdasarkan NPM." << std::endl;
}

int main() {
    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Tambah Mahasiswa" << std::endl;
        std::cout << "2. Tampilkan Mahasiswa" << std::endl;
        std::cout << "3. Urutkan Mahasiswa " << std::endl;
        std::cout << "4. Keluar" << std::endl;

        int pilihan;
        std::cout << "Pilih menu (1/2/3/4): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambah_mahasiswa();
                break;
            case 2:
                tampilkan_mahasiswa();
                break;
            case 3:
                bubble_sort();
                break;
            case 4:
                std::cout << "Terima kasih! Keluar dari program." << std::endl;
                return 0;
            default:
                std::cout << "Menu tidak valid. Silakan pilih menu yang benar." << std::endl;
        }
    }

    return 0;
}
