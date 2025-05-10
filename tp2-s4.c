#include <stdio.h>
#include <stdlib.h>

typedef struct date{
    char jour[3];
    char mois[3];
    char annee[5];

}date;
typedef struct produit{
    char *nom_produit;
    char reference[100];
    float montant;
    date DateAchat;
}produit;

typedef struct liste{
    produit cellule;
    struct liste*next
}liste;

typedef liste* list;
return (head = NULL);

list cree_list_produit(){
    return NULL;
}

int est_vide(list head){
    if(head==NULL) 
        return 1;
  else 
  return 0;
}
list cree_produit(){
    list newL = (list)malloc(sizeof(liste));
    if(newL==NULL)
    printf("echec d'allocation\n");

     else{
        printf("Nom du produit\n");
        scanf("%s",newL->cellule.nom_produit);
        printf("reference\n");
        scanf("%s",newL->cellule.reference);
        printf("montant\n");
        scanf("%f",newL->cellule.montant);
        printf("DateAchat\n");
        printf("jour\n");
        scanf("%s",newL->cellule.DateAchat.jour);
        printf("mois\n");
        scanf("%s",newL->cellule.DateAchat.mois);
        printf("annee\n");
        scanf("%s",newL->cellule.DateAchat.annee);
     }
    
    return newL;
}

void afficher_produit(list produit){
    if(produit==NULL)
    printf("produit inexistant\n.");
 else {
    printf("Nom: %s, Reference : %s, Montant : %.2f, Date Achat : %s/%s/%s\n",produit->cellule.nom_produit,
         produit->cellule.reference, produit->cellule.montant, produit->cellule.DateAchat.jour, 
         produit->cellule.DateAchat.mois, produit->cellule.DateAchat.annee );
 }

}

list ajouterD(list head){

    list newProduit = cree_list_produit();
 
 if (newProduit!=NULL)
 {
    newProduit->next=head;
 }

return newProduit;
}

list ajouterF(list head){

 list newProduit = cree_list_produit();
 if(newProduit!=NULL)
 list temp=head;
 while(temp->next!=NULL)
 temp=temp->next;

return newProduit;
}
void afficher_produits(list tete) 
{ 
    if (est_vide(tete)) // Vérifie si la liste est vide 
    { 
        printf("La liste est vide.\n"); 
    } 
    else 
    { 
        list temp = tete; 
        // Parcourt et affiche chaque produit 
        while (temp != NULL) 
        { 
            afficher_produit(temp); 
            temp = temp->psuiv
        } 
    } 
} 
 
int longueur(list tete) 
{ 
    int count = 0;
    while (tete != NULL) 
    { 
        count++; 
        tete = tete->psuiv; 
    } 
    return count;
} 
 

void filtrer_date(list tete, date dt) 
{ 
    list temp = tete; 
    while (temp != NULL) 
    { 
         
        if (strcmp(temp->cellule.DateAchat.jour, dt.jour) == 0 && 
            strcmp(temp->cellule.DateAchat.mois, dt.mois) == 0 && 
            strcmp(temp->cellule.DateAchat.annee, dt.annee) == 0) 
        { 
            afficher_produit(temp); // Affiche si la date correspond 
        } 
        temp = temp->psuiv; 
    } 
} 
 

list supprimer_debut(list tete) 
{ 
    if (est_vide(tete)) 
        return NULL; 
 
    list temp = tete; 
    tete = tete->psuiv;  
    free(temp);          
    return tete;         
} 
 
void supprimer_fin(list tete) 
{ 
    if (est_vide(tete))
        printf("La liste est vide.\n"); 
 
    if (tete->psuiv == NULL) // Cas ou il n'y a qu'un seul élément 
    { 
        free(tete);  
        tete = NULL; 
    } 
    else 
    { 
        list temp = tete; 
        list prev = NULL; 
        // Parcourt jusqu'à l'avant-dernier élément 
        while (temp->psuiv != NULL) 
        { 
            prev = temp; 
            temp = temp->psuiv; 
        } 
        prev->psuiv = NULL; 
        free(temp);         
    } }

    / Fonction pour supprimer un produit par sa référence 
list rembourser(liste *tete, char *refer) 
{ 
    if (est_vide(tete)) 
        return NULL; 
 

    if (strcmp(tete->cellule.Reference, refer) == 0) 
    { 
        return supprimer_debut(tete); 
    } 
 
    list temp = tete; 
    list prev = NULL; 
    
    while (temp != NULL && strcmp(temp->cellule.Reference, refer) != 0) 
    { 
        prev = temp; 
        temp = temp->psuiv; 
    } 
 
    if (temp == NULL) 
    { 
        printf("Produit non trouvé.\n"); 
        return tete; 
    } 
 
    if (temp->psuiv == NULL)
    { 
        supprimer_fin(tete); 
    } 
    else 
    { 
        prev->psuiv = temp->psuiv; 
        free(temp);               
    } 
 
    return tete; 
} 
 

int main() 
{ 
    list stock = creer_liste_produits(); 
    int choix; 
    char refer[100]; 
    date dt; 
 
    do \ 
    { 
              
               printf("\nMenu :\n"); 
               printf("1. Ajouter un produit au début\n"); 
               printf("2. Ajouter un produit à la fin\n"); 
               printf("3. Afficher tous les produits\n"); 
               printf("4. Supprimer le premier produit\n"); 
               printf("5. Supprimer le dernier produit\n"); 
               printf("6. Supprimer un produit par référence\n"); 
               printf("7. Afficher les produits achetés à une date\n"); 
               printf("8. Quitter\n"); 
               printf("Choix : "); 
               scanf("%d", &choix); 
        
               switch (choix) 
               { 
               case 1: 
                   stock = ajouter_debut(stock); 
                   break; 
               case 2: 
                   ajouter_fin(stock); 
                   break; 
               case 3: 
                   afficher_produits(stock); 
                   break; 
               case 4: 
                   stock = supprimer_debut(stock); 
                   break; 
               case 5: 
                   supprimer_fin(stock); 
                   break; 
               case 6: 
                   printf("Entrez la référence du produit à supprimer : "); 
                   scanf("%s", refer); 
                   stock = rembourser(stock, refer); 
                   break; 
               case 7: 
                   printf("Entrez la date (JJ MM AAAA) : "); 
                   scanf("%s %s %s", dt.jour, dt.mois, dt.annee); 
                   filtrer_date(stock, dt); 
                   break; 
               case 8: 
                   printf("Programme terminé.\n"); 
                   break; 
               default: 
                   printf("Choix invalide, réessayez.\n"); 
               } 
           } while (choix != 8); 
        
           return 0; 
       } 