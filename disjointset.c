#include<stdio.h>
#include<stdlib.h>
typedef struct{
int value;
struct rep *repptr; //pointer to header node of the list
struct node *next;
}
node;

//structure  to represent header node of linked representation of set
typedef struct{
node *head;
node *tail;
}
rep;
typedef struct{
int key;
node *obj_node_ptr;
struct nodaddr *next;
}nodaddr;
nodaddr *ndr=0; //list to store keys and object node pointer

//function to create a set for an object
void makeset(int a)
{//create a object node pointer
nodaddr *t=(nodaddr *)malloc(sizeof(nodaddr));

//create a new set
rep *newset=(rep*)malloc(sizeof(node));
node *n=(node *)malloc(sizeof(node));

//fill values
n->value=a;
n->repptr=newset;
n->next=0;

//intialize head and tail
newset->head=newset->tail=n;

//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}


//function to return pointer of the representative(header node)of the set containing x
rep *find(int x)
{
nodaddr *t=ndr;
while(t->key!=x && t!=0)
t=t->next;
return t->obj_node_ptr->repptr;
}


//to find union of two set coresponding to object given
void unionset(int key1,int key2)
{
rep * set1,*set2;
node *t1;
set1=find (key1);
set2=find(key2);
if(set1==set2)
printf("\n %d  and %d belongs to same set \n",key1,key2);
else
{
//changing the header point of the objects of set 2 to that of set 1
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set1->tail=set2->tail; //set the tail of set1 to tail of set2
free(set2);
}
}


//function to display a set
void display_set(int a)
{
int i=0;
rep *r;
node *t;
r=find(a);
t=r->head;
printf("set members containing %d :",a);
while(t!=0)
{
printf("%d,",t->value);
t=t->next;
}
}


 void main()
{
int opt,data,data1,data2;
do
{
printf("\n 1.makeset \n");
printf("\n 2.findset \n");
printf("\n 3.unionset \n");
printf("\n 4.display set \n");
printf("\n 5.exit \n");
printf("enter your option");
scanf("%d",& opt);
switch (opt)
{

case 1:printf("enter the data:");
scanf("%d",&data);
makeset(data);
break;

case 2:printf("enter set value:");
scanf("%d",&data);
printf("refference of set containing  %d is %x",data,find(data));
break;

case 3:printf("\nEnter the first data:");
   scanf("%d",&data1);
   printf("\nEnter the second data:");
   scanf("%d",&data2);
   unionset(data1,data2);
break;

case 4:printf("enter the data:");
scanf("%d",&data);
display_set(data);
break;

case 5:exit(0);
}
}
while(1);
}


