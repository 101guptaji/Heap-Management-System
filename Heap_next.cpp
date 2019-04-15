#include<bits/stdc++.h>

using namespace std;

void next_fit(int block_size[] , int m , int requested_size[] , int n)
{
    int allocation[n],j=0;
    
    for(int i=0;i<n;i++)
   {
   	allocation[i]=-1;
   }
    for(int i=0;i<n;i++)
    {
    	int count=0;
        while(j<m)
        {
            if(block_size[j] >= requested_size[i])
            {
                allocation[i] = j;

                block_size[j] -= requested_size[i];
                break;
            }
    		count++;
    		if(count<=m)
            j = (j+1) % m; 
            else
            break;
        }
    }

    cout<<"\n Block No. \tRequested Size \tBlock No.\n";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<requested_size[i]<<"\t\t";
        if(allocation[i] != -1)
            cout<<allocation[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }
}


int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int requested_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(requested_size)/ sizeof(requested_size[0]);

    cout<<"\n Block Size : ";
    for(int i=0;i<m;i++)
        cout<<block_size[i]<<" ";
    cout<<endl;

    next_fit(block_size , m , requested_size , n);

    return 0;
}
