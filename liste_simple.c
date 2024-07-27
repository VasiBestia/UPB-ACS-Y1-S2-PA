#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    char data;
    struct Elem *next;
} Elem;

void stackCreate(Elem **List) {
    *List = NULL; // Initialize the list to NULL
}


void addAtBeginning(Elem **head, char v){
	Elem* newNode = (Elem*)malloc(sizeof(Elem));
	newNode->data = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Elem** head, char v){
	Elem *aux = *head;
	Elem *newNode = (Elem*)malloc(sizeof(Elem)); 
	newNode->data = v; 
	if (*head == NULL) addAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}


void deleteNode(Elem **head,char v){	
	if (*head==NULL) return; 
	Elem *headcopy = *head;
	if (headcopy->data==v){
		*head = (*head)->next;
		free(headcopy);
		return; 
	}
	Elem *prev = *head;
	while (headcopy!=NULL){
		if(headcopy->data!=v){
			prev = headcopy;
			headcopy = headcopy->next;
		}else{
			prev->next = headcopy->next;
			free(headcopy); 
			return; 
		} 
	}
}


void deleteFromNode(Elem **List, Elem *startNode) {
    if (startNode == NULL) {
        printf("Nodul de început nu există\n");
        return;
    }

    Elem *current = *List;
    while (current != NULL && current != startNode) {
        current = current->next;
    }

    // Dacă nodul de început este găsit
    if (current == startNode) {
        // Șterge toate nodurile de la nodul de început până la sfârșit
        Elem *nextNode;
        while (current != NULL) {
            nextNode = current->next;
            deleteNode(List, current->data); // Șterge nodul curent
            current = nextNode;
        }
    } else {
        printf("Nodul de început nu este găsit în listă\n");
    }
}

void freeStack(Elem *List) {
    Elem *current = List;
    while (current != NULL) {
        Elem *temp = current;
        current = current->next;
        free(temp);
    }
}

Elem* adoualista(Elem **List,char *partit){
    Elem *temp=*List;
    Elem *in=NULL;Elem *fin=NULL;
        while(temp!=NULL){
        if(temp->data==partit[0]&&temp->next->data==partit[1]){
             in=temp;

             while(temp!=NULL&&temp->data!=partit[2])
             temp=temp->next;

            if(temp!=NULL&&temp->data==partit[2]){
                 fin=temp;
                 break;
            }
        }
        temp=temp->next;
    }

   Elem*prima=*List;
    while(prima!=fin)
       prima=prima->next;

      prima=prima->next;
      printf("%c ",prima->data);
    for(Elem* i=fin;i!=fin->next;i=i->next)
      addAtBeginning(&prima,i->data);
      return prima;
}

void cautare(Elem **List,char *partit){
    Elem *temp=*List;
    Elem *in=NULL;Elem *fin=NULL;
        while(temp!=NULL){
        if(temp->data==partit[0]&&temp->next->data==partit[1]){
             in=temp;

             while(temp!=NULL&&temp->data!=partit[2])
             temp=temp->next;

            if(temp!=NULL&&temp->data==partit[2]){
                 fin=temp;
                 break;
            }
        }
        temp=temp->next;
    }

    if(in!=NULL&&fin!=NULL){
      printf("secventa este: ");
   for(Elem *i=in;i!=fin->next;i=i->next)
      printf("%c ",i->data);
    }
    else printf("secventa nu e gasita");

    //refrenul

   Elem*doua=*List;
   Elem*prima=*List;
    while(prima!=fin)
       prima=prima->next;

      prima=prima->next;
      printf("%c ",prima->data);
    for(Elem* i=fin;i!=fin->next;i=i->next)
      addAtBeginning(&prima,i->data); 
    printf("in interior:\n");

    while(doua!=fin)
       doua=doua->next;

      doua=doua->next;

     deleteFromNode(List,doua);
     while(prima!=NULL){
        addAtEnd(List,prima->data);
        prima=prima->next;
     }
}

void stackprint(Elem **List){
    Elem *current = *List;
    printf("Lista este: ");
    while (current != NULL) {
        printf("%c ", current->data); // Access character directly
        current = current->next;
    }
    printf("\n");
}

int main() {
    Elem *p;
    stackCreate(&p);

    char *partit;

    partit=(char *)malloc(3*sizeof(char));

    for(int i=0;i<3;i++)
      scanf("%c",&partit[i]);

    // Push consecutive ASCII characters onto the stack
    for (char c = 'a'; c <= 'z'; c++) {
        addAtEnd(&p, c);
    }

    // Print the stack
    stackprint(&p);

    cautare(&p,partit);

    stackprint(&p);

     freeStack(p);
    return 0;
}
