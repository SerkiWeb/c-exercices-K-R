#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b_tree.h"
#include  "nlist.h"

union test {
    char *t[4];
    int b;
} test2;


void long_string()
{
    char str[80+1];

    while (scanf("%s", str) != EOF) {
        if (strlen(str) > 80) {
            printf("%s\n", str);
        } else {
            printf("string is not enough longer to be display, (minimal lenght 80 characters) \n");
        }
    }
}

char *strcat_bis(char *dest, char *src)
{
    char *tmp=NULL;
    tmp=dest;
    printf("%s = %s ", tmp, dest);
    while ( (*tmp) != '\0') {
        tmp++;
    }

    tmp=NULL;
    tmp=(char *)malloc(sizeof(char)*sizeof(strlen(src)));
    for(; (*src)!='\0'; src++) {

    }
    test2.b=15;
    printf("%d", test2.b);
    return dest;
}

int strlen_bis(char *pt)
{
    int lenght=0;

    for (; *pt!='\0'; pt++) {
        lenght++;
    }

    return lenght;
}

void reverse(char *str)
{
    char *pt = str;

    for (char *last=pt+6; last>=pt; last--) {
        printf("%c", *last);
    }
    printf("\n");
}

void print_histo_horizontal(int histo[], int max)
{
    printf("before print max : %d \n", max);

    for (int i=max; i>0; i--) {
        for (int j=0; j<127; j++) {

            if (histo[j] == i || histo[j] > i) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        printf("\n");
    }

    for (int i=0; i<50; i++) {
        putchar('_');
    }
}

/*
void print_histo_vertical(int histo[], int max)
{
    for (int i=0; i<24; i++) {
        //printf("occurences de mot de %d letres %d\n", i, words_lenght[i]);
        printf("%d", i);
        for (int j=0; j<words_lenght[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}*/

int main()
{
    /*printf("%d\n", test);
    assign_test(5);
    printf("%d\n", test);
   
    
    unsigned int test=hash("TEST");
    printf("%d\n", test);

    test=hash("KARIM");
    printf("%d\n", test);

    test=hash("LENGHT");
    printf("%d\n", test);
     */

    install("TEST", "test");
    install("TEST2", "test");
    install("TEST3", "test");
    install("TEST", "test");
    install("TEST2", "test");
    install("TEST3", "test");

    printf("affichage table\n");
    for (int i=0; i<HASHSIZE; i++) {
        
        if (hashtable[i] != NULL) {
            int i=0;
            for (nlist *tmp=hashtable[i]; tmp != NULL; tmp=tmp->next) {
                printf("name : %s  ndef : %s \n", tmp->name, tmp->ndef);
                printf("%d\n", i);
                i++;
            }
        }
    }

    int *ptr=NULL;
    char c='r';
    ptr=c;
    printf("%c\n", *ptr);
    
    /*
    FILE *fp=fopen("word_count.txt", "r");
    char *str=malloc(sizeof(char)*400);
    int i=0;
    b_tree *tree=NULL;

    while ((fgets(str, 400, fp)) != NULL) {
        
        char *word=malloc(sizeof(strlen(str)));
        for (int i=0; i<strlen(str); i++) {
            if (str[i] ==  ' ' || str[i] ==  ',' ) {
                printf("%s\n", word);
                tree=ajout_en_place(tree, word);

                break;
            }
            printf("%c\n", str[i]);
            word[i]=str[i];
        }    
    }
    printf("%s\n", str);
    treeprint(tree);
    b_tree *tree=(b_tree *)malloc(sizeof(b_tree));
    tree->word="test";
    tree->count=1;
    
    b_tree *left=(b_tree *)malloc(sizeof(b_tree));
    left->word="fils gauche";
    left->count=1;
    
    b_tree *right=(b_tree *)malloc(sizeof(b_tree));
    right->word="fils droit";
    right->count=1;

    tree->bt_left=left;
    tree->bt_right=right;

    //browse_btree(tree);
    ajout_en_place(tree, "blesse");
    ajout_en_place(tree, "mon");
    ajout_en_place(tree, "coeur");
    ajout_en_place(tree, "de");
    ajout_en_place(tree, "cette");
    ajout_en_place(tree, "langueur");
    ajout_en_place(tree, "monotone");
    //browse_btree(tree);
    treeprint(tree);
    
    union prix {
        int tva;
        double prix;
    } promo;

    promo.tva =5;
    printf("%d\n", promo.tva);
    promo.prix=3.14;
    printf("%f\n", promo.prix);
    
    //reverse("azerty");
    //printf("test");
    //reverse("azerty");
    //char *tab;
    //char tab[280];
    while (scanf("%s", tab) != EOF) {
        //reverse(tab);
        //printf("before call");
        int res = strlen_bis(tab);
        printf("chaine de longeur %d \n", res);
    }
    char * tmp="test";
    char *tmp2="test";
    strcat(tmp2, tmp);
    return 0;
    */
}
