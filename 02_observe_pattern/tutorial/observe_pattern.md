* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu


# observe_pattern


# ✨观察者模式介绍
---
观察者模式定义了对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都将得到通知，并自动更新。观察者模式属于行为型模式，行为型模式关注的是对象之间的通讯，观察者模式就是观察者和被观察者之间的通讯。

“观察”不是“直接调用”，实现观察者模式的时候要注意，观察者和被观察对象之间的互动关系不能体现成类之间的直接调用，否则就将使观察者和被观察对象之间紧密的耦合起来，从根本上违反面向对象的设计的原则。不管是观察者“观察”对象，还是被观察者将自己的改变“通知”观察者，都不应该直接调用。

观察者模式中存在两种角色：
- 观察者： 内部包含被观察者对象，当被观察者对象的状态发⽣变化时，更新⾃⼰的状态。（接收通知更新状态）
- 被观察者（主题）： 内部包含了所有观察者对象，当状态发⽣变化时通知所有的观察者更新⾃⼰的状态。（发送通知）
  
# ✨使用观察者模式的场景
---
1. 当⼀个对象的改变需要同时改变其他对象，且不知道具体有多少对象有待改变时，应该考虑使用观察者模式；
2. ⼀个抽象模型有两个方面，其中⼀方面依赖于另⼀方面，这时可以用观察者模式将这两者封装在独立的对象中使它们各自独立地改变和复用。


## 🍰应用场景
世界时钟程序
    世界时钟程序，有多个图形时钟去显示比如北京时区，巴黎时区，等等。如果设置一个北京时间，那么其他时钟图形都需要根据时差更新时区时间。

温度程序图形界面
    一个温度程序，在温度条件改变时，需要更新显示图形来呈现。


# ✨发布-订阅模式
---
其实24种基本的设计模式中并没有发布订阅模式，也有说他只是观察者模式的一个别称。但是经过时间的沉淀，似乎他已经强大了起来，已经独立于观察者模式，成为另外一种不同的设计模式。

发布订阅模式也是一种一对多的依赖关系，称为发布者的消息发送者不会将消息直接发送给订阅者，这意味着发布者和订阅者不知道彼此的存在。在发布者和订阅者之间存在第三个组件，称为消息代理或调度中心或中间件或消息通道，它维持着发布者和订阅者之间的联系，过滤所有发布者传入的消息并相应地分发它们给订阅者。消息的发布者将消息发布到通道中，订阅者从通道中订阅消息。

当存在一个复杂的消息通信网络，多个发布者和多个订阅者之间需要进行灵活的消息交互时，可以使用发布-订阅模式。例如，分布式系统中的事件通知、消息队列等情况。

举一个例子，你在微博上关注了A，同时其他很多人也关注了A，那么当A发布动态的时候，微博就会为你们推送这条动态。A就是发布者，你是订阅者，微博就是调度中心，你和A是没有直接的消息往来的，全是通过微博来协调的（你的关注，A的发布动态）。

发布订阅模式中，有以下角色：
- 消息通道（Message Channel）： 用于发布者发布消息和订阅者订阅消息的中介。
- 发布者（Publisher）： 负责发布消息到消息通道。
- 订阅者（Subscriber）： 订阅感兴趣的消息类型，并从消息通道中接收相应的消息。



# ✨观察者模式和发布订阅模式有什么区别？
---
观察者模式（Observer Pattern）和发布-订阅模式（Publish-Subscribe Pattern）都是用于处理对象之间的一对多依赖关系，但它们在实现方式和应用场景上有一些异同。



## 🍰事件调度中心
观察者模式和发布订阅模式最大的区别就是发布订阅模式有个事件调度中心。

观察者模式，在目标和观察者之间是没有事件通道的。一方面，观察者要想订阅目标事件，由于没有事件通道，因此必须将自己添加到目标(Subject) 中进行管理；另一方面，目标在触发事件的时候，也无法将通知操作(notify) 委托给事件通道，因此只能亲自去通知所有的观察者。

发布订阅模式，相比观察者模式多了个事件通道，事件通道作为调度中心，统一由调度中心进行处理，管理事件的订阅和发布工作，订阅者和发布者互不干扰，彻底隔绝了发布者和订阅者之间的依赖，即订阅者在订阅事件的时候，只关注事件本身，而不关心谁会发布这个事件。这样一方面实现了解耦，还有就是可以实现更细粒度的一些控制。比如发布者发布了很多消息，但是不想所有的订阅者都接收到，就可以在调度中心做一些处理，类似于权限控制之类的。还可以做一些节流操作。

## 不同点：

实现方式：
    观察者模式通常是面向对象的，主题和观察者之间直接交互。
    发布-订阅模式使用中介（消息通道）来进行消息的发布和订阅，发布者和订阅者之间没有直接的耦合关系。
通信方式： 
    观察者模式中主题主动通知观察者
    发布-订阅模式中发布者和订阅者之间通过消息通道进行通信。
灵活性： 
    发布-订阅模式更具有灵活性，可以支持多对多的关系
    观察者模式通常是一对多的关系。


# ✨总结

---

以上就是今天要讲的内容，后续会有更多内容。

  
  
  

# ✨参考资料

---

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。

1. ===

2.

  
  
  




























# 五、观察者模式优缺点

优点：

开闭原则：无需修改发布者的代码就能够引入新的订阅者
可以在运行时建立对象之间的联系
依赖倒置：让耦合的双方都依赖于抽象，而不是依赖于具体
缺点：

过多的更新操作：如果观察者很多，而且每个观察者对主题的状态变化都做出相应的反应，可能会导致系统的性能下降
可能引起循环依赖： 如果观察者之间存在相互依赖，可能导致循环更新，从而影响系统的稳定性和可维护性。





# 六、代码示例



被观察者（主题）

```c++
// 主题类
class Subject
{
public:
    void addObserver(Observer *obser, int msgid)
    {
        // map添加数据的方法1
        _subMap[msgid].push_back(obser);

        /**
         * 当_subMap[msgid]不存在时等价于
         * list<Observer*> mylist;
         * mylist.push_back(obser)
         * _subMap[msgid] = mylist */

        // map添加数据的方法2：
        /*
        auto it = _subMap.find(msgid); //
        if (it != _subMap.end())
        {
            it->second.push_back(obser);
        }
        else
        {
            list<Observer*> lis;
            lis.push_back(obser);
            _subMap.insert({ msgid,lis });
        }
        */
    }
    // 主题检测发生改变，通知相应的观察者对象处理事件
    void dispatch(int msgid)
    {
        auto it = _subMap.find(msgid);
        if (it != _subMap.end())
        {
            for (Observer *pObser : it->second)
            {
                pObser->handle(msgid);
            }
        }
    }

private:
    unordered_map<int, list<Observer *>> _subMap;
};
```



观察者

```c++
class Observer
{
public:
    // 处理消息的接口
    virtual void handle(int msgid) = 0;
};

// 第一个观察者实例
class Observer1 : public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
        case 1:
            cout << "Observer1 recv 1 msg!" << endl;
            break;
        case 2:
            cout << "Observer1 recv 2 msg!" << endl;
            break;
        default:
            cout << "Observer1 recv unknow msg!" << endl;
            break;
        }
    }
};

//第二个观察者实例
class Observer2 :public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
        case 1:
            cout << "Observer2 recv 1 msg!" << endl;
            break;
        case 3:
            cout << "Observer2 recv 3 msg!" << endl;
            break;
        default:
            cout << "Observer2 recv unknow msg!" << endl;
            break;
        }
    }
};

//第三个观察者实例
class Observer3 :public Observer
{
  public:
    void handle(int msgid)
    {
        switch (msgid)
        {
            case 2:
                cout << "Observer3 recv 2 msg!" << endl;
                break;
            case 3:
                cout << "Observer3 recv 3 msg!" << endl;
                break;
            default:
                cout << "Observer3 recv unknow msg!" << endl;
                break;
        }
    }
};

```



main函数

```c++
int main()
{
    cout << "----------------begain------------------" << endl;
    
    Subject subject;
    Observer* p1 = new Observer1();
    Observer* p2 = new Observer2();
    Observer* p3 = new Observer3();
    
    subject.addObserver(p1, 1);
    subject.addObserver(p1, 2);
    subject.addObserver(p2, 2);
    subject.addObserver(p3, 1);
    subject.addObserver(p3, 3);
    
    int msgid = 0;
    for (;;)
    {
        cout << "输入消息id:";
        cin >> msgid;
        if (msgid == -1)
            break;
        subject.dispatch(msgid);
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}
```







# 七、总结

以上就是今天要讲的内容，后续会有更多内容。



# 八、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
1. https://blog.csdn.net/bandaoyu/article/details/83385482
1. https://blog.csdn.net/m0_56069910/article/details/136642360
1. https://blog.csdn.net/hf872914334/article/details/88899326
1. https://blog.csdn.net/m0_56069910/article/details/136642360
1. https://blog.csdn.net/linux_wgl/article/details/50178539









---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---

