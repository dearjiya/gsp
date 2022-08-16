#include <doctest/doctest.h>
#include <iostream>
#include <string>

namespace jiya
{

class string
{
public:
	string()
		: content_{ nullptr }
		, length_{ 0 }
		, memory_capacity{ 0 }
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
		content_ = new char[length_ + 1]();
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

	string& append(const string& str)
	{
		size_t length_sum = length_ + str.length_;
		char* prev_content_ = content_;
		content_ = new char[length_sum + 1];
		int j = 0;
		for (int i = 0; i < length_sum; i++)
		{
			if (i < length_)
			{
				content_[i] = prev_content_[i];
			}
			else
			{
				content_[i] = str.content_[j];
				j++;
			}
		}
		content_[length_sum] = '\0';

		delete[] prev_content_;
		return *this;
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

	void reserve(int size)
	{
		if (size > memory_capacity)
		{
			char* prev_content_ = content_;
			content_ = new char[size];
			memory_capacity = size;

			for (int i = 0; i < length_; i++)
			{
				content_[i] = prev_content_[i];
			}

			delete[] prev_content_;
		}
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
			content_ = new char[memory_capacity + 1];

			int i;
			for (i = 0; i < loc; i++)
			{
				content_[i] = prev_content_[i];
			}
			for (int j = 0; j < str.length_; j++)
			{
				content_[i + j] = str.content_[j];
			}
			for (; i < length_; i++)
			{
				content_[str.length_ + i] = prev_content_[i];
			}
			delete[] prev_content_;
			length_ = length_ + str.length_;
			return *this;
		}
		// 동적할당이 필요없는 경우 추가하기
	}

	string& erase(int loc, int num) 
	{
		if (num < 0 || loc < 0 || loc > length_)
		{
			return *this;
		}

		for (int i = loc + num; i < length_; i++)
		{
			content_[i - num] = content_[i];
		}

		length_ = length_ - num;

		return *this;
	}

	int find(int find_from, const string& str) const
	{
		int i;
		int j;
		if (str.length_ > length_ || str.length_ == 0)
		{
			return -1;
		}
		for (i = find_from; i < length_; i++)
		{
			for (j = 0; j < str.length_; j++)
			{
				if (content_[i + j] != str.content_[j])
				{
					break;
				}
			}
			if (j == str.length_)
			{
				return i;
			}
		}
		return -1;
	}

	int compare(const string& str) const
	{
		// 사전식 배열 비교 
		// -1: 사전식으로 앞에 위치한다, 0: 같다, 1: 뒤에 위치한다,

		for (int i = 0; i < std::min(length_, str.length_); i++)
		{
			if (content_[i] > str.content_[i])
			{
				return 1;
			}
			else if (content_[i] < str.content_[i])
			{
				return -1;
			}
		}
		if (length_ == str.length_)
		{
			return 0;
		}
		else if (length_ > str.length_)
		{
			return 1;
		}
		return -1;
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

			CHECK(str == str2);
		}
		SUBCASE("단위 테스트 2 - operation==")
		{
			jiya::string str("hello");
			jiya::string str2("hello");

			CHECK(str == str2);
		}

		SUBCASE("단위 테스트 3 - append")
		{
			// tmp를 str의 자리에 재할당 시키는 방법
			jiya::string str{ "hello" };
			jiya::string str2{"world"};
			jiya::string res{ "helloworld" };
			//CHECK(str == res);
		}

		SUBCASE("단위 테스트 4 - assign")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "world" };
			jiya::string& s = str.assign(str2);

			CHECK(s == str.c_str());
		}

		SUBCASE("단위 테스트 5 - memory reserve")
		{
			jiya::string str{ "HiHiWorld" };
			int memory_size = 20;
			str.reserve(memory_size);

			CHECK(str.capacity() == memory_size);
		}

		SUBCASE("단위 테스트 6 - at")
		{
			jiya::string str{ "helloworld" };
			jiya::string res{ "l" };

			std::cout << "at: " << str.at(3) << std::endl;
			CHECK(res == str.at(3));
		}

		SUBCASE("단위 테스트 7 - insert")
		{
			// memory_capacity 를 고려하여 수정하기
			jiya::string str{ "hihi" };
			jiya::string str2{ "length" };
			jiya::string& st = str.insert(2, str2);
			std::cout << "insert: " << st.c_str() << std::endl;
		}

		SUBCASE("단위 테스트 8 - erase")
		{
			// 초기화하지 않고 뒤에 부분을 앞으로 끌고 왔기 때문에 뒷부분이 남아있음 
			jiya::string str{ "HelloWorld" };
			jiya::string res{ "HWorld" };
			jiya::string& st = str.erase(1, 4);
			std::cout << "erase: " << str.c_str() << std::endl;
			//CHECK(res == str.erase(1, 4));
		}
		SUBCASE("단위 테스트 9 - find")
		{
			jiya::string str{ "helloworld" };
			jiya::string str2{ "wor" };
			//std::cout << "find: " << str.find(0, str2) << std::endl;
			CHECK(5 == str.find(0, str2));
		}
		SUBCASE("단위 테스트 10 - compare")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "helloss" };
			CHECK(-1 == str.compare(str2));
		}
	}
}