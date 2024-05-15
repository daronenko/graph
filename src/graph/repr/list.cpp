#include "list.hpp"

#include <cassert>
#include <cstdint>


namespace graph {

ListGraph::ListGraph(std::size_t size): adjacency_lists_(size) {
}

ListGraph::ListGraph(const IGraph& graph): adjacency_lists_(graph.VerticesCount()) {
    for (vertex_t from = 0; from < graph.VerticesCount(); ++from) {
        adjacency_lists_[from] = graph.GetNextVertices(from);
    }
}

void ListGraph::AddEdge(vertex_t from, vertex_t to) {
    assert(from < VerticesCount());
    assert(to < VerticesCount());
    adjacency_lists_[from].push_back(to);
}

[[nodiscard]] std::size_t ListGraph::VerticesCount() const {
    return adjacency_lists_.size();
}

[[nodiscard]] std::vector<vertex_t> ListGraph::GetNextVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());
    return adjacency_lists_[vertex];
}

[[nodiscard]] std::vector<vertex_t> ListGraph::GetPrevVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> prev_vertices;
    for (vertex_t from = 0; from < VerticesCount(); ++from) {
        for (auto to: adjacency_lists_[from]) {
            if (to == vertex) {
                prev_vertices.push_back(from);
            }
        }
    }

    return prev_vertices;
}

}  // namespace graph
