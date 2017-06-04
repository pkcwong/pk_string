#include "pk_string.h"

struct String_t String = {
	._constructor = &str_constructor,
	._free = &str_free,
	.append_c = &str_append_c,
	.append = &str_append,
	.insert_c = &str_insert_c,
	.insert = &str_insert,
	.concat = &str_concat,
	.substr = &str_substr,
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

string str_append_c(string this, const char* str)
{
	size_t* header = (size_t*)(this) - 1;
	*this = realloc(*this, String.length(this) + strlen(str) + 1);
	strcpy(&((*this)[String.length(this)]), str);
	*header = *header + strlen(str);
	return this;
}

string str_append(string this, const string str)
{
	size_t* header = (size_t*)(this) - 1;
	*this = realloc(*this, String.length(this) + String.length(str) + 1);
	for (int i = 0; i != String.length(str); i++)
	{
		(*this)[String.length(this) + i] = String.c_str(str)[i];
	}
	*header = *header + String.length(str);
	(*this)[*header] = '\0';
	return this;
}

string str_insert_c(string this, size_t pos, const char* str)
{
	size_t* header = (size_t*)(this) - 1;
	*this = realloc(*this, String.length(this) + strlen(str) + 1);
	for (int i = String.length(this) + strlen(str); i != strlen(str) + pos - 1; i--)
	{
		(*this)[i] = (*this)[i - strlen(str)];
	}
	for (int i = 0; i != strlen(str); i++)
	{
		(*this)[i + pos] = str[i];
	}
	*header = *header + strlen(str);
}

string str_insert(string this, size_t pos, const string str)
{
	size_t* header = (size_t*)(this) - 1;
	*this = realloc(*this, String.length(this) + String.length(str) + 1);
	for (int i = String.length(this) + String.length(str); i != String.length(str) + pos - 1; i--)
	{
		(*this)[i] = (*this)[i - String.length(str)];
	}
	for (int i = 0; i != String.length(str); i++)
	{
		(*this)[i + pos] = String.c_str(str)[i];
	}
	*header = *header + String.length(str);
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

string str_substr(const string this, int iterator_start, int iterator_end)
{
	size_t* header = malloc(sizeof(size_t) + sizeof(char**));
	char** data = (char**)(header + 1);
	*data = malloc(iterator_end - iterator_start + 1);
	for (int i = 0; i != iterator_end - iterator_start; i++)
	{
		(*data)[i] = String.c_str(this)[iterator_start + i];
	}
	*header = iterator_end - iterator_start;
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

