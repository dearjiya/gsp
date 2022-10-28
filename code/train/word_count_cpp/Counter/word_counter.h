#include<vector>
#include<string>
#include<set>
#include"file_reader.h"

class Counter
{
public:
	Counter() : count(0)
	{
	}
	int wordCount();
	int uniqueWordCount();

private:
	int count;
};


