#include <iostream>
#include <fstream>
#include <cstdlib>
#include "eulerian.h"
using namespace std;


int main()
{
    cout<<"Number of tops:  ";
    int n;
    cin>>n; // Количество вершин
    int zn;// Текущее значение
    Node **graph;
    graph=new Node*[n];
    for(int i=0; i<n; i++)graph[i]=NULL;

    fstream open_file("matrix.txt");
    for(int i=0; i<n; i++) // заполняем массив списков
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            open_file>>zn;
            if (zn)
                add(graph[i],j);
            cout<<zn<<" ";
        }
    }
    /*for(int i=0; i<n; i++) // заполняем массив списков
        for(int j=0; j<n; j++)
        {
            cin>>zn;
            if (zn)
                add(graph[i],j);
        }*/
    cout<<"\n\nThe result  ";

    if(eiler(graph,n))eiler_path(graph);
    else cout<<"The graph is not Eulerian.";

    return 0;

}
