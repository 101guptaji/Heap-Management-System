#include<bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

typedef struct heap_node{
	string key;
	int data;
	bool active;
}node;

node heap[MAX_SIZE];


void sub_memalot(string name , int data , int i)
{
    heap[i].key = name;
    heap[i].data=data;
    heap[i].active=true;
}


void memalot(string name , int data , int n)
{
    for(int i=0;i<n;i++)
    {
        if(heap[i].key==name && heap[i].active==true)
        {
            sub_memalot(name,data,i);
            return;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(heap[i].active==false)
        {
            sub_memalot(name,data,i);
            return;
        }
    }
    cout<<"Heap is Full";
}


void free_mem(string name , int n)
{
    for(int i=0;i<n;i++)
    {
        if(heap[i].key==name && heap[i].active==true)
        {
            heap[i].key = "";
            heap[i].data = rand();
            heap[i].active = false;
        }
    }
}


int main()
{
    int n,data,ch;
    char ch1;
    string name;
    

    do
    {
        cout<<"\n1.Memory allocation \n2.Free memory \n3.Display list \n4.Exit \n";
        cout<<"\n Enter your Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            cout<<"\n Enter the Size : ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the Key_name and Data: ";
                cin>>name>>data;
                memalot(name , data , n);
            }
            break;

            case 2:
            do
            {
                cout<<"Enter the Key_name that you want to free : ";
                cin>>name;
                free_mem(name , n);
                cout<<"\n Do you want to free more : [y/n] ";
                cin>>ch1;

            }while(ch1 == 'y');
            break;

            case 3:
            cout<<"Free List Content : \n";
            for(int i=0;i<n;i++)
            {
                if(heap[i].active==false)
                {
                    cout<<heap[i].key<<" "<<heap[i].data;
                }
            }

            cout<<"\nAllocated List Content : \n";
            for(int i=0;i<n;i++)
            {
                if(heap[i].active==true)
                {
                    cout<<heap[i].key<<" "<<heap[i].data<<endl;
                }
            }
            break;

            case 4 :  exit(0); break;

            default : cout<<"\n Wrong Choice !!! \n"<<endl; break;
        }   
    }while(ch!=4);

    return 0;
}
