#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct coordinate{
    int T;
    int x[100];
    int y[100];
};

int extractMin(bool mst[], int v, int key[]) 
{
    int m = INT_MAX;
    int least_weight; 
  
    for (int i = 0; i < v; i++) 
        if (mst[i] == false && key[i] < m){
            m = key[i];
            least_weight = i; 
        }
  
    return least_weight; 
}

void printWeight(int v, int graph[15][15], int p[]){
    int total_weight = 0;
    for (int i = 1; i < v; i++){
        total_weight += graph[i][p[i]];
    }
    cout << "MST weight " << total_weight << endl;
}
  
void MST_prim(int v, int graph[15][15]) 
{
    int p[v], key[v];
    bool mst[v];
    for (int i = 0; i < v; i++){
        key[i] = INT_MAX;
        mst[i] = false; 
    }

    key[0] = 0; 
    p[0] = -1; 
  
    for (int i = 0; i < v-1; i++)
    {
        int u = extractMin(mst, v, key); 
        mst[u] = true;
        for (int j = 0; j < v; j++) 
            if (graph[u][j] < key[j] && graph[u][j] && mst[v] == false){
                p[j] = u; 
                key[j] = graph[u][j];
            }
    }

    printWeight(v, graph, p); 
}

int main() 
{
    ifstream file;
    file.open("graph.txt");
    
    coordinate c;

    file >> c.T;
    for (int i = 0; i < c.T; i++){
        int v;
        file >> v;
        int graph[15][15];
        for (int j = 0; j < v; j++){
            file >> c.x[j] >> c.y[j];
        }
        for (int k = 0; k < v; k++){
            for (int l = 0; l < v; l++){
                double weight = sqrt(pow(c.x[k] - c.x[l], 2) + pow(c.y[k] - c.y[l], 2));
                int closestweight = round(weight);
                graph[k][l] = closestweight;
            }
        }

        int x = i + 1;
        cout << "Test case " << x << ": ";
        MST_prim(v, graph);
        cout << endl;
    }

    return 0; 
}