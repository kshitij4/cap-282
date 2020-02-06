#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct DLL
{
    struct DLL*prev;
    int info;
    struct DLL *next;
}node;
node*head,*tail;
void empty_list()
{
    cout<<"\nhead and tail are assinged null";
    head=tail=NULL;
}
void insrt_beg(int item)
{
    node*ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        ptr->prev=ptr->next=NULL;
        head=tail=ptr;
        cout<<"\nnode is inserted";
    }
    else
    {
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        cout<<"\nnode is inserted";
    }
}
void insrt_end(int item)
{
    node*ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->info=item;
    if(head==NULL)
    {
        ptr->next=ptr->prev=NULL;
        head=tail=ptr;
    }
    else
    {
        ptr->next=NULL;
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;
    }
}
node* searc(int item)
{
    node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            cout<<"\nitem found";
            return (ptr);
            break;
        }
        else
            ptr=ptr->next;
       return (NULL);
    }
}
void insrt_pos(int item,int after)
{
    node*loc;
    loc=searc(after);
    if(loc==NULL)
            cout<<"\nitem not found ";
    else if(loc->next==NULL)
    {
        insrt_end(item);
    }
    else
    {
        node *ptr=(node*)malloc(sizeof(node));
        ptr->info=item;
        node *aloc=loc->next;
        ptr->prev=loc;
        ptr->next=aloc;
        loc->next=aloc->prev=ptr;
    }
}
void trav()
{
    node*ptr=head;
    if(head==NULL)
            cout<<"\nlist is empty";
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"  ";
            ptr=ptr->next;
        }
    }
}
void trav_rev()
{
    node*ptr;
    ptr=tail;
    if(head==NULL)
            cout<<"\nlist is empty";
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"  ";
            ptr=ptr->prev;
        }
    }
}
int main()
{
    int x;
    while(1)
    {
        cout<<"\n\n.............Choose one of the following:.............";
        cout<<"\n\n1. empty list\n2.insert node at beg\n";
        cout<<"3.Insert node at the end\n4.Insert after a given node\n";
        cout<<"5.Display the elements of DLL\n";
        cout<<"6.Display the elements of DLLin reverse\n7. Exit\n";
        cin>>x;
        switch (x)
        {
        case 1:
            {
                empty_list(); break;
             }
        case 2:
            {
                int a;
                cout<<"\nenter the info of the node:";
                cin>>a;
                insrt_beg(a); break;
            }
        case 3:
            {
                int a;
                cout<<"\nenter the info of the node:";
                cin>>a;
                insrt_end(a); break;
            }
        case 4:
            {
                int item,after;
                cout<<"\nenter the info of the node:";
                cin>>item;
                cout<<"\nenter the item after which you want the node:";
                cin>>after;
                insrt_pos(item,after);
            }
        case 5:
            {
                trav(); break;
            }
        case 6:
            {
                trav_rev(); break;
            }
        case 7:
            exit(0);
        default:
            {
                cout<<"\nyou have selected the wrong option\ntry again";
            }
        }
    }
    return 0;
}
