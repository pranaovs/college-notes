#include<iostream>
#include<vector>
using namespace std;

class heap
{
    struct node
    {
        int parent;
        int target;
        int weight;
    };
    vector<node*> array;

    public:

    void insert(int u,int v,int weight)
    {
        node* newnode=new node;
        newnode->parent=u;
        newnode->target=v;
        newnode->weight=weight;
        if(array.empty())
        {
            array.push_back(newnode);
        }
        else
        {
            array.push_back(newnode);
            int i=array.size()-1;
            while(((i+1)/2 -1)>=0)
            {
                if(array[i]->weight<array[((i+1)/2 -1)]->weight)
                {
                    swap(array[i],array[((i+1)/2 -1)]);
                    i=(i+1)/2 -1;
                }
            }
        }
    }
    void delete_root()
    {
        if(array.empty())
        {
            cout<<"The Queue is empty";
        }
        else
        {
            array[0]=array.back();
            array.pop_back();
            int i=0;
            while(2*i+1<array.size())
            {
                int j=2*i+1;
                if(j+1<array.size())
                {
                    if(array[i]->weight>array[j]->weight && array[i]->weight>array[j+1]->weight)
                    {
                        if(array[j]->weight<array[j+1]->weight)
                        {
                            swap(array[i],array[j]);
                            i=j;
                        }
                        else
                        {
                            swap(array[i],array[j+1]);
                            i=j+1;
                        }
                    }
                    else if(array[i]->weight>array[j]->weight)
                    {
                        swap(array[i],array[j]);
                        i=j;
                    }
                    else if (array[i]->weight>array[j+1]->weight)
                    {
                        swap(array[i],array[j+1]);
                        i=j+1;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                else
                {
                    if(array[i]->weight>array[j]->weight)
                    {
                        swap(array[i],array[j]);
                        i=j;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
        }
    }
    void sort()
    {
        vector<node*> sorted;
        while(!array.empty())
        {
            sorted.push_back(array[0]);
            delete_root();
        }
        array=sorted;
    } 

    // Check if heap is empty
    bool isEmpty() {
        return array.empty();
    }
    
    // Get minimum element (root) without deleting
    struct Triple {
        int first, second, third;
    };
    
    Triple getMin() {
        if (array.empty()) {
            cout << "The Queue is empty";
            return {-1, -1, -1};
        }
        return {array[0]->parent, array[0]->target, array[0]->weight};
    }
};