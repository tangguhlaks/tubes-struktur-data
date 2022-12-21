#include "TUBES.h"
#include "TUBES.cpp"

int main(){
	int x=1;
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

		}else if (x==2) {
		
		}else if (x==3) {
		
		}else if (x==4) {
		
		}else if(x==0){
			cout << "Sampai Jumpa :)" << endl;
			break;
		}else{
			cout << "Pilihan Tidak Tersedia :( " << endl << endl;
		}
	}
}
