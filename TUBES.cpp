#include "TUBES.h"
//Tangguh
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
		(LD).last = data;
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

//Farhan
void createPasien(ListPasien &LP){
	(LP).first =NULL;
}

adr_pasien createElementPasien(pasien data){
	adr_pasien p =  new element_pasien;
	(p)->next = NULL;
	(p)->info = data;
	return p;
}

bool checkDokter(ListDokter LD,string spesialisasi,string tanggal){
	adr_dokter q = (LD).first;
	bool ans=false;
	if(q!=NULL){
		while (q!=NULL) {
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.spesialisasi == spesialisasi) {
				ans=true;
			}	
			q = (q)->next;
		}
	}
	return ans;
}

void deleteDokter(ListDokter &LD, string nama,string tanggal){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		while (q!=NULL) {
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.nama == nama) {
				break;
			}
			q = (q)->next;
		}
		if((q)->next == NULL){
			adr_dokter c = (LD).last;
			(LD).last = (c)->prev;
			(c)->next = NULL;
			(c)->prev = NULL;
			((LD).last)->next = NULL;
		}else if((q)->prev == NULL) {
			adr_dokter c = (LD).first;
			(LD).first = (c)->next;
			(c)->next = NULL;
			(c)->prev = NULL;	
			((LD).first)->prev = NULL;
		}
	}
}
adr_dokter findDokter(ListDokter LD,string spesialisasi,string tanggal){
	adr_dokter q = (LD).first;
	adr_dokter ans;
	if(q!=NULL){
		while (q!=NULL) {
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.spesialisasi == spesialisasi) {
				ans=q;
			}
			q = (q)->next;
		}
	}
	return ans;
}

void insertConnect(ListDokter &LD, adr_pasien newPasien,string spesialisasi,string tanggal){
	if (checkDokter(LD,spesialisasi,tanggal)) {
		adr_dokter mydokter = findDokter(LD,spesialisasi,tanggal);
		if((mydokter)->info.kuota > 0){
			if((mydokter)->child == NULL){
				(mydokter)->child = newPasien;
				((mydokter)->child)->next = newPasien;
			}else if (((mydokter)->child)->next == (mydokter)->child) {
				(newPasien)->next = (mydokter)->child;
				((mydokter)->child)->next = newPasien;
			}else {
				adr_pasien p = (mydokter)->child;
				while((p)->next != (mydokter)->child){
					p = (p)->next;
				}
				(newPasien)->next = (mydokter)->child;
				(p)->next = newPasien;
			}
			cout << "Pendaftaran pasien berhasil" << endl;
			(mydokter)->info.kuota -= 1;
		}else{
			cout << "Kuota pasien habis" << endl;
		}
	}else{
		cout << "Tidak ada dokter spesialisasi " << spesialisasi << " pada tanggal " << tanggal << endl;	
	}
}

void deletePasienByID(ListDokter &LD, int id){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		adr_pasien mypasien;
		adr_dokter mydokter;
		while (q!=NULL) {
			adr_pasien d = (q)->child;
			do{
				if((d)->info.id == id){
					mypasien = d;
					mydokter = q;
					break;
				}
				d = (d)->next;
			}while(d != (q)->child);
			q = (q)->next;
		}
		if(mypasien == (mydokter)->child){
			(mydokter)->child = NULL;
		}else{
			adr_pasien c = (mydokter)->child;
			while ((c)->next != mypasien) {
				c = (c)->next;
			}
			(c)->next = (mypasien)->next;
			(mypasien)->next = NULL;
		}
		cout << "Pasien berhasil di hapus" << endl;
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}

void deletePasienByNama(ListDokter &LD, string nama){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		adr_pasien mypasien;
		adr_dokter mydokter;
		while (q!=NULL) {
			adr_pasien d = (q)->child;
			do{
				if((d)->info.nama == nama){
					mypasien = d;
					mydokter = q;
					if(mypasien == (mydokter)->child){
						(mydokter)->child = NULL;
					}else{
						adr_pasien c = (mydokter)->child;
						while ((c)->next != mypasien) {
							c = (c)->next;
						}
						(c)->next = (mypasien)->next;
						(mypasien)->next = NULL;
					}

				}
				d = (d)->next;
			}while(d != (q)->child);
			
			q = (q)->next;
		}
		cout << "Pasien berhasil di hapus" << endl;
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}
}

void showPasien(ListDokter LD){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		cout << "=== Data Pasien ===" << endl;
		while (q!=NULL) {
			adr_pasien d = (q)->child;
			do{
				cout << "ID : " << (d)->info.id << endl;
				cout << "Nama : " << (d)->info.nama << endl;
				cout << "Jenis Pasien (BPJS atau non BPJS) : "<<(d)->info.jenis << endl << endl;
				d = (d)->next;
			}while(d != (q)->child);
			q = (q)->next;
		}
		cout << endl;
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}

void showPasienByTanggal(ListDokter LD){
	
}
