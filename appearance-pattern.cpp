/**
 * 关键代码：客户与系统之间加一个外观层，外观层处理系统的调用关系、依赖关系等。
 * 以下实例以电脑的启动过程为例，客户端只关心电脑开机的、关机的过程，并不需要了解电脑内部子系统的启动过程。
 */
#include <iostream>
using namespace std;
 
// 抽象控件类，提供接口
class Control
{
public:
    virtual void start() = 0;
    virtual void shutdown() = 0;
};

// 子控件，主机
class Host: public Control
{
public:
    void start() override
    {
        cout << "Host start" << endl;
    }
    
    void shutdown() override
    {
        cout << "Host shutdown" << endl;
    }
};

// 子控件， 显示屏
class LCDDisplay: public Control
{
public:
    void start() override
    {
        cout << "LCD Display start" << endl;
    }
    
    void shutdown() override
    {
        cout << "LCD Display shutdonw" << endl;
    }
};

// 子控件， 外部设备
class Peripheral: public Control
{
public:
    void start() override
    {
        cout << "Peripheral start" << endl;
    }
    
    void shutdown() override
    {
        cout << "Peripheral shutdown" << endl;
    }
};

class Computer
{
public:
    void start()
    {
        m_host.start();
        m_display.start();
        m_peripheral.start();
        cout << "Computer start" << endl;
    }
    
    void shutdown()
    {
        m_host.shutdown();
        m_display.shutdown();
        m_peripheral.shutdown();
        cout << "Computer shutdown" << endl;
    }

private:
    Host m_host;
    LCDDisplay m_display;
    Peripheral m_peripheral;
};

int main()
{
    Computer computer;
    computer.start();

    // do something
    computer.shutdown();
    return 0;
}
