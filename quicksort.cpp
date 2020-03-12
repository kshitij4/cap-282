#include <iostream>
#define max1 10
#define max2 10
using namespace std;
int arr[30],upper[max1],lower[max2];
int n;

void swap(int *x,int *y)
{
    int temp=0;
    temp=*x;
    *x=*y;
    *y=temp;
}
void push(int stack[],int top,int item)
{
    if(top==maxstk)
    {
          cout<<"\nOverflow";
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
int pop(int stack[],int top,int item)
{
    if(top==0)
     {
         cout<<"\nUnderflow";
         return(0);
     }
    else
    {
        item=stack[top];
        top=top-1;
    }
    return (item);
}

void quickSort()
{
    int beg,last,piv;
    beg=arr[1];
    last=arr[n];
    piv=beg;
    for(int i=n;i>0:i--)
    {
        if(piv>arr[i])
        {
            swap(&piv,&arr[i]);
        }
    }


}

int main()
{
    cout<<"\nEnter the range of array :"
    cin>>n;
    cout<<"\nEnter  "<<n<<" values to the array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quickSort();

    return 0;
}
