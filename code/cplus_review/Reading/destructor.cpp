#include <doctest/doctest.h>
#include <iostream>

TEST_CASE("destructor")
{
	/**
	 * �����ΰ�? � Ŭ������ �ν��Ͻ��� �� �̻� �������� ���� �� ����Ǵ� �Լ��̴�. 
	 * �� �ʿ��Ѱ�? �ش� Ŭ���� �ν��Ͻ��� ���ÿ� �����ؾ� �ϴ� �͵��� �Ҹ��Ų��.   
	 * ��ǥ������ ���� �ڵ�, ���� �ڵ�, �޸� ���� �ִ�.
	 */
	SUBCASE("intro")
	{
		class DestructorSample
		{
		public:
			DestructorSample()
				: buf_(nullptr)
				, buf_len_(128)
			{
				buf_ = new char[buf_len_];
			}

			~DestructorSample()
			{
				delete[] buf_;
			}

		private: 
			char* buf_;
			size_t buf_len_;
		};

		DestructorSample sample; 
	}

	/**
	 * 
	 */
	SUBCASE("use case")
	{

	}
}