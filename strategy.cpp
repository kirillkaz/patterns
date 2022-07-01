#include<iostream>

class MobModeStrategy{
public:
    virtual void setMode(std::string& mode) = 0;
};

class getAgressiveStrategy : public MobModeStrategy{
    void setMode(std::string& mode) override{
        mode = "agressive";
    }
};

class getPeasefullStrategy : public MobModeStrategy{
public:
    void setMode(std::string& mode) override{
        mode = "peasefull";
    }
};

class Mob{
    std::string name;
    std::string state;
    MobModeStrategy* strategy;
public:

    Mob(std::string name,MobModeStrategy* strategy){
        this->name = name;
        strategy->setMode(this->state);
    }

    std::string getState(){
        return state;
    }

};

int main(){
    MobModeStrategy* strategy1 = new getAgressiveStrategy();
    MobModeStrategy* strategy2 = new getPeasefullStrategy();

    Mob* monster = new Mob("Slime",strategy1);
    Mob* villager = new Mob("Tomas",strategy2);

    std::cout<<"Slime state - " + monster->getState()<<std::endl;
    std::cout<<"Tomas state - " + villager->getState()<<std::endl;
    return 0;
}