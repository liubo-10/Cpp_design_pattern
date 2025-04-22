/*****************************************************************************
 * | @file    : Singleton_hunger.hpp
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#ifndef _SINGLETON_IDLER_LOCK_HPP_
#define _SINGLETON_IDLER_LOCK_HPP_

#include <mutex>

namespace Singleton_hunger {

// 饿汉实现
class Singleton {
  public:
    // 获取单实例
    static Singleton* GetInstance();

    // 释放单实例，进程退出时调用
    static void deleteInstance();

    // 打印实例地址
    void Print();

  private:
    // 将其构造和析构成为私有的, 禁止外部构造和析构
    Singleton();
    ~Singleton();

    // 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
    Singleton(const Singleton& signal);
    const Singleton& operator=(const Singleton& signal);

  private:
    // 唯一单实例对象指针
    static Singleton* g_pSingleton;
};

}  // namespace Singleton_hunger
#endif  // #ifndef _SINGLETON_IDLER_LOCK_HPP_

/*****************************************************************************
 * end of file
 ******************************************************************************/
