#pragma once

#include "base.hpp"

#include <cstdint>
#include <utility>


namespace graph {

class ArcGraph: public IGraph {
    using edge_t = std::pair<vertex_t, vertex_t>;

 public:
    explicit ArcGraph(std::size_t size);

    explicit ArcGraph(const IGraph& graph);

    void AddEdge(vertex_t from, vertex_t to) override;

    [[nodiscard]] std::size_t VerticesCount() const override;

    [[nodiscard]] std::vector<vertex_t> GetNextVertices(vertex_t vertex) const override;

    [[nodiscard]] std::vector<vertex_t> GetPrevVertices(vertex_t vertex) const override;

 private:
    std::size_t vertices_count_;
    std::vector<edge_t> edges_;
};

}  // namespace graph
