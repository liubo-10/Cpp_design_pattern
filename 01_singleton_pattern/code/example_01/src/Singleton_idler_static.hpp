/*****************************************************************************
 * | @file    : Singleton_idler_static.hpp
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#ifndef _SINGLETON_IDLER_STATIC_HPP_
#define _SINGLETON_IDLER_STATIC_HPP_

namespace Singleton_idler_static {
//  内部静态变量的懒汉实现
class Singleton {
  public:
    // 获取单实例对象
    static Singleton& GetInstance();

    // 打印实例地址
    void Print();

  private:
    // 禁止外部构造
    Singleton();

    // 禁止外部析构
    ~Singleton();

    // 禁止外部拷贝构造
    Singleton(const Singleton& single) = delete;

    // 禁止外部赋值操作
    const Singleton& operator=(const Singleton& single) = delete;
};
}  // namespace Singleton_idler_static

#endif  // #ifndef _SINGLETON_IDLER_STATIC_HPP_

/*****************************************************************************
 * end of file
 ******************************************************************************/
