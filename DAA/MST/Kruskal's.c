// AIM:
// To find Minimum Spanning Tree using Kruskal’s Algorithm.

#include <stdio.h>
#define V 5   // Number of vertices
#define E 6   // Number of edges
int parent[V];
// Function to find leader (root) of a set
int findLeader(int v) 
{
    while (parent[v] != v)
        v = parent[v];
    return v;
}
// Function to merge two sets
void mergeSets(int u, int v) 
{
    int a = findLeader(u);
    int b = findLeader(v);
    parent[a] = b;
}
// Function to sort edges based on weight (Bubble Sort)
void sortEdges(int edges[E][3]) 
{
    for (int i = 0; i < E - 1; i++) 
    {
        for (int j = 0; j < E - i - 1; j++) 
        {
            if (edges[j][2] > edges[j + 1][2]) 
            {
                // Swap entire edge (u, v, weight)
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
// Function to implement Kruskal’s Algorithm
void kruskal(int edges[E][3]) 
{
    // Sort edges by weight
    sortEdges(edges);
    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int count = 0, cost = 0;
    printf("Selected Edges:\n");
    // Pick edges one by one
    for (int i = 0; i < E; i++) 
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // Check if cycle is formed
        if (findLeader(u) != findLeader(v)) 
        {
            printf("%d -- %d (Weight: %d)\n", u, v, w);

            mergeSets(u, v);
            cost += w;
            count++;
        }
        // Stop when MST is formed
        if (count == V - 1)
            break;
    }
    printf("Total Cost: %d\n", cost);
}
int main() 
{
    // Edge list: {source, destination, weight}
    int edges[E][3] = {
        {0, 1, 2}, 
        {0, 2, 3}, 
        {1, 2, 5}, 
        {1, 3, 3}, 
        {2, 4, 4}, 
        {3, 4, 2}
    };
    // Function call
    kruskal(edges);
    return 0;
}
