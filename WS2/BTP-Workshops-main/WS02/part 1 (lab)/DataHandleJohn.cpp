// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "DataHandle.h"

//FOR TESTING ___ REMOVE AFTER FINISHING
#include <iostream>

using namespace std;

namespace seneca {
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
			auto currentPosition = ftell(g_fptr);

			// go to the begining of the file
			fseek(g_fptr, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			fseek(g_fptr, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}

	char* read(char delim) {
		int count = 0;
		long start = ftell(g_fptr);
		char inputChar = '\0'; 
		int read;
	
		do {
			read = fscanf(g_fptr, "%c", &inputChar);
			if(inputChar != delim && inputChar != '\n' && read != EOF) count++;
		} 	while (inputChar != delim && inputChar != '\n' && read != EOF);

		fseek(g_fptr, start, SEEK_SET); 

		if (count == 0) return nullptr;

		char* strArr = new char[count + 1];
	
		for (int i = 0; i < count; i++) {
			fscanf(g_fptr, "%c", &strArr[i]);
		}

		fscanf(g_fptr, "%c", &inputChar);
		strArr[count] = '\0';

		return strArr;
	}

	bool read(int& val, char delim) {
		char* arr = read(delim); 

		if (!arr) {
			return false;
		} 

		val = atoi(arr);

		delete[] arr;
		arr = nullptr;

		return true;
	}

	bool read(long& val, char delim) {
		char* arr = seneca::read(delim);

		if (!arr) {
			return false;
		}

		val = atol(arr);

		delete[] arr;
		arr = nullptr;

		return true;
	}

	bool read(double& val, char delim) {
		char* arr = seneca::read(delim);

		if (!arr) {
			return false;
		}

		val = atof(arr);

		delete[] arr;
		arr = nullptr;

		return true;
	}
}


