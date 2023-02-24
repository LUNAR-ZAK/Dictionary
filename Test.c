#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//the list of pages
typedef struct page *liste ;

typedef struct page
{
int number;
liste next;
}composant;

typedef struct node *arbre ;
struct node{
char data[42];
liste pages;
struct node *left;
struct node *right;

};
int count=0;
//(1)-(2)
// ajouter un element dans la liste au debut

//pour parcourir la liste des pages
void parcoursList(liste a)
{
liste pCourant;
liste Tete;
Tete = a;
if (Tete != NULL)
    {
      pCourant = Tete;
printf("\t\t\t\n\n");
        while (pCourant != NULL)
        {
          printf("%d --> ",pCourant->number );
                    pCourant = pCourant->next;
        }

    }
}


liste insere(int element, liste Q) {

  liste L;
      L = (liste)malloc(sizeof(composant));
      L->number = element;
      L->next = Q ;
      return(L);

}
/**<  ajouter des fils et liste et mot pour une node */
arbre insTree(char value[],arbre noud,arbre nd,liste l)
{

  arbre Node = malloc(sizeof(struct node));
  strcpy(Node->data,value);
  Node->left = noud;
  Node->right = nd;
  Node->pages = l;
  return(Node);
}


arbre constree()
{
 arbre Head;
 Head=insTree("process",insTree("ram",NULL,NULL,insere(2,insere(14,NULL))),insTree("memoire",NULL,NULL,insere(1,insere(6,insere(21,NULL)))),insere(1,insere(10,insere(13,NULL))));
 return (Head);
}



/**<  initialisation d’une feuille */
arbre initnode(char ch[],liste l){
    arbre NewNode=malloc(sizeof(struct node));
    strcpy(NewNode->data,ch);
    NewNode->left=NULL;
    NewNode->right=NULL;
    NewNode->pages=l;
    return(NewNode);
}

//ajouter la liste des pages

liste addpage()
{
	liste liste,p,q;
	int n,tmp,i,j;
	printf("combien de pages a ajouter ? :..  ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
{
	printf("quelle page vous voulez ajouter ? .. \n" );
	p = (struct page *)malloc(sizeof(struct page));
	scanf("%d",&(*p).number);
	if(i==0) liste=p;
	else{
	(*q).next=p;
	(*p).next=NULL;
	}
	q=p;
}
for(i=0;i<n-1;i++)
{
	for(j=0,p=liste;j<n-1-i;j++)
	{
		 q=(*p).next;
		 if((*p).number>(*q).number)
		 {
				tmp=(*p).number;
				(*p).number=(*q).number;
				(*q).number=tmp;
		 }
		 p=q;
	}
}
p=liste;
return p;

}

struct node *insert(struct node *root,char ar[42]){
    liste l;
    liste liste,p,q;
    int n,tmp,i,j;

if(root==NULL){

    root=(struct node *)malloc(sizeof(struct node));
        printf("\t\t\t " );
    strcpy(root->data,ar);

		root->pages=addpage();
    root->left=NULL;
    root->right=NULL;


    return root;
}
else{

    printf("\t\t\tdo you want this under %s\n?(y/n):",root->data);
        printf("\t\t\t " );
    getchar();
    char ans;
        printf("\t\t\t");
    scanf("%c",&ans);
    printf("\t\t\t");
    if(ans=='y'){

            if(root->left!=NULL & root->right==NULL){

                root->right = insert(root->right,ar);


                //printf("%s ->right is %s\n",root->data,root->right->data);
            }
            else if(root->left==NULL){

        root->left = insert(root->left,ar);
        //printf("%s ->left is %s\n",root->data,root->left->data);
            }
            else{
                   if(insert(root->left,ar)!=NULL)
									 {

                   }
                   else
                    insert(root->right,ar);
            }

    }

    else{

        return NULL;
    }
}


//printf("ROOT IS %s\n",root->data);
return root;
}

//(3)
typedef struct element element;
struct element{
    arbre info;
    element *suiv;
};

typedef struct file file;
struct file {
    element *tete,*queue;
};

void initFile(file* f){
    f->tete = NULL;
    f->queue = NULL;
}

void Enfiler(file* f,arbre x){
    element *nouv = (element *)malloc(sizeof(element));
    nouv->info = x;
    nouv->suiv = NULL;
    if(f->queue == NULL){
        f->tete = nouv;f->queue = nouv;
    }
    else{
        f->queue->suiv = nouv;
        f->queue = nouv;
    }
}

arbre Defiler(file* f){
    arbre x;
    element *temp;
    x = f->tete->info;
    temp = f->tete;
    f->tete = f->tete->suiv;
    free(temp);
    return x;
}

bool filevide(file* f){
    if(f->tete == NULL)
        return true;
    else
        return false;
}

void parcours(arbre A){
    file f;
    liste p ;
    arbre b;
    initFile(&f);
    Enfiler(&f,A);
   while (!filevide(&f)){
        b=Defiler(&f);
        printf("%s  [",b->data);
        p=b->pages;
        while (p!=NULL){
        printf("%d;",p->number);
        p=p->next;
        }
        printf("]\n");
        if(filevide(&f)){
            initFile(&f);
        }
          if(b->right!=NULL){
            Enfiler(&f,b->right);
          }
          if(b->left!=NULL){
            Enfiler(&f,b->left);
          }
   }
}

//4

void inorder(struct node *root,int count){



if(root==NULL)
    return;
printf("\n\t\t\t le fils gauche   ---   le fils droit \n");
printf("\n\t\t\t%s -> %s   ---  %s-> %s\n",root->data,root->left->data,root->data,root->right->data);
printf("\n\n\t\t\t le mot existe dans ces pages : \n" );
parcoursList(root->pages);
inorder(root->left,count);
    printf("\t\t\t " );
count++;
inorder(root->right,count);
    printf("\t\t\t " );
}

//5

void searchTree(arbre root, char* word,int niveau)
{
  if (root == NULL) {
    return;
  } else if (strcmp(word, root->data) == 0) {
    printf("\t\t\t mot trouvee : %s dans le niveau : %d \n", root->data,niveau);
		printf("\t\t\t et les pages sont : \n" );
				parcoursList(root->pages);
  }

    searchTree(root->left, word,niveau+1);
    searchTree(root->right, word,niveau+1);
  }

	void insert_sorted(liste head, int data) {
	  // Création d'un nouveau noeud contenant la donnée à ajouter
	  liste new_node = (liste)malloc(sizeof(composant));
	  new_node->number = data;

	  // Cas où la liste est vide ou que le nouveau noeud doit être inséré au début
	  if (head == NULL || head->number >= new_node->number) {
	    new_node->next = head;
	    head = new_node;
	  } else {
	    // Recherche de la position où insérer le nouveau noeud
	    liste current = head;
	    while (current->next != NULL && current->next->number < new_node->number) {
	      current = current->next;
	    }
	    // Insertion du nouveau noeud
	    new_node->next = current->next;
	    current->next = new_node;
	  }

	}

//6
void SearchAndAddPage(struct node *noeud, char *data) {
	int x;
  if (noeud == NULL)
  {
    printf("Mot non trouvé ... \n" );
    return;
  } // Le noeud n'a pas été trouvé

  // Si le noeud courant est égal à la valeur recherchée, ajouter une page dans le mot
  if (strcmp(noeud->data, data) == 0) {
printf("donnez le numero pour ajouter dans la liste : ... \n" );
scanf("%d\n",&x );
		insert_sorted(noeud->pages,x);



    return;
  }

  // Rechercher dans l'arbre gauche et droit
  SearchAndAddPage(noeud->left, data);
  SearchAndAddPage(noeud->right, data);
}

//7
void delete(int val, struct page *head) {
    struct page *curr = head;
    struct page *prev = NULL;

    while (curr != NULL && curr->number < val) {
        prev = curr;
        curr = curr->next;

    }

    // Cas où l'élément à supprimer n'est pas dans la liste
    if (curr == NULL || curr->number != val) {

        return;
    }

    // Cas où l'élément à supprimer est le premier de la liste
    if (prev == NULL) {
        head = curr->next;

    } else {
        prev->next = curr->next;

    }

}
void SearchAndRemovePage(struct node *noeud, char *data) {
  if (noeud == NULL)
  {
    printf("Mot non trouvé ... \n" );
    return;
  } // Le noeud n'a pas été trouvé

  // Si le noeud courant est égal à la valeur recherchée, ajouter une page dans le mot
  if (strcmp(noeud->data, data) == 0) {
int x;
printf("donnez le numero a supprimer  :.. \n" );
		printf("entrez 00 pour retourner au menu .. \n");
      scanf("%d\n",&x );
		printf("entrez 00 pour retourner au menu .. \n");
		delete(x,noeud->pages);


    return;
  }

  // Rechercher dans l'arbre gauche et droit
  SearchAndRemovePage(noeud->left, data);
  SearchAndRemovePage(noeud->right, data);
}




int count_leaves_recursive(arbre root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return count_leaves_recursive(root->left) + count_leaves_recursive(root->right);
}




//2-1


typedef struct BinarySearchTree {
 struct node* root;
} BinarySearchTree;

void insertNode(struct node** root, char* data,liste pages) {
  if (*root == NULL) {
    *root =(struct node*)malloc(sizeof(struct node));
    strcpy((*root)->data,data);
    (*root)->pages = pages;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else {
    int cmp = strcmp((*root)->data, data);
    if (cmp > 0) {
      insertNode(&(*root)->left, data,pages);
    } else if (cmp < 0) {
      insertNode(&(*root)->right, data,pages);
    } else {
      // data already exists in the tree, do nothing
    }
  }
}

BinarySearchTree* convertToBST(struct node* root) {
  if (root == NULL) {
    return NULL;
  }
  BinarySearchTree* bst = malloc(sizeof(BinarySearchTree));
  bst->root = NULL;
  insertNode(&bst->root, root->data,root->pages);
  BinarySearchTree* left = convertToBST(root->left);
  if (left != NULL) {
    struct node* curr = left->root;
    while (curr != NULL) {
      insertNode(&bst->root, curr->data,curr->pages);
      curr = curr->right;
    }
  }
  BinarySearchTree* right = convertToBST(root->right);
  if (right != NULL) {
    struct node* curr = right->root;
    while (curr != NULL) {
      insertNode(&bst->root, curr->data,curr->pages);
      curr = curr->right;
    }
  }
  return bst;
}

//2-2
void printInOrder(struct node *root) {
  liste p ;
  if (root == NULL) return;
  printInOrder(root->left);
  printf(" %s : [ ", root->data);
        p=root->pages;
        while (p!=NULL){
        printf(" %d ; ",p->number);
        p=p->next;
        }
    printf(" ] -> ");
  printInOrder(root->right);


}

//2-3
void rechercher_noeud(struct node *root, char *data, int niveau) {
  if (root == NULL) return; // Le noeud n'a pas été trouvé

  // Si le noeud courant est égal à la valeur recherchée, afficher le mot et le niveau
  if (strcmp(root->data, data) == 0) {
    printf("\t\t\t Mot trouvé : %s (niveau : %d) \n", data, niveau);
    return;
  }else if(strcmp(root->data, data) < 0)
  rechercher_noeud(root->left, data, niveau + 1);
  else {
  rechercher_noeud(root->right, data, niveau + 1);
}
}


//2-4
// Fonction pour créer un nouveau noeud
struct node* createNode(char *data) {
  struct node *newNode = malloc(sizeof(struct node));
      strcpy(newNode->data,data);
  newNode->pages=addpage();
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Fonction pour ajouter un élément à l'arbre
void addNode(struct node **root, char *data) {
  int x;
  // Si l'arbre est vide, créez un nouveau noeud et retournez-le
  if (*root == NULL) {
    *root = createNode(data);
    return;
  }
  if (strcmp(data, (*root)->data) == 0)
  {
    printf(" quelle page vous voulez ajouter ? : ..\n" );
    scanf("%d\n",x );
    insert_sorted((*root)->pages,x);

  }
  // Si la valeur à ajouter est inférieure à celle du noeud actuel, ajoutez-la à la gauche
  if (strcmp(data, (*root)->data) < 0) {
    addNode(&(*root)->left, data);
  }
  // Sinon, ajoutez-la à la droite
  else {
    addNode(&(*root)->right, data);
  }
}



//2-5
arbre removeNoeud(arbre Racine, char* valeur)
{
	arbre NoeudASupprimer;

	if (strcmp(Racine->data,valeur) == 0) // on a trouvé l'élément à supprimer
	{
		NoeudASupprimer=Racine;
		if (NoeudASupprimer->left==NULL) //si ya pa de SAG, on retourne SAD
			return NoeudASupprimer->right;
		else
		{
			Racine=NoeudASupprimer->left; //sinon on recherche dans SAG l'endroit pour insérer le SAD
				while (Racine->right!=NULL)
				{
					Racine=Racine->right;
				}
				Racine->right=NoeudASupprimer->right;
			return NoeudASupprimer->left;
		}
		free(NoeudASupprimer);
	}
	else
	{
		if (strcmp(Racine->data,valeur) > 0)
		{
			Racine->left=removeNoeud(Racine->left,valeur);
		}
		else
		{
			Racine->right=removeNoeud(Racine->right,valeur);
		}
	}
	return Racine;
}







#define MAX_SIZE 100

//print path for normal root

void printArray(char **arr, int n,int i)
{
          printf("\t\t\t path[%d] = ",i);
 int j;
  for (int j = 0; j < n; j++) printf("%s ->", arr[j]);
  printf("NULL \n");
      return;
}


void printPathsRecur(struct node* node, char *path[], int pathLen,int i)
{
    if (node == NULL)
        return;

    // Ajouter le noeud courant au chemin
    path[pathLen] = node->data;
    pathLen++;

    // Si c'est un noeud feuille, imprimer le chemin
    if (node->left == NULL && node->right == NULL){
      i++;
        printArray(path, pathLen,i);
         }
    else
    {
        // Sinon, continuer à parcourir l'arbre binaire
        printPathsRecur(node->left, path, pathLen,i);
        printPathsRecur(node->right, path, pathLen,i);
    }

}

// Fonction principale pour imprimer tous les chemins
void printPaths(struct node* node)
{
    int i=0;
    char *path[1000];
    printPathsRecur(node, path, 0,i);
        return;
}








//menu
void menu()
{

	    printf("\n\n\t\t\t  ____________________________________________________________________" );
	      printf("\n\t\t\t |                                                                    |" );
	      printf("\n\t\t\t |               1.  exemple de arbre                                 |" );
	      printf("\n\t\t\t |               2.  ajouter des elements a larbre                    |");
	      printf("\n\t\t\t |               3.  affiche le contenu de l'arbre                    |" );
	      printf("\n\t\t\t |               4.  afficher la structure de l'arbre                 |");
	      printf("\n\t\t\t |               5.  recherche un mot dans larbre :                   |");
	      printf("\n\t\t\t |               6.  ajouter une page dans un mot :                   |");
	      printf("\n\t\t\t |               7.  supprimer une page dans un mot :                 |");
	      printf("\n\t\t\t |               8.  afficher les cheminsde larbre :                  |");
	      printf("\n\t\t\t |               9.  convertir en arbre de recherche :                |");
	      printf("\n\t\t\t |               10. afficher arbre de recherche :                    |");
	      printf("\n\t\t\t |               11. recherche un mot dans larbre de recherche :      |");
	      printf("\n\t\t\t |               12. ajouter un mot dans larbre de recherche :        |");
	      printf("\n\t\t\t |               13. supprimer un mot dans larbre de recherche :      |");
	      printf("\n\t\t\t |               14. afficher les cheminsde larbre de recherche :     |");
	      printf("\n\t\t\t |               15. retourner a zero :                               |");
				printf("\n\t\t\t |               99. sortir de program                                |");
	      printf("\n\t\t\t |____________________________________________________________________|\n\n" );

}

//program principale ..

int main(){



struct BinarySearchTree* BSTroot=NULL;
struct node *rootBST=NULL;
struct node *root=NULL;
char c[42];
char d[]={'x','\0'};
while(1){ menu();
    int choice;
    printf("\t\t\t " );
    scanf(" %d",&choice);

switch(choice){

	case 00:

			 menu();
					break;
	case 1:
struct node * temp=NULL;
root=constree();
int rootc=0;
		printf("\t\t\t\n exemple de arbre binaire : \n" );
		        parcours(root);
						printf("\n" );
						          inorder(root,rootc);
																	printf("\n" );


					break;

  case 2:
	liste l;
	liste liste,p,q;
	int n,tmp,i,j;

    printf("\n\t\t\t Enter the data to be inserted:\n\n");
    getchar();
    scanf("%[^\n]s",&c);
    //fgets(c,40,stdin);
    count++;
    root = insert(root,c);
    strcpy(c,d);
		printf("combien de pages a ajouter ? :..  ");
		scanf("%d",&n);

    break;

    case 3:

        parcours(root);
            break;
      case 4:
          //printf("\t\t\t %s\n",root->data);

          inorder(root,count);
          break;


      case 5:
              printf("\t\t\t donner la chaine : ... \n" );
                  printf("\t\t\t");
                  getchar();
                  scanf("%[^\n]s",&c);
                  int r=0;
									searchTree(root, c,r);
              break;



							case 6:
							  printf("\t\t\t donner la chaine : ... \n" );
									printf("\t\t\t");
									getchar();
									scanf("\t\t\t%[^\n]s",&c);
									SearchAndAddPage(root,c);
											break;

						case 7:
							  printf("\t\t\t donner la chaine : ... \n" );
								printf("\t\t\t");
								getchar();
								scanf("\t\t\t%[^\n]s",&c);
								SearchAndRemovePage(root,c);
										menu();


															break;
								case 8:

                          printPaths(root);
                  										menu();

							break;


              case 9:

              BSTroot=convertToBST(root);
                                    menu();

            break;

              case 10:
              printInOrder(BSTroot->root);

                            break;


                case 11:
                printf("\t\t\t donner la chaine : ... \n" );
                    printf("\t\t\t");
                    getchar();
                    scanf("%[^\n]s",&c);
                    int level=0;
  									searchTree(BSTroot->root, c,level);
            								break;


								case 12:
                printf("\n\t\t\t Enter the data to be inserted:\n\n");
                getchar();
                scanf("%[^\n]s",&c);
                addNode(BSTroot,c);
															break;


                              case 13:
                              printf("\t\t\t donner la chaine a supprimer : ... \n" );
                                  printf("\t\t\t");
                                  getchar();
                                  scanf("%[^\n]s",&c);
                                BSTroot->root= removeNoeud(BSTroot->root, c);

              															break;


                                            case 14:
                                              printPaths(BSTroot->root);
                            															break;

                                                          case 15:
                                                            root=NULL;
                                                            BSTroot=NULL;
                                                                        break;








      case 99:
          exit(1);


          }
      }

      return 0;
}
