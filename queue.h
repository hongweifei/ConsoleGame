

#ifndef QUEUE_HEAD
#define QUEUE_HEAD


typedef struct _array_queue
{
	void **data;
	int data_count;
}ArrayQueue;


#define ArrayQueue_Init(TYPE)							\
do													\
{													\
	ArrayQueue *queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));	\
	queue->data = (TYPE**)calloc(0, sizeof(TYPE*));	\
	queue->data_count = 0;							\
	return queue;									\
}while(0)

ArrayQueue *ArrayQueueInit();
void ArrayQueueAdd(ArrayQueue *queue,void *data);
void *ArrayQueueGet(ArrayQueue *queue);



typedef struct _queue
{
	struct _queue *prev;
	struct _queue *next;
	void *data;
}Queue;

Queue *QueueInit();
void QueueAdd(Queue *queue,void *obj);
void *QueueGet(Queue *queue);


#endif // !QUEUE_HEAD
