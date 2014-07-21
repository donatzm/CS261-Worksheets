#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
    assert(lst != 0);
    
    lst->firstLink = malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);

    lst->lastLink = malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0);

    lst->firstLink->next = lst->lastLink;
    lst->firstLink->prev = NULL;

    lst->lastLink->prev = lst->firstLink;
    lst->lastLink->next = NULL;

    lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *lnk, TYPE e)
{
	assert(lnk != 0);
    struct DLink * previous = lnk->prev;
    struct DLink * newlink = malloc(sizeof(struct DLink));
    assert(newlink != 0);

    newlink->value = e;
    newlink->prev = previous;
    newlink->next = lnk;

    previous->next = newlink;
    lnk->prev = newlink;

    lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	struct DLink * frontSntl = lst->firstLink;

    _addLinkBefore(lst, frontSntl->next, e);
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	struct DLink * backSntl = lst->lastLink;

    _addLinkBefore(lst, backSntl, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	TYPE front = 0;

    front = lst->firstLink->next->value;

    return front;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	TYPE back = 0;

    back = lst->lastLink->prev->value;
    return back;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *lnk)
{

	struct DLink * previous = lnk->prev;
    struct DLink * following = lnk->next;

    previous->next = following;
    following->prev = previous;

    lnk->prev = NULL;
    lnk->next = NULL;

    free(lnk);
    lst->size--;
	
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	assert(!isEmptyList(lst));
    _removeLink(lst, lst->firstLink->next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	assert(!isEmptyList(lst));
    _removeLink(lst, lst->lastLink->prev);
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    struct DLink * link = lst->firstLink->next;
    printf("Linked List : ");
    while(link != lst->lastLink)
    {
        printf("%3d ", link->value);
        link = link->next;
    }
    printf("\n");
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	if(!containsList(lst, v))
    {
        addFrontList(lst, v);
    }

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	struct DLink* cursor = lst->firstLink->next;

    while(cursor != lst->lastLink)
    {
        if(cursor->value == e)
        {
            return 1;
        }
        cursor = cursor->next;
    }

    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	struct DLink* cursor = lst->firstLink->next;

    while(cursor != lst->lastLink)
    {
        if(cursor->value == e)
        {
            _removeLink(lst, cursor);
        }
        return;
    }
}