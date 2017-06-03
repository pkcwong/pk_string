#include "pk_string.h"

struct String_t String = {
	._constructor = &str_constructor,
	._free = &str_free,
	.concat = &str_concat,
	.c_str = &str_c_str,
	.length = &str_length
};

string str_constructor(const char* str)
{
	size_t* header = malloc(sizeof(size_t) + sizeof(char**));
	char** data = (char**)(header + 1);
	*data = strdup(str);
	*header = strlen(str);
	return data;
}

void str_free(string this)
{
	size_t* header = (size_t*)(this) - 1;
	free(*this);
	free(header);
}

string str_concat(const string str1, const string str2)
{
	size_t* header = malloc(sizeof(size_t) + sizeof(char**));
	char** data = (char**)(header + 1);
	*data = malloc(String.length(str1) + String.length(str2) + 1);
	for (int i = 0; i != String.length(str1); i++)
	{
		(*data)[i] = String.c_str(str1)[i];
	}
	for (int i = 0; i != String.length(str2); i++)
	{
		(*data)[String.length(str1) + i] = String.c_str(str2)[i];
	}
	*header = String.length(str1) + String.length(str2);
	(*data)[*header] = '\0';
	return data;
}

const char* str_c_str(const string this)
{
	return *this;
}

size_t str_length(const string this)
{
	return *((size_t*)(this) - 1);
}

