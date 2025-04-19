/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * --------------------------------------
 * | @version  @date
 * |  V1.0.0    2025-04-18
 * ---------------------------------------
 * | @brief   : main template
 ******************************************************************************/
#include <stdio.h>   // C语言的标准库，包含C语言流操作 printf等
#include <iostream>  // 包含输入和输出操作
#include <string.h>  // C语言的标准库，包含字符串处理操作 strcpy等
#include <unistd.h>  // pause()头文件
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class Subject;

class Observer // 观察者
{
public:
    virtual void update(Subject *subject) = 0;
    int _hour;
    int _min;
    int _sec;
    Subject *_subject;
};

class Subject // 被观察者
{
public:
    void addRegister(Observer *observer) // 观察者注册
    {
        observerList.push_back(observer);
    }

    void delRegister(Observer *observer) // 观察者取消
    {
        observerList.erase(find(observerList.begin(), observerList.end(), observer));
    }
    void notify()
    {
        list<Observer *>::iterator itr;
        for (itr = observerList.begin(); itr != observerList.end(); ++itr)
        {
            (*itr)->update(this);
        }
    }

    int _hour;
    int _min;
    int _sec;
    list<Observer *> observerList; // 注册后的观察者集合
};

class ChinaClock:public Subject  //被观察者子类 北京时间
{
public:
    void set(int hour, int min, int sec)
    {
        cout<<"China clock is set"<<endl;
        _hour = hour;
        _min = min;
        _sec = sec;
        notify();              //被观察者发出通知
    }
};

class AmericaClock:public Observer //观察者子类 美国时间
{
public:
    AmericaClock(Subject * subject)
    {
        _subject = subject;
        _subject->addRegister(this);
    }
    void update(Subject * subject)
    {

        _hour = subject->_hour;
        _min  = subject->_min;
        _sec  = subject->_sec;
        dis();

    }
    void dis()
    {
        cout << "America clock is set" << endl;
        cout << "hour:" << _hour << "min:" << _min << "sec:" << _sec << endl;
    }
};

class LondenClock : public Observer // 观察者子类 英国时间
{
public:
    LondenClock(Subject *subject)
    {
        _subject = subject;
        _subject->addRegister(this);
    }
    void update(Subject *subject)
    {
        _hour = subject->_hour;
        _min = subject->_min;
        _sec = subject->_sec;
        dis();
    }
    void dis()
    {
        cout << "Londen clock is set" << endl;
        cout << "hour:" << _hour << "min:" << _min << "sec:" << _sec << endl;
    }
};

class JapanClock : public Observer // 观察者子类 日本时间
{
public:
    JapanClock(Subject *subject)
    {
        _subject = subject;
        _subject->addRegister(this);
    }
    void update(Subject *subject)
    {
        _hour = subject->_hour;
        _min = subject->_min;
        _sec = subject->_sec;
        dis();
    }
    void dis()
    {
        cout << "Japan clock is set" << endl;
        cout << "hour:" << _hour << "min:" << _min << "sec:" << _sec << endl;
    }
};

int main()
{
    printf("--------------------begain-------------------\n");
    ChinaClock   *cc  = new ChinaClock;       //创建北京时间被观察对象
 
    AmericaClock *ac  = new AmericaClock(cc); //创建美国时间观察对象
    LondenClock  *lc  = new LondenClock(cc);  //创建英国时间观察对象
    JapanClock   *jc  = new JapanClock(cc);   //创建日本时间观察对象

    cc->set(1,2,3);                           //改变被观察北京时间
    cout<<"-------------"<<endl;

    cc->delRegister(jc);                      //移除日本时间观察者

    cc->set(6,7,8);                           //再次改变被观察者时间

    printf("--------------------end----------------------\n");
    // cin.get();
    // getchar();
    // pause();
    return EXIT_SUCCESS;
}

/*****************************************************************************
 * end of file
 ******************************************************************************/
