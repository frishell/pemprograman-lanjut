#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int HitungJumlahKarakter(const string& teks) {
    return teks.length();
}

int HitungJumlahKata(const string& teks) {
    istringstream stream(teks);
    int jumlahKata = 0;
    string kata;
    
    while (stream >> kata) {
        jumlahKata++;
    }
    
    return jumlahKata;
}

bool CariKata(const string& teks, const string& kataDicari) {
    return teks.find(kataDicari) != string::npos;
}

int HitungJumlahKataTertentu(const string& teks, const string& kataTertentu) {
    int jumlah = 0;
    string teksSalin = teks;
    
    transform(teksSalin.begin(), teksSalin.end(), teksSalin.begin(), ::tolower);
    
    size_t pos = teksSalin.find(kataTertentu);
    while (pos != string::npos) {
        jumlah++;
        pos = teksSalin.find(kataTertentu, pos + 1);
    }
    
    return jumlah;
}

int main() {
    string tulisan;
    cout << "Masukkan teks: ";
    getline(cin, tulisan);

    int pilihan;
    cout << "Pilih tindakan yang ingin Anda lakukan:" << endl;
    cout << "1. Hitung jumlah karakter dalam teks" << endl;
    cout << "2. Hitung jumlah kata dalam teks" << endl;
    cout << "3. Cari kata tertentu dalam teks" << endl;
    cout << "4. Hitung jumlah kata tertentu dalam teks" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;
     

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer hingga karakter newline

    switch (pilihan) {
        case 1:
            cout << "Jumlah karakter dalam tulisan: " << HitungJumlahKarakter(tulisan) << endl;
            break;
        case 2:
            cout << "Jumlah kata dalam tulisan: " << HitungJumlahKata(tulisan) << endl;
            break;
        case 3: {
            string kataCari;
            cout << "Masukkan kata yang ingin dicari: ";
            getline(cin, kataCari);

            if (CariKata(tulisan, kataCari)) {
                cout << "Kata ditemukan dalam tulisan." << endl;
            } else {
                cout << "Kata tidak ditemukan dalam tulisan." << endl;
            }
            break;
        }
        case 4: {
            string kataHitung;
            cout << "Masukkan kata yang ingin dihitung: ";
            getline(cin, kataHitung);

            cout << "Jumlah kata '" << kataHitung << "' dalam tulisan: " << HitungJumlahKataTertentu(tulisan, kataHitung) << endl;
            break;
        }
        cout << "Pilihan tidak valid. Silakan pilih yang sesuai." << endl;
            
    }

    return 0;
}
