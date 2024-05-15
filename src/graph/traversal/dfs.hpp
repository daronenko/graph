#pragma once

#include "graph/repr/base.hpp"

#include <vector>
#include <functional>
#include <cstdint>


namespace graph {

void DFS(
    const IGraph& graph,
    const std::function<void(vertex_t)>& func
);

}  // namespace graph

