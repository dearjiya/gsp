#include <doctest/doctest.h>

#include <vector>

namespace
{

class StaticMember
{
public:
	static int value;

	static int GetAnyValue()
	{
		return 3;
	}

	int ChangeValue()
	{
		value = 3;
	}
};

int StaticMember::value = 0;

} // namespace

TEST_CASE("class_const_static_member")
{
	/**
	 * c++에서 일반적으로 const는 한번만 지정 가능한 변수, 멤버를 변경하지 않는 함수에 사용하는 키워드
	 * 이다. 따라서, const member는 한번만 지정 가능한 변수로 추측할 수 있다.
	 */
	SUBCASE("const member variable")
	{

	}

	/**
	 * static 클래스 변수나 함수는 클래스 타잎의 변수나 함수이다. 
	 * 따라서, 전체 인스턴스에 모두 적용되고 하나만 있는 변수나 함수이다.
	 * 인스턴스가 아닌 클래스 범위에서 정의된다.
	 */
	SUBCASE("static member variable")
	{
		StaticMember::value = 3;
	}

	/**
	 * 무엇인가? 멤버 변수를 변경할 수 없는 함수이다.
	 * 왜 필요한가? 명시적으로 상태 변경이 없는 함수를 만들기 위해서
	 * 어떻게 사용하는가?  
	 */
	SUBCASE("const member function")
	{
		class ConstMemberFunction
		{
		public: 
			ConstMemberFunction()
				: v_{ 0 }
			{
			}

			void ChangeValue() const
			{
				v_ = 5;
			}

			int GetValue() const
			{
				return v_;
			}

		private: 
			mutable int v_;
		};

		ConstMemberFunction cmf;
		cmf.ChangeValue();
		CHECK(cmf.GetValue() == 5);
	}

	SUBCASE("static member function")
	{
		CHECK(StaticMember::GetAnyValue() == 3);
	}

	SUBCASE("use case")
	{
		SUBCASE("..")
		{
		
		}
	}
}
