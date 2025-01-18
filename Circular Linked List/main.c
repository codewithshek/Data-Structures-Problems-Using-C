#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*new,*last;

void create(int n){
    int data1;
    for(int i=1;i<=n;i++){
        printf("enter data:");
        scanf("%d",&data1);
        new=(struct node*)malloc(sizeof(struct node));
        new->data=data1;
        new->next=NULL;
        if(head==NULL){
            temp=head=new;
        }
        else{
            temp->next=new;
            temp=temp->next;
        }
        last=temp;
        last->next=head;
    }
}

void display(){
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

void insert_begin(int n){
    new=(struct node *) malloc(sizeof(struct node));
    new->data=n;
    new->next=head;
    last->next=new;
    head=new;
}

void insert_end(int n){
    new=(struct node *) malloc(sizeof(struct node));
    new->data=n;
    last->next=new;
    new->next=head;
    last=new;
}

void insert_after(int n){
    temp=head;
    int val;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter value to insert :");
    scanf("%d",&val);
    new->data=val;
    if(head==NULL){
        new->next=new;
        head=last=new;
    }
    else{
        while(temp->data!=n)
            temp=temp->next;
        new->next=temp->next;
        temp->next=new;
    }
}

void delete_begin(){
    temp=head;
    head=head->next;
    last->next=head;
    free(temp);
}

void delete_end(){
    temp=head;
    while(temp->next!=last){
        temp=temp->next;
    }
    temp->next=head;
    free(last);
    last=temp;
}

void delete_any(int val){
    struct node *prev;
    temp=head;
    while(temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}

void main(){
    int opt,val;
    do{
        printf("ENter your option");
        scanf("%d",&opt);
        switch(opt){
            case 1: printf("Enter the number of nodes");
                    scanf("%d",&val);
                    create(val);
                    break;
                    
            case 2 : printf("Enter val to inser:");
                     scanf("%d",&val);
                     insert_begin(val);
                     break;
                     
            case 3 : printf("Enter val to inser:");
                     scanf("%d",&val);
                     insert_end(val);
                     break;
                     
            case 4: printf("enter value after which to insert:");
                    scanf("%d",&val);
                    insert_after(val);
                    break;
                    
            case 5 : delete_begin();
                      break;
                      
            case 6 : delete_end();
                      break;
                      
            case 7: printf("enter value to delete:");
                    scanf("%d",&val);
                    delete_any(val);
                    break;
                    
            case 8 : display();
                      break;
            
        }
    }while(opt>0 && opt<=8);
}
