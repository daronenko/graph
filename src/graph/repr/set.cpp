#include "set.hpp"

#include <cassert>
#include <cstdint>


namespace graph {

SetGraph::SetGraph(std::size_t size): adjacency_sets_(size) {
}

SetGraph::SetGraph(const IGraph& graph): adjacency_sets_(graph.VerticesCount()) {
    for (vertex_t from = 0; from < graph.VerticesCount(); ++from) {
        for (const auto& to: graph.GetNextVertices(from)) {
            adjacency_sets_[from].insert(to);
        }
    }
}

void SetGraph::AddEdge(vertex_t from, vertex_t to) {
    assert(from < VerticesCount());
    assert(to < VerticesCount());
    adjacency_sets_[from].insert(to);
}

[[nodiscard]] std::size_t SetGraph::VerticesCount() const {
    return adjacency_sets_.size();
}

[[nodiscard]] std::vector<vertex_t> SetGraph::GetNextVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> next_vertices;
    for (const auto& to: adjacency_sets_[vertex]) {
        next_vertices.push_back(to);
    }

    return next_vertices;
}

[[nodiscard]] std::vector<vertex_t> SetGraph::GetPrevVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> prev_vertices;
    for (vertex_t from = 0; from < VerticesCount(); ++from) {
        if (adjacency_sets_[from].contains(vertex)) {
            prev_vertices.push_back(from);
        }
    }

    return prev_vertices;
}

}  // namespace graph
