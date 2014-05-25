#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int flag=0;
struct cir_queue_a{
   char arr[SIZE];
   int f;
   int r;
}q;
int cir_queue_IS_empty(struct cir_queue_a *qu){
   if(qu->r==(SIZE-1)&&qu->f==0&&flag==0)
       return 1;
   else
       return 0;
}
int cir_queue_IS_full(struct cir_queue_a *qu){
   if(qu->r==(SIZE-1)&&qu->f==0&&flag==1)
       return 1;
   else
       return 0;
}
void insert_cir_queue(struct cir_queue_a *qu,int x){
   qu->r=(++(qu->r))%SIZE;
   qu->arr[qu->r]=x;
   flag=1;
}
int delete_cir_queue(struct cir_queue_a *qu){
   int x;
   x=qu->arr[qu->f];
   qu->f=(qu->f)+1;
   flag=0;
   return x;
}
int peek_cir_queue(struct cir_queue_a *qu){
   int x;
   x=qu->arr[qu->f];
   return x;
}
void show_cir_queue_1(struct cir_queue_a *qu){
qu->f=(--(qu->f))%SIZE;
   int i;
   for(i=qu->r;i!=(qu->f);i--){
       printf("%d\t",qu->arr[i]);
   }
   printf("\n");
qu->f=(++(qu->f))%SIZE;
}
int main(){
   int choice,ele;
   q.f=0;
   q.r=SIZE-1;
   while(1){
       printf("Enter 1 to insert\n2 to delete\n3 to peek\n4 to show queue\n5 to exit");
       scanf("%d",&choice);
       switch(choice){
       case 1:
           if(!cir_queue_IS_full(&q)){
               printf("Enter an element to insert\n");
               scanf("%d",&ele);
               insert_cir_queue(&q,ele);
           }
           else
               printf("Sorry but the queue is full\n");
           break;
       case 2:
           if(!cir_queue_IS_empty(&q)){
               ele=delete_cir_queue(&q);
               printf("Deleted element is %d\n",ele);
           }
           else
               printf("Sorry but the queue is empty\n");
           break;
       case 3:
           if(!cir_queue_IS_empty(&q)){
               ele=peek_cir_queue(&q);
               printf("Peeked element is %d\n",ele);
           }
           else
               printf("Sorry but the queue is empty\n");
           break;
       case 4:
           if(!cir_queue_IS_empty(&q)){
               show_cir_queue_1(&q);
           }
           else
               printf("Sorry but the queue is empty\n");
           break;
       case 5:
           exit(0);
       }
   }
   return 0;
}

