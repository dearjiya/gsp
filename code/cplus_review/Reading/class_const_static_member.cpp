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
	 * c++���� �Ϲ������� const�� �ѹ��� ���� ������ ����, ����� �������� �ʴ� �Լ��� ����ϴ� Ű����
	 * �̴�. ����, const member�� �ѹ��� ���� ������ ������ ������ �� �ִ�.
	 */
	SUBCASE("const member variable")
	{

	}

	/**
	 * static Ŭ���� ������ �Լ��� Ŭ���� Ÿ���� ������ �Լ��̴�. 
	 * ����, ��ü �ν��Ͻ��� ��� ����ǰ� �ϳ��� �ִ� ������ �Լ��̴�.
	 * �ν��Ͻ��� �ƴ� Ŭ���� �������� ���ǵȴ�.
	 */
	SUBCASE("static member variable")
	{
		StaticMember::value = 3;
	}

	/**
	 * �����ΰ�? ��� ������ ������ �� ���� �Լ��̴�.
	 * �� �ʿ��Ѱ�? ��������� ���� ������ ���� �Լ��� ����� ���ؼ�
	 * ��� ����ϴ°�?  
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
