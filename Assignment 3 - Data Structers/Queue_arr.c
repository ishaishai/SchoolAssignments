#include "Queue_arr.h"

void create_queue (queue *pq)
{
	pq->items_num = 0;
    pq->front = 0;
    pq->rear = 0;
}

int enqueue (Tnode *x, queue *pq)
{
	if (pq->items_num == MaxQueue)
		return 0;
    pq->items[pq->rear] = (*x);
    pq->rear = (pq->rear+1) % MaxQueue;
    pq->items_num++;
    return 1;
}

int dequeue (queue *pq, Tnode *px)
{
	if (pq->items_num == 0)
		return 0;
	(*px) = pq->items[pq->front];
	pq->front = (pq->front+1) % MaxQueue;
	pq->items_num--;
	return 1;
}

int queue_front (queue *pq, Tnode *px)
{
	if (pq->items_num == 0)
		return 0;
	(*px) = pq->items[pq->front];
	return 1;
}

int queue_is_empty (queue *pq)
{
	return pq->items_num == 0;
}

int queue_is_full (queue *pq)
{
	return pq->items_num == MaxQueue;
}

int size_of_queue (queue *pq)
{
	return pq->items_num;
}











