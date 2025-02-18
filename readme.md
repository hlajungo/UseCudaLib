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

# Use CPM to download UseCudaLib
include(cmake/CPM.cmake)
CPMAddPackage("gh:hlajungo/UseCudaLib#v1.0.0")

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE UseCuda)
```

### generate documentation
```
doxygen
realpath html/index.html
```
