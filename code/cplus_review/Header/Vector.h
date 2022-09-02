#include <iostream>

namespace 
{
class Vector
{
public:
	Vector(int s);
	double& operator[](int i);
	int size();
private:
	double* elem;
	int s;
};

double sqrt_sum(Vector& v)
{
	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
	{
		sum += std::sqrt(v[i]);
	}
	return sum;
}
} // namespace 
