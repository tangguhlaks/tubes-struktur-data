#include "TUBES.h"
#include "TUBES.cpp"

int main(){
	ListDokter LD;
	creatListDokter(LD);
	int x=1;
	system("cls");
	while(x != 0){
		cout << "=== RUMAH SAKIT ===" << endl;
		cout << "1.Tambah Data Dokter" << endl;
		cout << "2.Pendaftaran Pasien" << endl;
		cout << "3.Jadwal Dokter" << endl;
		cout << "4.Lihat Semua Pasien" << endl;
		cout << "5.Hapus Pasien by ID" << endl;
		cout << "6.Hapus Pasien by Nama" << endl;
		cout << "7.Hapus Jadwal Dokter" << endl;
		cout << "0.Keluar" << endl;
		cout << "pilihan : "; 
		cin >> x;
		cin.ignore();
		system("cls");
		if(x==1){
			dokter d;
			cout << "=== Tambah Data ===" << endl;
			cout << "ID : ";cin >> d.id;cin.ignore();
			cout << "Nama : ";cin(d.nama);
			cout << "Spesialisasi : ";cin(d.spesialisasi);
			cout << "Tanggal (dd-mm-yyyy) : ";cin(d.tanggal);
			cout << "Jam Praktek (Start) : ";cin >> d.jam_praktek_start;cin.ignore();
			cout << "Jam Praktek (End) : ";cin >> d.jam_praktek_end;cin.ignore();
			cout << "Kuota Pasien : ";cin >> d.kuota;cin.ignore();
			adr_dokter newdata = createElementDokter(d);
			insertFirstDokter(LD,newdata);
		}else if (x==2){
			pasien p;
			cout << "=== Pendaftaran Pasien ===" << endl;
			cout << "ID : ";cin >> p.id;cin.ignore();
			cout << "Nama : ";cin(p.nama);
			cout << "Jenis Pasien (BPJS atau non BPJS) : ";cin(p.jenis);
			string dokter_cari,tanggal;
			cout << "Dokter Penyakit yang di inginkan : ";cin(dokter_cari);
			cout << "Tanggal : ";cin(tanggal);
			adr_pasien newdata = createElementPasien(p);
			insertConnect(LD,newdata, dokter_cari,tanggal);
		}else if (x==3){
			showDokter(LD);	
		}else if (x==4){
			showPasien(LD);
		}else if(x==5){
			int id;
			cout << "ID : ";cin >> id;cin.ignore();
			//deletePasienByID(LD,id);
		}else if(x==6){
			string nama;
			cout << "Nama : ";cin(nama);
			//deletePasienByID(LD,nama);
		}else if(x==0){
			cout << "Sampai Jumpa :)" << endl;
			break;
		}else{
			cout << "Pilihan Tidak Tersedia :( " << endl << endl;
		}
	}
}
