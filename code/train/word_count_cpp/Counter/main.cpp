#include<iostream>
#include"word_counter.h"

/*
 * istringstream �� ���ڿ� ������ parsing�� �� ���ȴ�  => ���ڿ����� �ʿ��� ���� �����ϰ�, ����� \n�� ������
 */
int main()
{
	Counter counter;
	std::cout << "word count: ";
	std::cout << counter.wordCount() << std::endl;
	std::cout << "unique word count: ";
	std::cout << counter.uniqueWordCount() << std::endl;
	//// 
	//std::string str = "aa bb, ccc";
	//std::istringstream ss(str);
	//std::string stringBuffer;
	//std::vector<std::string> vec;
	//vec.clear();

	//while (std::getline(ss, stringBuffer, ' '))
	//{
	//	vec.push_back(stringBuffer);
	//	std::cout << stringBuffer << ": ";
	//}
	//return 0;
}

//std::vector<std::string> split(std::string str, std::string delim)
//{
//	std::vector<std::string> vec;
//	char* c = (char*)str.c_str();
//	std::strtok()
//}

//int main()
//{
//	std::string line;
//	std::ifstream file("D:\\dearjiya\\gsp\\code\\train\\word_count\\data\\helloworld.txt");
//	if (file.is_open())
//	{
//		while (std::getline(file, line, ' '))
//		{
//			std::cout << line << std::endl;
//		}
//		file.close();
//	}
//	else
//	{
//		std::cout << "Unable to open file" << std::endl;
//		return 1;
//	}
//	return 0;
//}