#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1)return 1;
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r == q->f)return 1;
    return 0;
}

void Enqueue(struct queue *q,int val)
{
    if(isFull(q)){
        printf("Queue is full!!!");
    }else{
        q->r = q->r+1;
        q->arr[q->r] = val;
    }
}

int Dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty!!!");
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    printf("Welcome");
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    //enqueue some elements
    if(isEmpty(&q)){
        printf("Queue is empty!!!");
    }
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    if(isEmpty(&q)){
        printf("Queue is empty!!!\n");
    }
    //Dequeue(&q);
    printf("dequeue element %d\n",Dequeue(&q));
    printf("dequeue element %d\n",Dequeue(&q));
    printf("dequeue element %d\n",Dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is empty!!!");
    }


    return 0;
}
