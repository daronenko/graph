#include "topological_sort.hpp"

#include "graph/repr/base.hpp"

#include <vector>
#include <deque>


namespace graph {

namespace {

void TopologicalSort(
    const IGraph& graph,
    vertex_t vertex,
    std::vector<bool>& visited,
    std::deque<vertex_t>& sorted
) {
    visited[vertex] = true;

    for (const auto& next_vertex: graph.GetNextVertices(vertex)) {
        if (!visited[next_vertex]) {
            TopologicalSort(graph, next_vertex, visited, sorted);
        }
    }

    sorted.push_front(vertex);
}

}

std::deque<vertex_t> TopologicalSort(const IGraph& graph) {
    std::deque<vertex_t> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (vertex_t i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            TopologicalSort(graph, i, visited, sorted);
        }
    }

    return sorted;
}

}  // namespace graph

