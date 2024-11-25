#include "graph.h"

void createVertex_103032300101(char newVertexID, adrVertex &v) {
    v->idVertex = newVertexID;
    v->firstEdge = NULL;
    v->nextVertex = NULL;
}

void initGraph_103032300101(graph &g) {
    g.firstVertex = NULL;
}

void addVertex_103032300101(graph &g, char newVertexID) {
    adrVertex v = new vertex;
    createVertex_103032300101(newVertexID, v);
    if (g.firstVertex == NULL) {
        g.firstVertex = v;
    } else {
        adrVertex q = g.firstVertex;
        while(q->nextVertex != NULL) {
            q = q->nextVertex;
        }
        q->nextVertex = v;
    }
}

void buildGraph_103032300101(graph &g) {
    char input;
    cin >> input;
    while (input >= 'A' && input <= 'Z') {
        if (g.firstVertex == NULL) {
            addVertex_103032300101(g, input);
        } else {
            bool unique = true;
            adrVertex v = g.firstVertex;
            while (v != NULL && unique) {
                if (v->idVertex == input) {
                    unique = false;
                }
                v = v->nextVertex;
            }
            if (unique) {
                addVertex_103032300101(g, input);
            } else {
                cout << "ID Sudah ada" << endl;
            }
        }
        cin >> input;
    }
}


