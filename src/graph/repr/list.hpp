#pragma once

#include "base.hpp"

#include <cstdint>
#include <vector>


namespace graph {

class ListGraph: public IGraph {
 public:
    explicit ListGraph(std::size_t size);

    explicit ListGraph(const IGraph& graph);

    void AddEdge(vertex_t from, vertex_t to) override;

    [[nodiscard]] std::size_t VerticesCount() const override;

    [[nodiscard]] std::vector<vertex_t> GetNextVertices(vertex_t vertex) const override;

    [[nodiscard]] std::vector<vertex_t> GetPrevVertices(vertex_t vertex) const override;

 private:
    std::vector<std::vector<vertex_t>> adjacency_lists_;
};

}  // namespace graph
