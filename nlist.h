#ifndef NLIST_H_INCLUDED
#define NLIST_H_INCLUDED
#define HASHSIZE 101

/**
 * @file [<name>]
 * @brief fichier ut
 *
 *
 *
 */

/**
 * @struct nlist 
 * @brief Nieme element d'un list chainée cette structure 
 * est utilisé par la table de hachage, lors des collisions
 */
typedef struct nlist {
	struct nlist *next; /* @field  nlist *next  */
	char *name;         /* @field  nlist *name  */
	char *ndef;			
} nlist;

/**
 * @brief La table de hachage, un simple tableau à 100 éléments, est 
 * une variable globale
 * @var array  hashtable
 */
nlist *hashtable[HASHSIZE];

unsigned int hash(char *str);

nlist *lookup(char *s);

nlist *install(char *name, char *defn);

#endif