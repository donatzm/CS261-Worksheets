#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the Sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
    assert(q != 0);
  	q->Sentinel = malloc(sizeof(struct DLink));
    assert(q->Sentinel != 0);

    q->Sentinel->next = q->Sentinel;
    q->Sentinel->prev = q->Sentinel;

    q->size = 0;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink* link = malloc(sizeof(struct DLink));
    assert(link != 0);

    link->value = val;
	return link; 
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
    assert(q != 0);
    assert(lnk != 0);

	struct DLink* newLink = _createLink(v);
    
    // Set up the new link's links
    newLink->prev = lnk;
    newLink->next = lnk->next;

    // Change the next next link's link
    lnk->next->prev = newLink;

    // change the current link's link
    lnk->next = newLink;

    q->size++;

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
    assert(q != 0);
	_addLinkAfter(q, q->Sentinel->prev, val);

}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    assert(q != 0);

	_addLinkAfter(q, q->Sentinel, val); 

}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

	assert(lnk != 0);

    (lnk->prev)->next = lnk->next;
    (lnk->next)->prev = lnk->prev;	

    free(lnk);

    q->size--; 

}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

	_removeLink(q, q->Sentinel->next);	 
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

  	_removeLink(q, q->Sentinel->prev);	 
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink* link = q->Sentinel->next;

    while(link != q->Sentinel)
    {
        _removeLink(q, link);
    }

    free(q);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
    assert(q != 0);
  	return q->Sentinel->next == q->Sentinel;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

	struct DLink* link = q->Sentinel->next;
    printf("Linked list: ");

    while(link != q->Sentinel)
    {
        printf("%3g ", link->value);
        link = link->next;
    }	 

    printf("\n");

}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));

    struct DLink* link = q->Sentinel;
	struct DLink* temp = link->next;
    
    link->next = link->prev;
    link->prev = temp;
    link = temp;

    while(link != q->Sentinel)
    {
        temp = link->next;
        link->next = link->prev;
        link->prev = temp;
        link = temp;
    }

}
