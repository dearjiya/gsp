#include <doctest/doctest.h>

#include <iostream>

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
		// ������ �߰�. 
		
		int a = 5;
		// delete& a;
	}

	SUBCASE("int�� �迭 �Ҵ�� ���")
	{
		// ������ ���� 
		// �Ʒ��� CHECK�� ����Ͽ� �Է� ���� ������ �� �� �ֵ��� �����Ѵ�. 

		int arr_size;

		std::cout << "array size : ";
		std::cin >> arr_size;

		int* list = new int[arr_size];

		for (int i = 0; i < arr_size; i++) 
		{
			std::cin >> list[i];
		}

		for (int i = 0; i < arr_size; i++) 
		{
			std::cout << i << "th element of list : " << list[i] << std::endl;
		}
		delete[] list;
	}

	SUBCASE("Ŭ������ �迭 �Ҵ�� ���")
	{
		// Ŭ������ ��� ������ Ȯ��

	}

	SUBCASE("Animal struct �ٷ��")
	{

		SUBCASE("struct�� c�� c++ ����")
		{
			// c++���� struct�� class�� �����ϰ� public�� ���� �ٸ���

		}

		SUBCASE("create_animal")
		{
			// �Լ� �ۼ��ϰ� ȣ�� �غ���

		}

		SUBCASE("play")
		{
			// �Լ� �ۼ��ϰ� ȣ�� �غ���
		}
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