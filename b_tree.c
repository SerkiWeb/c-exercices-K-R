/**
 * \file b_tree.c
 * \brief API pour un arbre binaire
 * \author FK.TURKI
 * \version 0.1
 * \date 07/09/2018
 *
 * API pour un arbre binaire
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b_tree.h"


/**
 * Tree print
 * @brief print a tree
 * @param   b_tree  l'arbre a imprimer
 *
 */
void treeprint(b_tree *tree)
{
	if (tree != NULL) {
		treeprint(tree->bt_left);
		printf("%4d %s\n", tree->count, tree->word);
		treeprint(tree->bt_right);
	}
}

/**
 * Browse btree
 * @brief parcours un arbre de la racine
 * @param  b_tree  l'arbre à affichez
 * 
 */
void browse_btree(b_tree *tree)
{
	printf(" node : %s\n", tree->word);
	

	if (tree->bt_left != NULL) {
		printf("\t");
		browse_btree(tree->bt_left);	
	}
	
	if (tree->bt_right != NULL) {
		printf("\t");
		browse_btree(tree->bt_right);	
	}

	return;
	
}

/**
 * Ajoute un mot dans l'arbre binaire b_tree un nouveau noeud passé en parametre
 * @parame 	b_tree *   l'arbre binaire
 * @param  	char *     le mot a ajouter
 * @return  b_tree *   l'arbre avec le nouveau noeud ajouter
 */
b_tree *ajout_en_place(b_tree *tree, char *word)
{

	if (tree == NULL) {
		b_tree *node=(b_tree *)malloc(sizeof(b_tree));
		node->word=word;
		node->count++;

		return node;
	}

	if (strcmp(word, tree->word) < 0) {
//		printf("%s word are inferior %s\n", word, tree->word);
		tree->bt_left=ajout_en_place(tree->bt_left, word);
	} else if (strcmp(word, tree->word) == 0) {
//		printf("%s word are equal %s\n", word, tree->word);
		tree->count++;
	} else {
//		printf("%s word are greater %s\n", word, tree->word);
		tree->bt_right=ajout_en_place(tree->bt_right, word);
	}

	return tree;
}