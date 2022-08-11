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
 * ���ڿ��� �������� ���α׷��ӵ��� ����� �ذ����� �� �ߴ� �����̰� 
 * �����ڵ� ǥ��ȭ�� �̸� �����ϴ� ���̺귯������ ������ ������ 
 * ��ٷ��� �߰�, ������ ��� ���� Ȯ���Ǿ����� �� ���� �������� 
 * ������ ������ ���� �ִ�. 
 * 
 * �������� ���н� �迭������ utf8�� ǥ������ �ڸ� ��Ұ� 
 * �����쿡���� utf16le�� ǥ������ �����Ǿ���.
 */
TEST_CASE("string class")
{
	SUBCASE("std::string ���")
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

	SUBCASE("������ string Ŭ���� �����")
	{
		SUBCASE("���� �׽�Ʈ 1")
		{
			jiya::string str("hello world");
			jiya::string str2(str);
			auto tmp = str2.GetValue();
			// 
		}
	}
}