#pragma once

#include "base.hpp"

#include <cstdint>
#include <set>


namespace graph {

class SetGraph: public IGraph {
 public:
    explicit SetGraph(std::size_t size);

    explicit SetGraph(const IGraph& graph);

    void AddEdge(vertex_t from, vertex_t to) override;

    [[nodiscard]] std::size_t VerticesCount() const override;

    [[nodiscard]] std::vector<vertex_t> GetNextVertices(vertex_t vertex) const override;

    [[nodiscard]] std::vector<vertex_t> GetPrevVertices(vertex_t vertex) const override;

 private:
    std::vector<std::set<vertex_t>> adjacency_sets_;
};

}  // namespace graph
