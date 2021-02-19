#include <iostream>

using namespace std;

int main()
{
    int a[30][30],m,n,i,j;
    int rsl,csl,rgl,cgl;
    cout<<"\nenter the size of column of matrix:";
    cin>>m;
    cout<<"\nenter the size of row of matrix:";
    cin>>n;
    cout<<"\nenter the values of matrix:";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"\nenter a["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
        cout<<endl;
    }
    cout<<"entered array/matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<(a[i][j])<<" ";
        }
        cout<<endl;
    }
    int largest=a[0][0];
    int smallest=a[0][0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>largest)
            {
                largest=a[i][j];
                rgl=i;
                cgl=j;
            }
            if(a[i][j]<smallest)
            {
                smallest=a[i][j];
                rsl=i;
                csl=j;
            }
        }
    }
    cout<<"\nlargest element is at position "<<rgl<<","<<cgl<<" and element is:"<<largest;
    cout<<"\nsmallest element is at position "<<rsl<<","<<csl<<" and element is:"<<smallest;

    return 0;
}
