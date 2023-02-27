#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define INIT_CAPACITY 100

struct  queue_type
{
    Item    *contents;  //배열선언
    int front;
    int rear;
    int size;   //저장된 데이터의 개수
    int capacity; // 배열 contents의 크기
}   Queue;

int get_size(Queue q)
{
    return q->size;
}

Queue   create()
{
    Queue   q = (Queue)malloc(sizeof(struct queue_type));
    if (q == NULL)
        exit(1);
    q->contents = (Item *)malloc(INT_CAPACITY * sizeof(Item));
    if (q->contents == NULL)
    {
        free(q);
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = INIT_CAPACITY;
    return q;
}

void    destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void    make_empty(Queue q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool    is_empty(Queue q)
{
    return q->size == 0;
}

bool    is_full(Queue q)
{
    return q->size == q->capacity;
}

void    enqueue(Queue q, Item i)
{
    if (is_full(q))
        reallocate(q);
    q->rear = (q->rear + 1)%q->capacity;
    q->contents[q->rear] = i;
    q->size++;    
}

Item    dequeue(Queue q)
{
    if (is_empty)
        exit(1);
    Item    result = q->contents[q->front];
    q->front = (q->front + 1)%q->capacity;
    q->size--;
    return result;
}

Item    peek(Queue q)
{
    if (is_empty(q))
        exit(1);
    return (q->contents[q->front]);
}

void    reallocate(Queue q)
{
    Item    *tmp = (Item *)malloc(2*q.capacity*sizeof(Item));
    if (tmp == NULL)
        exit(1);
    int j = q->front;
    int i;
    i = 0;
    while (i < q->size)
    {
        tmp[i] = q->contents[j];
        j = (j + 1)%q->capacity;
        i++;
    }
    free(q->contents);
    q->front = 0;
    q->rear = q->size - 1;
    q->contents = tmp;
    q->capacity *= 2;    
}