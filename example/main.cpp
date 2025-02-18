#include <iostream>
#include <type_traits>
#include <cuda_runtime.h>

#include "UseCudaLib.h"

class My_compute : public Use_cuda
{
public:
  virtual void my_compute(int x) = 0;
};

// 子類：定義不同版本的函數
class My_cuda_task : public My_compute
{
  public:

    // CUDA 版本
    void my_compute(int x) override
    {
      std::cout << "MyCudaTask: x = " << x << std::endl;
    }

};

class My_cpu_task : public My_compute
{
  public:
    // CPU 版本
    void my_compute(int x)
    {
      std::cout << "MyCpuTask: x = " << x << std::endl;
    }
};


int main() {

  My_compute* mc0 = new My_cpu_task();
  mc0->my_compute(0);

  My_compute* mc1 = new My_cuda_task();
  if (!mc1->get_has_gpu())
  {
    std::cerr << "Didn't find available GPU." << std::endl;
    return 1;
  }
  mc1->my_compute(1);


  return 0;
}



