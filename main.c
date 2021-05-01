#include <stdio.h>
#include <stdlib.h>

FILE *f,*g;

struct studenti
{
    char prenume[15],nume[15],materie[15];
    int clasa,nota;
};


struct node
{
    int data;
    struct node *next;
    struct node *prev;
};


void append(struct node *head, int val)
{
    struct node *nou,*p;
    nou=(struct node*)malloc(sizeof(struct node));
    p=(struct node*)malloc(sizeof(struct node));
    if(head->next==NULL)
    {
        head->next=nou;
        nou->prev=nou;
        nou->next=NULL;
        nou->data=val;
    }

}


void afisare ( struct node *nod)
{
    while(nod!=NULL)
    {
        printf("Valoarea e %d,  inainte e %d   si dupa e %d\n",nod->data,nod->prev,nod->next);
        nod=nod->next;
    }
}



int main()
{
    int n=1,i,j;
    char c;
    if((f=fopen("studenti.txt","r"))==NULL)
    {
    	printf("Eroare\n");
	}
    if((g=fopen("promovati.txt","w"))==NULL)
    {
    	printf("Eroare\n");
	}

	struct studenti stud[100];
	for(i=0;i<10;i++)
    {
        if(feof(f)==NULL)
        {
            fscanf(f,"%s %s %d %s %d",stud[i].prenume,stud[i].nume,&stud[i].clasa,stud[i].materie,&stud[i].nota);
            printf("%s %s %d %s %d\n",stud[i].prenume,stud[i].nume,stud[i].clasa,stud[i].materie,stud[i].nota);
        }
    }
    printf("\n");
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));                 //aici incercam sa invat sa folosesc o lista dublu inlantuita cu valori intregi
    head->data=10;
    head->prev=NULL;
    head->next=NULL;
    append(head,1);
    afisare(head);
    printf("\n");
    for(i=0;i<10;i++)
        printf("%s %s din clasa a %d-a, nota la materia %s este %d\n",stud[i].nume, stud[i].prenume,stud[i].clasa,stud[i].materie,stud[i].nota);
    printf("\n");
    for(i=0;i<10;i++)
    {
        if(strcmp(stud[i].nume,stud[i+1].nume)!=0 && stud[i].nota>5)
        {
            fprintf(g,"%s %d\n", stud[i].nume, stud[i].nota);
        }
    }
    fclose(f);
    return 0;
}
 // ce am facut eu a fost sa incerc sa combin lucrurile pe care le-am facut la curs, respectiv laborator
