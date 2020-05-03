

#include "queue.h"
#include <stdlib.h>

ArrayQueue *ArrayQueueInit()
{
	ArrayQueue *queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	queue->data = (void**)calloc(0, sizeof(void*));
	return queue;
}

void ArrayQueueAdd(ArrayQueue *queue, void *data)
{
	queue->data_count++;
	queue->data = (void**)realloc(queue->data,sizeof(void*) * queue->data_count);
	queue->data[queue->data_count - 1] = data;
}

void *ArrayQueueGet(ArrayQueue *queue)
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



Queue *QueueInit()
{
	Queue *queue = (Queue*)calloc(1,sizeof(Queue));
	queue->prev = queue->next = queue;
	queue->data = (void*)calloc(0,sizeof(char));
	return queue;
}

void QueueAdd(Queue *queue, void *data)
{
	Queue *obj = QueueInit();
	obj->data = data;

	obj->next = queue;
	obj->prev = queue->prev;

	queue->prev->next = obj;
	queue->prev = obj;
}

void *QueueGet(Queue *queue)
{
	Queue *obj = QueueInit();

	obj = queue->next;

	//queue->next = obj->next;
	queue->next = queue->next->next;
	queue->next->prev = queue;

	return obj->data;
}

