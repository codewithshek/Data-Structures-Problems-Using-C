#include <stdio.h>
int size = 0;
void heapSort(int array[], int size) ;
void heapify(int array[], int size, int i);
void create(int array[]);
void printArray(int array[], int size);
int main()
{
int array[10];
create(array);
printArray(array, size);
heapSort(array,size);
printArray(array, size);
}
void create(int array[])
{
int n,i,newNum;
printf("Enter the number of elements\n");
scanf("%d",&n);
for(size=0;size<n;size++)
{
printf("Enter the element\n");
scanf("%d",&newNum);
if (size == 0)
array[0] = newNum;
else
{
array[size] = newNum;
for (int i = size / 2 - 1; i>= 0; i--)
{
heapify(array, size, i);
}
}
}
}
void heapSort(int array[], int size)
{
int i,temp;
for (i = size / 2 - 1; i>= 0; i--)
heapify(array, size, i);
for (i=size-1; i>=0; i--)
{
temp = array[0];
array[0]= array[i];
array[i] = temp;
heapify(array, i, 0);
}
}
void heapify(int array[], int size, int i)
{
int temp;
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;
if (l < size && array[l] > array[largest])
largest = l;
if (r < size && array[r] > array[largest])
largest = r;
if (largest != i)
{
temp = array[i];
array[i]= array[largest];
array[largest] = temp;
heapify(array, size, largest);
}
}
void printArray(int array[], int size)
{
for (int i = 0; i< size; ++i)
printf("%d ", array[i]);
printf("\n");
}