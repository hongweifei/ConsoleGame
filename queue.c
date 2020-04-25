

#include "queue.h"
#include <stdlib.h>

Queue* QueueInit()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->data = (void**)calloc(0, sizeof(void*));
	return queue;
}

void QueueAdd(Queue *queue, void *data)
{
	queue->data_count++;
	queue->data = (void**)realloc(queue->data,sizeof(void*) * queue->data_count);
	queue->data[queue->data_count - 1] = data;
}

void *QueueGet(Queue *queue)
{
	void *data = queue->data[0];
	queue->data[0] = NULL;
	queue->data_count--;

	int i;
	for (i = 0; i < queue->data_count; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->data[queue->data_count + 1] = NULL;

	return data;
}

