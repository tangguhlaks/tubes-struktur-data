#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;
#define cin(x) getline(cin,x)

typedef struct element_dokter *adr_dokter;
typedef struct element_pasien *adr_pasien;

struct pasien{
	int id, biaya_dokter, biaya_obat;
	string nama, jenis, hasil;
};

struct dokter{
	string tanggal,nama,spesialisasi;
	int kuota,jam_praktek_start,jam_praktek_end,id;
};

struct element_pasien {
	pasien info;
	adr_pasien next;

};


struct element_dokter {
	dokter info;
	adr_dokter next,prev;
	adr_pasien child;
};

struct ListPasien{
	adr_pasien first;
};

struct ListDokter{
	adr_dokter first,last;
};

//dokter
void creatListDokter(ListDokter &LD);
adr_dokter createElementDokter(dokter data);
void insertFirstDokter(ListDokter &LD,adr_dokter data);
void showDokter(ListDokter LD);
void deleteDokter(ListDokter &LD, string nama,string tanggal);
bool checkDokter(ListDokter LD,string spesialisasi,string tanggal);
adr_dokter findDokter(ListDokter LD,string spesialisasi,string tanggal);
//pasien
void createPasien(ListPasien &LP);
adr_pasien createElementPasien(pasien data);
void insertConnect(ListDokter &LD, adr_pasien newPasien,string spesialisasi,string tanggal);
void deletePasienByID(ListDokter &LD, int id);
void deletePasienByNama(ListDokter &LD, string nama);
void showPasien(ListDokter LD);
void showPasienByTanggal(ListDokter LD);

#endif
