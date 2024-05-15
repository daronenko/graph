#include "arc.hpp"

#include <cassert>
#include <cstdint>


namespace graph {

ArcGraph::ArcGraph(std::size_t size): vertices_count_(size) {
}

ArcGraph::ArcGraph(const IGraph& graph): vertices_count_(graph.VerticesCount()) {
    for (vertex_t from = 0; from < graph.VerticesCount(); ++from) {
        for (const auto& to: graph.GetNextVertices(from)) {
            edges_.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(vertex_t from, vertex_t to) {
    assert(from < VerticesCount());
    assert(to < VerticesCount());
    edges_.emplace_back(from, to);
}

[[nodiscard]] std::size_t ArcGraph::VerticesCount() const {
    return vertices_count_;
}

[[nodiscard]] std::vector<vertex_t> ArcGraph::GetNextVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> next_vertices;
    for (const auto& edge: edges_) {
        if (edge.first == vertex) {
            next_vertices.push_back(edge.second);
        }
    }

    return next_vertices;
}

[[nodiscard]] std::vector<vertex_t> ArcGraph::GetPrevVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> prev_vertices;
    for (const auto& edge: edges_) {
        if (edge.second == vertex) {
            prev_vertices.push_back(edge.first);
        }
    }

    return prev_vertices;
}

}  // namespace graph
