// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "DataHandle.h"
// TODO: include any other header that is necessary for your solution

using namespace std;
namespace seneca {
// TODO: put everything in the `seneca` namespace

	/// <summary>
	/// The file descriptor; will be set when a file is open with
	///   `openFile`, and reset when the file is closed with `closeFile`.
	/// </summary>
	FILE* g_fptr;

	bool openFile(const char filename[])
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	void closeFile()
	{
		if (g_fptr)
		{
			fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	int getRecordsCount()
	{
		int noOfRecs = -1;

		if (g_fptr != nullptr)
		{
			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}
	char* read(char d){

		int numOfChar = 0;
		int position = ftell(g_fptr);
		char input = '\0';
		int read;
	
		do{
			read = fscanf(g_fptr, "%c", &input);
			if (input != d && read == 1){
				numOfChar++;
			}
		}while(input != d && read == 1);
		
		fseek(g_fptr, position, SEEK_SET);
		if(numOfChar == 0){
			return nullptr;
		}	

		char* str = new char[numOfChar + 1];
		for(int i = 0; i < numOfChar; i++)
		{
			fscanf(g_fptr, "%c", &str[i]);
		}
		fscanf(g_fptr, "%c", &input);
		str[numOfChar] = '\0';
		return str;
	};

	bool read(int& refff, char d)
	{
		char* str1 = seneca::read(d);
		

		if(!str1){
			return false;
		}
		
		refff = std::atoi(str1);

		// cout << refff << endl;

		delete[] str1;
		str1 = nullptr;
		return true;
		
			// const char* example1 = "34534    woiefhWH 483";
			// int intConversion = std::atoi(example1);
			// // int example = std::atoi("234  awdwd  ");
			// cout << "Debug:     " << intConversion << "atoi works" << endl;

			// int refRef = reference;
			
			// cout << std::atoi(str1) << endl;
			// int ref = refff;
			
			
	};
	bool read(long& ref, char delim)
	{
		char* str1 = seneca::read(delim);

		if (str1 != nullptr)
		{
			ref = std::atol(str1);
			
			delete[] str1;
			str1 = nullptr;
			return true;
		}
		else {
			return false;
		}
	};
	bool read(double& reference, char del)
	{
		// cout << "read double" << endl;
		
		char* str1 = seneca::read(del);

		if (str1 != nullptr)
		{
			reference = std::atof(str1);
			
			delete[] str1;
			str1 = nullptr;
			return true;
		}
		else {
			return false;
		}
	}
}
// TODO: define below all the functions from this module


