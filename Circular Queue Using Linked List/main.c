#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL,*new,*temp;

void enqueue(int n){
    new=(struct node *)malloc(sizeof(struct node));
    new->data=n;
    new->next=NULL;
    if(rear==NULL){
        front=rear=new;
        rear->next=front;
    }
    else{
        rear->next=new;
        rear=new;
        rear->next=front;
    }
}

void dequeue(){
    temp=front;
    if((front==NULL)&&(rear==NULL)){
        printf("Empty queue");
    }
    else if((rear==front)&&(front!=NULL)){
        front=rear=NULL;
        free(temp);
    }
    else{
        front=front->next;
        free(temp);
        rear->next=front;
    }
}

void frontdata(){
    if((rear==NULL)&&(front==NULL)){
        printf("queue is empty");
    }
    else{
        printf("Front value is: %d",front->data);
    }
}

void reardata(){
    if((rear==NULL)&&(front==NULL)){
        printf("queue is empty");
    }
    else{
        printf("Front value is: %d",rear->data);
    }
}

void display(){
    temp=front;
    if((rear==NULL)&&(front==NULL)){
        printf("queue is empty");
    }
    else{
        do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
    }
}

void main(){
    int opt,val;
    do{
        printf("ENter your option:");
        scanf("%d",&opt);
        switch(opt){
            case 1: printf("Enter the  value to insert:");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
                    
            case 2 : dequeue();
                     printf("value is deleted\n");
                     break;
                     
            
            case 3 : frontdata();
                      break;
                      
            case 4 : reardata();
                      break;
                      
                    
            case 5 : display();
                      break;
            
        }
    }while(opt>0 && opt<=5);
}
