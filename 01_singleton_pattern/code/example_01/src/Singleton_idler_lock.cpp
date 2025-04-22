/*****************************************************************************
 * | @file    : Singleton_idler_lock.c
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#include <iostream>

#include "Singleton_idler_lock.hpp"

using std::cin;
using std::cout;
using std::endl;
namespace Singleton_idler_lock {

// 初始化静态成员变量
// 静态成员变量必须在类的外部进行定义和初始化，因为类的声明仅仅是描述了静态成员变量的类型和名称，并没有为其分配实际的内存空间。
Singleton* Singleton::m_Singleton = nullptr;
std::mutex Singleton::m_Mutex;

// 注意：不能返回指针的引用，否则存在外部被修改的风险！
Singleton* Singleton::GetInstance()
{
    // 这里使用了两个 if
    // 判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
    // 避免每次调用 GetInstance的方法都加锁，锁的开销毕竟还是有点大的。
    if (m_Singleton == nullptr) {
        std::unique_lock<std::mutex> lock(m_Mutex);  // 加锁
        if (m_Singleton == nullptr) {
            volatile auto temp = new (std::nothrow) Singleton();
            m_Singleton        = temp;
        }
    }

    return m_Singleton;
}

void Singleton::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex);  // 加锁
    if (m_Singleton) {
        delete m_Singleton;
        m_Singleton = nullptr;
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

}  // namespace Singleton_idler_lock

/*****************************************************************************
 * end of file
 ******************************************************************************/
