#include <iostream>
#include "file.h"

FILE* file;
using namespace std;

namespace seneca {
bool openFile(const char filename[])
	{
		bool allGood = false;
		if (file == nullptr)
		{
			file = fopen(filename, "r");
			allGood = file != nullptr;
		}
		return allGood;
}
void closeFile()
	{
		if (file)
		{
			fclose(file);
			file = nullptr;
		}
}

char* read(char d){
		int numOfChar = 0;
		int position = ftell(file);
		char input = '\0';
		int read;
	
		do{
			read = fscanf(file, "%c", &input);
			if (input != d && read == 1){
				numOfChar++;
			}
		}while(input != d && read == 1);
		
		fseek(file, position, SEEK_SET);
		if(numOfChar == 0){
			return nullptr;
		}	

		char* str = new char[numOfChar + 1];
		for(int i = 0; i < numOfChar; i++)
		{
			fscanf(file, "%c", &str[i]);
		}
		fscanf(file, "%c", &input);
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

int getRecordsCount()
	{
		int noOfRecs = -1;

		if (file != nullptr)
		{
			// get current position in the file.
			auto currentPosition = std::ftell(file);

			// go to the begining of the file
			std::fseek(file, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(file, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(file, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}
}