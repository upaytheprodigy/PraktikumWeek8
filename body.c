#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <limits.h>

Kota kota[MAX_KOTA];

void CreateList(List *L) {
    L->First = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        strcpy(P->nama, X);
        P->q = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

void Insert(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (L->First == Nil) {
            L->First = P;
        } else {
            address Q = L->First;
            while (Q->q != Nil) {
                Q = Q->q;
            }
            Q->q = P;
        }
    }
}

void DeleteNamadanKota (List *L, int *TotKota) {
    address P = L->First;
    while (P != Nil) {
        address Q = P;
        P = P->q;
        Dealokasi(Q);
        (*TotKota)--;
    }
    L->First = Nil;
}

void PrintList(List L) {
    if (L.First == Nil) {
        printf("Daftar kosong.\n"); // Debug log
        return;
    }
    address P = L.First;
    while (P != Nil) {
        printf("%s\n", P->nama);
        P = P->q;
    }
}

void initKota() {
    const char *kota_names[MAX_KOTA] = {
        "Jakarta", "Bandung", "London", "Milan", "Paris",
        "Medan", "Semarang", "Tokyo", "Barcelona", "New York"
    };

    for (int i = 0; i < MAX_KOTA; i++) {
        if (i < 10) { // Sesuaikan jumlah kota
            strcpy(kota[i].kota, kota_names[i]);
            printf("Kota diinisialisasi: %s\n", kota[i].kota); // Debug log
        } else {
            strcpy(kota[i].kota, "");
        }
        CreateList(&kota[i].p);
    }
}

int CariIndexKota(char *nama_kota) {
    for (int i = 0; i < MAX_KOTA; i++) {
        if (strcmp(kota[i].kota, nama_kota) == 0) {
            return i;
        }
    }
    return -1;
}

int JumlahNamaPerKota(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->q;
    }
    return count;
}

int JumlahNamaKeseluruhan(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->q;
    }
    return count;
}