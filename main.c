#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "header.h"

int main() {
    initKota(); // Inisialisasi daftar kota
    int pilihan;
    char nama[50], nama_kota[50];
    int index_kota;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Nama ke Kota\n");
        printf("2. Hapus Semua Nama di Kota\n");
        printf("3. Tampilkan Data Nama per Kota\n");
        printf("4. Tampilkan Jumlah Nama Per Kota\n");
        printf("5. Tampilkan Jumlah Seluruh Nama\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                scanf("%s", nama_kota);
                index_kota = CariIndexKota(nama_kota);
                if (index_kota != -1) {
                    printf("Masukkan nama: ");
                    scanf("%s", nama);
                    Insert(&kota[index_kota].p, nama);
                    printf("Nama '%s' berhasil ditambahkan ke kota '%s'.\n", nama, nama_kota);
                } else {
                    printf("Kota '%s' tidak ditemukan.\n", nama_kota);
                }
                break;

            case 2:
                printf("Masukkan nama kota: ");
                scanf("%s", nama_kota);
                index_kota = CariIndexKota(nama_kota);
                if (index_kota != -1) {
                    int total_kota = JumlahNamaPerKota(kota[index_kota].p);
                    DeleteNamadanKota(&kota[index_kota].p, &total_kota);
                    printf("Semua nama di kota '%s' telah dihapus.\n", nama_kota);
                } else {
                    printf("Kota '%s' tidak ditemukan.\n", nama_kota);
                }
                break;

            case 3:
                printf("\nData Nama per Kota:\n");
                for (int i = 0; i < MAX_KOTA; i++) {
                    if (strcmp(kota[i].kota, "") != 0) {
                        printf("Kota: %s\n", kota[i].kota);
                        PrintList(kota[i].p);
                    }
                }
                break;

            case 4:
                printf("\nJumlah Nama per Kota:\n");
                for (int i = 0; i < MAX_KOTA; i++) {
                    if (strcmp(kota[i].kota, "") != 0) {
                        printf("Kota: %s, Total Nama: %d\n", kota[i].kota, JumlahNamaPerKota(kota[i].p));
                    }
                }
                break;

            case 5: {
                int total_nama = 0;
                for (int i = 0; i < MAX_KOTA; i++) {
                    total_nama += JumlahNamaPerKota(kota[i].p);
                }
                printf("Total seluruh nama: %d\n", total_nama);
                break;
            }

            case 6:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}