#ifndef B_TREE_H_INCLUDED
#define B_TREE_H_INCLUDED

/**
 * Structure d'un arbre binaire 
 * @field
 *
 */ 
typedef struct binary_tree {
	char *word;
	int count;
	struct binary_tree *bt_left;
	struct binary_tree *bt_right;
} b_tree;

/**
 *  affiche  l'arbre binaire btree passer en parametre
 */
void browse_btree(b_tree *tree);

/**
 *  Ajoute en place un noeud dans l'arbre binaire
 */
b_tree *ajout_en_place(b_tree *tree, char *word);

/**
 *  imprime un arbre 
 */
void treeprint(b_tree *tree);

#endif