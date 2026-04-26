#include <stdio.h> 

#define V 5   // number of vertices
#define E 6   // number of edges

int parent[V];  // array to store parent of each vertex (for union-find)

// function to find leader (root) of a set
int findLeader(int v) 
{ 
    // keep moving to parent until root is found
    while (parent[v] != v) 
        v = parent[v]; 

    return v; 
} 

// function to merge two sets
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 

    // make one root point to another
    parent[a] = b; 
} 

// function to sort edges based on weight (ascending)
void sortEdges(int edges[E][3]) 
{ 
    // using bubble sort
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            // compare edge weights
            if (edges[j][2] > edges[j + 1][2]) 
            { 
                // swap edges
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 

// function to apply Kruskal's algorithm
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges);  // sort edges first

    // initialize each vertex as its own parent
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int count = 0;  // number of edges selected
    int cost = 0;   // total cost of MST

    printf("Selected Edges:\n"); 

    // go through all edges
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0];  // start vertex
        int v = edges[i][1];  // end vertex
        int w = edges[i][2];  // weight

        // check if adding edge forms cycle
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 

            mergeSets(u, v);  // join sets
            cost += w;        // add weight
            count++;          // increase edge count
        }

        // stop when MST has V-1 edges
        if (count == V - 1) 
            break; 
    } 

    // print total cost
    printf("Total Cost: %d\n", cost); 
} 

int main() 
{ 
    // edge list: {source, destination, weight}
    int edges[E][3] = { 
        {0, 1, 2}, 
        {0, 2, 3}, 
        {1, 2, 5}, 
        {1, 3, 3}, 
        {2, 4, 4}, 
        {3, 4, 2}
    }; 

    // call Kruskal function
    kruskal(edges); 

    return 0; 
}
