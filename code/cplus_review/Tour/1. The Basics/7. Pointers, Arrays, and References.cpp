#include <doctest/doctest.h>
#include <iostream>
#include <vector>

TEST_CASE("Basics / Pointers, Arrays, and References")
{

	/**
	 * 적절한 타잎의 포인터를 초기화 하고, 값을 지정하고, 값을 얻는다.
	 */
	SUBCASE("pointer 연습")
	{
		char v[6];
		char* p = &v[3];  // p는 v의 4번째 요소를 가리킨다
		char x = *p; // 
	}

	SUBCASE("ranged-for array")
	{
		int v[] = { 1, 2, 3, 4 };
		// TODO: 
	}

	/**
	 * double sum(vector<double> values);
	 * 위와 같이 하면 vector가 복사된다. 어떻게 알 수 있을까?
	 */
	SUBCASE("copy occurrs without reference")
	{
	}

	/**
	 * char* p; 
	 * int* p;
	 * ++가 어떻게 다르게(같게?) 동작하는가?
	 */
	SUBCASE("++ on pointer type")
	{
		
	}
}