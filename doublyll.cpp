#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct doubly
{
    struct doubly *next;
    int info;
    struct doubly *prev;
}node;
node*head;
node*tail;
void emptylist()
{
    head=tail=NULL;
}
void insrtEnd(int item)
{
    node*ptr,*loc;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->next=ptr->prev=NULL;
    }
    else
    {
        loc=tail;
        loc->next=ptr;
        ptr->prev=loc;
        ptr->next=NULL;
        tail=ptr;
    }
}
node*searchItem(int item)
{
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            cout<<"\nitem found";
            return (ptr);
            break;
        }
        ptr=ptr->next;
    }
    cout<<"\nitem not found";
    return (NULL);
}
void del_after(int after)
{
    node*ptr,*loc,*aloc;
    loc=searchItem(after);
    if(loc==NULL)
    {
        cout<<"\nitem  is not present in the list";
    }
    else if(loc->next==NULL)
    {
        cout<<"\nNo item after the node";
    }
    else
    {
         ptr=loc->next;
        if(ptr->next!=NULL)
        {
            aloc=ptr->next;
            loc->next=aloc;
            aloc->prev=loc;
            free(ptr);
        }
        else
        {
            loc->next=NULL;
            tail=loc;
            free(ptr);
        }
    }
}
void alter(int item)
{
    int data;
    node* x=searchItem(item);
    if(x==NULL)
    {
          insrtEnd(item);
    }
    else
    {
        del_after(item);
    }
}
void traverse()
{
    node*ptr;
    if(head==NULL)
        cout<<"\nList is empty";
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"  ";
            ptr=ptr->next;
        }
    }

}
int main()
{
    int x;
    while(1)
    {
        cout << "\n------Enter your choice-------:"<< endl;
        cout<<"\n1.empty the head and tail\n2.Insert in the linked list";
        cout<<"\n3.Display the elements of the list\n4.search for an element";
        cout<<"\n5.Delete after a node\n6.Call the alter function\n7.exit\n";
        cin>>x;
        switch(x)
        {
        case 1:
            {
                emptylist(); break;
            }
        case 2:
            {
                int info;
                cout<<"\nenter the info of the node:";
                cin>>info;
                insrtEnd(info); break;
            }
        case 3:
            {
                traverse(); break;
            }
        case 4:
            {
                int item;
                cout<<"\nEnter what you want to search:";
                cin>>item;
                searchItem(item); break;
            }
        case 5:
            {
                int x;
                cout<<"\nenter the item:";
                cin>>x;
                del_after(x); break;
            }
        case 6:
            {
                int y;
                cout<<"\nenter the item to search:";
                cin>>y;
                alter(y); break;
            }
        case 7:
            {
                exit(0); break;
            }
        default:
            {
            cout<<"\nwrong entry try again:";
            }
        }
    }
}
