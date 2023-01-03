#include "TUBES.h"
//Tangguh
void creatListDokter(ListDokter &LD){
	(LD).first = NULL;
}
adr_dokter createElementDokter(dokter data){
	adr_dokter a = new element_dokter;
	(a)->next = NULL;
	(a)->info = data;
	return a;
}

void insertFirstDokter(ListDokter &LD,adr_dokter data){
	if((LD).first != NULL){
		adr_dokter p = (LD).first;
		while ((p)->next != (LD).first) {
			p = (p)->next;
		}	
		(p)->next = data;
		(data)->next = (LD).first;
		(LD).first = data;
	}else{
		(data)->next = data;
		(LD).first = data;
	}
}

void showDokter(ListDokter LD){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		cout << "=== Data Dokter ===" << endl;
		do{
			dokter d = (q)->info;
			cout << "ID : " <<  d.id << endl; 
			cout << "Nama : " <<  d.nama << endl; 
			cout << "Spesialisasi : " <<  d.spesialisasi << endl; 
			cout << "Tanggal (dd-mm-yyyy) : " <<  d.tanggal << endl; 
			cout << "Jam Praktek (Start) : " <<  d.jam_praktek_start  << endl; 
			cout << "Jam Praktek (End) : " <<  d.jam_praktek_end  << endl; 
			cout << "Kuota Pasien : " <<  d.kuota  << endl << endl;
			q = (q)->next;
		}while(q != (LD).first);
		cout << endl;
	}else {
		cout << "Data Dokter Kosong :( " << endl;
	}
}

//Farhan
void createPasien(ListPasien &LP){
	(LP).first =NULL;
	(LP).last = NULL;
}

adr_pasien createElementPasien(pasien data){
	adr_pasien p =  new element_pasien;
	(p)->next = NULL;
	(p)->prev = NULL;
	(p)->info = data;
	(p)->mydokter =NULL;
	return p;
}

bool checkDokter(ListDokter LD,string spesialisasi,string tanggal){
	adr_dokter q = (LD).first;
	bool ans=false;
	if(q!=NULL){
		do{
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.spesialisasi == spesialisasi) {
				ans=true;
			}	
			q = (q)->next;
		}while(q!=(LD).first);
	}
	return ans;
}

void deleteDokter(ListDokter &LD, string nama,string tanggal){
	adr_dokter q = (LD).first;
	if(q!=NULL){
		bool flag = false;
		adr_dokter qq = q;
		do{
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.nama == nama) {
				flag = true;
				break;
			}
			qq=q;
			q = (q)->next;
		}while(q != (LD).first);

		if (flag) {
			if(q == (LD).first){
				(q)->next = NULL;
				(LD).first = NULL;
			}else{
				(qq)->next = (q)->next;
				(q)->next = NULL;
			}
			cout << "Dokter berhasil di hapus" << endl;
		}else {
			cout << "Dokter dengan nama " << nama << " tidak tersedia pada tanggal " << tanggal << endl;
		}

	}
}
adr_dokter findDokter(ListDokter LD,string spesialisasi,string tanggal){
	adr_dokter q = (LD).first;
	adr_dokter ans;
	if(q!=NULL){
		do{
			dokter d = (q)->info;
			if (d.tanggal == tanggal && d.spesialisasi == spesialisasi) {
				ans=q;
			}
			q = (q)->next;
		}while(q != (LD).first);
	}
	return ans;
}

void insertConnect(ListDokter &LD, adr_pasien newPasien,string spesialisasi,string tanggal,ListPasien &LP){
	if (checkDokter(LD,spesialisasi,tanggal)) {
		adr_dokter mydokter = findDokter(LD,spesialisasi,tanggal);
		if((mydokter)->info.kuota > 0){
			(newPasien)->mydokter = mydokter;
			adr_pasien p = (LP).first;
			if(p == NULL){
				(LP).first = newPasien;
				(LP).last = newPasien;
			}else{
				((LP).last)->next = newPasien;
				(newPasien)->prev = (LP).last;
				(LP).last = newPasien;
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

void deletePasienByID(ListPasien &LP, int id){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		while (q != NULL) {
			if ((q)->info.id == id) {
				break;
			}
			q = (q)->next;
		}
		if (q!=NULL) {
			if((q)->next == NULL && (q)->prev != NULL){
				(LP).last = (q)->prev;
				((LP).last)->next = NULL;
				q =NULL;
			}else if((q)->next != NULL && (q)->prev == NULL){
				(LP).first = (q)->next;
				((LP).first)->prev = NULL;
				q =NULL;
			}else{
				((q)->prev)->next = (q)->next;
				((q)->next)->prev = (q)->prev;
				q =NULL;
			}
			cout << "Pasien berhasil di hapus" << endl;
		}else {
			cout << "Pasien dengan id " << id << " tidak ada" << endl;
		}
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}

void deletePasienByNama(ListPasien &LP, string nama){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		while (q != NULL) {
			if ((q)->info.nama == nama) {
				break;
			}
			q = (q)->next;
		}
		if (q!=NULL) {
			if((q)->next == NULL && (q)->prev != NULL){
				(LP).last = (q)->prev;
				((LP).last)->next = NULL;
				q =NULL;
			}else if((q)->next != NULL && (q)->prev == NULL){
				(LP).first = (q)->next;
				((LP).first)->prev = NULL;
				q =NULL;
			}else if ((q)->next == NULL && (q)->prev == NULL) {
				(LP).first =NULL;
				(LP).last =NULL;
			}else{
				((q)->prev)->next = (q)->next;
				((q)->next)->prev = (q)->prev;
				q =NULL;
			}
			cout << "Pasien berhasil di hapus" << endl;
		}else {
			cout << "Pasien dengan nama " << nama << " tidak ada" << endl;
		}
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}
void showPasien(ListPasien LP){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		cout << "=== Data Pasien ===" << endl;
		while (q!=NULL) {
			adr_dokter d = (q)->mydokter;
			cout << "ID : " << (q)->info.id << endl;
			cout << "Nama : " << (q)->info.nama << endl;
			cout << "Jenis Pasien (BPJS atau non BPJS) : "<<(q)->info.jenis << endl;
			cout << "Nama Dokter : " << (d)->info.nama << endl;
			cout << "Spesialisasi : " << (d)->info.spesialisasi << endl << endl;
			q = (q)->next;
		}
		cout << endl;
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}
void showPasienByTanggal(ListPasien LP,string tanggal){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		cout << "=== Data Pasien ===" << endl;
		while (q!=NULL) {
			adr_dokter d = (q)->mydokter;
			if((d)->info.tanggal == tanggal){
				cout << "ID : " << (q)->info.id << endl;
				cout << "Nama : " << (q)->info.nama << endl;
				cout << "Jenis Pasien (BPJS atau non BPJS) : "<<(q)->info.jenis << endl;
				cout << "Nama Dokter : " << (d)->info.nama << endl;
				cout << "Spesialisasi : " << (d)->info.spesialisasi << endl << endl;
				if((q)->info.hasil != "-"){
					cout << "Hasil Pemeriksaan : " << (q)->info.hasil << endl;
					cout << "Biaya : " << (q)->info.biaya_dokter << endl;
				}
			}
			q = (q)->next;
		}
		cout << endl;
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}


void gantiJadwal(ListDokter &LD, ListPasien &LP, int id,string tanggal_baru){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		while (q!=NULL) {
			adr_dokter d = (q)->mydokter;
			if((q)->info.id == id){
				if(checkDokter(LD, (d)->info.spesialisasi,tanggal_baru)){
					adr_dokter nd = findDokter(LD,(d)->info.spesialisasi,tanggal_baru);
					(q)->mydokter = nd;
					cout << "Jadwal pasien berhasil diperbaharui " << endl;
				}else{
					cout << "Tidak ada jadwal dokter "<< (d)->info.spesialisasi <<" pada tanggal " << tanggal_baru << endl;	
				}
				return;
			}
			q = (q)->next;
		}
		cout << "Pasien dengan ID " << id << " tidak ditemukan" << endl; 
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}
}

void setHasilPemeriksaan(ListPasien &LP,int id){
	adr_pasien q = (LP).first;
	if(q!=NULL){
		while (q!=NULL) {
			if((q)->info.id == id){
				adr_dokter d = (q)->mydokter;
				string hasil;
				cout << "Hasil Pemeriksaan : ";cin(hasil);
				(q)->info.hasil = hasil;
				int biaya = 100000;
				if((d)->info.spesialisasi == "umum" ||(d)->info.spesialisasi == "Umum" || (d)->info.spesialisasi == "UMUM"){
				biaya =200000;
				}
				if((q)->info.jenis == "BPJS" && biaya > 500000){
					biaya -= 500000;
				}else if ((q)->info.jenis == "BPJS" && biaya <= 500000) {
					biaya = 0;
				}
				(q)->info.biaya_dokter =biaya;
				cout << "Hasil pemeriksaan pasien berhasil diperbaharui " << endl;
				return;
			}
			q = (q)->next;
		}
		cout << "Pasien dengan ID " << id << " tidak ditemukan" << endl; 
	}else {
		cout << "Data Pasien Kosong :( " << endl;
	}

}

