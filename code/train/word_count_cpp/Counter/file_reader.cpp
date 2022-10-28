#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "file_reader.h"

std::vector<std::string> Reader::fileRead()
{
	std::string str;
	std::ifstream file;
	std::vector<std::string> vec;
	std::string stringBuffer;
	file.open("D:\\dearjiya\\gsp\\code\\train\\word_count_cpp\\data\\helloworld.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, str);
			std::istringstream ss(str);
			while (std::getline(ss, stringBuffer, ' '))
			{
				vec.push_back(stringBuffer);
			}
		}
		file.close();
	}

	/*for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}*/

	return vec;
}