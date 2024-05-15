add_library(${PROJECT_NAME}_objs OBJECT
        graph/repr/base.hpp
        graph/repr/list.hpp
        graph/repr/list.cpp
        graph/repr/matrix.hpp
        graph/repr/matrix.cpp
        graph/repr/set.hpp
        graph/repr/set.cpp
        graph/repr/arc.hpp
        graph/repr/arc.cpp
        graph/traversal/dfs.hpp
        graph/traversal/dfs.cpp
        graph/traversal/bfs.hpp
        graph/traversal/bfs.cpp
        graph/traversal/topological_sort.hpp
        graph/traversal/topological_sort.cpp
)
target_include_directories(${PROJECT_NAME}_objs PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objs)
