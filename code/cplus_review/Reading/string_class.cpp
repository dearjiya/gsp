#include <doctest/doctest.h>
#include <iostream>
#include <string>

namespace jiya
{

class string
{
public:
	char* string_content;
	int string_length;

	string(char c)
	{
		string_content = new char[1];
		string_content[0] = c;
		string_length = 1;
	}

	string(char* cs)
	{
		string_length = strlen(cs);
		string_content = new char[string_length]();
		for (int i = 0; i < string_length; i++)
		{
			string_content[i] = cs[i];
		}
	}
	string(const char* str)
	{
		string_length = strlen(str);
		string_content = new char[string_length]();
		for (int i = 0; i < string_length; i++)
		{
			string_content[i] = str[i];
		}
	}

	int len() const
	{
		return string_length;
	}
	
	char* GetValue()
	{
		char* tmp = new char[string_length];
		std::cout << "leng" << string_length;
		for (int i = 0; i < string_length; i++)
		{
			tmp[i] = string_content[i];
		}
		return tmp;
	}

	void print()
	{
		for (int i = 0; i != string_length; i++)
		{
			std::cout << string_content[i];
		}
	}
};

} // namespace jiya

/**
 * 문자열은 오랫동안 프로그래머들이 제대로 해결하지 못 했던 문제이고 
 * 유니코드 표준화와 이를 지원하는 라이브러리들이 안정될 때까지 
 * 기다려야 했고, 이제는 어느 정도 확정되었으나 몇 가지 영역에서 
 * 이전의 개념들과 섞여 있다. 
 * 
 * 리눅스와 유닉스 계열에서는 utf8가 표준으로 자리 잡았고 
 * 윈도우에서는 utf16le가 표준으로 정리되었다.
 */
TEST_CASE("string class")
{
	SUBCASE("std::string 사용")
	{
		SUBCASE("basic use")
		{
			std::string s{ "hello world" };
			CHECK(s == "hello world");
			CHECK(s.length() == 11);
		}

		SUBCASE("concatenate")
		{
			std::string s1{ "hello" };
			std::string s2{ "world" };

			auto s3 = s1 + " " + s2;
			CHECK(s3 == "hello world");
		}

		SUBCASE("access with index")
		{
			std::string s{ "abcd012" };
			CHECK(s[0] == 'a');
			CHECK(s[1] == 'b');
		}
	}

	SUBCASE("나만의 string 클래스 만들기")
	{
		SUBCASE("단위 테스트 1")
		{
			jiya::string str("hello world");
			jiya::string str2(str);
			auto tmp = str2.GetValue();
			// 
		}
	}
}