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
	string tanggal,nama,spesialisasi,jam_praktek_start,jam_praktek_end;
	int kuota,id;
};

struct element_pasien {
	pasien info;
	adr_pasien next,prev;
	adr_dokter mydokter;
};


struct element_dokter {
	dokter info;
	adr_dokter next;
};

struct ListPasien{
	adr_pasien first,last;
};

struct ListDokter{
	adr_dokter first;
};

//dokter
void creatListDokter(ListDokter &LD);
adr_dokter createElementDokter(dokter data);
void insertFirstDokter(ListDokter &LD,adr_dokter data);
void showDokter(ListDokter LD);
void deleteDokter(ListDokter &LD, string nama,string tanggal);
bool checkDokter(ListDokter LD,string spesialisasi,string tanggal);
adr_dokter findDokter(ListDokter LD,string spesialisasi,string tanggal);
void setHasilPemeriksaan(ListPasien &LP,int id);
//pasien
void createPasien(ListPasien &LP);
adr_pasien createElementPasien(pasien data);
void insertConnect(ListDokter &LD, adr_pasien newPasien,string spesialisasi,string tanggal,ListPasien &LP);
void deletePasienByID(ListPasien &LP, int id);
void gantiJadwal(ListDokter &LD, ListPasien &LP, int id,string tanggal_baru);
void deletePasienByNama(ListPasien &LP, string nama);
void showPasien(ListPasien LP);
void showPasienByTanggal(ListPasien LP,string tanggal);

#endif
