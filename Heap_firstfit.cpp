#include<iostream>

using namespace std;

void first_fit(int block_size[] , int m , int request_size[] , int n)
{
    int allocat[n];

   for(int i=0;i<n;i++)
   {
   	allocat[i]=-1;
   }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( block_size[j] >= request_size[i])
            {
                allocat[i] = j;
                block_size[j] -= request_size[i];
                break;
            }
        }
    }

    cout<<"\n Process No. \tRequested Size \tBlock No. \n";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<request_size[i]<<"\t\t";
        if( allocat[i] != -1)
            cout<<allocat[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }
}

 int main()
{
    int block_size[] = {100, 500, 200, 400, 600};
    int requested_size[] = {112, 317, 212, 426};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(requested_size)/ sizeof(requested_size[0]);

    cout<<"\n Block Size : ";
    for(int i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    first_fit(block_size , m , requested_size , n);

    return 0;
}
