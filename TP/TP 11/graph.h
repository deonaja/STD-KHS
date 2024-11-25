#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct vertex* adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertex;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex_103032300101(char newVertexID, adrVertex &v);
void initGraph_103032300101(graph &g);
void addVertex_103032300101(graph &g, char newVertexID);
void buildGraph_103032300101(graph &g);



#endif // GRAPH_H_INCLUDED
