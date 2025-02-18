# UseCudaLib

A simple lib for detecting is there a GPU on computer.

### compile on linux
```
wget https://github.com/hlajungo/UseCudaLib/archive/refs/tags/v1.0.0.tar.gz
tar xf v1.0.0.tar.gz
cd UseCudaLib-1.0.0
cmake -S . -B ./build -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/PATH/TO/INSTALL -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel $(nproc)
cmake --install build
```

### install with CPM
```
cmake_minimum_required(VERSION 3.14)
project(MyProject LANGUAGES CXX CUDA)

include(cmake/CPM.cmake)
CPMAddPackage("gh:hlajungo/UseCudaLib#main")

add_executable(MyExecutable main.cpp)
target_include_directories(MyExecutable PRIVATE ${UseCudaLib_SOURCE_DIR}/include)
target_link_libraries(MyExecutable PRIVATE UseCudaLib)

install(TARGETS MyExecutable
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
```

### generate documentation
```
doxygen
realpath html/index.html
```
