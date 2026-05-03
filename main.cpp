#include<bits/stdc++.h>
#include "Heap.cpp"

using namespace std;

int main()
{
    Heap myHeap;
    bool flag = false;
    int action;
    cout<<"Welcome to my Max Heap Program.\n";

    cout<<"Enter the number corosponding to the action.\n";
    while(!flag)
    {
        cout<<"1 for Inserting, 2 for Deleting,\n 3 for Displaying and 4 for exiting the program : ";
        cin>>action;

        switch(action)
        {
            case 1:
                int value;
                cout<<"Enter the number you want to insert : ";
                cin>>value;
                cout<<"\n";
                myHeap.Insert(value);

            break;

            case 2:
                int to_del;
                cout<<"Enter the index nubmer you want to delete : ";
                cin>>to_del;
                cout<<endl;
                myHeap.Delete(to_del);
                break;

            case 3:
                myHeap.DisplayLikeTree(0);
                cout<<"\n";
            break;

            default:
                cout<<"Program Exited Successfully.\n";
                return 0;
            break;
        }
    }
}