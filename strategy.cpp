/**
 * 方法函数
 * @Author unknow
 */

// 传统策略模式实现
class Hurt {
    public:
        virtual void redBuff() = 0;
};

class AdcHurt : public Hurt {
    public:
        void redBuff () {
            cout << "Adc hurt" << endl;
        }
};

class ApcHurt : public Hurt {
    public:
        void redBuff () {
            cout << "Apc hurt" << endl;
        }
};

// 传入一个指针参数
class Soldier {
    public:
        Soldier (Hurt* hurt) : m_hurt(hurt){}
        ~Soldier () {}
        
        void beInjured () {
            m_hurt->redBuff();
        }
    private:
        Hurt* m_hurt;
};

// 传入一个参数标签
typedef enum {
    adc,
    apc
} HurtType;

class Master {
    public:
        Master (HurtType type) {
            switch (type) {
            case adc:
                m_hurt = new AdcHurt;
                break;
            case apc:
                m_hurt = new ApcHurt;
                break;
            default:
                m_hurt = NULL;
                break;
            }
        }
        ~Master () {}

        void beInjured () {
            if(m_hurt != NULL) {
                m_hurt->redBuff();
            } else {
                cout << "Not hurt" << endl;
            }
        }
    private:
        Hurt* m_hurt;
};

// 使用模板类
template <typename T>
class Tank {
    public:
        void beInjured () {
            m_hurt.redBuff();
        }
    private:
        T m_hurt;
};

// 使用函数指针实现策略模式
void adcHurt (int num) {
    cout << "adc hurt:" << num << endl;
}

void apcHurt (int num) {
    cout << "apc hurt:" << num << endl;
}

// 普通函数指针
class Aid {
    public:
        typedef void (*HurtFun)(int);
        
        Aid (HurtFun fun) : m_fun (fun) {}

        void beInjured (int num) {
            m_fun(num);
        }
    private:
        HurtFun m_fun;
};

// 使用std::function，头文件：#include<functional>
class Bowman {
    public:
        typedef std::function<void(int)> HurtFunc;

        Bowman (HurtFunc fun) : m_fun(fun) {}
        
        void beInjured (int num) {
            m_fun(num);
        }
    private:
        HurtFunc m_fun;
};