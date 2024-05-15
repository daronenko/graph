#pragma once

#include "base.hpp"

#include <cstdint>
#include <vector>


namespace graph {

class MatrixGraph: public IGraph {
 public:
    explicit MatrixGraph(std::size_t size);

    explicit MatrixGraph(const IGraph& graph);

    void AddEdge(vertex_t from, vertex_t to) override;

    [[nodiscard]] std::size_t VerticesCount() const override;

    [[nodiscard]] std::vector<vertex_t> GetNextVertices(vertex_t vertex) const override;

    [[nodiscard]] std::vector<vertex_t> GetPrevVertices(vertex_t vertex) const override;

 private:
    std::vector<std::vector<bool>> adjacency_matrix_;
};

}  // namespace graph
