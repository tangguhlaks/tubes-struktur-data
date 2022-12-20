#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

typedef struct jadwal_dokter *adr_dokter;
typedef struct element_pasien *adr_pasien;

struct pasien{
	int id, biaya_dokter, biaya_obat;
	string nama, jenis, hasil;
};

struct jadwal_dokter{
	string tanggal,nama,spesialisasi;
	int kuota,jam_praktek_start,jam_praktek_end;
};

struct element_pasien {
	pasien info;
	adr_pasien next, prev;

};


struct element_jadwal_dokter {
	jadwal_dokter info;
	adr_dokter next;
};

struct ListPasien{
	adr_pasien first, last;
};

struct ListJadwalDokter{
	adr_dokter first;
};


#endif
