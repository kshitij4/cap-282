#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct pll
{
    struct pll *link;
    int prior;
    int info;

}node;
node*head;

void insrt(int item,int pro)
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    ptr->prior=pro;
    node* aloc;
    if(head==NULL||ptr->prior<head->prior)
    {

        ptr->link=head;
        head=ptr;
    }
    else
    {
        loc=head;
        while(loc->prior<=ptr->prior&&loc->link!=NULL)
        {
            aloc=loc;
            loc=loc->link;
        }
        if(loc->prior>ptr->prior)
        {
            ptr->link=loc;
            aloc->link=ptr;
        }
        else
        {
            loc->link=ptr;
            ptr->link=NULL;
        }
    }
}
void traverse()
{
    node*ptr;
    ptr=head;
    if(head==NULL)
        cout<<"\nlist is empty";
    else
    {
        while(ptr!=NULL)
        {
            cout<<"\ninfo:"<<ptr->info<<"\npriority:"<<ptr->prior<<"\n";
            ptr=ptr->link;
        }
    }
}
int main()
{
    int x;
    while(1)
    {
        cout<<"\n\n-----------Enter your choice -----------";
        cout<<"\n1.Insert new node\n2.Traverse\n3.Exit\n\n";
        cin>>x;
        switch(x)
        {
        case 1:
            {
                int item,pro;
                cout<<"\nEnter priority:";
                cin>>pro;
                cout<<"\nEnter info:";
                cin>>item;
                insrt(item,pro);
                break;
            }
        case 2:
            {
                traverse();
                break;
            }
        case 3:
            exit(0);
        default:
            {
                cout<<"\ntry again:";
                break;
            }
        }
    }

    return 0;
}
