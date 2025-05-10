#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud{
 int valeur;
 struct Noeud *next;
}Noeud;

typedef Noeud *liste;
liste head =NULL; //creation d'une liste vide

liste cree(int _valeur){
liste NewE=(liste)malloc(sizeof(Noeud));
 if(NewE==NULL)
printf("echec d'allocation\n");
 else {
    NewE->valeur=_valeur;
    NewE->next=NULL;
 }
return NewE;
}

void affiche(liste head){
if(head==NULL)
printf("la liste est vide\n");
else{

    liste temp=head;
    while(temp!=NULL){
      
		printf("%d \n",temp->valeur);
		temp= temp->next;
	}
    }
}

liste ajoutD(liste head, int _valeur){
 liste NewE=cree(_valeur);
 if(NewE==NULL)
 printf("allocation introuvable\n");
 else{
    NewE->valeur=_valeur;
    NewE->next=NULL;
 }
 return NewE;
}

liste ajoutF(liste head, int _valeur){
    liste NewE=cree(_valeur);
    if(NewE!=NULL){
  liste temp=head;
  while(temp->next!=NULL)
  temp=temp->next;
  temp->next=NewE; // on doit pas faire apres NewE=_valeur?
    }
   
    return head;
   }
int taille(liste head){
int c=0;
liste temp=head;
while(temp!=NULL){
    ++c;
temp=temp->next;
}
return c;
}

liste insert(liste head,int pos,int _valeur){

    if(pos <1 || pos > taiile(head)+1)
    printf("position introuvable\n");
    else if (pos == 1)
     head=ajoutD(head,_valeur);
     liste NewE=cree(_valeur);
     if(NewE==NULL)
     return head;
     liste temp=head;
     for(int i=1;i<pos-1;i++){ //?pourquoi i?
     temp=temp->next;
     NewE->next=temp->next;
     temp->next=NewE; 

     }
     return head;
     }
 
     void rechercher(liste head,int _valeur){
      if(head==NULL)
      pritnf("la liste est vide\n");
      else{
        liste temp=head;
        while(temp!=NULL && temp->valeur!=_valeur)
         temp=temp->next;
         if(temp==NULL)
         printf("%d est introuvable\n",_valeur);
         if(temp->valeur==_valeur)
         printf("%d est trouvee",_valeur);

      }
     }

    

     liste suppressionD(liste head){
    if(head == NULL){
        printf("Liste vide\n");
        return NULL;
    }
    liste temp = head;
    head = head->next;
    free(temp);
    return head;
}

liste suppresioonF(liste head){
    if(head == NULL){
        printf("Liste vide\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    liste temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

liste suppressionP(liste head, int pos){
    if(pos < 1 || pos > taille(head)){
        printf("Position invalide\n");
        return head;
    }
    if(pos == 1)
        return suppressionD(head);

    liste temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    liste ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);

    return head;
}

void modifierD(liste head, int _Valeur){
    if(head != NULL)
        head->valeur = _Valeur;
}

void modifierF(liste head, int _Valeur){
    if(head == NULL)
        return;
    liste temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->valeur = _Valeur;
}

void modifierP(liste head, int pos, int _Valeur){
    if(pos < 1 || pos > taille(head)){
        printf("Position invalide\n");
        return;
    }
    liste temp = head;
    for(int i = 1; i < pos; i++)
        temp = temp->next;
    temp->valeur = _Valeur;
}

int main() {
    liste head = NULL;

    head = ajoutF(head, 10);
    head = ajoutF(head, 20);
    head = ajoutF(head, 30);
    printf("Liste initiale:\n");
    affiche(head);

    head = ajoutD(head, 5);
    printf("Après ajout début:\n");
    affiche(head);

    head = ajoutF(head, 40);
    printf("Après ajout fin:\n");
    affiche(head);

    head = insert(head, 3, 15);
    printf("Après insertion position 3:\n");
    affiche(head);

    head = suppD(head);
    printf("Après suppression début:\n");
    affiche(head);

    head = suppF(head);
    printf("Après suppression fin:\n");
    affiche(head);

    head = suppPos(head, 2);
    printf("Après suppression position 2:\n");
    affiche(head);

    modifierDebut(head, 100);
    printf("Après modification début:\n");
    affiche(head);

    modifierFin(head, 200);
    printf("Après modification fin:\n");
    affiche(head);

    modifierPos(head, 2, 150);
    printf("Après modification position 2:\n");
    affiche(head);

    printf("Recherche de 150:\n");
    rechercher(head, 150);

    printf("Recherche de 999:\n");
    rechercher(head, 999);

    return 0;
}

