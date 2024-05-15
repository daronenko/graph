#pragma once

#include "graph/repr/base.hpp"

#include <vector>
#include <functional>
#include <cstdint>


namespace graph {

void BFS(
    const IGraph& graph,
    const std::function<void(vertex_t)>& func
);

}  // namespace graph

