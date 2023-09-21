#include <iostream>
#include <vector>

// Struct untuk menyimpan data mahasiswa 
struct Mahasiswa
{
    std::string Nama;
    std::string NPM;
    double IPK;
};

// Fungsi untuk menampilkan data mahasiswa 
void tampilkanData(const std::vector<Mahasiswa>& mahasiswalist){
    std::cout << "Daftar Mahasiswa" << std::endl;
    for (size_t i = 0; i < mahasiswalist.size(); ++i)
    {
        const Mahasiswa& mhs = mahasiswalist[i];
        std::cout << "Nama: " << mhs.Nama <<  std::endl;
        std::cout << "NPM: " << mhs.NPM <<  std::endl;
        std::cout << "IPK: " << mhs.IPK <<  std::endl;
        std::cout << "--------------------" <<  std::endl;
    }
}

int main(){
    std::vector<Mahasiswa> mahasiswalist;
    while (true)
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Tambah Mahasiswa" << std::endl;
        std::cout << "2. Tampilkan Mahasiswa" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        
        int pilihan ;
        std::cin >> pilihan;
        
        if (pilihan == 1)
        {
            Mahasiswa mhs;
            std::cout << "Nama Mahasiswa: ";
            std::cin.ignore(); // Membersihkan newline dari buffer
            std::getline(std::cin, mhs.Nama);

            // Validasi NPM
            bool npmValid = false;
            while (!npmValid) {
                std::cout << "NPM Mahasiswa: ";
                std::cin >> mhs.NPM;

                // Periksa apakah NPM sudah ada dalam vektor
                npmValid = true;
                for (size_t i = 0; i < mahasiswalist.size(); ++i) {
                    if (mahasiswalist[i].NPM == mhs.NPM) {
                        std::cout << "NPM sudah ada. Mohon masukkan NPM yang berbeda." << std::endl;
                        npmValid = false;
                        break;
                    }
                }
            }

            // Validasi IPK
            bool ipkValid = false;
            while (!ipkValid) {
                std::cout << "IPK Mahasiswa: ";
                std::cin >> mhs.IPK;

                if (mhs.IPK >= 0 && mhs.IPK <= 4.0) {
                    ipkValid = true;
                } else {
                    std::cout << "IPK tidak valid. Mohon masukkan IPK dalam rentang 0 hingga 4.0." << std::endl;
                }
            }

            mahasiswalist.push_back(mhs);
            std::cout << "Mahasiswa berhasil ditambahkan." << std::endl;
        } else if (pilihan == 2){
            tampilkanData(mahasiswalist);
        } else if (pilihan == 3){
            break;
        } else {
            std::cout <<"Pilihan tidak valid. Silahkan coba lagi." << std::endl;
        }
    }
    return 0;
}

