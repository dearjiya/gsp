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
	//error: const char* 형식의 값을 사용하여 char* 형식의 엔티티를 초기화할 수 없습니다
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
		jiya::Player player_;  // 일반적인 구조체 선언

		jiya::Player* player2_ = new jiya::Player; // 구조체 동적할당
		player2_->damage_ = 30;

		jiya::Monster monster_; // 클래스(객체) 선언
		monster_.damage_ = 50;

		jiya::Monster* monster2_ = new jiya::Monster(); // 클래스(객체) 동적선언 

		std::cout << "player_ damage: " << player_.damage_ << std::endl;
		std::cout << "plyer2_ damage: " << player2_->damage_ << std::endl;

		std::cout << "monster_ damage: " << monster_.damage_ << std::endl;
		std::cout << "monster2_ damage: " << monster2_->damage_ << std::endl;
	}
}