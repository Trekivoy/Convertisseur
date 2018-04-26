#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void inverseTableau(int taille,char tab[]){
    int i;
    char pont;
    for(i=0;i<taille/2;i++){
        pont = tab[i];
        tab[i]=tab[taille-i-1];
        tab[taille-i-1]=pont;
    }
}
int str_len(char *input){
    int i;
    for(i=0;input[i]!='\0';i++){
    }
    return i;
}

void decimaleToBinaire(int nombre,char binaire[]){
    int i;
    for(i=0;nombre!=0;i++){
        if(nombre%2==1){
            binaire[i]='1';
        }else{
            binaire[i]='0';
        }
        nombre/=2;
    }
    binaire[i]='\0';
    int taille =str_len(binaire);
    inverseTableau(taille,binaire);
}
int binaireToDecimale(char binaire[]){
    int i;
    int nombre =0;
    int taille = str_len(binaire);
    for(i=0;i<taille;i++){
        if(binaire[i]=='1'){
            nombre+=pow(2,taille-i-1);
        }
    }
    return nombre;
}
int binaireTo(char binaire[]){
    int i;
    int nombre =0;
    int taille = str_len(binaire);
    for(i=0;i<taille;i++){
        if(binaire[i]=='1'){
            nombre+=pow(2,taille-i-1);
        }
    }
    return nombre;
}
char adapteurProduit(int produit,int base){
    char converti=48;
    int i;
    if(produit>0&&produit<10){
        for(i=0;i<=produit;i++){
            if(i==produit){
                converti+=i;
            }
        }
    }else if(produit>9&&produit<base){
        converti = 65;
        for(i=0;i<=produit-10;i++){
            if(i==produit-10){
                converti+=i;
            }
        }
    }
    return converti;
}
int decimaleTo(int nombre, char hexa[],int base){
    int i;
    int j;
    int k=0;
    int carre=1;
    int produit =1;
    for (i=0;nombre>carre*carre;i++){
        carre=pow(base,i);

    }
    while(nombre!=0){
        for(j=0;nombre>=(j*carre);j++){
            produit= j*carre;
        }
        hexa[k]=adapteurProduit(j-1,base);
        nombre-=produit;
        carre/=base;
        k++;
    }
    hexa[k]='\0';
}
int convertisseur();

int main()
{
    //convertisseur;
    int nombre;
    char binaire[100];
    char hexa[100];
//    printf("Taper un nombre svp !\n");
//    scanf("%d",&nombre);
//    decimaleToBinaire(nombre,binaire);
//    printf("Le voici en binaire %s\n",binaire);
//    printf("le voici en decimale %d",binaireToDecimale(binaire));
    int base =16;
    decimaleTo(257,hexa,base);
    printf("%s",hexa);

    return 0;
}
