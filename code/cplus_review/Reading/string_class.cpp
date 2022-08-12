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
		content_[1] = '\0'; // invariant - ���� �ι��ڰ� �ִ�.
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

			auto tmp = str2.c_str();
		}
		SUBCASE("���� �׽�Ʈ 2 - operatio==")
		{
			jiya::string str("hello");
			jiya::string str2("hello");

			CHECK(str == str2);
		}

		SUBCASE("���� �׽�Ʈ 3 - append")
		{
			// tmp�� str�� �ڸ��� ���Ҵ� ��Ű�� ���
			jiya::string str("hello");
			jiya::string str2(" world");
			auto tmp = str.append(str2.c_str());
			//std::cout << "append: " << tmp; 
		}

		SUBCASE("���� �׽�Ʈ 4 - assign")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "world" };
			//str.print();
			jiya::string& s = str.assign(str2);

			//str.print();
		}

		SUBCASE("���� �׽�Ʈ 5 - at")
		{
			jiya::string str{ "helloworld" };

			str.print();
			std::cout << "at: " << str.at(3);
		}
	}
}