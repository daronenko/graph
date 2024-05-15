#include "dfs.hpp"

#include "graph/repr/base.hpp"

#include <vector>
#include <functional>
#include <cstdint>


namespace graph {

namespace {

void DFS(
    const IGraph& graph,
    vertex_t vertex,
    std::vector<bool>& visited,
    const std::function<void(vertex_t)>& func
) {
    visited[vertex] = true;
    func(vertex);

    for (const auto& next_vertex: graph.GetNextVertices(vertex)) {
        if (!visited[next_vertex]) {
            DFS(graph, next_vertex, visited, func);
        }
    }
}

}  // namespace

void DFS(
    const IGraph& graph,
    const std::function<void(vertex_t)>& func
) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (std::size_t i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, func);
        }
    }
}

}  // namespace graph

