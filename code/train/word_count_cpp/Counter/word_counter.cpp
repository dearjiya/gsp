#include<vector>
#include<string>
#include<set>
#include"word_counter.h"
#include"file_reader.h"

int Counter::wordCount()
{
	Reader reader{};
	std::vector<std::string> words;
	words = reader.fileRead();
	count = words.size();
	return count;
}

int Counter::uniqueWordCount()
{
	Reader reader{};
	std::vector<std::string> words = reader.fileRead();

	std::set<std::string> wordSets(words.begin(), words.end());
	return wordSets.size();
}


