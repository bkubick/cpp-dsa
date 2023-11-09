#include <iostream>

#include "Graph.hpp"


Graph::Graph(std::string vertex)
{
    addVertex(vertex);
}


bool Graph::addVertex(std::string vertex)
{
    if (adjacencyList.count(vertex) != 0) return false;

    adjacencyList[vertex];

    return true;
}


bool Graph::addEdge(std::string vertex1, std::string vertex2)
{
    if (adjacencyList.count(vertex1) == 0 || adjacencyList.count(vertex2) == 0) return false;

    adjacencyList[vertex1].insert(vertex2);
    adjacencyList[vertex2].insert(vertex1);

    return true;
}


bool Graph::removeEdge(std::string vertex1, std::string vertex2)
{
    if (adjacencyList.count(vertex1) == 0 || adjacencyList.count(vertex2) == 0) return false;

    adjacencyList[vertex1].erase(vertex2);
    adjacencyList[vertex2].erase(vertex1);

    return true;
}


bool Graph::removeVertex(std::string vertex)
{
    if (adjacencyList.count(vertex) == 0) return false;

    for (auto edge : adjacencyList[vertex])
    {
        adjacencyList[edge].erase(vertex);
    }

    adjacencyList.erase(vertex);

    return true;
}


void Graph::printGraph()
{
    for (auto vertex : adjacencyList)
    {
        std::cout << vertex.first << ": [ ";
        for (auto edge : vertex.second)
        {
            std::cout << edge << " ";
        }
        std::cout << "]" << std::endl;
    }
}


int main()
{
    Graph* graph = new Graph("A");
    graph->addVertex("B");
    graph->addVertex("C");

    graph->addEdge("A", "B");
    graph->addEdge("A", "C");
    graph->addEdge("B", "C");

    std::cout << "--------------------------" << std::endl;
    graph->printGraph();

    graph->removeEdge("A", "B");

    std::cout << "--------------------------" << std::endl;
    graph->printGraph();

    graph->removeVertex("C");

    std::cout << "--------------------------" << std::endl;
    graph->printGraph();
}
