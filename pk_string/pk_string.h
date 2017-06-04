#ifndef _PK_STRING
#define _PK_STRING

#include <stdlib.h>
#include <string.h>

typedef char** string;

extern struct String_t String;

struct String_t
{
	string (*_constructor)(const char* str);
	void (*_free)(string this);
	string (*append_c)(string this, const char* str);
	string (*append)(string this, const string str);
	string (*insert_c)(string this, size_t pos, const char* str);
	string (*insert)(string this, size_t pos, const string str);
	string (*erase)(string this, size_t iterator_start, size_t iterator_end);
	string (*concat)(const string str1, const string str2);
	string (*substr)(const string this, size_t iterator_start, size_t iterator_end);
	const char* (*c_str)(const string this);
	size_t (*length)(const string this);
};

string str_constructor(const char* str);
void str_free(string this);

string str_append_c(string this, const char* str);
string str_append(string this, const string str);
string str_insert_c(string this, size_t pos, const char* str);
string str_insert(string this, size_t pos, const string str);
string str_erase(string this, size_t iterator_start, size_t iterator_end);

string str_concat(const string str1, const string str2);
string str_substr(const string this, size_t iterator_start, size_t iterator_end);

const char* str_c_str(const string this);
size_t str_length(const string this);

#endif

