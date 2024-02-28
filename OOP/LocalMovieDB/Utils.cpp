#pragma once
#include "Utils.h"
#include <sstream>
#include <regex>
#include <assert.h>
using namespace std;

vector<string> tokenize(std::string& str, char delimiter)
{
	vector<string> result;
	string token;
	stringstream ss(str);
	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}

string trim(string& to_trim)
{
	return regex_replace(to_trim, regex("^\\s+|\\s+$"), "");
}


string r_redundant_spaces(string& to_process)
{
	return regex_replace(to_process, regex("\\s+"), " ");
}

void test_trim()
{
	string to_trim = "     imi  plac    pointerii   ";
	string trimmed_string = trim(to_trim);
	assert(trimmed_string == "imi  plac    pointerii");
}


void test_redunant_spaces()
{
	string to_process = "What is    a    pointer";
	to_process = r_redundant_spaces(to_process);
	assert(to_process == "What is a pointer");
}

void test_tokenize()
{
	string to_tokenize = "What is a pointer | RhabuDhabi | 22 33 | 1000 | www.dasdas.com ";
	vector<string> tokenized_string = tokenize(to_tokenize, '|');
	assert(tokenized_string[0] == "What is a pointer ");
	assert(tokenized_string[1] == " RhabuDhabi ");
	assert(tokenized_string[2] == " 22 33 ");
	assert(tokenized_string[3] == " 1000 ");
	assert(tokenized_string[4] == " www.dasdas.com ");
}

void test_trim();

