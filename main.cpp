#include "TUBES.h"
#include "TUBES.cpp"

int main(){
	ListDokter LD;
	creatListDokter(LD);
	ListPasien LP;
	createPasien(LP);
	int x=1;
	system("cls");
	while(x != 0){
		cout << "=== RUMAH SAKIT ===" << endl;
		cout << "1.Tambah Data Dokter" << endl;
		cout << "2.Pendaftaran Pasien" << endl;
		cout << "3.Jadwal Dokter" << endl;
		cout << "4.Lihat Semua Pasien" << endl;
		cout << "5.Lihat Pasien By tanggal" << endl;
		cout << "6.Hapus Pasien by ID" << endl;
		cout << "7.Hapus Pasien by Nama" << endl;
		cout << "8.Hapus Jadwal Dokter" << endl;
		cout << "9.Ganti Jadwal Dokter" << endl;
		cout << "10.Pemeriksaan Dokter" << endl;
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
			cout << "Jam Praktek (Start) : ";cin(d.jam_praktek_start);
			cout << "Jam Praktek (End) : ";cin(d.jam_praktek_end);
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
			cout << "Dokter spesialis yang diinginkan : ";cin(dokter_cari);
			cout << "Tanggal : ";cin(tanggal);
			(p).hasil = "-";
			adr_pasien newdata = createElementPasien(p);
			insertConnect(LD,newdata, dokter_cari,tanggal,LP);
		}else if (x==3){
			showDokter(LD);	
		}else if (x==4){
			showPasien(LP);
		}else if (x==5){
			string tanggal;
			cout << "Tanggal : ";cin(tanggal);
			showPasienByTanggal(LP, tanggal);
		}else if(x==6){
			showPasien(LP);
			int id;
			cout << "ID : ";cin >> id;cin.ignore();
			deletePasienByID(LP,id);
		}else if(x==7){
			showPasien(LP);
			string nama;
			cout << "Nama : ";cin(nama);
			deletePasienByNama(LP,nama);
		}else if (x==8) {
			showDokter(LD);	
			string nama,tanggal;
			cout << "Nama : ";cin(nama);
			cout << "Tanggal : ";cin(tanggal);
			deleteDokter(LD,nama,tanggal);
		}else if (x==9) {
			string tanggal;
			int id;
			showPasien(LP);
			cout << "ID Pasien : ";cin >> id;cin.ignore();
			cout << "Tanggal Baru : ";cin(tanggal);
			gantiJadwal(LD,LP,id,tanggal);
		}else if (x==10) {
			int id;
			showPasien(LP);
			cout << "ID Pasien : ";cin >> id;cin.ignore();
			setHasilPemeriksaan(LP,id);
		}else if(x==0){
			cout << "Sampai Jumpa :)" << endl;
			break;
		}else{
			cout << "Pilihan Tidak Tersedia :( " << endl << endl;
		}
	}
}
