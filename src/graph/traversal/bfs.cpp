#include "dfs.hpp"

#include "graph/repr/base.hpp"

#include <vector>
#include <functional>
#include <cstdint>
#include <queue>


namespace graph {

namespace {

void BFS(
    const IGraph& graph,
    vertex_t vertex,
    std::vector<bool>& visited,
    const std::function<void(vertex_t)>& func
) {
    std::queue<vertex_t> queue;
    queue.push(vertex);
    visited[vertex] = true;
    
    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        
        func(currentVertex);
        
        for (int next_vertex: graph.GetNextVertices(currentVertex)) {
            if (!visited[next_vertex]) {
                visited[next_vertex] = true;
                queue.push(next_vertex);
            }
        }
    }
}

}  // namespace

void BFS(
    const IGraph& graph,
    const std::function<void(vertex_t)>& func
) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    
    for (vertex_t i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, func);
        }
    } 
}

}  // namespace graph
