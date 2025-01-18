#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *right_child;
struct node *left_child;
}*root=NULL,*temp;
struct node* insert(struct node*,int);
struct node* search(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* delete(struct node*,int);
struct node* find_min(struct node*);
void main()
{
root=insert(root,1);
insert(root,4);
insert(root,5);
insert(root,3);
root=delete(root,4);
if ((search(root,5))==NULL)
printf("Element not found\n");
else
printf("Element found\n");
printf("Inorder traversal is:\n");
inorder(root);
printf("\nPreorder traversal is:\n");
preorder(root);
printf("\nPostorder traversal is:\n");
postorder(root);
}
struct node* insert(struct node* root, int x)
{
if(root==NULL)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=x;
temp->left_child=temp->right_child=NULL;
root=temp;
}
else if(x > root->data)
root->right_child=insert(root->right_child,x);
else
root->left_child=insert(root->left_child,x);
return root;
}
struct node* search(struct node* root, int x)
{
if(root==NULL || root->data==x)
return root;
else if(x > root->data)
return search(root->right_child,x);
else
return search(root->left_child,x);
}
void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left_child);
printf("%d ", root->data);
inorder(root->right_child);
}
}
void preorder(struct node *root)
{
if(root!=NULL)
{
printf("%d ",root->data);
preorder(root->left_child);
preorder(root->right_child);
}
}
void postorder(struct node *root)
{
if(root!=NULL)
{
postorder(root->left_child);
postorder(root->right_child);
printf("%d ",root->data);
}
}
struct node* delete(struct node* root, int x)
{
if(root==NULL)
return root;
if (x>root->data)
root->right_child = delete(root->right_child, x);
else if(x<root->data)
root->left_child = delete(root->left_child, x);
else{
if(root->left_child==NULL && root->right_child==NULL)
{
free(root);
return NULL;
}
else if(root->left_child==NULL || root->right_child== NULL)
{
struct node *temp;
if(root->left_child==NULL)
temp = root->right_child;
else
temp = root->left_child;
free(root);
return temp;
}
else
{
struct node *temp = find_min(root->right_child);
root->data = temp->data;
root->right_child = delete(root->right_child, temp->data);
}
}
return root;
}
struct node* find_min(struct node* root){
if(root == NULL)
return NULL;
else if(root->left_child != NULL)
return find_min(root->left_child);
return root;
}