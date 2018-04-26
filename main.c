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
char adapteurDecimale(int produit,int base){
    char converti;
    int i;
    if(produit>0&&produit<10){
        converti=48;
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
int adaptateurChar(char c, int carre){
    int chiffre = '0';
    printf("c vaut %d\n",c);
    int lettre = 'A';
    int i ;
    if(c>=chiffre&&c<57){
        for(i=0;c!=chiffre+i;i++){
        }
    }else if(c>64&&c<91){
        for(i=0;c!=lettre+i;i++){
        }
        i+=10;
    }
    return i*carre;
}
int toDecimale(char tableau[], int base){
    int carre;
    int i;
    int nombre =0;
    int taille = str_len(tableau);
    for(i=0;i<taille;i++){
        carre=pow(base,taille-1-i);
        nombre+=adaptateurChar(tableau[i],carre);
    }
    return nombre;
}
int decimaleTo(int nombre, char tableau[],int base){
    int i;
    int j;
    int k=0;
    int carre=1;
    int produit =1;
    if(nombre>base){
        for (i=0;nombre>base*carre;i++){ // ne fonctionne pas quand nombre < base
            carre=pow(base,i);
        }
    }else{
        i=1;
    }
    while(i!=0){
        for(j=0;nombre>=(j*carre);j++){
            produit= j*carre;
        }
        tableau[k]=adapteurDecimale(j-1,base);
        nombre-=produit;
        carre/=base;
        k++;
        i--;
    }
    tableau[k]='\0';
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
    //int base =8;
   // decimaleTo(5,hexa,base);
    //printf("%s",hexa);
    char test[100] ="101001001";
    nombre = toDecimale(test,2);
    printf("%d",nombre);
    return 0;
}
