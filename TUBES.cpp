#include "TUBES.h"

//code in here
void createListPasien(ListPasien &L){
    L.first = NULL;
}

adr_pasien createElemenPasien(pasien data){
    adr_pasien p = new element_pasien;
    p->info = data;
    p->next = NULL;
    return p; 
}