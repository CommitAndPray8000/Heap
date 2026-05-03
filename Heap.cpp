#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:

    int Heap_arr[10];
    int Heap_size = 0;

    int row_first=0;
    int def_spaces =20;
    int def_rowspace =20;

    //||||||||||||||||||||  Making Max Heap |||||||||||||||||||||

    void Insert(int value)
    {
        if(Heap_size<10)
        {
            Heap_size++;
            Heap_arr[Heap_size-1] = value;
            cout<<"Element Inserted Successfully.\n";
            UpHeapify(Heap_size -1);
        }
        else
        {
            cout<<"! Heap is Full, Free up space first !\n";
        }
    }


    void UpHeapify(int index)
    {
        if(index > 0)
        {
            int parent = (index-1)/2;
            if(Heap_arr[index]>Heap_arr[parent])
            { 
                swap(index,parent);
                UpHeapify(parent);
            }
        }
    }

    void Delete(int index)
    {
        Heap_arr[index] = Heap_arr[Heap_size-1];
        Heap_arr[Heap_size-1] = 0;
        Heap_size--;
        DownHeapify(index, Heap_size);
        cout<<"Element Successfully Deleted.\n";

    }

    void DownHeapify(int index, int limit)
    {
        if(index<limit-1)
        {
            int L_Child= index*2+1;
            int R_Child= index*2+2;
            int larger;

            if(L_Child < limit )
            {
                if(R_Child < limit)
                {
                    if(Heap_arr[R_Child] > Heap_arr[L_Child])
                        larger = R_Child;
                        
                    else
                        larger = L_Child;

                    if(Heap_arr[index] > Heap_arr[larger])
                    {    
                        swap(index,larger);
                        DownHeapify(larger, limit);
                    }

                }
                else
                {
                    if(Heap_arr[index] < Heap_arr[L_Child])
                    {
                        swap(index,L_Child);
                        DownHeapify(L_Child, limit);
                    }
                }
            }
        }
    }

    void HeapSort()
    {
        int un_sorted;
        for(un_sorted = Heap_size-1;un_sorted >= 0;un_sorted--)
        {
            swap(0,un_sorted);
            DownHeapify(0,un_sorted+1);
        }
    }

    void DisplayLikeTree(int index)
    {
        if(index == row_first)
        {
            space_printer(def_rowspace);
        }
        if(index <= row_first*2)
        {
            cout<<Heap_arr[index];
            space_printer(def_rowspace *2 );                 //|||||| Gotta fix the spacing issue, this line is just temporary.

            if(index + 1 < Heap_size)
                DisplayLikeTree(index +1);

            else
            {
                row_first = 0;
                def_spaces =20;
                def_rowspace =20;
            }
        }
        else
        {
            row_first = index;
            def_rowspace = def_rowspace/2;
            def_spaces-=6;
            cout<<"\n";
            DisplayLikeTree(index);
        }
    }

    void space_printer(int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<" ";
        }
    }

    void swap(int index,int parent)
    {
        int temp = Heap_arr[index];
        Heap_arr[index] = Heap_arr[parent];
        Heap_arr[parent] = temp;
    }
};