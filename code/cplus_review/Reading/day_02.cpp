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
	SUBCASE("c pointer 사용")
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
		// p는 a를 가리키는지 확인
		// p가 a말고 b를 가리키는지 확인
		int a = 10;
		int* p = &a;
		CHECK(*p == 10);

		int b = 3;
		p = &b;
		CHECK(*p == 3);
	}

	SUBCASE("여러가지 참조자 예시들 검사하기")
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

	SUBCASE("레퍼런스에 대한 배열 - 안됨 검증")
	{
		int a = 1;
		int b = 2;
		//int& arr[2] = { a,b };
		
	}

	SUBCASE("배열에 대한 레퍼런스 - 됨")
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

	SUBCASE("레퍼런스를 리턴하는 함수는 어색하지만 클래스 멤버함수는 일반적이다.")
	{
		// 참조자 아닌 값 리턴
		int b = return_a();
		// 지역변수의 레퍼런스를 리턴 -> segmentation fault 발생되지 않고 복사 잘됨?
		int ref = return_ref();
		ref = 3;
		int c = 5;
		// 외부변수의 레퍼런스를 리턴
		int var = return_var(c);
		// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
		const int& func_ref = return_a();

		CHECK(b == 2);
		CHECK(ref == 3);
		CHECK(var == 5);
		CHECK(func_ref == 2);
	}
}

TEST_CASE("new delete")
{
	SUBCASE("C++의 new는 특정 타잎의 메모리를 확보하여 생성한다")
	{
		// 메모리 할당 -> 생성자를 호출
	}

	SUBCASE("C++의 delete는 특정 타잎을 파괴하고 메모리를 해제한다")
	{
		// 소멸자를 호출 -> 메모리 해제
	}

	SUBCASE("new로 할당한 메모리만 delete가 가능하다")
	{
		// 설명을 추가. 
		
		int a = 5;
		// delete& a;
	}

	SUBCASE("int의 배열 할당과 사용")
	{
		// 사용법만 익힘 
		// 아래를 CHECK를 사용하여 입력 없이 실행해 볼 수 있도록 수정한다. 

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

	SUBCASE("클래스의 배열 할당과 사용")
	{
		// 클래스를 배운 다음에 확인

	}

	SUBCASE("Animal struct 다루기")
	{

		SUBCASE("struct의 c와 c++ 차이")
		{
			// c++에서 struct는 class와 동일하고 public인 점만 다르다

		}

		SUBCASE("create_animal")
		{
			// 함수 작성하고 호출 해보기

		}

		SUBCASE("play")
		{
			// 함수 작성하고 호출 해보기
		}
	}
}

/**
 - 타잎 위치 
   - number : int 
 - 문장 구분 
   - ;
 - 참조자 (레퍼런스, reference)
   - 포인터인데 일반 변수처럼 사용 가능하다. 
   - 
*/