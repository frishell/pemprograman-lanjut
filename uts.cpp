#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

float F(float x) {
    return (x * x * x) - (x * x * 2) - (3 * x) - 8;
}

float Ft(float x) {
    return (3 * x * x) - (x * 4) - 3;
}

double g(double x) {
    return pow((x * x * 2) + (3 * x) + 8, 1.0 / 3.0);
}

int main() {
    double eth;
    int i = 1;
    int choice;

    while (true) {
        cout << "Pilih Operasi Yang Ingin Dilakukan:" << endl;
        cout << "1. Metode Biseksi" << endl;
        cout << "2. Metode Regula Falsi" << endl;
        cout << "3. Metode Newton-Raphson" << endl;
        cout << "4. Metode Secant" << endl;
        cout << "5. Iterasi Sederhana" << endl;
        cout << "6. Keluar" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                // Kode Metode Biseksi
                float bAtas, bBawah, bC, error, input_error;

                cout << "Masukkan Batas Bawah : ";
                cin >> bBawah;
                cout << "Masukkan Batas Atas : ";
                cin >> bAtas;
                cout << "Masukkan Nilai Error  : ";
                cin >> input_error;

                if (F(bBawah) * F(bAtas) >= 0) {
                    cout << "Proses dibatalkan, Anda tidak memasukkan bAtas dan bBawah dengan benar sesuai teori" << endl;
                    break;
                } else if (F(bBawah) == 0 || F(bAtas) == 0) {
                    cout << "Akar merupakan salah satu dari bAtas dan bBawah dengan benar sesuai teori" << endl;
                    cout << "Akar persamaan = " << (F(bAtas) == 0 ? bAtas : bBawah) << endl;
                    break;
                }

                cout << "Iterasi\ta\tb\tf(a)\tf(b)\tc\tf(c)\terror\n";

                float mC;

                do {
                    mC = bC;
                    bC = (bBawah + bAtas) / 2;
                    cout << ++i << "\t" << bBawah << "\t" << bAtas << "\t" << F(bBawah) << "\t" << F(bAtas) << "\t" << bC << "\t" << F(bC) << "\t" << error << endl;

                    if (F(bC) == 0) {
                        cout << "Akar persamaan = " << bC << endl;
                    } else if ((F(bBawah) * F(bC)) > 0) {
                        bBawah = bC;
                    } else {
                        bAtas = bC;
                    }

                    error = fabs(bC - mC);

                } while (error > input_error);

                cout << "\nAproksimasi Akar = " << bC << endl;
                break;

            case 2:
                // Implementasi Metode Regula Falsi
                float r_a, r_b, r_c, r_error;

                cout << "Masukkan Batas Bawah : ";
                cin >> r_a;
                cout << "Masukkan Batas Atas : ";
                cin >> r_b;
                cout << "Masukkan Nilai Error  : ";
                cin >> r_error;

                if (F(r_a) * F(r_b) >= 0) {
                    cout << "Proses Dibatalkan, Anda Tidak Memasukkan r_a dan r_b Dengan Benar Sesuai Teori" << endl;
                    break;
                } else if (F(r_a) == 0 || F(r_b) == 0) {
                    cout << "Akar merupakan salah satu dari r_a dan r_b dengan benar sesuai teori" << endl;
                    cout << "Akar persamaan = " << (F(r_a) == 0 ? r_a : r_b) << endl;
                    break;
                }

                cout << "Ite\tr_a\t\t\tr_b\t\tf(r_a)\t\tf(r_b)\t\tr_c\t\tf(r_c)\t\terror" << endl;

                do {
                    r_c = r_a - F(r_a) * (r_b * r_a) / (F(r_b) - F(r_a));
                    cout << ++i << "\t" << r_a << "\t\t" << r_b << "\t\t" << F(r_a) << "\t\t" << F(r_b) << "\t\t" << r_c << "\t\t" << F(r_c) << endl;

                    if (F(r_c) == 0) {
                        cout << "Akar persamaan = " << r_c << endl;
                        break;
                    }

                    if (F(r_c) * F(r_a) < 0) {
                        r_b = r_c;
                    } else {
                        r_a = r_c;
                    }

                    error = fabs(r_c - r_a);

                } while (error > r_error);

                cout << "\nAproksimasi Akar (Regula Falsi) = " << r_c << endl;
                break;
            case 3:
                eth = numeric_limits<float>::epsilon();

                cout << "Metode Newton Raphson" << endl << endl;
                float x[100];
                cout << "Masukkan Nilai Awal: ";
                cin >> x[0];
                cout << "Masukkan Batas Toleransi: ";
                cin >> eth;

                cout << "\nIterasi\t  x(i)\t\t x(i+1)\t\t f(x(i+1))\t f'(x(i+1))\n";

                do {
                    i++;
                    float f_x = F(x[i]);
                    float f_prime_x = Ft(x[i]);

                    if (fabs(f_prime_x) < eth) {
                        cout << "Metode Newton-Raphson Tidak Konvergen. Memilih Nilai Awal Yang Berbeda." << endl;
                        break;
                    }

                    x[i + 1] = x[i] - (f_x / f_prime_x);
                    cout << i << "\t " << x[i] << "\t " << x[i + 1] << "\t " << F(x[i + 1]) << "\t " << Ft(x[i + 1]) << endl;
                } while (fabs(F(x[i + 1])) > eth);

                cout << "\nAkar = " << x[i + 1] << endl;
                break;

            case 4:
                // Kode untuk metode Secant
                cout << "Masukkan nilai x0 : ";
                cin >> x[0];
                cout << "Masukkan nilai x1 : ";
                cin >> x[1];
                cout << "Masukkan nilai toleransi : ";
                cin >> eth;

                cout << "\nIterasi Secant\t x(i-1)\t x(i)\t\t x(i+1)\t f(i+1)\n";
                do {
                    i++;
                    x[i + 2] = x[i] - (F(x[i]) * (x[i - 1] - x[i])) / (F(x[i - 1]) - F(x[i]));
                    cout << i << "\t " << x[i] << "\t " << x[i + 1] << "\t " << x[i + 2] << "\t " << F(x[i + 2]) << endl;
                } while (fabs(F(x[i + 2])) > eth);

                cout << "\nAkar (Secant) = " << x[i + 2] << endl;
                break;

            case 5:
                cout << "Metode Iterasi Sederhana" << endl << endl;
                double a, e;
                int i_maks, iterasi;

                cout << "Masukkan Tebakan Awal : ";
                cin >> a;
                cout << "Masukkan Toleransi Eror : ";
                cin >> e;
                cout << "Masukkan Iterasi Maksimum : ";
                cin >> i_maks;
                cout << "i\t\tx\t\t\tg(x)\t\t\tf(x)" << endl;
                iterasi = 0;

                do {
                    double b = g(a);
                    double c = F(a);
                    cout << iterasi << "\t\t" << a << "\t\t" << b << "\t\t" << c << endl;
                    a = b;
                    iterasi++;
                } while ((fabs(F(a)) > e) && (iterasi < i_maks));

                if (iterasi < i_maks) {
                    cout << "\nJadi Ditemukan Penyelesaian X Iterasi Sederhana Adalah " << a << endl;
                } else {
                    cout << "\nMaaf Iterasi Maksimum Tercapai, Sehingga Tidak Bisa Memenuhi Toleransi" << endl;
                }
                break;

            case 6:
                cout << "Terima Kasih! Keluar Dari Program." << endl;
                return 0;

            default:
                cout << "Pilihan Metode Tidak Valid." << endl;
                break;
        }
    }

     return 0;
}
