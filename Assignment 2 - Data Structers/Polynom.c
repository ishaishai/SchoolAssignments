#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "Polynom.h"
#include <stdio.h>

void initPoly(Polynomial *lst)
{
	(*lst) = (PolyStruct*)calloc(1, sizeof(PolyStruct));
}

//is empty Polynomial
int isEmpty(Polynomial *lst)
{
	return (*lst)->head == NULL;
}

//return amount of Nodes in the list
int length(Polynomial *lst)
{
	int length = 0;
	Node *current;
	
	for(current = (*lst)->head; current != NULL; current = current->next)
		length++;
	
   return length;
}

//allocate a new item
Node* allocItem(poly_type coef,poly_type exp)
{
	Node* item = (Node*)calloc(1,sizeof(Node));
	item->coef = coef;
	item->exp = exp;
	return item;
}

////return item located in spesific index
Node* getLinkByIndex(Polynomial *lst, int idx)
{
	int i;
	//start from the first link
	Node* link = (*lst)->head;

	//navigate through list
	for (i=0; i<idx && link != NULL ;i++)
		link = link->next;
	
	return link;
}

//insert item at the first location
int insertFirst(Polynomial *lst, Node *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmpty(lst))
		{
			//make head & tail pointing to item
			(*lst)->head = (*lst)->tail = item;	
		}
		else 
		{
			//update first prev link
			(*lst)->head->prev = item;
			//point item to old first link
			item->next = (*lst)->head;
			//point head to new first node
			(*lst)->head = item;
		}
		return 1;
	}
	return 0;
}

//insert item at the last location
int insertLast(Polynomial *lst, Node *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmpty(lst))
		{
			//make head & tail pointing to item
			(*lst)->head = (*lst)->tail = item;
		}
		else 
		{
			//update last next link
			(*lst)->tail->next = item;     
			//point item to old last link
			item->prev = (*lst)->tail;
			//point last to new last node
			(*lst)->tail = item;
		}
		return 1;
	}
	return 0;
}

//delete first item
int deleteFirst(Polynomial *lst)
{	
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		Node *temp = (*lst)->head;

		//if only one link
		if(temp->next == NULL)
		{			
			initPoly(lst);
		}
		else
		{
			(*lst)->head->next->prev = NULL;
			(*lst)->head = (*lst)->head->next;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link at the last location
int deleteLast(Polynomial *lst)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		Node *temp = (*lst)->tail;

		//if only one link
		if(temp->prev == NULL)
		{
			initPoly(lst);
		}
		else
		{
			(*lst)->tail->prev->next = NULL;
			(*lst)->tail = (*lst)->tail->prev;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link from list
int deleteLink(Polynomial *lst, Node *link)
{
	if (!isEmpty(lst))
	{
		if (link == NULL)
			return 0;
		if (link == (*lst)->head)
			return deleteFirst(lst);
		if (link == (*lst)->tail)
			return deleteLast(lst);

		//bypass the current link
		link->prev->next = link->next;
		link->next->prev = link->prev;
		free(link);
		return 1;
	}
	return 0;
}

//insert a new item after link
int insertAfter(Polynomial *lst, Node *item, Node *link)
{
	if (!isEmpty(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == (*lst)->tail)
			return insertLast(lst,item);

		//assign new item pointers
		item->prev = link;
		item->next = link->next;
		//chain link and link->next to new item
		link->next->prev = item;
		link->next = item;
		return 1;
	}
	return 0;
}

//insert a new item before link
int insertBefore(Polynomial *lst, Node *item, Node *link)
{
	if (!isEmpty(lst))
	{
		if ((item == NULL) || (link == NULL))
			return 0;
		if (link == (*lst)->head)
			return insertFirst(lst,item);

		//assign new item pointers
		item->next = link;
		item->prev = link->prev;
		//chain link and link->prev to new item
		link->prev->next = item;
		link->prev = item;
		return 1;
	}
	return 0;
}