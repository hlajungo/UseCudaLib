cmake_minimum_required(VERSION 3.14)
project(UseCudaLib LANGUAGES CXX CUDA)

add_library(UseCuda STATIC UseCuda.cpp)
target_include_directories(UseCuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 如果你想支援 CUDA
set_target_properties(UseCuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# 安裝目標
install(TARGETS UseCuda EXPORT UseCudaTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES UseCuda.h DESTINATION include)

# 生成 CMake Package 配置文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/UseCudaConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

install(EXPORT UseCudaTargets
        FILE UseCudaTargets.cmake
        NAMESPACE UseCuda::
        DESTINATION lib/cmake/UseCuda)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/UseCudaConfigVersion.cmake"
    DESTINATION lib/cmake/UseCuda)

