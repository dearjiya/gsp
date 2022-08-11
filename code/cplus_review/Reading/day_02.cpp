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

	int return_a()
	{
		int a = 2;
		return a;
	}

	int& return_ref()
	{
		int a = 1;
		return a;
	}
	int& return_var(int& a)
	{
		a = 5;
		return a;
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
		// p�� a�� ����Ű���� Ȯ��
		// p�� a���� b�� ����Ű���� Ȯ��
		int a = 10;
		int* p = &a;
		CHECK(*p == 10);

		int b = 3;
		p = &b;
		CHECK(*p == 3);
	}

	SUBCASE("�������� ������ ���õ� �˻��ϱ�")
	{
		int x = 1;
		int& y = x;
		int& z = y;
		y = 2;
		z = 3;

		CHECK(x == 3);
		CHECK(y == 3);
		CHECK(z == 3);
	}

	SUBCASE("���۷����� ���� �迭 - �ȵ� ����")
	{
		int a = 1;
		int b = 2;
		//int& arr[2] = { a,b };
		
	}

	SUBCASE("�迭�� ���� ���۷��� - ��")
	{
		int arr[3] = { 1,2,3 };
		int(&ref)[3] = arr;
		ref[0] = 2;
		ref[1] = 3;
		ref[2] = 1;
		CHECK(arr[0] == 2);
		CHECK(arr[1] == 3);
		CHECK(arr[2] == 1);
	}

	SUBCASE("���۷����� �����ϴ� �Լ��� ��������� Ŭ���� ����Լ��� �Ϲ����̴�.")
	{
		// ������ �ƴ� �� ����
		int b = return_a();
		// ���������� ���۷����� ���� -> segmentation fault �߻����� �ʰ� ���� �ߵ�?
		int ref = return_ref();
		ref = 3;
		int c = 5;
		// �ܺκ����� ���۷����� ����
		int var = return_var(c);
		// �����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� �ޱ�
		const int& func_ref = return_a();

		CHECK(b == 2);
		CHECK(ref == 3);
		CHECK(var == 5);
		CHECK(func_ref == 2);
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

		/*int arr_size;

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
		delete[] list;*/
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