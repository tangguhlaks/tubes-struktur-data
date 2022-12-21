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
		cout << "2.Tambah Data Pasien" << endl;
		cout << "3.Lihat Data Dokter" << endl;
		cout << "4.Lihat Data Pasien" << endl;
		cout << "0.Keluar" << endl;
		cout << "pilihan : "; cin >> x;
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
		}else if (x==3){
			showDokter(LD);	
		}else if (x==4){
		
		}else if(x==0){
			cout << "Sampai Jumpa :)" << endl;
			break;
		}else{
			cout << "Pilihan Tidak Tersedia :( " << endl << endl;
		}
	}
}
