#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <functional>
#include <stack>
#include <vector>

template<typename NodePayload>
class Graph {
public:
    typedef unsigned NodeHandle; // Unique ID for each node.
    typedef std::pair<NodeHandle, NodeHandle> EdgeHandle; // Pair of NodeHandle
    typedef std::function<void(NodeHandle const &)> NodeVisitor; // Custom function for node.
    typedef std::function<void(EdgeHandle const &)> EdgeVisitor; // Custom function for edge.

private:
    std::vector<NodePayload> nodePayloads;
    std::vector<std::vector<NodeHandle> > graph;

public:
    // Constructor
    Graph() = default; 
    // Destructor
    ~Graph() = default; 
    
    // Load graph from file
    void loadFromFile(std::string const &filename); 
    // Save graph in file
    void saveToFile(std::string const &filename); 
    // Add new node
    NodeHandle addNode(); 
    // Add new edge
    void addEdge(NodeHandle const &a, NodeHandle const &b); 
    // Run custom function for each node.
    void forEachNode(std::function<void(NodeHandle const &)> const &visitor) const; 
    // Get nodes count
    size_t getNodesCount() const;

    void forEachEdge(EdgeVisitor const &visitor);

    // Get the end of edge, starting in this node
    NodeHandle move(NodeHandle const &origin, EdgeHandle const &edge); 
    // Return payload of selected node.
    NodePayload &operator[](NodeHandle const &node);
    // DFS
    void dfs(NodeVisitor const &startNode, NodeVisitor const &endNode, NodeVisitor const &discoverNode);
};

template<typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::addNode() {
    NodeHandle nodeHandle = nodePayloads.size() + 1;
    nodePayloads.push_back(0);
        graph.push_back(std::vector<NodeHandle>(nodeHandle));
    for (int i = 0; i < nodeHandle; ++i) {
        graph[i].push_back(0);
    }
    return nodeHandle;
}

template<typename NodePayload>
size_t  Graph<NodePayload>::getNodesCount() const {
    return nodePayloads.size();
}

template<typename NodePayload>
NodePayload &Graph<NodePayload>::operator[](Graph::NodeHandle const &node) {
    return nodePayloads[node];
}

template<typename NodePayload>
void Graph<NodePayload>::addEdge(Graph::NodeHandle const &a, Graph::NodeHandle const &b) {
    graph[a][b] = 1;
}

template<typename NodePayload>
void Graph<NodePayload>::forEachNode(std::function<void(NodeHandle const &)> const &visitor) const {
    for (NodeHandle nodeHandle = 0; nodeHandle < getNodesCount(); ++nodeHandle) {
        visitor(nodeHandle);
    }
}

template<typename NodePayload>
void Graph<NodePayload>::forEachEdge(Graph::EdgeVisitor const &visitor) {
    for (unsigned i = 0; i < getNodesCount(); ++i) {
        for (unsigned j = 0; j < getNodesCount(); ++j) {
            if (graph[i][j] == 1) {
                EdgeHandle edgeHandle;
                edgeHandle.first = i, edgeHandle.second = j;
                visitor(edgeHandle);
            }
        }
    }
}

template<typename NodePayload>
void Graph<NodePayload>::dfs(Graph::NodeVisitor const &startNode,
        Graph::NodeVisitor const &endNode, Graph::NodeVisitor const &discoverNode) {
    const int IN = 0;
    const int OUT = 1;
    std::vector<int> used(getNodesCount());
    std::stack<std::pair<int, int>> st;
    int n = getNodesCount();
    st.push(std::make_pair(0, IN));
    while (!st.empty()) {
        std::pair<int, int> p = st.top();
        st.pop();
        if (p.second == IN) {
            startNode(p.first);
            std::vector<int> temp;
            st.push(std::make_pair(p.first, OUT));
            for (int i = 0; i < n; ++i) {
                if (graph[p.first][i]) {

                    discoverNode(i);
                    temp.push_back(i);
                }
            }
            for (int i = temp.size() - 1; i >= 0; i--) {
                if (!used[temp[i]])
                    st.push(std::make_pair(temp[i], IN));

            }
        }
        else {
            used[p.first] = OUT;
                        endNode(p.first);
        }
    }

}

template<typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::move(Graph<NodePayload>::NodeHandle const &origin, Graph<NodePayload>::EdgeHandle const &edge) {
    return origin == edge.first ? edge.second : edge.first;
}

template<typename NodePayload>
void Graph<NodePayload>::saveToFile(std::string const &filename) {
    std::ofstream fout(filename);
    fout << getNodesCount() << "\n";
    for (unsigned i = 0; i < getNodesCount(); ++i)
        fout << nodePayloads[i] << " ";
    fout << "\n";
    for (unsigned i = 0; i < getNodesCount(); ++i) {
        for (unsigned j = 0; j < getNodesCount(); ++j) {
            fout << graph[i][j] << " ";
        }
        fout << "\n";
    }
    fout.close();

}

template<typename NodePayload>
void Graph<NodePayload>::loadFromFile(std::string const &filename) {

    std::ifstream fin;
    fin.open(filename);
    unsigned n = 0;
    fin >> n;
    nodePayloads.resize(n);
    for (unsigned i = 0; i < n; ++i)
        fin >> nodePayloads[i];
    graph.resize(n);
    for (unsigned i = 0; i < n; ++i) {
        graph[i].resize(n);
        for (unsigned j = 0; j < n; ++j) {
            fin >> graph[i][j];
        }
    }
    fin.close();
}


#endif