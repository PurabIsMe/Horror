cmake_minimum_required(VERSION 3.0.0)
project(VoxelDance VERSION 0.1.0)

include(CTest)
enable_testing()

#add_executable(VoxelDance main.cpp IndexBuffer.h VertexArray.h VertexBuffer.h VertexBufferLayout.h IndexBuffer.cpp VertexArray.cpp VertexBuffer.cpp)
add_executable(VoxelDance main.cpp IndexBuffer.cpp VertexArray.cpp VertexBuffer.cpp)
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(VoxelDance glfw GLEW GL GLU)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
