#include <doctest/doctest.h>

TEST_CASE("copy constructor")
{
	/**
	 * 복사생성자는 무엇인가? 왜 필요한가? 어떻게 쓰는가?
	 * 
	 * - 클래스는 외부에 인터페이스를 통해서만 사용할 수 있다. 
	 * - 클래스도 타잎이고 변수에 할당할 수 있다. 
	 * - 이미 있는 클래스 인스턴스를 다른 변수에 할당할 수 있도록 하기위해 복사 생성자가 필요하다.
	 */
	SUBCASE("intro")
	{
		SUBCASE("copy constructor generated from the c++ compiler")
		{
			class Simple
			{
			public:
				Simple()
					: v_(0)
				{
				}

				Simple(int v)
					: v_(v)
				{
				}

				int GetValue() const
				{
					return v_;
				}

				Simple(const Simple& rhs) = default;

			private:
				int v_;
			};

			Simple v(3);
			Simple v2 = v;
			CHECK(v2.GetValue() == 3);
		}

		SUBCASE("custom copy constructor") 
		{
			class Simple
			{
			public:
				Simple()
					: v_(0)
				{
				}

				Simple(int v)
					: v_(v)
				{
				}

				int GetValue() const
				{
					return v_;
				}

				Simple(const Simple& rhs)
				{
					v_ = rhs.v_ + 1;
				}

			private:
				int v_;
			};

			Simple v(3);
			Simple v2 = v;
			CHECK(v2.GetValue() == 4);
		}
	}

	/**
	 * intro에서 대부분의 용례는 설명되었지만 C++을 더 배우면서 
	 * 필요한 부분들이 생기면 여기로 돌아와서 추가로 연습한다. (2022.08.11)
	 */
	SUBCASE("use case")
	{

	}
}