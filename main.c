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
    if(produit>=0&&produit<10){
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
/*void decimaleToBinaire(int nombre,char binaire[]){
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
*/
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
    if(nombre>=base){
        for (i=0;nombre>=base*carre;i++){ // ne fonctionne pas quand nombre = base
            carre=pow(base,i);
            printf("carre vaut %d\n",carre);
        }
    }else{
        i=1;
    }
    while(i!=0){
        for(j=0;nombre>=(j*carre);j++){
            produit= j*carre;
        }
        printf("valeur = %d\n",adapteurDecimale(j-1,base));
        tableau[k]=adapteurDecimale(j-1,base);
        nombre-=produit;
        carre/=base;
        k++;
        i--;

    }
    tableau[k]='\0';
}
int menu(){
    printf("Bonjour bienvenue dans le super convertisseur !\n\n\n\n");
    while(1){
        int choix;
        printf("Taper 1 pour convertir un entier en binaire et en hexadecimale \n\nTaper 2 pour convertir un nombre de la base de votre choix en entier\n\nTaper 3 pour convertir un entier dans la base que vous souhaitez\n\nTaper 4 pour convertir un nombre de la base que vous souhaitez à la base que vous souhaitez\n\n");
        scanf("%d",&choix);
        char tableau[100];
        char tableau2[100];
        int nombre =0;
        int base = 0;
        int base2 = 0;
        switch(choix){
            case 1:printf("Veuillez choisir un nombre a convertir\n");
            scanf("%d",&nombre);
            decimaleTo(nombre,tableau,2);
            printf("Voici votre nombre en binaire: \n%s\n",tableau);
            decimaleTo(nombre,tableau,16);
            printf("Voici votre nombre en hexadecimale : \n%s\n",tableau);
            break;
            case 2:printf("Veuillez choisir une base\n");
            scanf("%d",&base);
            printf("Veuillez entrez un nombre en base %d\n",base);
            scanf("%s",tableau);
            printf("Voici votre nombre : \n%d\n",toDecimale(tableau,base));
            break;
            case 3:printf("Veuillez choisir une base\n");
            scanf("%d",&base);
            printf("Veuillez entrer votre entier\n");
            scanf("%d",&nombre);
            decimaleTo(nombre,tableau,base);
            printf("Voici votre nombre : \n%s\n",tableau);
            break;
            case 4:printf("Veuillez choisir la base du nombre a convertir\n");
            scanf("%d",&base);
            printf("Veuillez choisir la base d'arrivee\n");
            scanf("%d",&base2);
            printf("Veuillez maintenant entrer votre nombre a convertir\n");
            scanf("%s",&tableau);
            decimaleTo(toDecimale(tableau,base),tableau2,base2);
            printf("Voici votre nombre en base %d :\n%s\n",base2,tableau2);
            break;
            case 5:
            break;
            default : printf("Veuillez entrer un nombre valide comme demander\n");
        }
    }
}

int main()
{
    menu();

    return 0;
}
