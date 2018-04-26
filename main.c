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
int adapteurProduit(int produit,base){
    if(produit>9){

    }
}
int decimaleTo(int nombre, char base[]){
    int i;
    int j;
    int k=0;
    int base =16;
    int carre=1;
    int produit =1;
    for (i=0;nombre>carre*carre;i++){
        carre=pow(base,i);
        printf("i vaut %d, carre vaut %d\n",i,carre);
    }
    while(i!=0){
        printf("nombre vaut %d et carre vaut %d\n",nombre, carre);
        for(j=0;nombre>(j*carre);j++){
            produit= j*carre;
            printf("j vaut %d, produit vaut %d\n",j,produit);
        }
        hexa[k]=j;
        nombre-=produit;
        printf("carre = %d\n",carre);
        carre/=base;
        i--;
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
    decimaleToHexa(637,hexa);
    printf("%s",hexa);
//    int carre;
//    carre=pow(16,1);
//    printf("carre vaut %d",carre);
    return 0;
}
