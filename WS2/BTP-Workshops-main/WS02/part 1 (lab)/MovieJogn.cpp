#include <iostream>
#include <cstring>
#include "Movie.h"
#include "DataHandle.h"

using namespace std;
using namespace seneca;

namespace seneca{
	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	Movie* g_colMovies = nullptr;

	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	int g_cntMovies = 0;

	void deallocateMemory() {
		for (int i = 0; i < g_cntMovies; i++) {
			delete[] g_colMovies[i].m_title;
		}
		delete[] g_colMovies;
		g_colMovies = nullptr;
		g_cntMovies = 0;
	}

	bool loadData(Movie& aMovie) {

		int budget = 0;
		long grossIncome = 0;
		double rating = 0.0;

		if(!read(budget, ',')){
			return false;
		}

		if(!read(grossIncome, ',')){
			return false;
		}

		if(!read(rating, ',')){
			return false;
		}

		char* title = aMovie.m_title = read('\n');
		if (!title) {
			return false;
		}
		
		aMovie.m_budget = budget;
		aMovie.m_grossIncome = grossIncome;
		aMovie.m_rating = rating;
		aMovie.m_title = title;

		return true;
	}

	bool loadData(const char* filename) {
		if (g_colMovies != nullptr) {
			deallocateMemory();
		}

		bool fileOpened = openFile(filename);
		
		if(!fileOpened) {
			return fileOpened;
		} else {
			g_cntMovies = getRecordsCount();
			g_colMovies =  new Movie[g_cntMovies];

			for (int i = 0; i < g_cntMovies; i++) {
				loadData(g_colMovies[i]);
			}
		}

		closeFile();
		return fileOpened;
	}

	void display(int idx) {
		if (idx >= 0 && idx < g_cntMovies) {
			cout << g_colMovies[idx].m_title << ", " << g_colMovies[idx].m_budget << ", $" << g_colMovies[idx].m_grossIncome << ", " << g_colMovies[idx].m_rating << endl;
		} else {
			cout << "Index out of bounds." << endl;
		}
	}

	void display(const char* label, int startIdx, int endIdx) {
		cout << "******** " << label << " ****************" << endl;
		for (int i = startIdx; i <= endIdx && i < g_cntMovies; i++) {
			cout << ">> ";
			display(i);
		}
	}
}