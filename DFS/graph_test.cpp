#include <algorithm>
#include <gtest/gtest.h>
#include "graph.h"

int count = -1;//we will need this later in test
void discoverNode(unsigned a) {
}
void startNode(unsigned a) {
}
void endNode(unsigned a) {
}
void endNode2(unsigned a) {
    count++;
}

TEST(graph, addNode) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    EXPECT_TRUE(g.getNodesCount() == 5);

}

TEST(graph, dfsTest) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.dfs(startNode, endNode, discoverNode);
    EXPECT_TRUE(g.getNodesCount() == 5);
}


TEST(graph, payload) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(2, 3);
    g[2] = 5;
    EXPECT_TRUE(g[2] == 5);

}
TEST(graph, fileSaveLoad) {
    Graph<int> g;
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addNode();
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 2);
    g[1] = 51;
    g[2] = 4;
    g[4] = 123;
    g.saveToFile("imafile.txt");
    Graph<int> g2;
    g2.loadFromFile("imafile.txt");
    EXPECT_TRUE(g.getNodesCount() == g2.getNodesCount());
}

TEST(graph, bigGraphDfs) {
    Graph<int> g;
    unsigned n = 100;
    for (unsigned i = 0; i < n; ++i) {
        g.addNode();
    }
    for (unsigned j = 0; j < n; ++j) {
        for (unsigned i = 0; i < j; ++i) {
            g.addEdge(i,j);
        }
    }
    unsigned rightAnswer = (n * (n - 1)) / 2;
    g.dfs(startNode,endNode2,discoverNode);
    EXPECT_EQ(count,rightAnswer);
}

