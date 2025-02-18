cmake_minimum_required(VERSION 3.14)
project(UseCudaLib LANGUAGES CXX CUDA)

add_library(UseCudaLib STATIC source/UseCudaLib.cu)

target_include_directories(UseCudaLib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# 如果你想支援 CUDA
set_target_properties(UseCudaLib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# 安裝目標
install(TARGETS UseCudaLib EXPORT UseCudaLibTargets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(FILES UseCudaLib.h DESTINATION include)

# 生成 CMake Package 配置文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/UseCudaLibConfigVersion.cmake"
  VERSION 1.0.0
  COMPATIBILITY SameMajorVersion
)

install(EXPORT UseCudaLibTargets
  FILE UseCudaLibTargets.cmake
  NAMESPACE UseCudaLib::
  DESTINATION lib/cmake/UseCudaLib)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/UseCudaLibConfigVersion.cmake"
  DESTINATION lib/cmake/UseCudaLib)

