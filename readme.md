# pk_string

release date - 2017/06/04

Log:
- added modifier methods
- added constructors and destructors

---

## Brief

Augmentation string library for standard ```<string.h>```. Automatic dynamic memory management to provide ```string``` data type for C.

## Terminology

### string

The ```string``` type is defined as follows.
```C
typedef char** string;
```
A ```string``` variable stores two pieces of information, the length of the ```cstring```, and also the pointer to the ```cstring```. The variable when dereferenced may be used as a ```char*```.

### String

All methods of the library are exported in a single ```String``` module.

## Method Summary

### class String

Method Declaration | Arguments | Method Description
--- | --- | ---
string \_constructor | const char\* str | convert a ```cstring``` to ```string```
void \_free | string this | free up memory for ```string``` object
string append_c | string this, const char\* str | append a ```cstring```
string append | string this, const string str | append a ```string```
string insert_c | string this, size_t pos, const char* str | insert a ```cstring``` at position
string insert | string this, size_t pos, const string str | insert a ```string``` at position
string erase | string this, size_t iterator_start, size_t iterator_end | removes part of a ```string```
string concat | const string str1, const string str2 | create a new ```string``` for the result of concatenation
string substr | const string this, size_t iterator_start, size_t iterator_end | create a new string for the result of substring
const char\* c_str | const string this | return a ```cstring``` representation
size_t length | const string this | return length of ```string```
