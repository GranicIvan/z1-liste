#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  studnet
{
    char ime[30];
    char prezime[30];
    char index[7];
    struct studnet* sledeci;

}studnet;

void ubaci_element(studnet** koren, studnet* novi){

    if (*koren == NULL)
    {
        *koren = novi;
    }else{
        while ((*koren)->sledeci != NULL && 0 > (strcmp( (*koren)->prezime , novi->prezime ) ))
        {
           *koren =  (*koren)->sledeci;
        }
        studnet* temp;
        temp = (*koren)->sledeci;
        (*koren)->sledeci = novi;
        novi->sledeci = temp;
        
    }
    
}

void ispisi_studenta(studnet* studnet){
    printf("%10s  %12s  %7s \n", studnet->ime, studnet->prezime, studnet->index);
}

void ispis(studnet* koren){
    while (koren != NULL)
    {
        ispisi_studenta(koren);
        koren = koren->sledeci;
    }
}

studnet* ucitavanje(char ime_fajla[30]){

    studnet* prvi = NULL;
    

    FILE* f = fopen(ime_fajla, "r");

    int n;

    fscanf(f, "%d\n", &n);

    printf("n je: %d \n", n);


    for(int i = 0; i < n ; i++){
        // printf(" i=%d \n",i);
        studnet* temp;
        temp = malloc(sizeof(studnet));
        //temp->ime = malloc(sizeof(char) * 30);
        // temp->prezime = malloc(sizeof(char) * 30 );
        // temp->index = malloc(sizeof(char) * 7);
        
        // printf("a i=%d \n",i);
        fscanf(f, "%s", temp->ime);
        // printf("b i=%d \n",i);
        fscanf(f, "%s", temp->prezime);
        // printf("c i=%d \n",i);
        fscanf(f, "%s", temp->index);
        // printf("d i=%d \n",i);

        // fgets(temp->ime, 30, f);
        //  printf("b i=%d \n",i);
        // fgets(temp->prezime, 30, f);
        //  printf("c i=%d \n",i);
        // fgets(temp->index, 10, f);
        //  printf("d i=%d \n",i);

        // printf("procitali smo element kad je i= %d\n",i);
        // ispisi_studenta(temp);
        ubaci_element(&prvi, temp);
        // printf("Ubacili smo elem kad je i=%d\n",i);
    }

    return prvi;
}




int main(){
    printf(" --- POCETAK PROGRAMA --- \n\n");

    studnet* koren;

    koren = ucitavanje("studenti.dat");
   
    printf("krece ispis\n");
    ispis(koren);



    printf(" ###### KRAJ PROGRAMA ######");
    return 0;
}
