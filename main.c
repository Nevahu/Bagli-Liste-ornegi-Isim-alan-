#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct persanel
{
    char adi[21];
    struct personel *sonraki;
};

typedef struct personel dugum;
dugum *head, *oncekiDugum, *yeni, *silinecek;


void ara(char *aranan)
{
    dugum *p;
    p =head;
    oncekiDugum = head;
    while(p-> sonraki != NULL)
    {
        p= p->sonraki;
        if(strcmp(p ->adi, aranan ) >= 0)
            break;
        oncekiDugum = p;
    }
}


void ekle(char *s)
{
    yeni = (dugum*) malloc(sizeof(dugum));
    strcpy(yeni->adi, s);
    ara(yeni->adi);
    yeni-> sonraki = oncekiDugum-> sonraki;
    oncekiDugum-> sonraki = yeni;
}

void sil (char *s)
{
    ara(s);
    silinecek= oncekiDugum -> sonraki;
    oncekiDugum-> sonraki = silinecek ->sonraki;
    free(silinecek);
}

void listeleme(void)
{
    dugum *p;
    p = head;
    p = p->sonraki;
    while(p!= NULL)
    {
        printf("%s  \n", p->adi);
        p= p->sonraki;
    }
}

void enUzunBul(void)
{
    dugum *p, *enuzun;
    p = head;
    p= p->sonraki;
    enuzun= p;
    while(p != NULL)
    {
        if(strlen(p->adi) >= strlen(enuzun->adi)
           {
               enuzun= p;
           }
           p = p-> sonraki;
    }

    printf("\n En Uzun: %s  Uzunluk:%d", enuzun->adi, strlen(enuzun->adi));

}


int main()
{
   char sec;
   char s[21];
   head = (dugum*)malloc (sizeof(dugum));
   strcpy(head->adi, "Listenin basi");
   head -> sonraki =NULL;
   while(1)
   {
       listele();
       printf("\n\n 1- Ekle\n 2- Sil\n 3- En Uzun Isim\n 4- Cikis\n\nSec: ");
       sec = getchar();
       switch(sec)
       {
       case '1':
        printf("\nAdi: ");
        gets(s);
        ekle(s);
        break;
       case '2':
        printf("\nAdi: ");
        gets(s);
        sil(s);
        break;
       case '3':
        enUzunBul();
        break;
       case '4':
        exit(0);
        break;
       }
   }
    return 0;
}
