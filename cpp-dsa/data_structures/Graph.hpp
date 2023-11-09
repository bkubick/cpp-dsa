#include <unordered_map>
#include <unordered_set>


class Graph {
    private:
        std::unordered_map<std::string, std::unordered_set<std::string> > adjacencyList;
    
    public:
        Graph(std::string vertex);
        ~Graph();
        bool addVertex(std::string vertex);
        bool addEdge(std::string vertex1, std::string vertex2);
        bool removeEdge(std::string vertex1, std::string vertex2);
        bool removeVertex(std::string vertex);
        void printGraph();
};
