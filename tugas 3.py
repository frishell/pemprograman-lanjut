def hitung_jumlah_karakter(teks):
    return len(teks)

def hitung_jumlah_kata(teks):
    kata_kunci = teks.split()
    return len(kata_kunci)

def cari_kata(teks, kata_tertentu):
    return kata_tertentu in teks

def hitung_jumlah_kata_tertentu(teks, kata_tertentu):
    return teks.lower().count(kata_tertentu.lower())

# Meminta pengguna untuk memasukkan teks
teks = input("Masukkan teks: ")

# Menampilkan menu pilihan fitur
print("Pilih fitur:")
print("1. Hitung jumlah karakter")
print("2. Hitung jumlah kata")
print("3. Cari kata tertentu")
print("4. Hitung jumlah kata tertentu")

# Meminta pengguna memilih fitur
pilihan = input("Masukkan nomor fitur yang Anda inginkan (1/2/3/4): ")

if pilihan == "1":
    # Hitung jumlah karakter
    jumlah_karakter = hitung_jumlah_karakter(teks)
    print("Jumlah karakter dalam teks:", jumlah_karakter)
elif pilihan == "2":
    # Hitung jumlah kata
    jumlah_kata = hitung_jumlah_kata(teks)
    print("Jumlah kata dalam teks:", jumlah_kata)
elif pilihan == "3":
    # Cari kata tertentu
    kata_tertentu = input("Masukkan kata yang ingin Anda cari: ")
    if cari_kata(teks, kata_tertentu):
        print(f"Kata '{kata_tertentu}' ditemukan dalam teks.")
    else:
        print(f"Kata '{kata_tertentu}' tidak ditemukan dalam teks.")
elif pilihan == "4":
    # Hitung jumlah kata tertentu
    kata_tertentu = input("Masukkan kata yang ingin Anda hitung: ")
    jumlah_kata_tertentu = hitung_jumlah_kata_tertentu(teks, kata_tertentu)
    print(f"Jumlah kata '{kata_tertentu}' dalam teks:", jumlah_kata_tertentu)
else:
    print("Pilihan tidak valid. Silakan pilih fitur yang sesuai (1/2/3/4).")
