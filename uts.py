import math

def F(x):
    """
    Fungsi ini menghitung nilai fungsi F(x) sesuai dengan persamaan yang diberikan.
    """
    return (x * x * x) - (x * x * 2) - (3 * x) - 8

def Ft(x):
    """
    Fungsi ini menghitung turunan dari fungsi F(x) terhadap x (f'(x)).
    """
    return (3 * x * x) - (x * 4) - 3

def g(x):
    """
    Fungsi ini menghitung g(x) sesuai dengan persamaan yang diberikan. / bisa disebut pecahannya dari f(x)
    """
    return math.pow((x * x * 2) + (3 * x) + 8, 1.0 / 3.0)

while True:
    print("Pilih Operasi Yang Ingin Dilakukan:")
    print("1. Metode Biseksi")
    print("2. Metode Regula Falsi")
    print("3. Metode Newton-Raphson")
    print("4. Metode Secant")
    print("5. Iterasi Sederhana")
    print("6. Keluar")
    
    choice = int(input())
    
    if choice == 1:
        # Kode Metode Biseksi
        bAtas, bBawah, bC, error, input_error = 0, 0, 0, 0, 0

        bBawah = float(input("Masukkan Batas Bawah : "))
        bAtas = float(input("Masukkan Batas Atas : "))
        input_error = float(input("Masukkan Nilai Error  : "))

        if F(bBawah) * F(bAtas) >= 0:
            print("Proses dibatalkan, Anda tidak memasukkan bAtas dan bBawah dengan benar sesuai teori")
            break
        elif F(bBawah) == 0 or F(bAtas) == 0:
            print("Akar merupakan salah satu dari bAtas dan bBawah dengan benar sesuai teori")
            print("Akar persamaan =", bAtas if F(bAtas) == 0 else bBawah)
            break

        print("Iterasi\ta\tb\tf(a)\tf(b)\tc\tf(c)\terror\n")

        mC = 0

        i = 0
        error = r_b - r_a  # Initialize error to a large value

        while error > r_error:
            r_c = r_a - F(r_a) * (r_b - r_a) / (F(r_b) - F(r_a))
            i += 1
            print(f"{i}\t{r_a}\t\t{r_b}\t\t{F(r_a)}\t\t{F(r_b)}\t\t{r_c}\t\t{F(r_c)}")

            if F(r_c) == 0:
                print("Akar persamaan =", r_c)
                break

            if F(r_c) * F(r_a) < 0:
                r_b = r_c
            else:
                r_a = r_c

            error = abs(r_b - r_a)  # Update error


        print("\nAproksimasi Akar =", bC)

    elif choice == 2:
        # Implementasi Metode Regula Falsi
        r_a, r_b, r_c, r_error = 0, 0, 0, 0

        r_a = float(input("Masukkan Batas Bawah : "))
        r_b = float(input("Masukkan Batas Atas : "))
        r_error = float(input("Masukkan Nilai Error  : "))

        if F(r_a) * F(r_b) >= 0:
            print("Proses Dibatalkan, Anda Tidak Memasukkan r_a dan r_b Dengan Benar Sesuai Teori")
            break
        elif F(r_a) == 0 or F(r_b) == 0:
            print("Akar merupakan salah satu dari r_a dan r_b dengan benar sesuai teori")
            print("Akar persamaan =", r_a if F(r_a) == 0 else r_b)
            break

        print("Ite\tr_a\t\t\tr_b\t\tf(r_a)\t\tf(r_b)\t\tr_c\t\tf(r_c)\t\terror")
        
        i = 0
        error = r_b - r_a  # Initialize error to a large value

        while error > r_error:
            r_c = r_a - F(r_a) * (r_b - r_a) / (F(r_b) - F(r_a))
            i += 1
            print(f"{i}\t{r_a}\t\t{r_b}\t\t{F(r_a)}\t\t{F(r_b)}\t\t{r_c}\t\t{F(r_c)}")

            if F(r_c) == 0:
                print("Akar persamaan =", r_c)
                break

            if F(r_c) * F(r_a) < 0:
                r_b = r_c
            else:
                r_a = r_c

            error = abs(r_b - r_a)  # Update error
            
    elif choice == 3:
        eth = 1e-6

        print("Metode Newton Raphson\n")
        x = [0] * 100
        x[0] = float(input("Masukkan Nilai Awal: "))
        eth = float(input("Masukkan Batas Toleransi: "))

        print("\nIterasi\t  x(i)\t\t x(i+1)\t\t f(x(i+1))\t f'(x(i+1))\n")

        i = 0

        while abs(F(x[i + 1])) > eth:
            i += 1
            f_x = F(x[i])
            f_prime_x = Ft(x[i])

            if abs(f_prime_x) < eth:
                print("Metode Newton-Raphson Tidak Konvergen. Memilih Nilai Awal Yang Berbeda.")
                break

            x[i + 1] = x[i] - (f_x / f_prime_x)
            print(f"{i}\t {x[i]}\t {x[i + 1]}\t {F(x[i + 1])}\t {Ft(x[i + 1])}")

        print("\nAkar =", x[i + 1])

    elif choice == 4:
        # Kode untuk metode Secant
        x = [0] * 100
        x[0] = float(input("Masukkan nilai x0 : "))
        x[1] = float(input("Masukkan nilai x1 : "))
        eth = 1e-6

        print("\nIterasi Secant\t x(i-1)\t x(i)\t\t x(i+1)\t f(i+1)\n")

        i = 0

        while abs(F(x[i + 2])) > eth:
            i += 1
            x[i + 2] = x[i] - (F(x[i]) * (x[i - 1] - x[i])) / (F(x[i - 1]) - F(x[i]))
            print(f"{i}\t {x[i]}\t {x[i + 1]}\t {x[i + 2]}\t {F(x[i + 2])}")

        print("\nAkar (Secant) =", x[i + 2])

    elif choice == 5:
        print("Metode Iterasi Sederhana\n")
        a, e, i_maks, iterasi = 0, 0, 0, 0

        a = float(input("Masukkan Tebakan Awal : "))
        e = float(input("Masukkan Toleransi Eror : "))
        i_maks = int(input("Masukkan Iterasi Maksimum : "))
        print("i\t\tx\t\t\tg(x)\t\t\tf(x)")

        while abs(F(a)) > e and iterasi < i_maks:
            b = g(a)
            c = F(a)
            print(f"{iterasi}\t\t{a}\t\t{b}\t\t{c}")
            a = b
            iterasi += 1

        if iterasi < i_maks:
            print(f"\nJadi Ditemukan Penyelesaian X Iterasi Sederhana Adalah {a}")
        else:
            print("Maaf Iterasi Maksimum Tercapai, Sehingga Tidak Bisa Memenuhi Toleransi")

    elif choice == 6:
        print("Terima Kasih! Keluar Dari Program.")
        break

    else:
        print("Pilihan Metode Tidak Valid.")
