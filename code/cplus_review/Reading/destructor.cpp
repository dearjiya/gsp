#include <doctest/doctest.h>
#include <iostream>

TEST_CASE("destructor")
{
	/**
	 * 무엇인가? 어떤 클래스의 인스턴스가 더 이상 존재하지 않을 때 실행되는 함수이다. 
	 * 왜 필요한가? 해당 클래스 인스턴스와 동시에 존재해야 하는 것들을 소멸시킨다.   
	 * 대표적으로 파일 핸들, 소켓 핸들, 메모리 등이 있다.
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