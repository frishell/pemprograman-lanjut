#include <stdio.h>
#include <math.h>
#include <float.h>

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

    while (1) {
        printf("Pilih Operasi Yang Ingin Dilakukan:\n");
        printf("1. Metode Biseksi\n");
        printf("2. Metode Regula Falsi\n");
        printf("3. Metode Newton-Raphson\n");
        printf("4. Metode Secant\n");
        printf("5. Iterasi Sederhana\n");
        printf("6. Keluar\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Kode Metode Biseksi
                float bAtas, bBawah, bC, error, input_error;

                printf("Masukkan Batas Bawah : ");
                scanf("%f", &bBawah);
                printf("Masukkan Batas Atas : ");
                scanf("%f", &bAtas);
                printf("Masukkan Nilai Error  : ");
                scanf("%f", &input_error);

                if (F(bBawah) * F(bAtas) >= 0) {
                    printf("Proses dibatalkan, Anda tidak memasukkan bAtas dan bBawah dengan benar sesuai teori\n");
                    break;
                } else if (F(bBawah) == 0 || F(bAtas) == 0) {
                    printf("Akar merupakan salah satu dari bAtas dan bBawah dengan benar sesuai teori\n");
                    printf("Akar persamaan = %f\n", (F(bAtas) == 0 ? bAtas : bBawah));
                    break;
                }

                printf("Iterasi\ta\tb\tf(a)\tf(b)\tc\tf(c)\terror\n");

                float mC;

                do {
                    mC = bC;
                    bC = (bBawah + bAtas) / 2;
                    printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", i, bBawah, bAtas, F(bBawah), F(bAtas), bC, F(bC), error);

                    if (F(bC) == 0) {
                        printf("Akar persamaan = %f\n", bC);
                    } else if ((F(bBawah) * F(bC)) > 0) {
                        bBawah = bC;
                    } else {
                        bAtas = bC;
                    }

                    error = fabs(bC - mC);

                    i++;
                } while (error > input_error);

                printf("\nAproksimasi Akar = %f\n", bC);
                break;

            case 2:
                // Implementasi Metode Regula Falsi
                float r_a, r_b, r_c, r_error;

                printf("Masukkan Batas Bawah : ");
                scanf("%f", &r_a);
                printf("Masukkan Batas Atas : ");
                scanf("%f", &r_b);
                printf("Masukkan Nilai Error  : ");
                scanf("%f", &r_error);

                if (F(r_a) * F(r_b) >= 0) {
                    printf("Proses Dibatalkan, Anda Tidak Memasukkan r_a dan r_b Dengan Benar Sesuai Teori\n");
                    break;
                } else if (F(r_a) == 0 || F(r_b) == 0) {
                    printf("Akar merupakan salah satu dari r_a dan r_b dengan benar sesuai teori\n");
                    printf("Akar persamaan = %f\n", (F(r_a) == 0 ? r_a : r_b));
                    break;
                }

                printf("Ite\tr_a\t\t\tr_b\t\tf(r_a)\t\tf(r_b)\t\tr_c\t\tf(r_c)\t\terror\n");

                do {
                    r_c = r_a - F(r_a) * (r_b * r_a) / (F(r_b) - F(r_a));
                    printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", i, r_a, r_b, F(r_a), F(r_b), r_c, F(r_c));

                    if (F(r_c) == 0) {
                        printf("Akar persamaan = %f\n", r_c);
                        break;
                    }

                    if (F(r_c) * F(r_a) < 0) {
                        r_b = r_c;
                    } else {
                        r_a = r_c;
                    }

                    error = fabs(r_c - r_a);

                    i++;
                } while (error > r_error);

                printf("\nAproksimasi Akar (Regula Falsi) = %f\n", r_c);
                break;
            case 3:
                eth = DBL_EPSILON;

                printf("Metode Newton Raphson\n\n");
                float x[100];
                printf("Masukkan Nilai Awal: ");
                scanf("%f", &x[0]);
                printf("Masukkan Batas Toleransi: ");
                scanf("%lf", &eth);

                printf("\nIterasi\t  x(i)\t\t x(i+1)\t\t f(x(i+1))\t f'(x(i+1))\n");

                do {
                    i++;
                    float f_x = F(x[i]);
                    float f_prime_x = Ft(x[i]);

                    if (fabs(f_prime_x) < eth) {
                        printf("Metode Newton-Raphson Tidak Konvergen. Memilih Nilai Awal Yang Berbeda.\n");
                        break;
                    }

                    x[i + 1] = x[i] - (f_x / f_prime_x);
                    printf("%d\t %f\t %f\t %f\t %f\t %f\n", i, x[i], x[i + 1], F(x[i + 1]), Ft(x[i + 1]));
                } while (fabs(F(x[i + 1])) > eth);

                printf("\nAkar = %f\n", x[i + 1]);
                break;

            case 4:
                // Kode untuk metode Secant
                printf("Masukkan nilai x0 : ");
                scanf("%f", &x[0]);
                printf("Masukkan nilai x1 : ");
                scanf("%f", &x[1]);
                printf("Masukkan nilai toleransi : ");
                scanf("%lf", &eth);

                printf("\nIterasi Secant\t x(i-1)\t x(i)\t\t x(i+1)\t f(i+1)\n");
                do {
                    i++;
                    x[i + 2] = x[i] - (F(x[i]) * (x[i - 1] - x[i])) / (F(x[i - 1]) - F(x[i]));
                    printf("%d\t %f\t %f\t %f\t %f\n", i, x[i], x[i + 1], x[i + 2], F(x[i + 2]));
                } while (fabs(F(x[i + 2])) > eth);

                printf("\nAkar (Secant) = %f\n", x[i + 2]);
                break;

            case 5:
                printf("Metode Iterasi Sederhana\n\n");
                double a, e;
                int i_maks, iterasi;

                printf("Masukkan Tebakan Awal : ");
                scanf("%lf", &a);
                printf("Masukkan Toleransi Eror : ");
                scanf("%lf", &e);
                printf("Masukkan Iterasi Maksimum : ");
                scanf("%d", &i_maks);
                printf("i\t\tx\t\t\tg(x)\t\t\tf(x)\n");
                iterasi = 0;

                do {
                    double b = g(a);
                    double c = F(a);
                    printf("%d\t\t%f\t\t%f\t\t%f\n", iterasi, a, b, c);
                    a = b;
                    iterasi++;
                } while ((fabs(F(a)) > e) && (iterasi < i_maks));

                if (iterasi < i_maks) {
                    printf("\nJadi Ditemukan Penyelesaian X Iterasi Sederhana Adalah %f\n", a);
                } else {
                    printf("\nMaaf Iterasi Maksimum Tercapai, Sehingga Tidak Bisa Memenuhi Toleransi\n");
                }
                break;

            case 6:
                printf("Terima Kasih! Keluar Dari Program.\n");
                return 0;

            default:
                printf("Pilihan Metode Tidak Valid.\n");
                break;
        }
    }

    return 0;
}
