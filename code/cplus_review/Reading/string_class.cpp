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
		content_[1] = '\0'; // invariant - ���� �ι��ڰ� �ִ�.
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
		// �����Ҵ��� �ʿ���� ��� �߰��ϱ�
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
		// ������ �迭 �� 
		// -1: ���������� �տ� ��ġ�Ѵ�, 0: ����, 1: �ڿ� ��ġ�Ѵ�,

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

			CHECK(str == str2);
		}
		SUBCASE("���� �׽�Ʈ 2 - operation==")
		{
			jiya::string str("hello");
			jiya::string str2("hello");

			CHECK(str == str2);
		}

		SUBCASE("���� �׽�Ʈ 3 - append")
		{
			// tmp�� str�� �ڸ��� ���Ҵ� ��Ű�� ���
			jiya::string str{ "hello" };
			jiya::string str2{"world"};
			jiya::string res{ "helloworld" };
			//CHECK(str == res);
		}

		SUBCASE("���� �׽�Ʈ 4 - assign")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "world" };
			jiya::string& s = str.assign(str2);

			CHECK(s == str.c_str());
		}

		SUBCASE("���� �׽�Ʈ 5 - memory reserve")
		{
			jiya::string str{ "HiHiWorld" };
			int memory_size = 20;
			str.reserve(memory_size);

			CHECK(str.capacity() == memory_size);
		}

		SUBCASE("���� �׽�Ʈ 6 - at")
		{
			jiya::string str{ "helloworld" };
			jiya::string res{ "l" };

			std::cout << "at: " << str.at(3) << std::endl;
			CHECK(res == str.at(3));
		}

		SUBCASE("���� �׽�Ʈ 7 - insert")
		{
			// memory_capacity �� ����Ͽ� �����ϱ�
			jiya::string str{ "hihi" };
			jiya::string str2{ "length" };
			jiya::string& st = str.insert(2, str2);
			std::cout << "insert: " << st.c_str() << std::endl;
		}

		SUBCASE("���� �׽�Ʈ 8 - erase")
		{
			// �ʱ�ȭ���� �ʰ� �ڿ� �κ��� ������ ���� �Ա� ������ �޺κ��� �������� 
			jiya::string str{ "HelloWorld" };
			jiya::string res{ "HWorld" };
			jiya::string& st = str.erase(1, 4);
			std::cout << "erase: " << str.c_str() << std::endl;
			//CHECK(res == str.erase(1, 4));
		}
		SUBCASE("���� �׽�Ʈ 9 - find")
		{
			jiya::string str{ "helloworld" };
			jiya::string str2{ "wor" };
			//std::cout << "find: " << str.find(0, str2) << std::endl;
			CHECK(5 == str.find(0, str2));
		}
		SUBCASE("���� �׽�Ʈ 10 - compare")
		{
			jiya::string str{ "hello" };
			jiya::string str2{ "helloss" };
			CHECK(-1 == str.compare(str2));
		}
	}
}