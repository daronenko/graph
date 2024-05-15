#pragma once

#include "graph/repr/base.hpp"

#include <vector>
#include <deque>


namespace graph {

std::deque<vertex_t> TopologicalSort(const IGraph& graph);

}  // namespace graph
