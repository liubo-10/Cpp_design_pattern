/*****************************************************************************
 * | @file    : Singleton_idler_lock.c
 * | @author  : liubo
 * --------------------------------------
 * | @version   @date
 * |  V1.0.0    2025-04-22
 * |            2025-05-20
 * ---------------------------------------
 * | @brief   : Singleton example
 ******************************************************************************/
#include <iostream>
#include <memory>

#include "Singleton_idler_lock2.hpp"

using std::cin;
using std::cout;
using std::endl;
namespace Singleton_idler_lock2 {

static std::shared_ptr<Singleton> singleton = nullptr;
static std::mutex                 singletonMutex;

std::shared_ptr<Singleton> Singleton::getSingleton()
{
    if (singleton == nullptr) {
        std::unique_lock<std::mutex> lock(singletonMutex);
        if (singleton == nullptr) {
            auto temp = std::shared_ptr<Singleton>(new Singleton());
            singleton = temp;
        }
    }
    return singleton;
}

void Singleton::Print()
{
    std::cout << "Hello World." << std::endl;
}

Singleton::Singleton()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Singleton::~Singleton()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}  // namespace Singleton_idler_lock2

/*****************************************************************************
 * end of file
 ******************************************************************************/
