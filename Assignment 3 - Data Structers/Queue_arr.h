#include "BST.h"
#define MaxQueue 100


//typedef int queue_type;

typedef struct
{
	int front, rear, items_num;
	Tnode items[MaxQueue];
}	queue;

void create_queue (queue *);

int enqueue (Tnode *, queue *);

int dequeue (queue *, Tnode *);

int queue_front (queue *, Tnode *);

int queue_is_empty (queue *);

int queue_is_full (queue *);

int size_of_queue (queue *);