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
		// 바꾸기 해보기 
	}

	SUBCASE("여러가지 참조자 예시들 검사하기")
	{

	}

	SUBCASE("레퍼런스에 대한 배열 - 안됨 검증")
	{

	}

	SUBCASE("배열에 대한 레퍼런스 - 됨")
	{

	}

	SUBCASE("레퍼런스를 리턴하는 함수는 어색하지만 클래스 멤버함수는 일반적이다.")
	{

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
		int a = 5;
		delete& a;
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