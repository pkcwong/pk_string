#include "pk_string.h"

struct String_t String = {
	._constructor = &str_constructor,
	._free = &str_free,
	.append = &str_append,
	.concat = &str_concat,
	.length = &str_length
};

string str_constructor(const char* str)
{
	size_t* header = (size_t*)(malloc(sizeof(size_t) + strlen(str) + 1));
	char* data = (char*)(header + 1);
	for (int i = 0; i != strlen(str); i++)
	{
		data[i] = str[i];
	}
	*header = strlen(str);
	data[*header] = '\0';
	return data;
}

void str_free(string this)
{
	size_t* header = (size_t*)(this) - 1;
	free(header);
}

string str_append(string this, const string str)
{
	size_t* header = (size_t*)(realloc((size_t*)(this) - 1, sizeof(size_t) + String.length(this) + String.length(str) + 1));
	char* data = (char*)(header + 1);
	for (int i = 0; i != String.length(str); i++)
	{
		data[*header + i] = str[i];
	}
	*header  = *header + String.length(str);
	data[*header] = '\0';
	return data;
}

string str_concat(const string str1, const string str2)
{
	size_t* header = (size_t*)(malloc(sizeof(size_t) + String.length(str1) + String.length(str2) + 1));
	char* data = (char*)(header + 1);
	for (int i = 0; i != String.length(str1); i++)
	{
		data[i] = str1[i];
	}
	for (int i = 0; i != String.length(str2); i++)
	{
		data[String.length(str1) + i] = str2[i];
	}
	*header = String.length(str1) + String.length(str2);
	data[*header] = '\0';
	return data;
}

size_t str_length(const string this)
{
	return *((size_t*)(this) - 1);
}

