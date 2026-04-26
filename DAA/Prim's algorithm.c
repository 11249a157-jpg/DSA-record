#include <stdio.h> 
#include <stdlib.h> 

#define V 5   // number of vertices in graph
  
// function to find vertex with minimum key value
int minKey(int key[], int visited[]) 
{ 
    int min = 999999;     // large value (acts like infinity)
    int min_index = 0;    // index of minimum value
 
    // find the smallest key among unvisited vertices
    for (int i = 0; i < V; i++) 
    { 
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 

// function to print the MST and total cost
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 

    int total = 0; 

    // start from 1 because 0 is root
    for (int i = 1; i < V; i++) 
    { 
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]];  // add weight to total
    } 

    printf("Total Cost = %d\n", total); 
} 

// function to apply Prim's algorithm
void primMST(int graph[V][V]) 
{ 
    int parent[V];   // to store MST
    int key[V];      // minimum weight to connect
    int visited[V];  // track visited vertices

    // initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    key[0] = 0;      // start from vertex 0
    parent[0] = -1;  // root has no parent

    // loop to build MST
    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minKey(key, visited);  // pick minimum key vertex
        visited[u] = 1;                // mark it visited

        // update adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            // update if edge exists, not visited, and smaller weight found
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 

    // print the MST
    printPrimMST(parent, graph); 
} 
 
int main() 
{ 
    // adjacency matrix representation of graph
    int graph[V][V] =
    { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0},
    }; 

    // call Prim's algorithm
    primMST(graph); 

    return 0; 
}
