/*****************************************************************************
 * | @file    : Singleton_idler_static.c
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : Singleton example 局部静态变量的懒汉实现
 ******************************************************************************/
#include <iostream>

#include "Singleton_idler_static.hpp"

using std::cin;
using std::cout;
using std::endl;
namespace Singleton_idler_static {
Singleton& Singleton::GetInstance()
{
    /**
     * 局部静态特性的方式实现单实例。
     * 静态局部变量只在当前函数内有效，其他函数无法访问。
     * 静态局部变量只在第一次被调用的时候初始化，也存储在静态存储区，生命周期从第一次被初始化起至程序结束止。
     */
    static Singleton Singleton;
    return Singleton;
}

void Singleton::Print()
{
    std::cout << "我的实例内存地址是:" << this << std::endl;
}

Singleton::Singleton()
{
    std::cout << "构造函数" << std::endl;
}

Singleton::~Singleton()
{
    std::cout << "析构函数" << std::endl;
}
}  // namespace Singleton_idler_static

/*****************************************************************************
 * end of file
 ******************************************************************************/
