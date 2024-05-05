#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int top;
    int *arr;
    int size;
} stack;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int* arr;
}queue;

queue *createQueue(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->capacity = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    return q;
}
void enqueue(queue *q, int a)
{
    if (q->size == q->capacity)
    {
        return;
    }
    if(q->rear == -1)
    {
        q->front=0;
        q->rear=0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = a;
    q->size++;
}
int dequeue(queue *q)
{
    
}
stack *createStack(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(sizeof(int) * size);

    return s;
}
void push(stack *s, int a)
{
    if (s->top == s->size)
    {
        return;
    }
    s->top++;
    s->arr[s->top] = a;
}
void pop(stack *s)
{
    if (s->top == -1)
    {
        return;
    }
    else
    {
        s->size--;
        s->top--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    stack *s = createStack(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 1)
        {
            int b;
            scanf("%d", &b);
            push(s, b);
        }
        else if (arr[i] == 2)
        {
            pop(s);
        }
        else
        {
            int min = s->arr[0];
            for (int i = s->top; i>=0; i--)
            {
                // printf("%d",s->arr[i]);
                if (s->arr[i] < min)

                {
                
                    min = s->arr[i];
                }
            }
            printf("%d\n", min);
        }
    }

    return 0;
}