#include <doctest/doctest.h>
#include <cassert>
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
		, memory_capacity_{ 0 }
	{
	}

	string(char c)
	{
		content_ = new char[2];
		content_[0] = c;
		content_[1] = '\0'; // invariant - 끝에 널문자가 있다.
		length_ = 1;
		memory_capacity_ = 1;
		assert(length_ <= memory_capacity_);
	}

	string(const char* cs)
	{
		length_ = strlen(cs);
		content_ = new char[length_ + 1]();
		// NOTE: memcpy를 쓸 수도 있다.
		for (int i = 0; i < length_; i++)
		{
			content_[i] = cs[i];
		}
		content_[length_] = '\0';
		memory_capacity_ = length_;
		assert(length_ <= memory_capacity_);
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

	size_t capacity() const
	{
		return memory_capacity_;
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
		//std::cout << "append: " << content_ << std::endl;

		memory_capacity_ = length_sum + 1;
		length_ = length_sum;
		assert(length_ <= memory_capacity_);

		return *this;
	}

	string& assign(const string& str)
	{
		if (str.length_ > memory_capacity_)
		{
			delete[] content_;
			content_ = new char[str.length_ + 1];
		}
		for (int i = 0; i < str.length_; i++)
		{
			content_[i] = str.content_[i];
		}
		content_[str.length_] = '\0';

		memory_capacity_ = str.length_ + 1;
		length_ = str.length_;
		assert(length_ <= memory_capacity_);
		return *this;
	}

	void reserve(size_t size)
	{
		if (size > memory_capacity_)
		{
			char* prev_content_ = content_;
			content_ = new char[size];
			memory_capacity_ = size;

			for (int i = 0; i < length_; i++)
			{
				content_[i] = prev_content_[i];
			}

			delete[] prev_content_;
		}
	}

	char at(size_t i) const
	{
		if (i > length_)
		{
			throw std::out_of_range("size의 index 값이 초과하였습니다!");
		}

		return content_[i];
	}

	string& insert(size_t loc, const string& str)
	{
		assert(loc <= length_);

		if (loc > length_)
		{
			throw std::out_of_range("loc의 index가 길이를 초과하였습니다!");
		}

		// XXX: '\0' 처리가 일관되는가?
		if (length_ + str.length_ > memory_capacity_)
		{
			char* prev_content_ = content_;
			content_ = new char[length_ + str.length_ + 1];

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

			memory_capacity_ = length_ + str.length_ + 1;
			length_ = length_ + str.length_;
			content_[length_] = '\0';
			assert(length_ <= memory_capacity_);
			return *this;
		}
		else
		{
			std::cout << "insert- newX" << std::endl;
			for (int i = length_ - 1; i >= loc; i--)
			{
				content_[i + str.length_] = content_[i];
			}
			for (int i = 0; i < str.length_; i++)
			{
				content_[i + loc] = str.content_[i];
			}

			length_ = length_ + str.length_;
			content_[length_] = '\0';
			return *this;
		}
	}

	string& erase(size_t loc, size_t num)
	{
		if (loc >= length_)
		{
			throw std::out_of_range("loc의 index가 범위를 초과하였습니다!");
		}
		if ((num + loc) >= length_)
		{
			throw std::out_of_range("num+loc의 index가 범위를 초과하였습니다!");
		}

		for (int i = loc + num; i < length_; i++)
		{
			content_[i - num] = content_[i];
		}

		length_ = length_ - num; // 음수가 될 수 있으므로 체크에서 걸러야 한다.
		content_[length_] = '\0';
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
	size_t memory_capacity_;
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
			jiya::string str{ "hello" };
			jiya::string str2{ "world" };
			jiya::string res{ "helloworld" };

			CHECK(str.append(str2) == res);
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
			//std::cout << "at: " << str.at(3) << std::endl;
			CHECK(res == str.at(3));
		}

		SUBCASE("단위 테스트 7 - insert")
		{
			// memory_capacity_ 를 고려하여 수정하기
			jiya::string str{ "hihi" };
			jiya::string str2{ "length" };
			jiya::string res{ "hilengthhi" };
			jiya::string& st = str.insert(2, str2);
			//std::cout << "insert: " << st.c_str() << std::endl;
			CHECK(res == st.c_str());
		}
		SUBCASE("단위 테스트 8 - insert (동적할당X)")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "pp" };
			str.reserve(10);
			jiya::string res{ "heppllo" };
			jiya::string& st = str.insert(2, str2);
			std::cout << "insert: " << st.c_str() << std::endl;
			CHECK(res == st.c_str());
		}

		SUBCASE("단위 테스트 9 - erase")
		{
			jiya::string str{ "HelloWorld" };
			jiya::string res{ "HWorld" };
			jiya::string& st = str.erase(1, 4);
			// jiya::string& st2 = str.erase(8, 5);
			// std::cout << "erase: " << st.c_str() << std::endl;
			CHECK(res == st.c_str());
		}
		SUBCASE("단위 테스트 10 - find")
		{
			jiya::string str{ "helloworld" };
			jiya::string str2{ "wor" };
			//std::cout << "find: " << str.find(0, str2) << std::endl;
			CHECK(5 == str.find(0, str2));
		}
		SUBCASE("단위 테스트 11 - compare")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "helloss" };
			CHECK(-1 == str.compare(str2));
		}
	}
}