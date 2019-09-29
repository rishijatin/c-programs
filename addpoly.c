#include<stdio.h>
#include<stdlib.h>

struct node
{
    int base;
    int exp;
    struct node *add;
};

typedef struct node block;

void addnode(block **);
void addpoly(block **, block **,block **);
void display(block *);
void listprep(block **,block**);
void freelist(block **);

int main(int argc, char const *argv[])
{ block *head1=NULL;
  block *head2=NULL;
  block *head3=NULL;
int ch=1;
while (ch!=0)
{ printf("Enter 1 to add a node\n");
  printf("Enter 2 to add the two polynomials\n");
  scanf("%d",&ch);
  switch (ch)
     {
  case 1:
         printf("You want to add to 1st polynomial or second");
         scanf("%d",&ch);

         switch (ch)
         {
         case 1: addnode(&head1);
                 printf("The first polynomial is\n");
                 display(head1);
                 printf("The second polynomial is\n");
                 display(head2);
                 break;
         case 2:addnode(&head2);
                 printf("The first polynomial is\n");
                 display(head1);
                 printf("The second polynomial is\n");
                 display(head2);
                break;
         default:
                 break;
         }
      
         break;
  case 2: addpoly(&head1,&head2,&head3);
          printf("The added polynomial is= \n");
          display(head3);
          freelist(&head3);
          break;
  default:
      break;
     }
  }


   return 0;
}

void addnode(block **head_ref)
{  
    block *curr=(block *)malloc(sizeof(block));
    printf("Enter the base of polynomial and exponent resptively\n");
    scanf("%d %d",& curr->base,& curr->exp);
    curr->add=NULL;
    block *prev= *head_ref;
    if(*head_ref!=NULL)
    { if(curr->exp >= (*head_ref)->exp)
        { if(curr->exp != (*head_ref)->exp)
        {curr->add= *head_ref;
          *head_ref=curr;}
          else{
            (*head_ref)->base=((*head_ref)->base) + (curr->base);
          free(curr);
          }

        }
      else
        { while( (prev->add!=NULL) && ((prev->add->exp) > (curr->exp)))
             {prev=prev->add;}
          if (prev->add==NULL)
          {
            curr->add=prev->add;
            prev->add=curr;
          }
          
          else{
           if((prev->add->exp) != (curr->exp))
           {curr->add=prev->add;
           prev->add=curr;}
           else{
               prev=prev->add;
               prev->base= prev->base + curr->base;
              }
          }
          
        }    
    }

    else
    { *head_ref=curr;}

}

void display(block *head_ref1)
{ 
  while (head_ref1!=NULL)
  { printf("(%d)x^(%d)  ",head_ref1->base,head_ref1->exp);
    head_ref1=head_ref1->add;}
  printf("\n");

}

void freelist(block **head)
{ block *temp= *head;
  while (*head !=NULL)
  {
    temp=*head;
    (*head)=(*head)->add;
     free(temp);
  }
}


void addpoly(block **head1,block **head2,block **head3)
{ block *temp1= *head1;
  block *temp2= *head2;

  while(temp1!=NULL && temp2!=NULL)
  { if(temp1->exp > temp2->exp)
    { listprep(head3,&temp1);
      temp1=temp1->add;
    }

  else if(temp1->exp < temp2->exp)
    {listprep(head3,&temp2);
    temp2=temp2->add;
    }

  else
    { temp1->base += temp2->base;
    listprep(head3,&temp1);
    temp1->base -= temp2->base;
    temp1=temp1->add;
    temp2=temp2->add;
    }
  }
  
  if(temp1==NULL)
  {
    while(temp2!=NULL)
    {listprep(head3,&temp2);
      temp2=temp2->add;}
  }
  if(temp2==NULL)
  {
    while(temp1!=NULL)
    {listprep(head3,&temp1);
      temp1=temp1->add;}
  } 

}

void listprep(block **head1, block **head2)
{  block *curr=(block *)malloc(sizeof(block));
   curr->base= (*head2)->base;
   curr->exp=(*head2)->exp;
   curr->add=NULL;
    block *prev= *head1;
     if(*head1 ==NULL)
     { *head1 =curr;}
     else
     {
       while (prev->add !=NULL)
       {
         prev=prev->add;
       }
       curr->add=prev->add;
       prev->add=curr;
     }

}
