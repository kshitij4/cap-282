/*Program to merge two sorted arrays of size m and n respectively,
 Then delete 4th element from merged array*/
#include<iostream>

using namespace std;

int main()
{
       int a[30],b[30],c[30],m,n,k,i=0,j=0;
       cout<<"\nEnter the size of the first array:";
       cin>>m;
       cout<<endl;
       cout<<"Enter "<<m<<" sorted elements:\n";
       for(i=0;i<m;i++)
       {
            cin>>a[i];   //Entering values of first array
       }
       cout<<"Enter the size of second array:";
       cin>>n;
       cout<<endl;
       cout<<"Enter "<<n<<" sorted elements:\n";
       for(j=0;j<n;j++)
       {
            cin>>b[j];  //Entering values of second array
       }
       cout<<endl;
       //Merging the 2 sorted arrays
       i=j=k=0;
       while(i<m && j<n)
       {
            if(a[i]<b[j])
            {
                c[k]=a[i];
                i++;
            }
            else
            {
                c[k]=b[j];
                j++;
            }
            k++;
       }
            if(i>=m)
            {
                while(j<n)
                {
                    c[k]=b[j];
                    j++;
                    k++;
                }
            }
            else
            {
                while(i<m)
                {
                    c[k]=a[i];
                    i++;
                    k++;
                }
            }

       //Displaying the merged array
       cout<<"The required merged array is:\n";
       for(k=0;k<(m+n);k++)
       {
            cout<<c[k]<<" ";
       }
       cout<<endl;
       //To delete 4th element from the obtained array
       k=3;
       int item;
       item=c[k];        // Item to be deleted
       i=k;
       int g=m+n;
       cout<<"\nItem to be deleted at position 4 is: "<<item;
       cout<<endl;
       while(i<g)
       {
            c[i]=c[i+1];
            i++;
       }
       g=g-1;
       cout<<"\nThe required array is:\n";
       for(k=0;k<g;k++)
       {
            cout<<c[k]<<" ";      //Final array obtained
       }


}


