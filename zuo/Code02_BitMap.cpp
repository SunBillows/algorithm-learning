#include <iostream>
using namespace std;
#include <vector>

class BitMap
{
public:
	BitMap(int x);
	void _add(int x);
	void _delete(int x);
	bool find(int x);

private:
	vector<int> _bits;
};

BitMap::BitMap(int x)
{
	this->_bits.resize((x >> 5) + 1);
}

void BitMap::_add(int x)
{
	this->_bits[x >> 5] |= (1 << (x % 32));
}

void BitMap::_delete(int x)
{
	this->_bits[x >> 5] &= ~(1 << (x % 32));
}

bool BitMap::find(int x)
{
	if (this->_bits[x >> 5] &= (1 << (x % 32)))
	{
		return true;
	}
	else
		return false;
}

void testBitMap()
{
	BitMap bitmap(200);
	bitmap._add(163);
	bitmap._add(125);
	if (bitmap.find(163))
		cout << "存在该数" << endl;
	else
		cout << "不存在该数" << endl;
	if (bitmap.find(125))
		cout << "存在该数" << endl;
	else
		cout << "不存在该数" << endl;
	bitmap._delete(163);
	if (bitmap.find(163))
		cout << "存在该数" << endl;
	else
		cout << "不存在该数" << endl;

	bitmap._delete(5);
	if (bitmap.find(5))
		cout << "存在该数" << endl;
	else
		cout << "不存在该数" << endl;
}

int main()
{
	testBitMap();

	int num = 25681;
	cout << num % 30 << " ";
	cout << (num & 29) << " ";

	return 0;
}