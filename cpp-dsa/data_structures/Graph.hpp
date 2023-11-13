#include <unordered_map>
#include <unordered_set>


class Graph {
    private:
        std::unordered_map<std::string, std::unordered_set<std::string> > adjacencyList;
    
    public:
        Graph(std::string vertex);
        ~Graph();

        /**
         * @brief Adds a vertex to the graph.
         * 
         * @param vertex The vertex to add.
         * @return true if the vertex was added successfully.
        */
        bool addVertex(std::string vertex);

        /**
         * @brief Adds an edge between two vertices.
         * 
         * @param vertex1 The first vertex.
         * @param vertex2 The second vertex.
         * @return true if the edge was added successfully.
        */
        bool addEdge(std::string vertex1, std::string vertex2);

        /**
         * @brief Removes an edge between two vertices.
         * 
         * @param vertex1 The first vertex.
         * @param vertex2 The second vertex.
         * @return true if the edge was removed successfully.
        */
        bool removeEdge(std::string vertex1, std::string vertex2);

        /**
         * @brief Removes a vertex from the graph.
         * 
         * @param vertex The vertex to remove.
         * @return true if the vertex was removed successfully.
        */
        bool removeVertex(std::string vertex);

        /**
         * @brief Prints the graph.
        */
        void printGraph();
};
