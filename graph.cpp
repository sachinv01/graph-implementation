#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct node
{
    int vertex;
    node* next;
};

struct adjlist
{
    node* head;
};

struct Graph
{
    int v;
    adjlist* arr;
};


Graph* creategraph(int v)
{
    Graph* graph = new Graph();
    graph->v = v;
    graph->arr = new adjlist[v];
    for(int i = 0;i<v;i++)
    {
        graph->arr[i].head = NULL;
    }
    return graph;
}

node* createnewnode(int vertex)
{
    node* newnode = new node();
    newnode->vertex = vertex;
    newnode->next = NULL;
    return newnode;
}

void addedge(Graph* graph, int start, int dest)
{
    if(graph->arr[start].head == NULL)
    {
        graph->arr[start].head = createnewnode(dest);
    }
    else
    {
        node* temp = graph->arr[start].head;
        while(temp->next!=NULL)
        {
            temp = temp -> next;
        }
        temp->next = createnewnode(dest);

    }

    if(graph->arr[dest].head == NULL)
    {
        graph->arr[dest].head = createnewnode(start);
    }
    else
    {
        node* temp = graph->arr[dest].head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = createnewnode(start);
    }
}


void printgraph(Graph* graph)
{
    for(int i = 0; i<graph->v; i++)
    {
        cout<<"ADJACENT NODES OF "<<i<<" = ";
        node* temp = graph->arr[i].head;
        while(temp!= NULL)
        {
            cout<<temp->vertex<<">";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    Graph* graph;
    int v;
    cout<<"ENTER THE NUMBER OF VERTEX IN THE GRAPH"<<endl;
    cin>>v;
    graph = creategraph(v);
    int E;
    cout<<"ENTER THE NUMBER OF EDGES IN THE GRAPH"<<endl;
    cin>>E;
    for(int  i = 0;i<E;i++)
    {
        int start, destination;
        cout<<"ENTER THE START VERTEX AND END DESTINATION VERTEX"<<endl;
        cin>>start>>destination;
        addedge(graph,start,destination);
    }
    printgraph(graph);
}
