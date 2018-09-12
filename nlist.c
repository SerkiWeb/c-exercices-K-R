/**
 * \file nlist.c
 * \brief Programme de tests.
 * \author FK.TURKI
 * \version 0.1
 * \date 07/09/2018
 *
 * API pour une table de hachage
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nlist.h"


/**
 * Hash a string and return valye between and 100
 * @param   char *  str
 */
unsigned int hash(char *str)
{
	unsigned int hashval=0;
	for(; *str != '\0'; str++) {
		hashval= *str +31 * hashval;
	}
	return hashval % HASHSIZE;
}

/**
 * Look for a entry in hashtable
 * @param   array 
 * @return  *nlist|NULL  
 */
nlist *lookup(char *s)
{
	nlist *tmp;
	for (tmp=hashtable[hash(s)]; tmp!= NULL; tmp=tmp->next)
	{
		if (strcmp(tmp->name, s) == 0) {
			return tmp;
		}
	}

	return NULL;
}

/**
 * put (name,def) in hashtable
 * @param    char*   name 
 * @param    char*   defn
 * @return   nlist
 */
nlist *install(char *name, char *defn)
{
	int index=hash(name);
	printf("index calculé %d\n", index);
	if (lookup(name) == NULL) {
	
		nlist *item=(nlist *)malloc(sizeof(nlist));
		item->next=NULL;
		item->name=name;
		item->ndef=defn;
		
		hashtable[index]=item;
		return item;
	}

	nlist *tmp=NULL;

	for (tmp=hashtable[index]; tmp->next != NULL; tmp=tmp->next) {
		if (strcmp(tmp->name, name) == 0) {
			return tmp;
		}
	}

	nlist *item=(nlist *)malloc(sizeof(nlist));
	item->name=name;
	item->ndef=defn;
	tmp->next=item;

	return tmp;
}