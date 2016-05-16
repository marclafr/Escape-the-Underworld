#include <string.h>
#include <stdio.h>
#include "Vector.h"

#ifndef _CHAIN_
#define _CHAIN_

class String{
private:
	char* buffer = nullptr;
	unsigned int max_size;
public:
	//Constructors & Destructor
	String()
	{
		buffer = new char[40];
		max_size = 40;
	}
	String(const char* string)
	{
		int len = strlen(string);
		buffer = new char[len + 1];
		max_size = len + 1;
		strcpy_s(buffer, max_size, string);
	}
	String(const String& string)
	{
		max_size = string.max_size;
		buffer = new char[max_size];
		strcpy_s(buffer, string.max_size, string.buffer);
	}
	~String(){ delete[]buffer; }
	//--

	//Functions
	//read string
	const char* c_str()const
	{
		return buffer;
	}
	//read lenght
	const unsigned int lenght()const
	{
		return strlen(buffer);
	}
	//read size
	const unsigned int capacity()const
	{
		return max_size;
	}
	//string is empty(?)
	bool empty()const
	{
		return strlen(buffer) == 0;
	}
	//clear string
	const void Clear()
	{
		buffer[0] = '\0';
	}
	//write string
	void GetString()
	{
		gets_s(buffer, max_size);
	}

	//string into string
	bool ContainsString(const String& string)const
	{
		return strstr(string.buffer, buffer) != nullptr;
	}

	bool ContainsString(const char* string)const
	{
		return strstr(buffer, string) != nullptr;
	}
	//--

	//operator ==
	bool operator==(const String& string)const
	{
		return (strcmp(buffer, string.buffer) == 0);
	}
	bool operator==(const char* string)const
	{
		return (strcmp(buffer, string) == 0);
	}
	//--

	//operator =
	void operator=(const String& string)
	{
		unsigned int len = strlen(string.buffer) + 1;
		if (max_size >= len){
			strcpy_s(buffer, len, string.buffer);
		}
		else{
			delete[]buffer;
			buffer = new char[len];
			strcpy_s(buffer, len, string.buffer);
		}
	}
	void operator=(const char* string)
	{
		unsigned int len = strlen(string) + 1;
		if (max_size >= len){
			strcpy_s(buffer, len, string);
		}
		else{
			delete[]buffer;
			buffer = new char[len];
			strcpy_s(buffer, len, string);
		}
	}
	//--

	//operator +=
	void operator +=(const String& string)
	{
		if (max_size < lenght() + string.lenght() + 1)
		{
			char* temp = nullptr;
			temp = new char[lenght() + 1];
			strcpy_s(temp, lenght() + 1, buffer);
			delete[]buffer;
			int len = strlen(temp) + 1 + strlen(string.buffer) + 1;
			buffer = new char[len];
			strcpy_s(buffer, len, temp);
			strcat_s(buffer, len, string.buffer);
		}
		else{ strcat_s(buffer, string.lenght() + 1, string.buffer); }
	}

	void operator +=(const char* string){
		if (max_size < lenght() + strlen(string) + 1)
		{
			char* temp = nullptr;
			temp = new char[lenght() + 1];
			strcpy_s(temp, lenght() + 1, buffer);
			delete[]buffer;
			int len = strlen(temp) + 1 + strlen(string) + 1;
			buffer = new char[len];
			strcpy_s(buffer, len, temp);
			strcat_s(buffer, len, string);
		}
		else{ strcat_s(buffer, max_size, string); }
	}
	//--

	//operator +
	String operator +(const String& string)
	{
		String new_str;
		unsigned int len = lenght() + string.lenght() + 1;
		new_str.max_size = len;
		new_str.buffer = new char[len];
		strcpy_s(new_str.buffer, len, buffer);
		strcat_s(new_str.buffer, len, string.buffer);
		return new_str;
	}
	String operator +(const char* string)
	{
		String new_str;
		unsigned int len = lenght() + strlen(string) + 1;
		new_str.max_size = len;
		new_str.buffer = new char[len];
		strcpy_s(new_str.buffer, len, buffer);
		strcat_s(new_str.buffer, len, buffer);
		return new_str;
	}
	//--

	//Tokenize
	unsigned int Tokenize(const char* symbols, Vector<String> &tokens){  //, char* string
		unsigned int num_words = 0;
		char* context = nullptr;
		char* save = nullptr;
		save = strtok_s(buffer, symbols, &context);
		while (save != NULL)
		{
			num_words++;
			tokens.PushBack(save);
			save = strtok_s(NULL, symbols, &context);
		}
		return num_words;
	}
	//--

	//Remove character
	void RemoveChar(const char character)
	{
		int num_removed = 0;
		int len = strlen(buffer);
		for (int i = 0; i <= len; i++)
		{
			if (buffer[i] == character)
			{
				int j = i;
				while (buffer[j + 1] != NULL)
				{
					buffer[j] = buffer[j + 1];
					j++;
				}
				num_removed++;
			}
		}
		buffer[len - num_removed] = '\0';
	}
	//--
};
#endif //_CHAIN_