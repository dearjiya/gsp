#include <iostream>

namespace test 
{
class Vector
{
public:
	Vector(int s);

	double& operator[](int i);

	virtual int size() const
	{
		return size_;
	}
private:
	double* elem;
	int size_;
};
} // namespace 
