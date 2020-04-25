

#ifndef QUEUE_HEAD
#define QUEUE_HEAD


typedef struct
{
	void **data;
	int data_count;
}Queue;


#define Queue_Init(TYPE)							\
do													\
{													\
	Queue *queue = (Queue*)malloc(sizeof(Queue));	\
	queue->data = (TYPE**)calloc(0, sizeof(TYPE*));	\
	queue->data_count = 0;							\
	return queue;									\
}while(0)

Queue *QueueInit();
void QueueAdd(Queue *queue,void *data);
void *QueueGet(Queue *queue);

#endif // !QUEUE_HEAD
