// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 01/23/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "mark.h"

namespace seneca {
	/// <summary>
	/// The maximum number of `Mark` object that this application is able to handle.
	/// </summary>
	const int MAX_NO_RECS = 1000;

	/// <summary>
	/// Open a file for reading.
	/// </summary>
	/// <param name="filename">name of the file to open</param>
	/// <returns>true if file is opened successfuly, false otherwise</returns>
	bool openFile(const char* filename);

	/// <summary>
	/// Close the file if it's open; do nothing otherwise.
	/// </summary>
	void closeFile();

	/// <summary>
	/// Read one student record from the open file.
	/// </summary>
	/// <param name="mark">stores the address of a single object of type `Mark`</param>
	/// <returns>true if the record is read successfuly, false otherwise</returns>
	bool readSingleMark(Mark* mark);

	/// <summary>
	/// Reads the content of the file and populates an array of objects of type `Mark`.
	/// 
	/// This function stops reading from the file when there is nothing more to read,
	///   or `MAX_NO_RECS` marks have been extracted (whichever comes first).
	/// </summary>
	/// <param name="marks">the address of an array with `MAX_NO_RECS` capacity
	///   that will receive the data from file</param>
	/// <returns>the actual number of records read</returns>
	int readAllMarks(Mark* marks);
}
#endif 
