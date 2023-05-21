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
void insertar_recorrido_typo_1( struct node** raiz, int data );
void recorrido_typo_2( struct node* raiz );
void recorrido_typo_2_a_string( struct node* raiz, char* cadena, int* index );

int main() {

    char entrada[1000];
    printf("Escriba entrada:\n");
    scanf("%[^\n]%*c", entrada);
    printf("%s\n", bst_fun(entrada));
}

char* bst_fun( char* nodos ) {
    char* recorridoTipo2;
    char numero[1000] = "";
    int numeros[501];

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

    for(int k=0; k<=numerosIndex; k++){
        insertar_recorrido_typo_1( &root, numeros[k] );
    }

    recorridoTipo2 = (char*) malloc( sizeof(char) * strlen(nodos) );   
    
    int index = 0;
    recorrido_typo_2_a_string( root, recorridoTipo2, &index );
    recorridoTipo2[index - 1] = ' '; // Elimina la última coma.

    inorder_recorrido(root);
    return recorridoTipo2;
}

void insertar_recorrido_typo_1( struct node** raiz, int data ) {
    if( (*raiz) == NULL) {
        struct node *tempNode = (struct node*) malloc(sizeof(struct node));
        tempNode->value = data;
        tempNode->left = NULL;
        tempNode->right = NULL;    
        (*raiz) = tempNode;
    } else {
        if( data < (*raiz)->value ) {
            insertar_recorrido_typo_1( &((*raiz)->left), data );
        } else {
            insertar_recorrido_typo_1( &((*raiz)->right), data );
        }
    }
}

void recorrido_typo_2_a_string( struct node* raiz, char* cadena, int* index ) {
    if(raiz != NULL) {
        recorrido_typo_2_a_string(raiz->left, cadena, index);
        recorrido_typo_2_a_string(raiz->right, cadena, index);
        
        char temp[1000] = "";
        sprintf(temp, "%d", raiz->value );
        
        for(int i = 0; i < strlen(temp); i++) {
            cadena[*index] = temp[i];
            (*index)++;
        }
        cadena[*index] = ',';
        (*index)++;
    }
}

void recorrido_typo_2( struct node* raiz ) {
    if(raiz != NULL) {
        recorrido_typo_2(raiz->left);
        recorrido_typo_2(raiz->right);
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