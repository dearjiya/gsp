#include <doctest/doctest.h>
#include <iostream>

namespace
{
class Int
{
public:
	Int(int data)
		:data(data) {}
	Int(const Int& i)
		:data(i.data){}

	operator int() { return data; }

private:
	int data;
};

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}

	Test& operator++() {
		x++;
		std::cout << "���� ���� ������" << std::endl;
		return *this;
	}

	// ���� ������ ���� ������ ���̸� �α� ���� ���� ������ ��� ���ڷ� int ��
	// ������ �����δ� �ƹ��͵� ���޵��� �ʴ´�.
	Test operator++(int) {
		Test temp(*this);
		x++;
		std::cout << "���� ���� ������" << std::endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};

void func(const Test& t) {
	std::cout << "x : " << t.get_x() << std::endl;
}

} // namespace
/**
 * Ÿ�Ժ�ȯ������
 * operator (��ȯ�ϰ��� �ϴ� Ÿ��) ()
 */
TEST_CASE("int wrapper")
{
	SUBCASE("wrapper")
	{
		Int x = 3;
		int a = x + 4;
		CHECK(a == 7);
	}

	SUBCASE("a++, ++a")
	{
		Test t(3);

		//func(++t); // 4
		//func(t++); // 4 �� ��µ�
		//std::cout << "x : " << t.get_x() << std::endl;
	}
}
