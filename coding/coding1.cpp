#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}
	Item(int itemid, Rarity rarity, ItemType type) : _itemid(itemid), _rarity(rarity), _type(type) {}

public:
	int _itemid = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

class Knight
{
public:
	auto MakeResetHpJob()
	{
		//현재 여기서 주소값을 복사해서 사용하기 때문에  main에서 객체를 생성하고 delete를 한뒤 job()을 하려하면 잃어버린 상태
		//결국 _hp는 class에 종속적이기 때문이다.
		//여기서는 _hp를 캡쳐하는것이 아닌 this를 캡쳐하는것이다.
		auto job = [=]()
		{
			_hp = 200;
			//this->_hp나 다름없다.
		};
		return job;
	}

public:
	int _hp;
};
int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(1, Rarity::Common, ItemType::Armor));
	v.push_back(Item(1, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(1, Rarity::Unique, ItemType::Weapon));

	/*{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		//람다식
		//[](){}


		std::find_if(v.begin(), v.end(), IsUniqueItem());
	}*/


	std::find_if(v.begin(), v.end(), [](Item& item) {return item._rarity == Rarity::Unique; });

	Knight* k1 = new Knight;
	k1->_hp = 100;

	auto job = k1->MakeResetHpJob();
	delete k1;
	job();
}
