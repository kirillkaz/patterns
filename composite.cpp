#include <iostream>
#include <list>
class ItemInterface{
public:
    virtual void GetProperty() = 0;
};

class Item : public ItemInterface{
private:
    std::string propetry;
public:
    Item(std::string property) : propetry(property){
    }

    void GetProperty() override{
        std::cout<<propetry<<std::endl;
    }
};

class ItemBox : public ItemInterface{
private:
    std::list<ItemInterface*> ItemList;
public:

    void add(ItemInterface* item){
        this->ItemList.push_back(item);
    }

    void GetProperty() override{
        for(auto item : ItemList) item->GetProperty();
    }
};


int main(){
    ItemBox* box = new ItemBox;
    ItemBox* BootsBox = new ItemBox;

    Item* sword = new Item("damage = 5");
    Item* jewelry = new Item("heal = 10 hp/sec");
    Item* LeftBoot = new Item("def = 3");
    Item* RightBoot = new Item("def = 7");

    BootsBox->add(LeftBoot);
    BootsBox->add(RightBoot);

    box->add(sword);
    box->add(BootsBox);
    box->add(jewelry);

    box->GetProperty();
}
