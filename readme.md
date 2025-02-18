

### compile on linux
```
wget https://github.com/hlajungo/UseCudaLib/archive/refs/tags/1.0.0.tar.gz
tar xf UseCudaLib-1.0.0.tar.gz
cd UseCudaLib
cmake -S . -B ./build -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/PATH/TO/INSTALL -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel $(nproc)
cmake --install build
```

### install with CPM
```
cmake_minimum_required(VERSION 3.14)
project(MyProject LANGUAGES CXX CUDA)

# Use CPM to download UseCudaLib
include(FetchContent)
FetchContent_Declare(
    UseCuda
    GIT_REPOSITORY https://github.com/your-username/UseCudaLib.git
    GIT_TAG main
)
FetchContent_MakeAvailable(UseCuda)

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE UseCuda)
```
