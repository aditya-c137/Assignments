#include<iostream>
using namespace std;

struct ele
{
      int coef,exp,chk=0;
      struct ele *next;
};

struct ele *create(struct ele *head)
{
      int i;
      struct ele *nn,*temp;
      nn=new ele;
      nn->next=NULL;
      cout<<"enter exponent: ";
      cin>>nn->exp;
      cout<<"\n";
      cout<<"enter coefficient: ";
      cin>>nn->coef;
      cout<<"\n";
      temp=head;


      if (temp==NULL)
      {
            head=nn;
      }

      else
      {

           if(nn->exp==temp->exp)
           {
               temp->coef=temp->coef + nn->coef;
               return head;
           }

            while(temp->next!=NULL)
            {
                  temp=temp->next;
                  if(nn->exp==temp->exp)
                  {
                     temp->coef=temp->coef+nn->coef;
                     return head;
                  }

            }
            temp->next=nn;
      }

      return head;
}

void display(struct ele *head)
{
      struct ele *temp;
      temp=head;
      while(temp!=NULL)
      {
            cout<<temp->coef<<"x^"<<temp->exp;
            if(temp->next!=NULL)
            {
               cout<<"+";
            }
            temp=temp->next;
      }
      cout<<"\n";
}


struct ele *crtemp3(int sum, int exp1, struct ele *head)
{
      struct ele *nn,*temp;
      nn=new ele;
      nn->next=NULL;
      nn->coef=sum;
      nn->exp=exp1;
      temp=head;
      if (temp==NULL)
      {
            head=nn;
      }

      else
      {
            while(temp->next!=NULL)
            {
                  temp=temp->next;
            }
            temp->next=nn;
      }
      return head;
}


struct ele *add(struct ele *head1, struct ele *head2, struct ele *head3)
{
   struct ele *temp1, *temp2, *temp3, *temp4;
   int sum,exp1,flag=0;
   temp1=head1;
   temp2=head2;

   while(temp1!=NULL)
   {
      while(temp2!=NULL)
      {
         if(temp1->exp==temp2->exp)
         {
            sum=temp1->coef+temp2->coef;
            exp1=temp1->exp;
            head3=crtemp3(sum,exp1,head3);
            temp2->chk=1;
            flag=1;
         }

         temp2=temp2->next;
      }
      if(flag==0)
      {
         sum=temp1->coef;
         exp1=temp1->exp;
         head3=crtemp3(sum,exp1,head3);
      }
      temp1=temp1->next;
   }
   temp2=head2;
   while(temp2!=NULL)
    {
        if(temp2->chk==0)
        {
            head3=crtemp3(temp2->coef,temp2->exp,head3);
        }
        temp2=temp2->next;
    }

   return head3;
}



int main()
{
      int ch;
      struct ele *head1=NULL, *head2=NULL, *head3=NULL, *head4=NULL;
      cout<<"enter 1st polynomial: ";
      while(1)
      {
            head1=create(head1);
            cout<<"enter any number to continue and 1 to exit: ";
            cin>>ch;
            if(ch==1)
                  break;
      }

      cout<<"enter 2nd polynomial: ";
      while(1)
      {
            head2=create(head2);
            cout<<"enter any number to continue and 1 to exit: ";
            cin>>ch;
            if(ch==1)
                  break;
      }

      cout<<"\nFirst polynomial: ";
      display(head1);

      cout<<"\nsecond polynomial: ";
      display(head2);

      head3=add(head1,head2,head3);
      cout<<"\nresult of addition: ";
      display(head3);

}
