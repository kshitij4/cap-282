#include <iostream>

using namespace std;

int main()
{
    int a[30],n,i,k;
    cout<<"\nenter the size of array:";
    cin>>n;
    cout<<"enter "<<n<<" values:\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number you want to delete:";
    cin>>k;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            int g=i;
            while(g<n)
            {
                a[g]=a[g+1];
                g++;
            }
            i--;
            n--;
        }
    }
    cout<<"\nrequired array:\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
