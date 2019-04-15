#include<bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

typedef struct heap_node{
	string key;
	int data;
	bool active;
	
}node;

node heap[MAX_SIZE];

void sub_malloc(string key_name , int data , int i)
{
    heap[i].key = key_name;
    heap[i].data=data;
    heap[i].active=true;
}


void malloc(string key_name , int data , int n)
{
    for(int i=0;i<n;i++)
    {
        if(heap[i].key==key_name && heap[i].active==true)
        {
            sub_malloc(key_name,data,i);
            return;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(heap[i].active==false)
        {
            sub_malloc(key_name,data,i);
            return;
        }
    }
    cout<<"Heap is Full";
}


void free(string key_name , int n)
{
    for(int i=0;i<n;i++)
    {
        if(heap[i].key==key_name && heap[i].active==true)
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
    string key_name;
    

    do
    {
        cout<<"\n MENU \n";
        cout<<"\n1.Malloc \n2.Free \n3.Display \n4.Exit \n";
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
                cin>>key_name>>data;
                malloc(key_name , data , n);
            }
            break;

            case 2:
            do
            {
                cout<<"Enter the Key_name that you want to free : ";
                cin>>key_name;
                free(key_name , n);
                cout<<"\n Do you want to free more : [Y/y] ";
                cin>>ch1;

            }while(ch1 == 'y' || ch1 == 'Y');
            break;

            case 3:
            cout<<"Free List Content : \n";
            cout<<"Key name\t"<<"Data\t"<<"Location"<<endl;
            for(int i=0;i<n;i++)
            {
                if(heap[i].active==false)
                {
                	
                    cout<<heap[i].key<<"\t\t"<<heap[i].data<<"\t"<<i<<endl;
                }
            }

            cout<<"\nAllocated List Content : \n";
            	cout<<"Key name\t"<<"Data\t"<<"Location"<<endl;
            for(int i=0;i<n;i++)
            {
                if(heap[i].active==true)
                {
                
                    cout<<heap[i].key<<"\t\t"<<heap[i].data<<"\t"<<i<<endl;
                }
            }
            break;

            case 4 :  exit(0); break;

            default : cout<<"\n Wrong Choice !!! \n"<<endl;
			 break;
        }   
    }while(ch!=4);

    return 0;
}
