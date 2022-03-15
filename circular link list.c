#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node*link;

 };
 struct node*head=NULL;

 void insert_begin();
 void insert_end();
 void insert_position();
 void delete_begin();
 void delete_end();
 void delete_position();
 void search();
 void sorting();
 void traverse();

 int main()
 {
     int choice,ch1,ch2;
  do
  {
      printf("\n1 for insertion\n2 for delection\n3 for search\n4 for sorting\n5 for traverse\n6 for quit\n" );
      printf("\nEnter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
    case 1:
    {


        printf("1 for begin\n2 for end\n3 for position\n4 for quit\n:");
        printf("Enter your choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
     case 1:insert_begin();
       break;
     case 2:insert_end();
       break;
     case 3:insert_position();
       break;
     case 4:break;

    default:printf("invalid");



        }
    }
        break;


    case 2:
{


        printf("1 for begin\n2 for end\n3 for position\n4 for quit");
        printf("\nEnter your choice:");
        scanf("%d",&ch2);
        switch(ch2)
        {
     case 1:delete_begin();
       break;
     case 2:delete_end();
       break;
     case 3:delete_position();
       break;
     case 4:break;

    default:printf("invalid");
        }
}
        break;

    case 3:
        search();
        break;


    case 4:
        sorting();
        break;

    case 5:
        traverse();
        break;

    case 6:break;

    default:
        printf("\ninvalid");

      }


  }while(choice!=6);
 }

 void insert_begin()
 {
     int value;
     struct node*p,*y;
     p=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the value:\n");
     scanf("%d",&value);
     p->data=value;
     if(head==NULL)
      {
       head=p;
       p->link=head;
      }
     else
     {
       y=head;
       while(y->link!=head)
       {
           y=y->link;
       }

       p->link=head;
       head=p;
       y->link=head;
     }
 }

void insert_end()
{
     int value;
     struct node*p,*y,*x;
     p=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the value:\n");
     scanf("%d",&value);
     p->data=value;
      x=head;
     if(head==NULL)
      {
       head=p;
       p->link=head;
      }

           else if(x->link==head)
           {
             x==NULL;
             free(x);
           }
        else
     {
       y=head;
       while(y->link!=head)
       {
           y=y->link;
       }
       y->link=p;
       p->link=head;
     }

}
void insert_position()
{  int pos,count=1,i,val;
    printf("\nEnter your position:\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("\ninsertion is not possible");
    }
    if(pos==1)
   {
        insert_begin();
   }
else
    {
    printf("\nEnter a value:");
    scanf("%d",&val);
    struct node*x,*y,*z;
    x=(struct node*)malloc(sizeof(struct node));
    x->data=val;
    y=head;
    for(i=1;i<pos;i++)
    {
      z=y;
      y=y->link;
    }
     x->link=z->link;
     z->link=x;

}
}
void delete_begin()
 {

     if(head==NULL)
     {
         printf("\ndeletion is not possible");
     }
    else
    {
     struct node*x,*y,*z;
      z=head;
      while(z->link!=NULL)
      {
          z=z->link;
      }
      x=head;
      head=x->link;

      z->link=head;
      free(x);
      printf("\ndeleted");
    }

 }
 void delete_end()
 {
     if(head==NULL)
     {
         printf("Element is deleted");
     }
     else
        {
   struct node*x,*z;
   x=head;
   while(x->link!=head)
   {   z=x;
       x=x->link;
   }
   z->link=x->link;
   free(x);
   printf("node is deleted");
 }
 }
 void delete_position()
 {
     int pos,i;
     struct node*x,*z;
     printf("\nenter the position to delete ");
     scanf("%d",&pos);
     if(head==NULL)
     {
         printf("\nDelection is not possible");
     }
     if(pos==1)
     {
         delete_begin();
     }
     else
     {
         x=head;
         for(i=1;i<pos;i++)
         {
             z=x;
             x=x->link;
         }
         z->link=x->link;
         free(x);
         printf("node is deleted");
     }
 }

 void search()
 {
     int search,count=1,flag=0;
     struct node*x;
     x=head;
     printf("\nEnter a value to search:");
     scanf("%d",&search);
     while(x->link!=NULL)
     {
         if(search==x->data)
         {
             flag=1;
             break;
         }
         x=x->link;
         count++;
     }
    if(flag==1)
    {
        printf("\nvalue is found at positostruct node*x,*y,*z;n %d",count);

    }
     else if(search==x->data)
     {
         printf("\nvalue is found at position %d",count);
     }
     else
     {
         printf("\nnot found");
     }
 }

void sorting()
 {
   int temp;
   struct node*x,*y;
   x=head;

   while(x->link!=head)
   {
       y=x->link;
     while(y!=NULL)
     {
         if(x->data>y->data)
         {
             temp=x->data;
             x->data=y->data;
             y->data=temp;
         }
         y=y->link;
     }
       x=x->link;
   }

}
void traverse()
{
    int y;
    struct node*x;
    x=head;
    printf("\nElement in the list are:\n");
    if(head==NULL)
    {
        printf("\nlink is empty");
    }
    else
    {


    while(x->link!=head)
    {

        printf("%d\t",x->data);
        x=x->link;
    }
    printf("%d",x->data);
}
}
