#include<iostream>
using namespace std;
int main()
{
    int l,k;
    int w=1;
    int z=0;
    int mini=100;
    int maxi=0;
    int a[20];
    cout<<"Enter tree level: ";
    cin>>l;
    cout<<"Enter Child number: ";
    cin>>k;

    int x=k;

    for(int j=0;j<(l-1);j++)
    {
        w=w*k;
    }
    cout<<"Enter element: "<<endl;

    for(int i=0;i<w;i++)
    {
        cin>>a[i];
    }

    maxi=a[0];
    mini=a[0];

    cout<<endl;
    for(int i=0;i<w;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for (int i=0;i<k;i++)
    {
        for(int j=z;j<x;j++)
        {
            if(a[j]>maxi){
                        if(a[j+1]<mini)
                    {
                        mini=a[j+1];
                    }
                    //a[j]=maxi;

                }
                else
                    break;



        }
       /* if(mini>maxi)
        {
            maxi=mini;
        }*/
        z=z+k;
        cout<<mini<<" ";
        mini=a[z];
        x=x+k;


    }
    cout<<endl;
    cout<<maxi;
}
