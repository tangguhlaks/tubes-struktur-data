#include "TUBES.h"

void creatListDokter(ListDokter &LD){
	(LD).first = NULL;
}
adr_dokter createElementDokter(dokter data){
	adr_dokter a = new element_dokter;
	(a)->next = NULL;
	(a)->prev = NULL;
	(a)->info = data;
	(a)->child = NULL;
	return a;
}

void insertFirstDokter(ListDokter &LD,adr_dokter data){
	if((LD).first != NULL){
		(data)->next = (LD).first;
		((LD).first)->prev = data;
		(LD).first = data;
	}else{
		(LD).first = data;
	}
}

void showDokter(ListDokter LD){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		cout << "=== Data Dokter ===" << endl;
		while (q!=NULL) {
			dokter d = (q)->info;
			cout << "ID : " <<  d.id << endl; 
			cout << "Nama : " <<  d.nama << endl; 
			cout << "Spesialisasi : " <<  d.spesialisasi << endl; 
			cout << "Tanggal (dd-mm-yyyy) : " <<  d.tanggal << endl; 
			cout << "Jam Praktek (Start) : " <<  d.jam_praktek_start  << endl; 
			cout << "Jam Praktek (End) : " <<  d.jam_praktek_end  << endl; 
			cout << "Kuota Pasien : " <<  d.kuota  << endl << endl;
			q = (q)->next;
		}
		cout << endl;
	}else {
		cout << "Data Dokter Kosong :( " << endl;
	}
}
