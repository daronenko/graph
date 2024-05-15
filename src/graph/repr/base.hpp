#pragma once

#include <vector>
#include <cstdint>


namespace graph {

using vertex_t = std::uint64_t;

struct IGraph {
    virtual ~IGraph() {}

    // adding an edge from `from` to `to`.
    virtual void AddEdge(vertex_t from, vertex_t to) = 0;

    [[nodiscard]] virtual std::size_t VerticesCount() const  = 0;

    [[nodiscard]] virtual std::vector<vertex_t> GetNextVertices(vertex_t vertex) const = 0;
    [[nodiscard]] virtual std::vector<vertex_t> GetPrevVertices(vertex_t vertex) const = 0;
};

}  // namespace graph

