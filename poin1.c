#include <stdio.h>
#include <string.h>

int main() {
    char input[100];//untuk deklarasi array untuk menyimpan input dari pengguna,dengan batasan maksimum 100 karakter
    printf("Masukkan teks: "); //menampilkan pesan untuk penguna 

    
    fgets(input, sizeof(input), stdin);//untuk membaca input pengguna dan menyimpn dalam variabel input

    
    int jumlahKarakter  = strlen(input);//menghuting jumlah karakter dalam string input 

    
    printf("Jumlah karakter yang diinputkan adalah: %d\n", jumlahKarakter - 1);//untuk menampilkan hasil kepada pengguna 

    return 0;
}
