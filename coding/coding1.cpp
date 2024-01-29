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
		//���� ���⼭ �ּҰ��� �����ؼ� ����ϱ� ������  main���� ��ü�� �����ϰ� delete�� �ѵ� job()�� �Ϸ��ϸ� �Ҿ���� ����
		//�ᱹ _hp�� class�� �������̱� �����̴�.
		//���⼭�� _hp�� ĸ���ϴ°��� �ƴ� this�� ĸ���ϴ°��̴�.
		auto job = [=]()
		{
			_hp = 200;
			//this->_hp�� �ٸ�����.
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

		//���ٽ�
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
