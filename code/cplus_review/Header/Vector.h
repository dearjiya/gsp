#include <iostream>

namespace test 
{
class Vector
{
public:
	Vector(int s);
	double& operator[](int i);
	int size();
private:
	double* elem;
	int size_;
};
} // namespace 
