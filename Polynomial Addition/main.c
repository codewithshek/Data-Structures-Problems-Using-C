#include "stdio.h"
#include "stdlib.h"
struct node{
    int co,exp;
    struct node *next;
}*head=NULL,*p,*new,*p1,*p2,*poly1,*poly2,*temp;

struct node *create(){
    head=NULL;
    int n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        new=(struct node *)malloc (sizeof(struct node));
        printf("Enter coeff and exponent:");
        scanf("%d %d",&new->co,&new->exp);
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
            printf("%dx^%d+",p->co,p->exp);
            p=p->next;
        }
        printf("%dx^%d",p->co,p->exp);
    }
}

struct node *polyadd(struct node *poly1,struct node *poly2){
    p1=poly1;
    p2=poly2;
    if(p1==NULL && p2==NULL)
		printf("\n not a valid equation\n");
	else if(p1!=NULL && p2==NULL)
		return p1;
	else if(p1==NULL && p2!=NULL)
		return p2;
	else
	{
		struct node *res,*result;
		res=(struct node*)malloc(sizeof(struct node));
		result=res;
		while(p1 && p2)
		{
			if(p1->exp>p2->exp)
			{
				res->co=p1->co;
				res->exp=p1->exp;
				p1=p1->next;
			}
			else if(p1->exp<p2->exp)
			{
				res->co=p2->co;
				res->exp=p2->exp;
				p2=p2->next;
			}
			else
			{
				res->co=p1->co+p2->co;
				res->exp=p1->exp;
				p1=p1->next;
				p2=p2->next;
			}
			if(p1 && p2)
			{
				res->next=(struct node*)malloc(sizeof(struct node));
				res=res->next;
			}
		}
		while(p1 || p2)
		{
			res->next=(struct node*)malloc(sizeof(struct node));
			res=res->next;
			if(p1)
			{
				res->co=p1->co;
				res->exp=p1->exp;
				p1=p1->next;
			}
			if(p2)
			{
				res->co=p2->co;
				res->exp=p2->exp;
				p2=p2->next;
			}
		}
		res->next=NULL;
		return result;	
	}
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
                      
                    
            case 5 : display(polyadd(poly1,poly2));
                     break;
            
        }
    }while(opt>0 && opt<=5);
}
