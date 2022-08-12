#include <doctest/doctest.h>
#include <iostream>
#include <string>

namespace jiya
{

class string
{
public:
	string()
		: content_{nullptr}
		, length_{0}
		, memory_capacity{0}
	{
	}

	string(char c)
	{
		content_ = new char[2];
		content_[0] = c;
		content_[1] = '\0'; // invariant - 끝에 널문자가 있다.
		length_ = 1;
		memory_capacity = 1;
	}

	string(const char* cs)
	{
		length_ = strlen(cs);
		content_ = new char[length_+1]();
		for (int i = 0; i < length_; i++)
		{
			content_[i] = cs[i];
		}
		content_[length_] = '\0';
		memory_capacity = length_;
	}

	string(const jiya::string& str)
		: string(str.content_)
	{
	}

	~string()
	{
		delete[] content_;
	}

	size_t len() const
	{
		return length_;
	}

	int capacity() const
	{
		return memory_capacity;
	}
	
	const char* c_str() const
	{
		return content_;
	}

	void print() const
	{
		std::cout << content_;
		std::cout << std::endl;
	}

	bool operator==(const string& rhs) const
	{
		return strcmp(content_, rhs.content_) == 0;
	}

	char* append(const char* str)
	{
		size_t length_sum = length_ + strlen(str);
		char* res = new char[length_sum + 1]();
		int j = 0;
		for (int i = 0; i < length_sum; i++)
		{
			if (i < length_) 
			{
				res[i] = content_[i];
			}
			else
			{
				res[i] = str[j];
				j++;
			}
		}
		res[length_sum] = '\0';
		
		return res;
	}

	string& assign(const string& str)
	{
		if (str.length_ > memory_capacity)
		{
			delete[] content_;
			content_ = new char[str.length_ + 1];
			memory_capacity = str.length_;
		}
		for (int i = 0; i < str.length_; i++)
		{
			content_[i] = str.content_[i];
		}
		content_[str.length_] = '\0';
		length_ = str.length_;
		return *this;
	}

	char at(int i) const
	{
		if (i > length_ || i < 0)
		{
			return NULL;
		}
		else
			return content_[i];
	}

	string& insert(int loc, const string& str)
	{
		if (loc < 0 || loc > length_)
		{
			return *this;
		}
		if (length_ + str.length_ > memory_capacity)
		{
			memory_capacity = length_ + str.length_;

			char* prev_content_ = content_;
			content_ = new char[memory_capacity];
		}

	}

private:
	char* content_;
	size_t length_;
	int memory_capacity;
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

			auto tmp = str2.c_str();
		}
		SUBCASE("단위 테스트 2 - operatio==")
		{
			jiya::string str("hello");
			jiya::string str2("hello");

			CHECK(str == str2);
		}

		SUBCASE("단위 테스트 3 - append")
		{
			// tmp를 str의 자리에 재할당 시키는 방법
			jiya::string str("hello");
			jiya::string str2(" world");
			auto tmp = str.append(str2.c_str());
			//std::cout << "append: " << tmp; 
		}

		SUBCASE("단위 테스트 4 - assign")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "world" };
			//str.print();
			jiya::string& s = str.assign(str2);

			//str.print();
		}

		SUBCASE("단위 테스트 5 - at")
		{
			jiya::string str{ "helloworld" };

			str.print();
			std::cout << "at: " << str.at(3);
		}
	}
}