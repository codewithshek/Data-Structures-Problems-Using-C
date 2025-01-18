#include<stdio.h>
#define initial 1
#define waiting 2
#define visited 3
#define MAX 5
int queue[MAX];
int front=-1,rear=-1,n;
int G[MAX][MAX], state[10];
void insert_queue(int);
int delete_queue();
void bf_traversal();
void create_graph();
void bfs(int v);
void main()
{
create_graph();
bf_traversal();
}
void create_graph(){
int origin,destin,c,max_edge;
printf("Enter number of vertices : ");
scanf("%d",&n);
max_edge = n*(n-1);
for(c=1;c<=max_edge;c++)
{
printf("Enter edge %d(-1 -1 to quit):",c);
scanf("%d%d",&origin,&destin);
if(origin==-1 &&destin==-1)
break;
else if(origin>=n || destin>=n || origin<0 || destin<0)
{
printf("Invalid edge!\n");
c--;
}
else
G[origin][destin]=1;
}
}
void bf_traversal()
{
int v;
for(v=0; v<n; v++)
state[v] = initial;
printf("Enter Start Vertex for BFS: \n");
scanf("%d", &v);
bfs(v);
}
void bfs(int v)
{
int i;
insert_queue(v);
state[v]=waiting;
while(rear!=-1 && front!=rear+1)
{
v = delete_queue();
printf("%d ",v);
state[v] = visited;
for(i=0; i<n; i++)
{
if(G[v][i] == 1 && state[i] == initial)
{
insert_queue(i);
state[i] = waiting;
}
}
}
}
void insert_queue(int x)
{
if(front==-1)
front++;
queue[++rear]=x;
}
int delete_queue()
{
return(queue[front++]);
}