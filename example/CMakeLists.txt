cmake_minimum_required(VERSION 3.14)
project(MyProject LANGUAGES CXX CUDA)

include(cmake/CPM.cmake)
CPMAddPackage("gh:hlajungo/UseCudaLib#v1.0.0")

add_executable(MyExecutable main.cpp)
target_include_directories(MyExecutable PRIVATE ${UseCudaLib_SOURCE_DIR}/include)
target_link_libraries(MyExecutable PRIVATE UseCudaLib)

install(TARGETS MyExecutable
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

