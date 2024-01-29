/*#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

enum class ObjectType
{
    Player,
    Monster,
    Projectile,
    Env
};

class Object
{
public:
    Object(ObjectType type) : _type(type) {}

    virtual ~Object() {}
public:
    ObjectType GetObjectType() { return _type; }

    int _id;
    ObjectType _type;
};
class Player : public Object
{
public:
    Player() : Object(ObjectType::Player) {}
    Player(int id) : Object(ObjectType::Player) {}
private:
};
class Monster : public Object
{
public:
    Monster() : Object(ObjectType::Monster){}
    int _id;
};

class Projectile : public Object
{
public:

    Projectile() : Object(ObjectType::Projectile) {}

};

class Env : public Object
{

};
class Field
{
public:
    static Field* GetInstance()
    {
        static Field field;
        return &field;
    }

    void Add(Object* player)
    {
        _objects.insert(make_pair(player->_id, player));
    }

    void Remove(int id)
    {
        _objects.erase(id);
    }

    Object* Get(int id)
    {
        auto findit = _objects.find(id);

        if (findit != _objects.end())
            return findit->second;

        return nullptr;
    }

    unordered_map<int, Object*> _objects;


    //unordered_map<int, Player*> _players;
    //unordered_map<int, Monster*> _monsters;

};
int main()
{
    Field::GetInstance()->Add(new Player(1));
    Object* obj = Field::GetInstance()->Get(1);

    if (obj && obj->GetObjectType() == ObjectType::Player)
    {
        Player* player = static_cast<Player*>(obj);
    }
    Player* player = dynamic_cast<Player*>(Field::GetInstance()->Get(1));



}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Character {
public:
    Character(const std::string& name, int health, int damage)
        : name(name), health(health), damage(damage) {}

    void attack(Character& target) {
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage.\n";
        target.takeDamage(damage);
    }

    void takeDamage(int amount) {
        health -= amount;
        std::cout << name << " takes " << amount << " damage. Remaining health: " << health << "\n";
    }

    bool isAlive() const {
        return health > 0;
    }

    const std::string& getName() const {
        return name;
    }
};

class Monster : public Character {
public:
    Monster(const std::string& name, int health, int damage)
        : Character(name, health, damage) {}
};

class Item {
public:
    virtual void use(Character& target) = 0;
    virtual ~Item() {}
};

class HealthPotion : public Item {
public:
    void use(Character& target) override {
        std::cout << "You use a Health Potion. Restored 20 health.\n";
        target.takeDamage(-20); // Negative damage to represent healing
    }
};

class Sword : public Item {
public:
    void use(Character& target) override {
        std::cout << "You swing your sword at " << target.getName() << " dealing 30 damage.\n";
        target.takeDamage(30);
    }
};

class ItemContainer {
public:
    void addItem(std::unique_ptr<Item> item) {
        items.push_back(std::move(item));
    }

    std::vector<std::unique_ptr<Item>>::iterator begin() {
        return items.begin();
    }

    std::vector<std::unique_ptr<Item>>::iterator end() {
        return items.end();
    }

private:
    std::vector<std::unique_ptr<Item>> items;
};

class RPGGame {
public:
    RPGGame(Character& player, Monster& monster)
        : player(player), monster(monster) {
        itemContainer.addItem(std::make_unique<HealthPotion>());
        itemContainer.addItem(std::make_unique<Sword>());
    }

    void battle() {
        std::cout << "You encounter a " << monster.getName() << "!\n";

        while (player.isAlive() && monster.isAlive()) {
            std::cout << "1. Attack\n2. Use Item\n";
            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                player.attack(monster);
                break;
            case 2:
                useItem();
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }

            if (!monster.isAlive()) {
                std::cout << "You defeated the " << monster.getName() << "!\n";
                break;
            }

            monster.attack(player);

            if (!player.isAlive()) {
                std::cout << "You were defeated by the " << monster.getName() << ". Game Over.\n";
                break;
            }

            // Add some delay for readability
            std::cout << "\n";
            std::system("pause");
            std::cout << "\n";
        }
    }

private:
    Character& player;
    Monster& monster;
    ItemContainer itemContainer;

    void useItem() {
        std::cout << "Choose an item to use:\n";
        int index = 1;

        for (auto it = itemContainer.begin(); it != itemContainer.end(); ++it) {
            std::cout << index << ". ";
            (*it)->use(player);
            index++;
        }
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation

    Character player("Hero", 100, 20);
    Monster goblin("Goblin", 50, 10);

    RPGGame game(player, goblin);
    game.battle();

    return 0;
}
*/