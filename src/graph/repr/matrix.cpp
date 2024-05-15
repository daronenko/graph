#include "matrix.hpp"

#include <cassert>
#include <cstdint>


namespace graph {

MatrixGraph::MatrixGraph(std::size_t size): adjacency_matrix_(size) {
    for (auto& row: adjacency_matrix_) {
        row.resize(size, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph): adjacency_matrix_(graph.VerticesCount()) {
    for (vertex_t from = 0; from < graph.VerticesCount(); ++from) {
        adjacency_matrix_[from].resize(graph.VerticesCount(), false);
        auto to_vertices = graph.GetNextVertices(from);
        for (const auto& to: to_vertices) {
            adjacency_matrix_[from][to] = true;
        }
    }
}

void MatrixGraph::AddEdge(vertex_t from, vertex_t to) {
    assert(from < VerticesCount());
    assert(to < VerticesCount());
    adjacency_matrix_[from][to] = true;
}

[[nodiscard]] std::size_t MatrixGraph::VerticesCount() const {
    return adjacency_matrix_.size();
}

[[nodiscard]] std::vector<vertex_t> MatrixGraph::GetNextVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> next_vertices;
    for (vertex_t to = 0; to < VerticesCount(); ++to) {
        if (adjacency_matrix_[vertex][to]) {
            next_vertices.push_back(to);
        }
    }

    return next_vertices;
}

[[nodiscard]] std::vector<vertex_t> MatrixGraph::GetPrevVertices(vertex_t vertex) const {
    assert(vertex < VerticesCount());

    std::vector<vertex_t> prev_vertices;
    for (vertex_t from = 0; from < VerticesCount(); ++from) {
        if (adjacency_matrix_[from][vertex]) {
            prev_vertices.push_back(from);
        }
    }

    return prev_vertices;
}

}  // namespace graph
