/*
 * @filename ObjectMemPool.h
 * @brief 存放对象元素的内存池,可自动调用构造函数和析构函数
 * @author macwe@qq.com
 */

#ifndef _THEFOX_BASE_MEMPOOL_H_
#define _THEFOX_BASE_MEMPOOL_H_

#include <new>
#include <base/noncopyable.h>
#include <base/MemPool.h>

namespace thefox
{

template<typename T, int kBlockSize = 32>
class ObjectMemPool : MemPool<T, kBlockSize>
{
public:
    /// @brief 获取分配的内存
    T *get()
    {
        T *ret = MemPool::get();
        new(ret) T(); // placement new
		return ret;
    }
    
    void put(T *pointer)
    {
        pointer->~T();
		MemPool::put(pointer);
    }
};
    
} // namespace thefox

#endif // _THEFOX_BASE_MEMPOOL_H_