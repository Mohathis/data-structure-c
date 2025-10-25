#include<stdio.h>
#include<stdlib.h>
 struct node
 {
int data;
struct node* next;
};

 void main()
 {
  struct node* start=(struct node*)0; //null list
  
  struct node* push(struct node*, int);
  struct node* pop(struct node*);
  void display(struct node*);
  int search(struct node*,int);
  int opt,item,ans;
  
  while(1)
  {
   printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Search \n 5.Exit \n");
   printf("Your OPtion");
   scanf("%d",&opt);
   
   switch(opt)
   {
     case 1:printf("Item to push:");
     	    scanf("%d",&item);
   	    start=push(start,item);
   	    break;
   	    
     case 2:start=pop(start);
            break;
            
     case 3:display(start);
            break;
            
     case 4:printf("Item to search");
            scanf("%d",&item);
            ans=search(start,item);
             if(ans==1)
              printf("Found");
             else
              printf("Not Found...");
             break;
             
     case 5:exit(0);
     
   }	    
  }
 } // end of main
 
  //function to insert
  
  struct node* push(struct node* list,int data)
  {
   struct node* t;
   t=(struct node*)malloc(sizeof(struct node));//create node
   t->data=data; // fill data
   t->next=list; //attach at beginning
   list=t;
   return list;
   }
   
   //function to delete
   
   struct node* pop(struct node* list)
   {
    struct node* t=list;
    if(list !=(struct node*)0)
    {
     printf("deleted item : %d",list->data);
     list=list->next;
     free(t);
    
    }
    else
     printf("list is null");
     return list;
   }
   //function display
   
   void display(struct node* list)
   {
    while(list !=(struct node*)0)
    {
    printf("%d \n",list->data);
    list=list->next;
    }
    return;
   }
   //function to search
   
   int search(struct node* list,int item)
   {
    while(list !=(struct node*)0 && item!=list->data)
     list=list->next;
    if(list==(struct node*)0)
    return 0;
    else
    return 1;
   }
  
