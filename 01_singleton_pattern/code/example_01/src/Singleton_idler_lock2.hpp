/*****************************************************************************
 * | @file    : Singleton_idler_lock.hpp
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-05-20
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#ifndef _SINGLETON_IDLER_LOCK_HPP_
#define _SINGLETON_IDLER_LOCK_HPP_

#include <iostream>
#include <memory>
#include <mutex>

namespace Singleton_idler_lock2 {
// 加锁的懒汉式实现
class Singleton {
  public:
    static std::shared_ptr<Singleton> getSingleton();  // 获取单实例对象

    void Print();  // 打印实例地址
    ~Singleton();

  private:

    Singleton();
};
}  // namespace Singleton_idler_lock2
#endif  // #ifndef _SINGLETON_IDLER_LOCK_HPP_

/*****************************************************************************
 * end of file
 ******************************************************************************/
