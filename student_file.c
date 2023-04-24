#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

char * bst_fun( char* nodos );
void insert(int data);
void inorder_recorrido(struct node* raiz);
void recorrido_typo_1( struct node* raiz );
void recorrido_typo_2( struct node* raiz );

int main() {

    char entrada[1000];
    printf("Escriba entrada:\n");
    scanf("%[^\n]%*c", entrada);
    bst_fun(entrada);

}

char * bst_fun( char* nodos ) {
    char* recorridoTipo2;
    char numero[1000] = "";
    int numeros[501];
    bool flag = false;

    int j = 0;
    int numerosIndex = 0;
    for(int i=0; i < strlen(nodos) ; i++){
        if( nodos[i] == ',' ) {
            numeros[numerosIndex] = atoi(numero);
            numerosIndex++;        
            for(int d = 1; d <= j; d++) {
                numero[d] = ' ';
            }
            j = 0;
        }
        else {
            numero[j] = nodos[i];
            j++;
        }
    }   
    numeros[numerosIndex] = atoi(numero);

    printf("\nArray ints:\n");    
    for(int k=0; k<=numerosIndex; k++){
        printf("%i  ", numeros[k]);
    } 
    printf("\n----------------\n");    

    return recorridoTipo2;
}

void recorrido_typo_1( struct node* raiz ) {
    if(raiz != NULL) {
        printf("%d ", raiz->value);
        inorder_recorrido(raiz->left);
        inorder_recorrido(raiz->right);
   }
}

void recorrido_typo_2( struct node* raiz ) {
    if(raiz != NULL) {
        inorder_recorrido(raiz->left);
        inorder_recorrido(raiz->right);
        printf("%d ", raiz->value);
   }
}

// función: insert, agrega elementos en un árbol con puntero inicial root
void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *actual;
   struct node *padre;

   //agregamos los valores en node
   tempNode->value = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //si el árbol está vacio
   if(root == NULL) {
      root = tempNode;
   } else {
      actual = root;
      padre = NULL;

      while(1) {
         padre = actual;

         //recorrido por la izquierda del árbol
         if(data < padre->value) {
            actual = actual->left;

            //insertamos en izquierda
            if(actual == NULL) {
               padre->left = tempNode;
               return;
            }
         }
         //recorrido por la derecha del árbol
         else {
            actual = actual->right;
            //insertamos en derecha
            if(actual == NULL) {
                padre->right = tempNode;
                return;
            }
         }
      }
   }
}

void inorder_recorrido(struct node* raiz) {
   if(raiz != NULL) {
        inorder_recorrido(raiz->left);
        printf("%d ", raiz->value);
        inorder_recorrido(raiz->right);
   }
}