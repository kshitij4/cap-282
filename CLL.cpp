#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct CLL
{
    struct CLL *link;
    int info;
}node;
node*head;

void emptylist()
{
    head=NULL;
}
void insrt_beg(int item)
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        ptr->link=ptr;
        head=ptr;
    }
    else
    {
        loc=head;
        while(loc->link!=head)
            loc=loc->link;
        ptr->link=head;
        loc->link=ptr;
        head=ptr;
    }
}
void insrt_end(int item)
{
    node *ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        ptr->link=ptr;
        head=ptr;
    }
    else
    {
        loc=head;
        while(loc->link!=head)
                loc=loc->link;
        loc->link=ptr;
        ptr->link=head;
    }
}
void traverse()
{
    node*ptr=head;
    if(head==NULL)
        cout<<"\nlist is empty";
    else
    {
        do
        {
            cout<<ptr->info<<"  ";
            ptr=ptr->link;
        }while(ptr!=head);
    }
}
node* searc(int item)
{
    node *ptr;
    if(head==NULL)
           {
            cout<<"\nnothing to search list is empty";
            return(NULL);
           }
    else
    {
        ptr=head;
        do
        {
            if(ptr->info==item)
            {
                cout<<"\nitem is found";
                return(ptr);
            }
            ptr=ptr->link;
        }while(ptr!=head);
        cout<<"\nitem not found";
        return(NULL);
    }
}
void del_beg()
{
    node*ptr,*loc;
    if(head==NULL)
        cout<<"\nlist is empty";
    else if(head->link==head)
    {
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {
        ptr=loc=head;
        while(loc->link!=head)
            loc=loc->link;
        loc->link=ptr->link;
        head=ptr->link;
        free(ptr);
    }
}
int main()
{
    int x;
    while(1)
    {
        cout <<"\n\n......enter your choice....." << endl;
        cout<<"\n1.empty head\n2.insert node at beg\n";
        cout<<"3.insert at the end\n4.search in the CLL\n";
        cout<<"5.display the elements\n6.delete from beg\n7.exit\n";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                emptylist(); break;
            }
            case 2:
            {
                int a;
                cout<<"\nenter what you want to insert:";
                cin>>a;
                insrt_beg(a);cout<<"\nnode inserted";
                 break;
            }
            case 3:
            {
                int a;
                cout<<"\nenter what you want to insert:";
                cin>>a;
                insrt_end(a);cout<<"\nnode inserted";
                 break;
            }
            case 4:
            {
                int a;
                cout<<"\nenter what you want to search:";
                cin>>a;
                searc(a); break;
            }
            case 5:
                {
                    traverse(); break;
                }
            case 6:
            {
                del_beg(); break;
            }
            case 7:
                {
                   exit(0);break;
                }
            default:
                cout<<"\nwrong entry try again";
        }
    }
}
