#include<iostream>

using namespace std;

void best_fit(int block_size[] , int m , int requested_size[] , int n)
{
    int allocat[n],best_block,i,j;

   for(int i=0;i<n;i++)
   {
   	allocat[i]=-1;
   }

    for(i=0;i<n;i++)
    {
        best_block = -1;
        for(j=0;j<m;j++)
        {
            if(block_size[j] >= requested_size[i])
            {
                if(best_block == -1)
                    best_block = j;
                else if(block_size[best_block] > block_size[j])
                    best_block = j;
            }
        }

        if(best_block != -1)
        {
            allocat[i] = best_block;
            block_size[best_block] -= requested_size[i];
        }
    }

    cout<<"\n Process No. \tRequested Size \tBlock No.\n";
    for(i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<requested_size[i]<<"\t\t";
        if(allocat[i] != -1)
            cout<<allocat[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }
}

int main()
{
    int block_size[] = {100, 500, 200, 400, 300};
    int requested_size[] = {112,317, 212, 526};
    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(requested_size)/ sizeof(requested_size[0]);

    cout<<"\n Block Size : ";
    for(int i=0;i<m;i++)
        cout<<block_size[i]<<"\t";
    cout<<endl;

    best_fit(block_size , m , requested_size , n);

    return 0;
}
