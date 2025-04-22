#ifndef header_H
#define header_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define MAX_KOTA 10
#define MAX_NAMA 30

typedef char infotype[MAX_NAMA];
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype nama;
    address q;
} ElmtList;

typedef struct {
    address First;
} List;

typedef struct {
    infotype kota;
    List p;
} Kota;

extern Kota kota[MAX_KOTA];

void CreateList(List *L);
address Alokasi(infotype X);
void Dealokasi(address P);
void Insert(List *L, infotype X);
void DeleteNamadanKota (List *L, int *TotKota);
void PrintList(List L);
void initKota();
int CariIndexKota(char *nama_kota);
int JumlahNamaPerKota(List L);
int JumlahNamaKeseluruhan(List L);

#endif