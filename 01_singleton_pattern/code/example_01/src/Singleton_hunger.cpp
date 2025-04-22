/*****************************************************************************
 * | @file    : Singleton_hunger.c
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#include <iostream>

#include "Singleton_hunger.hpp"

using std::cin;
using std::cout;
using std::endl;
namespace Singleton_hunger {

// 代码一运行就初始化创建实例 ，本身就线程安全
Singleton* Singleton::g_pSingleton = new (std::nothrow) Singleton();

Singleton* Singleton::GetInstance()
{
    return g_pSingleton;
}

void Singleton::deleteInstance()
{
    if (g_pSingleton) {
        delete g_pSingleton;
        g_pSingleton = nullptr;
    }
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

}  // namespace Singleton_hunger

/*****************************************************************************
 * end of file
 ******************************************************************************/
