#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chainedDynamicList.h"

pList* creat_list()
{
	pList* list = (pList*)malloc(sizeof(pList));
	list->first = NULL;
	list->size = 0;
	return list;
}

/*function that insert one element in beginning of the list*/
void insert_beginning_list(pList* list, pItem node)
{
	pCell* node_aux = (pCell*)malloc(sizeof(pCell));
	node_aux->data = node;
	node_aux->next = list->first;
	list->first = node_aux;
	list->size++;
}
/*functin that insert one element in the next position of the list */
void insert_list(pList* list, pItem node)
{
	pCell* node_aux = (pCell*)malloc(sizeof(pCell));
	node_aux->data = node;
	node_aux->next = NULL;
	if (list->size == 0)
	{
		list->first = node_aux;
		list->size++;
	}
	else
	{
		pCell* aux = list->first;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = node_aux;
		list->size++;
	}
}

/*function that print the list*/
void print_list(pList* list)
{
	pCell* aux = list->first;
	printf("***** LIST ***** \n");
	for(int i =0; i < list->size; i++)
	{
		printf("REGISTRATION: %d \nNAME: %s\n", aux->data.info, aux->data.name);
		printf("-------------------------------------------------------\n");
		aux = aux->next;
	}
}

/*function that returt the element in the given index*/
pCell* at_Position(pList* list, int index)
{
	if (index >= 0 && index < list->size)
	{
		pCell* aux = list->first;
		for (int i = 0; i < index; i++)
		{
			aux = aux->next;
		}
		return aux;
	}
	else
		return NULL;
}

/*function that return the index of the given element*/
int index_Of(pList* list, pCell* node)
{
	if (node != NULL)
	{
		int count = 0;
		pCell* aux = list->first;
		while (aux != node && aux != NULL)
		{
			aux = aux->next;
			count++;
		}
		if (aux != NULL)
			return count;
		else
			return -1;
	}
	else
		return -1;
}

/*function that remove the first item of the list*/
void remove_beginning(pList* list)
{
	if (!empty_list(list))
	{
		pCell* aux = list->first;
		list->first = aux->next;
		free(aux);
		list->size--;
	}
	
}

/*function that verify if the list is empty*/
bool empty_list(pList* list)
{
	return(list->size == 0);
}
