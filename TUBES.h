#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

typedef struct jadwal_dokter *adr_dokter;

struct jadwal_dokter{
	string tanggal,nama,spesialisasi;
	int kuota,jam_praktek_start,jam_praktek_end;
};

struct element_jadwal_dokter {
	infotype info;
	adr next;
};

struct ListJadwalDokter{
	adr_dokter first;
};


#endif
