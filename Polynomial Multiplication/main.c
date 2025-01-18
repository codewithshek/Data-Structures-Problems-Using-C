#include "stdio.h"
#include "stdlib.h"
struct node{
    int co,expn;
    struct node *next;
}*head=NULL,*p,*new,*p1,*p2,*poly1,*poly2,*temp,*t,*pt;

struct node *create(){
    head=NULL;
    int n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        new=(struct node *)malloc (sizeof(struct node));
        printf("Enter coeff and exponent:");
        scanf("%d %d",&new->co,&new->expn);
        new->next=NULL;
        if(head==NULL){
            head=p=new;
        }
        else{
            p->next=new;
            p=p->next;
        }
    }
    return head;
}

void display(struct node *p){
    if(p==NULL){
        printf("POlynomial is empty\n");
    }
    else{
        while(p->next!=NULL){
            printf("%dx^%d+",p->co,p->expn);
            p=p->next;
        }
        printf("%dx^%d",p->co,p->expn);
    }
}

struct node* polymul(){
    struct node *res=NULL;
    p1=poly1,p2=poly2,pt=poly2;
    int flag=0;
    while(p1!=NULL){
        while(p2!=NULL){
            if(res==NULL){
                res=(struct node*) malloc(sizeof(struct node));
                temp=t=res;
            }
            else{
                while(t){
                    if(t->expn==(p1->expn+p2->expn)){
                        t->co+=p1->co*p2->co;
                        flag=1;break;
                        
                    }
                    else{
                    t=t->next;
                        
                    }
                }
                    if(flag==1){
                        p2=p2->next;
                        t=res;
                        flag=0;
                        continue;
                        
                    }
                    temp->next = (struct node *) malloc(sizeof(struct node));
                    temp=temp->next;
                    
                }
                temp->co=p1->co*p2->co;
                temp->expn=p1->expn+p2->expn;
                temp->next=NULL;
                p2=p2->next; t=res;
                
            }
            p2=pt; 
            p1=p1->next;
            
        }
        
     return res;   
    }
    

void main(){
    int opt,val;
    do{
        printf("ENter your option:");
        scanf("%d",&opt);
        switch(opt){
            case 1: poly1=create();
                    printf("pol1 is created\n");
                    
                    break;
                    
            case 2 :poly2=create();
                    printf("pol2 is created\n");
                    
                    break;
            
            case 3 : display(poly1);
                     break;
                      
            case 4 : display(poly2);
                      break;
                      
                    
            case 5 : display(polymul(poly1,poly2));
                     break;
            
        }
    }while(opt>0 && opt<=5);
}
