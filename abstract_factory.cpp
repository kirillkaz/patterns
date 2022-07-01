#include <iostream>

class Bar{
public:
    virtual std::string getSize() = 0;
};

class Pack{
public:
    virtual void showBrend() = 0;
};

class СhocolateInterface{
public:
    virtual Bar* createBar() = 0;
    virtual Pack* createPack() = 0;
};

class MilkaBar : public Bar{
public:
    std::string getSize() override{
        return "3x5";
    }
};

class AlpenGoldBar : public Bar{
public:
    std::string getSize() override{
        return "3x6";
    }
};

class MilkaPack : public Pack{
public:
    void showBrend() override{
        std::cout<<"Milka"<<std::endl;
    }
};

class AlpenGoldPack : public Pack{
public:
    void showBrend() override{
        std::cout<<"AplenGold"<<std::endl;
    }
};

class Milka : public СhocolateInterface{
public:
    Bar* createBar() override{
        return new MilkaBar;
    }

    Pack* createPack() override{
        return new MilkaPack;
    }
};

class AlpenGold : public СhocolateInterface{
public:
    Bar* createBar() override{
        return new AlpenGoldBar;
    }

    Pack* createPack() override{
        return new AlpenGoldPack;
    }
};

class ChocolateFactory{
    СhocolateInterface* m_interface;
public:
    ChocolateFactory(СhocolateInterface* interface){
        this->m_interface = interface;
    }

    void showParammetrs(){
        auto* pack = this->m_interface->createPack();
        auto* bar = this->m_interface->createBar();

        pack->showBrend();
        std::cout<<bar->getSize();
    }
};

int main(){
    //создаю милку
    СhocolateInterface* brend = new Milka;
    ChocolateFactory* chocolate = new ChocolateFactory(brend);
    chocolate->showParammetrs();

    std::cout<<std::endl<<std::endl;
    //создаю альпен гольд
    СhocolateInterface* brend_2 = new AlpenGold;
    ChocolateFactory* chocolate_2 = new ChocolateFactory(brend_2);
    chocolate_2->showParammetrs();

    return 0;
}