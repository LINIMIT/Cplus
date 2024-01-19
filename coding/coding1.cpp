#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Item
{
public:
	int _itemid = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

using ItemSelectorType = bool(*)(Item* item);

Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item))
			return item;
	}
	return nullptr;
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}
int main()
{
	Item items[10];
	items[3]._rarity = 1;

	FindItem(items, 10, IsRare);
}