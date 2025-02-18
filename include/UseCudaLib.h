#pragma once
#include <iostream>
#include <type_traits>
#include <cuda_runtime.h>

// 父類：控制是否使用 CUDA
/**
 * @class Use_cuda
 * @brief Check whether has GPU.
 */
class Use_cuda {
  public:
    /**
     * @brief When constructing, has_gpu will be seted.
     */
    Use_cuda();

    /**
     * @brief Get has_gpu.
     * @return true = Has GPU.<br>
     * false = No GPU.
     */
    bool get_has_gpu();

    /**
     * @brief Check GPU and update variable has_gpu.
     * @return true = Has GPU.<br>
     * false = No GPU.
     */
    bool check_has_gpu();

  protected:

  private:
    bool has_gpu; ///< Whether has GPU.
    /**
     * @brief Set variable
     * @param val Value.
     */
    void set_has_gpu(bool val);

};
