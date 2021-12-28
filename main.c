#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define Dictionnaire "Dictionnaire.txt"


/*************************************************************************************************************************************/
void color(int couleurDuTexte,int couleurDeFond)
{
    /*fonction d'affichage de couleurs*/

    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void gotoxy(int x,int y)
{
  COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

int  rechercheMot(char nomFichier[],char mot[15]) //recherche Mot dans un fichier
{
   char buff[128];
     int trouve=0;
   FILE *pFile;
   pFile = fopen(nomFichier, "r");
   if(pFile==NULL)
   {
    return 0;
   }
   do
   {
       fscanf(pFile,"%s",buff);
       if(strcmp(buff,mot)==0)
         trouve=1;
   }while(!feof(pFile)&&(!trouve));

     fclose(pFile);
     return trouve;
}
int Nbchiffre(int X)
{
    int cpt=1;
    X=abs(X);
    while(X>9)
    {
        cpt++;
        X=X/10;
    }
    return cpt;
}

/**********************************************************************************************************
*
*                                         LES OUTILS DE JEUX
*
********************************************************************************************************/

/************************************ Fonctions d'affichage ****************************************/

void Remplir_joueur(int i,int score)  //procedure qui affiche le tableau des informations de chaque player
{
         int m;
         printf("\n%c",218);
         for (m=0;m<40;m++)      printf("%c",196);
         printf("%c\n%c               PLAYER %d :               %c\n%c",191,179,i,179,195);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",194);
         for (m=0;m<19;m++)      printf("%c",196);
         printf("%c\n%c     Les Lettres    %c *******           %c\n%c",180,179,179,179,195);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",197);
         for (m=0;m<19;m++)      printf("%c",196);
         printf("%c\n%c  Le mot / Passer   %c *******           %c\n%c",180,179,179,179,195);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",197);
         for (m=0;m<19;m++)      printf("%c",196);
         printf("%c\n%c   Deplacement H/V  %c                   %c\n%c",180,179,179,179,195);
                  for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",197);
         for (m=0;m<9;m++)      printf("%c",196);
         printf("%c",194);
         for (m=0;m<9;m++)      printf("%c",196);
         printf("%c\n%c     Cordonne       %c  i=     %c  j=     %c\n%c",180,179,179,179,179,195);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",197);
         for (m=0;m<9;m++)      printf("%c",196);
         printf("%c",193);
         for (m=0;m<9;m++)      printf("%c",196);
         printf("%c\n%c     SCORE          %c   %d",180,179,179,score);
         for(m=0;m<16-Nbchiffre(score);m++)  printf(" ");
         printf("%c\n%c",179,192);
         for (m=0;m<20;m++)      printf("%c",196);
         printf("%c",193);
         for (m=0;m<19;m++)      printf("%c",196);
         printf("%c",217);
}
void Remplir_Grille(char grille[15][15]) // procesure qui affiche le plateau de scrabble
{
    for(int i=0; i<15 ;i++)
   {
     gotoxy(70,1+2*i);
      for(int j=0;j<15;j++)
      {

          if(i==0)
          {
              if(j==0)
              {
                  printf("%c%c%c%c",218,196,196,194);

              }
              else
              {
                  if(j!=14) printf("%c%c%c",196,196,194);
                  else  printf("%c%c%c",196,196,191);
              }
          }
          else
          {



                 if (j==0) printf("%c%c%c%c",195,196,196,197);
                 else
                 {
                     if(j!=14)  printf("%c%c%c",196,196,197);
                     else  printf("%c%c%c",196,196,180);
                 }

        }
      }
      gotoxy(70,1+i*2+1);
      for(int t=0;t<15;t++)
      {
              int ti=i*100+t;
              switch(ti)
              {
              case 0:
              case 7:
              case 14:
              case 1400:
              case 1407:
              case 1414:
              case 700:
                {
                  printf("%c",179);    //rouge
                  color(0,12);
                  printf("%c ",grille[i][t]);
                  color(15,0);
                }
                break;
              case 101:
              case 202:
              case 303:
              case 404:
              case 1301:
              case 1202:
              case 1103:
              case 1004:
              case 113:
              case 212:
              case 311:
              case 410:
              case 1010:
              case 1111:
              case 1212:
              case 1313:
                {
                  printf("%c",179);
                  color(0,13);     //rose
                  printf("%c ",grille[i][t]);
                  color(15,0);
                }
                break;
              case 707:
                {
                  printf("%c",179);
                  color(0,14);   //jaune
                  printf("%c ",grille[i][t]);
                  color(15,0);
                }
                break;
              case 300:
              case 1100:
              case 602:
              case 802:
              case 3:
              case 703:
              case 1403:
              case 206:
              case 606:
              case 806:
              case 1206:
              case 307:
              case 1107:
              case 208:
              case 1208:
              case 11:
              case 711:
              case 1411:
              case 612:
              case 812:
              case 314:
              case 1114:
              case 808:
              case 608:
                {
                  printf("%c",179);
                  color(0,11);    //bleu clair
                  printf("%c ",grille[i][t]);
                  color(15,0);
                }
                break;
              case 105:
              case 109:
              case 501:
              case 505:
              case 509:
              case 513:
              case 714:
              case 901:
              case 905:
              case 909:
              case 913:
              case 1305:
              case 1309:
                {
                  printf("%c",179);
                  color(0,9);    //bleu foncé
                  printf("%c ",grille[i][t]);
                  color(15,0);
                }
                break;
              default:
                  {
                  printf("%c",179);
                  color(15,0);
                  printf("%c ",grille[i][t]);
                  color(15,0);
                  }
                 break;

              }

      }
     printf("%c",179);
     printf("\n");

  }
  gotoxy(70,1+30);
     for(int j=0;j<15;j++)
      {
                if(j==0) printf("%c%c%c%c",192,196,196,193);
                 else
                 {
                     if(j!=14)  printf("%c%c%c",196,196,193);
                     else  printf("%c%c%c",196,196,217);
                 }
      }
          printf("\n");
}
/***************************************************** Fonctions de score *********************************************************************/
int ScoreOfLetter(char c)  // fonction qui retourne le score de chaque lettre
{
            if( c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'N' || c == 'R' || c == 'T' || c == 'L' || c == 'S' || c == 'U' ) return 1;
            else if( c == 'D' || c == 'G' || c == 'M') return 2;
            else if( c == 'B' || c == 'C'  || c == 'P' ) return 3;
            else if( c == 'F' || c == 'H' || c == 'V'   ) return 4;
            else if( c == 'J' || c == 'Q' ) return 8;
            else if( c == 'K' || c == 'W'|| c == 'X' || c == 'Y'|| c == 'Z') return 10;
            else if( c == '-' ) return 0;
            else return 0;
}
char *ScoreOfGrille(int p,int t) //on le donne les cordonnes de lettre dans la grille et elle nous retourne quel score
{

              int tp=p*100+t;
              switch(tp)
              {
              case 0:
              case 7:
              case 14:
              case 1400:
              case 1407:
              case 1414:
              case 700:
                {
                      return "TW";
                }
                break;
              case 101:
              case 202:
              case 303:
              case 404:
              case 1301:
              case 1202:
              case 1103:
              case 1004:
              case 113:
              case 212:
              case 311:
              case 410:
              case 1010:
              case 1111:
              case 1212:
              case 1313:
              case 707:
                {
                  return "DW";
                }
                break;
              case 300:
              case 1100:
              case 602:
              case 802:
              case 3:
              case 703:
              case 1403:
              case 206:
              case 606:
              case 806:
              case 1206:
              case 307:
              case 1107:
              case 208:
              case 1208:
              case 11:
              case 711:
              case 1411:
              case 612:
              case 812:
              case 314:
              case 1114:
              case 808:
              case 608:
                {
                   return "DL";
                }
                break;
              case 105:
              case 109:
              case 501:
              case 505:
              case 509:
              case 513:
              case 714:
              case 901:
              case 905:
              case 909:
              case 913:
              case 1305:
              case 1309:
                {
                   return "TL";
                }
                break;
              default:
                  {
                   return "__";
                  }
                 break;

              }


}
/******************************************* Fonctions de manipulation des chaines de caracteres *************************/
char*  SuppLetr (int i,char ch[]) // fonction qui supprime la lettre d'indice i dans un chaine de caractere
{
    int j=i;
    int nb=strlen(ch);
    while(j<nb)
     {
        ch[j]=ch[j+1];
         j++;
     }
     ch[j-1]='\0';
     return ch;
}
void  rechercheLettre(char title[],char c,int *i,int *stop)
{
    *i=0;
    *stop=0;
    while(((*i)<strlen(title))&&!(*stop))
    {
        if( title[*i]==c )
        {
            (*stop)=1;
        }
        (*i)++;
    }
}
/*********************************************************** Jeton et les lettres tirees *********************************/
void jeton(char jeton[104]) //fonction qui remplis le jeton ou bien sac des lettres
{

    int j=0;
    while(j<95)
    {
        if((j>=0)&&(j<15))
        {
            jeton[j]='E';
        }
        if((j>=15) && (j<24))
        {
            jeton[j]='A';
        }

        if((j>=24) && (j<32))
        {
            jeton[j]='I';
        }
        if(j>=32 && j<38)
        {
            jeton[j]='N';
        }
        if(j>=38 && j<44)
        {
            jeton[j]='O';
        }
        if(j>=44&&j<50)
        {
            jeton[j]='R';
        }
        if(j>=50&&j<56)
        {
            jeton[j]='S';
        }
        if(j>=56&&j<62)
        {
            jeton[j]='T';
        }
        if(j>=62&&j<68)
        {
            jeton[j]='U';
        }
        if(j>=68&&j<73)
        {
            jeton[j]='L';
        }
        if(j>=73&&j<76)
        {
            jeton[j]='D';
        }
        if(j>=76&&j<79)
        {
            jeton[j]='M';
        }
        if(j>=79&&j<81)
        {
            jeton[j]='G';
        }
        if(j>=81&&j<83)
        {
            jeton[j]='B';
        }
        if(j>=83&&j<85)
        {
            jeton[j]='C';
        }
        if(j>=85&&j<87)
        {
            jeton[j]='P';
        }
        if(j>=87 && j<89)
        {
            jeton[j]='F';
        }
        if(j>=89&&j<91)
        {
            jeton[j]='H';
        }
        if(j>=91&&j<93)
        {
            jeton[j]='V';
        }
        if(j>=93&&j<95)
        {
            jeton[j]='-';
        }

         j++;
    }
          if(j==95)
        {
            jeton[j]='J';
            j++;
            jeton[j]='Q';
            j++;
            jeton[j]='K';
            j++;
            jeton[j]='W';
            j++;
            jeton[j]='X';
            j++;
            jeton[j]='Y';
            j++;
            jeton[j]='Z';
            j++;
        }
   jeton[j]='\0';


}

void Title(char title[],char jeton[],int nb) //fonctin qui tiree nb caracteres d'une autre chaine de caractere
{
    int rnd;
    int i;
    srand(time(NULL));
    for( i=0;i<nb;i++)
    {
        rnd=rand() % strlen(jeton);
        title[i]=jeton[rnd];
        strcpy(jeton,SuppLetr(rnd,jeton));
    }
    title[i]='\0';
}
/****************************** Fonction qui permet de modifier la grille et l'affecte le mot a sa  place ********************************/
void PutMot(char grille[15][15],char mot[7],char mode,int ligne,int col,char title[15],int *score1,int *stop)
{
    int i,j=0,trv,score=0,TW=0,DW=0;
    char copTitle[8];
    sprintf(copTitle,"%s",title);
    *stop=0;
    if(mode=='H')
    {
              i=col;
              while((i<strlen(mot)+col)&&(!*stop))
              {
                  rechercheLettre(copTitle,mot[i-col],&j,&trv);
                  if(grille[ligne][i]!=' ' && grille[ligne][i]!= mot[i-col])
                    *stop=1;
                  if(grille[ligne][i]!= mot[i-col])
                  {
                      if(!trv)
                          *stop=1;
                      else
                          strcpy(copTitle,SuppLetr(j-1,copTitle));
                  }
                i++;
              }
              if(!*stop)
              {

                    strcpy(title,copTitle);
                    for(i=col ; i<strlen(mot)+col;i++)
                    {
                     if(strcmp(ScoreOfGrille(ligne,i),"DL")==0)
                     score=score+(ScoreOfLetter(mot[i-col])*2);
                     else if(strcmp(ScoreOfGrille(ligne,i),"TL")==0)
                     score=score+(ScoreOfLetter(mot[i-col])*3);
                     else  if((strcmp(ScoreOfGrille(ligne,i),"__")==0)||(strcmp(ScoreOfGrille(ligne,i),"DW")==0)||(strcmp(ScoreOfGrille(ligne,i),"TW")==0))
                     score=score+ScoreOfLetter(mot[i-col]);
                     if(strcmp(ScoreOfGrille(ligne,i),"DW")==0)
                      DW++;
                     if((strcmp(ScoreOfGrille(ligne,i),"TW")==0))
                      TW++;
                      grille[ligne][i]=mot[i-col];


                    }
                  if((TW!=0)||(DW!=0))
                       score=(score*(DW)*2)+(score*TW*3);
               }
    }
    if(mode=='V')
    {
           i=ligne;
           while((i<strlen(mot)+ligne)&&(!*stop))
           {
                  rechercheLettre(copTitle,mot[i-ligne],&j,&trv);
                  if(grille[i][col]!= mot[i-ligne] && grille[i][col]!= ' ')
                    *stop=1;
                  if(grille[i][col]!= mot[i-ligne])
                  {
                      if(!trv)
                          *stop=1;
                      else
                          strcpy(copTitle,SuppLetr(j-1,copTitle));
                  }
                  i++;
           }
           if(!*stop)
           {
               strcpy(title,copTitle);
               for(i=ligne ; i<strlen(mot)+ligne;i++)
               {
                    if(strcmp(ScoreOfGrille(i,col),"DL")==0)
                      score=score+(ScoreOfLetter(mot[i-ligne])*2);
                    else if(strcmp(ScoreOfGrille(i,col),"TL")==0)
                     score=score+(ScoreOfLetter(mot[i-ligne])*3);
                    else  if((strcmp(ScoreOfGrille(i,col),"__")==0)||(strcmp(ScoreOfGrille(i,col),"DW")==0)||(strcmp(ScoreOfGrille(i,col),"TW")==0))
                        score=score+ScoreOfLetter(mot[i-ligne]);
                    if(strcmp(ScoreOfGrille(i,col),"DW")==0)
                       DW++;
                    if(strcmp(ScoreOfGrille(i,col),"TW")==0)
                       TW++;
                    grille[i][col]=mot[i-ligne];
                }
                if((TW!=0)||(DW!=0))
                  score=(score*(DW)*2)+(score*TW*3);
           }
    }
    *score1=score;
    if(strlen(mot)==7 &&(!*stop))  //on verifie si le mot contient les 7 lettres de son title on ajoute au score 50 points
    {
        *score1=*score1+50;
    }
}


void tp_presentation(void) // Cette fonction imprime le splashscreen du tp
{
    color(6,0);
    printf("\n\n\n\n\n\n\n");
    color(15,0);

    printf("\n\t\t\t  _______   ______   _______   _______   _______   _      _      ______");
    printf("\n\t\t\t |  _____| |  ____| |  ___  | |  ___  | |  ___  | | |    | |    |  ____|");
    printf("\n\t\t\t | |_____  | |      | |___| | | |___| | | |___| | | |    | |    | |____");
    printf("\n\t\t\t |_____  | | |      |  ___  / |  ___  | |  ___  / | |    | |    |  ____|");
    printf("\n\t\t\t  _____| | | |____  | |   | | | |   | | | |___| | | |____| |____| |____");
    printf("\n\t\t\t |_______| |______| |_|   |_| |_|   |_| |_______| |______|______|______|");
    printf("\n\n\t\t\t     Annee Universitaire 2020-2021 | Semestre 2");
    color(10,0);
    printf("\n\t       __");
    printf("\n\t   _  |@@|");
    printf("\n\t  / | |--| __  ");
    printf("\n\t  ) O|----|  [=====================");
    printf("\n\t / / | }{ |  | Realise par: ");
    printf("\n\t )/  | __ |  |    Saadallah ");
    printf("\n\t|/  (--)(--) |    Roufida   ");
    printf("\n\t/   _)(  )(_ |              ");
    printf("\n\t   `---''---`[=====================");
    color(14,0);
    printf("\n\n\nAppuyez sur [ENTREE] pour continuer...");
    getchar();
    color(15,0);
    system("cls");

}
void menu()
{
    gotoxy(50,2);
    color(0,11);
    printf("   MENU  ");
    color(15,0);
    gotoxy(45,5);
    printf(" 1 -  DEUX PLAYERS \n");
    gotoxy(45,8);
    printf(" 2 -  TROIS PLAYERS \n");
    gotoxy(45,11);
    printf(" 3 -  QUATRE PLAYERS \n");
    gotoxy(45,14);
    printf(" 0 -  QUITTER \n");

    gotoxy(45,18);
    color(11,0);
        printf("\t.--.");
       gotoxy(45,19);
        printf("\t|__| .--------.");
        gotoxy(45,20);
        printf("\t|=.| |.------.|");
        gotoxy(45,21);
        printf("\t|--| ||      ||");
        gotoxy(45,22);
        printf("\t|  | |'------'|");
        gotoxy(45,23);
        printf("\t|__|~')______('");
        color(15,0);
        gotoxy(57,21);
}
void Affichage(int choix,char grille[15][15],int score1,int score2,int score3,int score4)
{
    system("cls");
    Remplir_joueur(1,score1);
    Remplir_joueur(2,score2);
    if(choix==2)
    {
          Remplir_joueur(3,score3);
    }
    if(choix==3)
    {
     Remplir_joueur(3,score3);
     Remplir_joueur(4,score4);
    }
        Remplir_Grille(grille);
}
void  PLayerI(int p,int cptMot,char title[], char mot[15],char *D,int *i,int *j,int *Pass)
{
    char end;    // pour le saute de ligne
    int rechmot; //si le mot existe
    int bol=0;
    int bolCentre=0; //pour verifier le centre
    gotoxy(23,4+13*p);
    printf("%s",title);
    strcpy(mot," ");
    *Pass=0;
    (*D)=' ';
    do
    {
         gotoxy(23,6+13*p);
         printf("*******");
         gotoxy(23,6+13*p);
         scanf("%s",mot);
         rechmot=rechercheMot(Dictionnaire,mot);
        if(strlen(mot)<2 || !rechmot)
        {
            gotoxy(43,6+13*p);
            printf(" CE N'est pas mot");
        }
        if(strcmp(mot,"Passer")==0)
        {
             *Pass=1;
             goto fin;
        }

    }while((strlen(mot)<2 )|| (!rechmot));

    gotoxy(43,6+13*p);
    printf("                 ");
    scanf ("%c", &end);
    do
    {
        gotoxy(23,8+13*p);
        printf("                 ");
        if(end=='\n')
        {
            gotoxy(23,8+13*p);
            scanf("%c",&*D);
        }
        scanf("%c",&end);
        if((*D!='H')&&(*D!='V'))
        {
            gotoxy(42,8+13*p);
            printf(" h ou d");
        }
    }while((*D!='H')&&(*D!='V'));
            gotoxy(42,8+13*p);
            printf("       \n");
    bol=0;
    do
    {
        gotoxy(26,10+13*p);
        printf("  ");
        gotoxy(36,10+13*p);
        printf("  ");
        gotoxy(26,10+13*p);
        scanf("%d",&(*i));
        gotoxy(36,10+13*p);
        scanf("%d",&(*j));
        if(*D=='H')
        {
            if(cptMot==0)
            {

                if(*i==7 )
                {
                    if (*j<7 )
                    {
                          if(*j+strlen(mot)-1>=7)
                           bolCentre=1;
                    }
                    else
                    {
                        if(*j==7)
                        {
                               bolCentre=1;
                        }
                    }
                }
            }
            else
                bolCentre=1;
            if(*j+strlen(mot)-1<15)
                bol=1;
            else
                bol=0;
        }
        if(*D=='V')
        {
            if(cptMot==0)
            {
                if(*j==7 )
                {
                    if (*i<7 )
                    {
                        if(*i+strlen(mot)-1>=7)
                            bolCentre=1;
                    }
                    else
                    {
                        if(*i==7)
                        {
                               bolCentre=1;
                        }
                    }
                }
            }
            else
                bolCentre=1;
            if(*i+strlen(mot)-1<15)
                bol=1;
            else
                bol=0;
        }
    }while(bol==0 || bolCentre==0);
 fin:
     if(*Pass==1)
        strcpy(mot," ");
}

int main()
{
    char grille[15][15];
    char mot[8];
    int Pass;
    int score;
    char title1[8];
    char title2[8];
    char title3[8];
    char title4[8];
    char rep1[8];
    char rep2[8];
    char rep3[8];
    char rep4[8];
    char jt[103];
    int rechmot;
    char D;
    int cptMot=0;
    int bol=0;
    int bolCentre=1;
    jeton(jt);
    Title(title1,jt,7);
    Title(title2,jt,7);
    int score1=0,score2=0,score3=0,score4=0,scr=0,i,j,stop;

    for(int k=0;k<15;k++)
     {
      for(int p=0;p<15;p++)
        grille[k][p]=' ';
     }
    tp_presentation();
        gotoxy(45,16);
    printf("ENTRER VOTRE CHOIX ");
menu:    menu();
    int choix;
    scanf("%d",&choix);
    if(choix==0)
        return 0;
    if (choix!=1 && choix !=2 && choix!=3 && choix!=0)
    {
      gotoxy(45,16);
      printf("SVP ENTRER UN AUTRE CHOIX ");
      goto menu;
    }
    if(choix==2)
    {
          Title(title3,jt,7);
    }
    if(choix==3)
    {
        Title(title3,jt,7);
        Title(title4,jt,7);
    }

Pass=0;
player1:
    Affichage(choix,grille,score1,score2,score3,score4);
    PLayerI(0,cptMot,title1,mot,&D,&i,&j,&Pass);
    gotoxy(5,50);
    if(Pass==1)
     goto player2;
    PutMot(grille,mot,D,i,j,title1,&score,&stop);
    if(strlen(title1)<7)
    {
        Title(rep1,jt,7-strlen(title1));
        strcat(title1,rep1);
    }
    if(stop)
    {
        gotoxy(43,6);
        printf("n'appartient pas au title\n");
        gotoxy(5,15+13*choix);
        system("pause");
        goto player1;
    }
    cptMot++;
    score1=score1+score;
     goto player2;
player2:
    Affichage(choix,grille,score1,score2,score3,score4);
   PLayerI(1,cptMot,title2,mot,&D,&i,&j,&Pass);
   if(Pass==1)
   {
       if(choix==2||choix==3)
        goto player3;
       else
       goto player1;
   }

    PutMot(grille,mot,D,i,j,title2,&score,&stop);
    if(strlen(title2)<7)
    {
        Title(rep2,jt,7-strlen(title2));
        strcat(title2,rep2);
    }
    if(stop)
    {
        gotoxy(43,6+13);
        printf("n'appartient pas au title\n");
        gotoxy(5,15+13*choix);
        system("pause");
        goto player2;
    }
    cptMot++;
    score2=score2+score;
    goto player1;
player3:
    Affichage(choix,grille,score1,score2,score3,score4);
   PLayerI(2,cptMot,title3,mot,&D,&i,&j,&Pass);
   if(Pass==1)
   {
       if(choix==3)
         goto player4;
       else
       goto player1;
   }

    PutMot(grille,mot,D,i,j,title3,&score,&stop);
    if(strlen(title3)<7)
    {
        Title(rep3,jt,7-strlen(title3));
        strcat(title3,rep3);
    }
    if(stop)
    {
        gotoxy(43,6+13*2);
        printf("n'appartient pas au title\n");
        gotoxy(5,15+13*choix);
        system("pause");
        goto player3;
    }
    cptMot++;
    score3=score3+score;
player4:
    Affichage(choix,grille,score1,score2,score3,score4);
   PLayerI(3,cptMot,title4,mot,&D,&i,&j,&Pass);
   if(Pass==1)
   {
       goto player1;
   }

    PutMot(grille,mot,D,i,j,title4,&score,&stop);
    if(strlen(title4)<7)
    {
        Title(rep4,jt,7-strlen(title4));
        strcat(title4,rep4);
    }
    if(stop)
    {
        gotoxy(43,6+13*3);
        printf("n'appartient pas au title\n");
        gotoxy(5,15+13*choix);
        system("pause");
        goto player4;
    }
    cptMot++;
    score4=score4+score;
}
