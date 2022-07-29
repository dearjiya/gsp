#include <doctest/doctest.h>

namespace 
{
	void change_val(int* p) 
	{
		*p = 3;
	}

	void change_val(int& p)
	{
		p = 3;
	}
}

TEST_CASE("day 02")
{
	SUBCASE("c pointer ���")
	{
		int v = 1;

		CHECK(v == 1);
		change_val(&v);
		CHECK(v == 3);
	}

	SUBCASE("another a")
	{
		int a = 1;
		int& another_a = a;

		a = 5;
		CHECK(another_a == 5);
		another_a = 10;
		CHECK(a == 10);
	}

	SUBCASE("another change a")
	{
		int a = 1;
		change_val(a);
		CHECK(a == 3);
	}

	SUBCASE("pointer can change pointing address of the variable")
	{
		// �ٲٱ� �غ��� 
	}

	SUBCASE("�������� ������ ���õ� �˻��ϱ�")
	{

	}

	SUBCASE("���۷����� ���� �迭 - �ȵ� ����")
	{

	}

	SUBCASE("�迭�� ���� ���۷��� - ��")
	{

	}

	SUBCASE("���۷����� �����ϴ� �Լ��� ��������� Ŭ���� ����Լ��� �Ϲ����̴�.")
	{

	}
}

TEST_CASE("new delete")
{
	SUBCASE("C++�� new�� Ư�� Ÿ���� �޸𸮸� Ȯ���Ͽ� �����Ѵ�")
	{
		// �޸� �Ҵ� -> �����ڸ� ȣ��
	}

	SUBCASE("C++�� delete�� Ư�� Ÿ���� �ı��ϰ� �޸𸮸� �����Ѵ�")
	{
		// �Ҹ��ڸ� ȣ�� -> �޸� ����
	}

	SUBCASE("new�� �Ҵ��� �޸𸮸� delete�� �����ϴ�")
	{
		int a = 5;
		delete& a;
	}
}

/**
 - Ÿ�� ��ġ 
   - number : int 
 - ���� ���� 
   - ;
 - ������ (���۷���, reference)
   - �������ε� �Ϲ� ����ó�� ��� �����ϴ�. 
   - 
*/