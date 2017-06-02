#ifndef _PK_STRING
#define _PK_STRING

#include <stdlib.h>
#include <string.h>

typedef char* string;

extern struct String_t String;

struct String_t
{
	string (*_constructor)(const char* str);
	void (*_free)(string this);
	string (*append)(string this, const string str);
	string (*concat)(const string str1, const string str2);
	size_t (*length)(const string this);
};

string str_constructor(const char* str);
void str_free(string this);

string str_append(string this, const string str);

string str_concat(const string str1, const string str2);

size_t str_length(const string this);

#endif

