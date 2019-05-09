/**
 * 简单工厂函数
 * @Author unknow
 */

typedef enum {
    T80 = 1,
    T99
} TankType;

class Tank {
public:
    virtual void message() = 0;
};

class Tank80 : public Tank {
public:
    void message () {
        cout << "Tank80" << endl;
    }
};

class Tank99 : public Tank {
public:
    void message () {
        cout << "Tank99" << endl;
    }
};

class TankFactory {
public:
    Tank* createTank (TankType type) {
        switch (type) {
        case 1:
            return new Tank80();
        case 2:
            return new Tank99();
        default:
            return NULL;
        }
    }
};