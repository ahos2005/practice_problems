// BreadthFirstSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int src, dst;
};

class Graph {
public:
    vector<int>* adjList;   //Array of vectorsto represent the adjacency list

    Graph(vector<Edge> const &edges, int N) {
        adjList = new vector<int>[N];       //allocate memory
        int src = 0, dest = 0;
        for (unsigned i = 0; i < edges.size(); i++) {
            src = edges[i].src;
            dest = edges[i].dst;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }

    ~Graph() {
        delete[] adjList;
    }
};

void BFS(Graph const &graph, int v, vector<bool> &discovered) {
    queue<int> q;   //create a queue

    discovered[v] = true;   //mark the source vertex as discovered

    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : graph.adjList[v]) {
            if (!discovered[u]) {
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

void recursiveBFS(Graph const &graph, queue<int> &q, vector<bool> &discovered) {
    if (q.empty()) {
        return;
    }

    int v = q.front();
    q.pop();
    cout << v << " ";

    for (int u : graph.adjList[v]) {
        if (!discovered[u]) {
            discovered[u] = true;
            q.push(u);
        }
    }

    recursiveBFS(graph, q, discovered);
}

int main()
{
    // vector of graph edges
    vector<Edge> edges = {
        { 1, 2 },{ 1, 3 },{ 1, 4 },{ 2, 5 },{ 2, 6 },{ 5, 9 },
        { 5, 10 },{ 4, 7 },{ 4, 8 },{ 7, 11 },{ 7, 12 }
    };

    unsigned int N = 15;

    Graph graph(edges, N);

    vector<bool> discovered(N, false);

    for (unsigned i = 0; i < N; i++) {
        if (!discovered[i]) {
            BFS(graph, i, discovered);
        }
    }
    return 0;
}