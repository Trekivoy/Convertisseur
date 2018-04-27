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
int adaptateurChar(char c, int carre){
    int chiffre = '0';
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
        printf("tableau[%d] vaut %d\n",i,tableau[i]);
        i--;

    }
    tableau[k]='\0';
}
int menu(){
    printf("Bonjour bienvenue dans le super convertisseur !\n\n\n\n");
    while(1){
        int choix;
        printf("Taper 1 pour convertir un entier en binaire et en hexadecimale \n\nTaper 2 pour convertir un nombre binaire en entier\n\nTaper 3 pour convertir un nombre hexadecimale en entier\n\nTaper 4 pour convertir un nombre dans la base que vous souhaitez\n\nTaper 5 pour cnovertir un nombre de la base que vous souhaitez en entier\n\n");
        scanf("%d",&choix);
        char tableau[100];
        int chiffre =0;
        int base = 0;
        switch(choix){
            case 1:printf("Veuillez choisir un nombre a convertir\n");
            scanf("%d",&chiffre);
            decimaleTo(chiffre,tableau,2);
            printf("Voici votre nombre en binaire: \n%s\n",tableau);
            decimaleTo(chiffre,tableau,16);
            printf("Voici votre nombre en hexadecimale : \n%s",tableau);
            break;
            case 2:printf("Veuillez écrire un nombre en binaire\n");
            scanf("%s",tableau);
            printf("Voici votre nombre : \n%d",toDecimale(tableau,2));
            break;
            case 3:printf("Veuillez écrire un nombre en hexadecimale\n");
            scanf("%s",tableau);
            printf("Voici votre nombre : \n%d",toDecimale(tableau,16));
            break;
            case 4:printf("Veuillez choisir un nombre a convertir\n");
            scanf("%d",&chiffre);printf("Veuillez choisir une base\n");
            scanf("%d",&base);
            printf("Voici votre nombre : \n%d",toDecimale(tableau,base));
            break;
            case 5:printf("Veuillez choisir une base \n");
            scanf("%d",&base);
            printf("Veuillez écrire un nombre en base %d\n",base);
            printf("Voici votre nombre : \n%d\n",toDecimale(tableau,16));
            break;
            default : printf("Veuillez entrer un nombre valide comme demander\n");
        }
    }
}

int main()
{
    //menu();
    int chiffre =55;
    char tableau[100];
    decimaleTo(chiffre,tableau,2);
    printf("%s\n",tableau);
    return 0;
}
