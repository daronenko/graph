#include "graph/repr/base.hpp"
#include "graph/repr/list.hpp"
#include "graph/repr/matrix.hpp"
#include "graph/repr/set.hpp"
#include "graph/repr/arc.hpp"

#include  "graph/traversal/dfs.hpp"
#include  "graph/traversal/bfs.hpp"
#include  "graph/traversal/topological_sort.hpp"

#include <iostream>


int main() {
    graph::ListGraph list_graph(7);

    list_graph.AddEdge(0, 1);
    list_graph.AddEdge(0, 5);
    list_graph.AddEdge(1, 2);
    list_graph.AddEdge(1, 3);
    list_graph.AddEdge(1, 5);
    list_graph.AddEdge(1, 6);
    list_graph.AddEdge(3, 2);
    list_graph.AddEdge(3, 4);
    list_graph.AddEdge(3, 6);
    list_graph.AddEdge(5, 4);
    list_graph.AddEdge(5, 6);
    list_graph.AddEdge(6, 4);

    std::cout << "List Graph" << std::endl;

    std::cout << "BFS: ";
    graph::BFS(list_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "DFS: ";
    graph::DFS(list_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "Topological Sort: ";
    for (const auto& vertex: graph::TopologicalSort(list_graph)) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////

    graph::MatrixGraph matrix_graph(list_graph);

    std::cout << std::endl << "Matrix Graph" << std::endl;

    std::cout << "BFS: ";
    graph::BFS(matrix_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "DFS: ";
    graph::DFS(matrix_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "Topological Sort: ";
    for (const auto& vertex: TopologicalSort(matrix_graph)) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////

    graph::SetGraph set_graph(matrix_graph);

    std::cout << std::endl << "Set Graph" << std::endl;

    std::cout << "BFS: ";
    BFS(set_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "DFS: ";
    DFS(set_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "Topological Sort: ";
    for (const auto& vertex: TopologicalSort(set_graph)) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////

    graph::ArcGraph arc_graph(set_graph);

    std::cout << std::endl << "Arc Graph" << std::endl;

    std::cout << "BFS: ";
    BFS(arc_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "DFS: ";
    DFS(arc_graph, [](graph::vertex_t vertex){
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;

    std::cout << "Topological Sort: ";
    for (const auto& vertex: TopologicalSort(arc_graph)) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    return 0;
}
