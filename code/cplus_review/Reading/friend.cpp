#include <doctest/doctest.h>


namespace
{
class A
{
private:
	void private_func() {}
	int private_num;

	friend class B;
	friend void func();
};

class B
{
public:
	void b()
	{
		A a;
		a.private_func();
		a.private_num = 2;
	}
};

void func()
{
	A a;
	a.private_func();
	a.private_num = 2;
}
} // namespace
/**
 * class A�� class B�� void �Լ� func�� friend ��� �����߱� ������ B�� func()�� A�� ��� private��
 * �� �� ������ A�� B�� private ��ü�� ������ �� ����.
 */
TEST_CASE("friend keyword")
{
	SUBCASE("")
	{

	}
}
