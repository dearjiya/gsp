#include <doctest/doctest.h>
#include <iostream>

namespace jiya
{
class Monster
{
public: 
	int hp_ = 100;
	int damage_ = 20;
	//char *name = "green monster";
	//error: const char* ������ ���� ����Ͽ� char* ������ ��ƼƼ�� �ʱ�ȭ�� �� �����ϴ�
};

struct Player
{
	int hp_ = 100;
	int damage_ = 10;
	//char* name = "human";
};
}

TEST_CASE("dot_arrow")
{
	SUBCASE("use case")
	{
		jiya::Player player_;  // �Ϲ����� ����ü ����

		jiya::Player* player2_ = new jiya::Player; // ����ü �����Ҵ�
		player2_->damage_ = 30;

		jiya::Monster monster_; // Ŭ����(��ü) ����
		monster_.damage_ = 50;

		jiya::Monster* monster2_ = new jiya::Monster(); // Ŭ����(��ü) �������� 

		std::cout << "player_ damage: " << player_.damage_ << std::endl;
		std::cout << "plyer2_ damage: " << player2_->damage_ << std::endl;

		std::cout << "monster_ damage: " << monster_.damage_ << std::endl;
		std::cout << "monster2_ damage: " << monster2_->damage_ << std::endl;
	}
}