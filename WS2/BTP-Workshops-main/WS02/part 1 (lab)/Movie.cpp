#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Movie.h"
#include "DataHandle.h"
// TODO: include any other header that is necessary for your solution

using namespace std;
namespace seneca {
// TODO: put everything in the `seneca` namespace

	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	// Movie* g_colMovies = nullptr;
	Movie* arrayOfMovies = nullptr;
	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	
	int g_cntMovies = 0;
	

	bool loadData(Movie& aMovie){
		// for(int i = 0; i < g_cntMovies; i++){
		// 		cout << "wwda" << endl;
		// seneca::read(aMovie.m_budget, ',');
		// aMovie.m_budget = 0;
		


		// int budget = 0;
		// long grossIncome = 0;
		// double rating = 0.0;
		// if(seneca::read(aMovie.m_budget, ',') == aMovie.m_budget && seneca::read(aMovie.m_grossIncome, ',') == aMovie.m_grossIncome && seneca::read(aMovie.m_rating, ',') == aMovie.m_rating && title) {
		// 	aMovie.m_title = title; 
			
		// 	return true;
		// 	}
		if(!seneca::read(aMovie.m_budget, ',')){
//			return false;
		}
		if(!seneca::read(aMovie.m_grossIncome , ',')){
//			return false;
		}
		else if(!seneca::read(aMovie.m_rating, ',')){
//			return false;
		}
		char* title = seneca::read('\n');
		if(!title){
			return false;
		}
		else {
			aMovie.m_title = title; 
			return true;
		}
			
		
	};

	void deallocateMemory(){
		for(int i = 0; i < g_cntMovies; i++){
			delete[] arrayOfMovies[i].m_title;
			arrayOfMovies[i].m_title = nullptr;
		}
		delete[] arrayOfMovies;
		arrayOfMovies = nullptr;
		// g_cntMovies = 0;
	}

	bool loadData(const char* filename){
		if(arrayOfMovies != nullptr){
			seneca::deallocateMemory();
		}
		bool fileOpened = openFile(filename);
		if(!fileOpened){
			return fileOpened;
		}
		
			
			g_cntMovies = getRecordsCount();

			arrayOfMovies = new Movie[g_cntMovies];
			// cout << g_cntMovies << endl;
			 

			// char* title_string = nullptr;
			// cout << title_string << endl;
			// title_string = new char[g_cntMovies + 1];
			// int start = 0;
			// cout << "awdawdawdawdawdawd" << endl;
			// cout << g_cntMovies << endl;
			for(int i = 0; i < g_cntMovies; i++){
				seneca::loadData(arrayOfMovies[i]);
				// cout << "waaaa" << endl;
				// cout << arrayOfMovies[i].m_budget << endl;
				// cout << "wwda" << endl;
				// seneca::read(arrayOfMovies[i].m_budget, ',');
				// // cout << arrayOfMovies[i].m_budget << endl;
				// seneca::read(arrayOfMovies[i].m_grossIncome, ',');
				// // cout << arrayOfMovies[i].m_grossIncome << endl;
				// seneca::read(arrayOfMovies[i].m_rating, ',');
				// // cout << arrayOfMovies[i].m_rating << endl;
				// arrayOfMovies[i].m_title = seneca::read(' ');
				// // cout << title_string << endl;
			}
			// delete[] arrayOfMovies;
			// // arrayOfMovies = nullptr;

			seneca::closeFile();
			return fileOpened;
			
			
			// char* str = read(',');
			// cout << str << endl;
			// delete[] str;
			// str = nullptr;
			// for(int i = 0; i < g_cntMovies; i++){
			// 	str[i] = 
			// 	// title_string[i] = read(',');
			// }
			// arrayOfMovies[i].m_title = read(',');

			// for(int i = 0; i < g_cntMovies; i++){
			// 	arrayOfMovies[i].m_title = read(',');
			// 	cout << "blyat" << endl;

			// 	cout << arrayOfMovies[i].m_title << endl;
			// 	// arrayOfMovies[i].m_budget = read();
			// }
		
	};

	void display(int idx){
		if(idx >= 0 && idx < g_cntMovies){
			cout << arrayOfMovies[idx].m_title << ", ";
			cout << arrayOfMovies[idx].m_budget << ", ";
			cout << "$" << arrayOfMovies[idx].m_grossIncome << ", ";
			cout << arrayOfMovies[idx].m_rating << endl;
		}
		else{
			cout << "Index out of bounds" << endl;
		}
	}

	void display(const char* label, int startIdx, int endIdx){
		for(auto i = 0; i < 8; i++){
			cout << "*";
		}
		cout << " " << label << " ";
		for(auto i = 0; i < 16; i++){
			cout << "*";
		}
		cout << "\n";

		for(int i = startIdx; i <= endIdx; i++){
			if(i == g_cntMovies){
				break;
			}
			cout << ">> ";
			seneca::display(i);
			cout << '\n';
		}
	
// TODO: define below all the functions from this module
}
}
