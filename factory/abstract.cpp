/**
 * 抽象工厂
 * @Author unknow
 */
class Tank {
    public:
        virtual void message() = 0;
};

class Tank80:public Tank {
    public:
        void message () {
            cout << "Tank80" << endl;
        }
};

class Tank99:public Tank {
    public:
        void message () {
            cout << "Tank99" << endl;
        }
};

class Plain {
    public:
        virtual void message() = 0;
};

class Plain80 : public Plain {
    public:
        void message () {
            cout << "Plain80" << endl;
        }
};

class Plain99 : public Plain {
    public:
        void message () {
            cout << "Plain99" << endl;
        }
};

class Factory {
    public:
        virtual Tank* createTank() = 0;
        virtual Plain* createPlain() = 0;
};

class Factory80 : public Factory {
    public:
        Tank* createTank () {
            return new Tank80();
        }

        Plain* createPlain () {
            return new Plain80();
        }
};

class Factory99 : public Factory {
    public:
        Tank* createTank () {
            return new Tank99();
        }

        Plain* createPlain () {
            return new Plain99();
        }
};
