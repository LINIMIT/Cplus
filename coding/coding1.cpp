#include <iostream>
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

	if(player)
	{

	}

}