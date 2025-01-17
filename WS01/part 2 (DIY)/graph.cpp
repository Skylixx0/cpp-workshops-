// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 01/23/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "graph.h"
#include "io.h"
using namespace std;

namespace seneca {
	void getSamples(int samples[], int noOfSamples)
	{
		for (int i = 0; i < noOfSamples; ++i)
		{
			cout << "  >> " << (i + 1) << "/";
			printInt(noOfSamples, 2);
			cout << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	/// <summary>
/// Draw a graph, allowing the user to visually compare the samples.
/// </summary>
/// <param name="samples">the collection of samples to be drawn</param>
/// <param name="noOfSamples">the number of samples in the collection</param>
/// <param name="label">the name of the graph</param>
void printGraph(int samples[], int noOfSamples, const char* label)
{
   // find which sample is the biggest. This sample will be used
   //   to scale the other sample so they can be visually compared.
   int max = findMax(samples, noOfSamples);

   printMsg("\n");
   drawLineWithLabel(GRAPH_WIDTH + 4, label); // PART_2: `+4` is new in part 2 (expands the graph to accommodate the number at the beginning of line)
   for (int i = 0; i < noOfSamples; ++i)
   {
      printInt((10 - i) * 10, 4); // PART_2: New in part 2
      printSampleBar(samples[i], max);
   }
   drawLine(GRAPH_WIDTH + 4); // PART_2: `+4` is new in part 2 (expands the graph to accommodate the number at the beginning of line)
}

	int findMax(int arr[], int arrSize)
	{
		int max = arr[0];
		for (int i = 1; i < arrSize; i++)
			if (max < arr[i])
				max = arr[i];

		return max;
	}

	void printSampleBar(int val, int max)
	{
		// Calculate the bar length as the width of the graph, minus
		//   - 2 to account for the left border (`| `)
		//   - 1 to account for the space between the bar and the sample value
		//   - 2 to account for the right border (` |`)
		//   - the number of digits in `max`
		//   and scaled to `max`. This scaling ensures that the largest
		//   sample will always occupy the width of the entire graph.
		int barLength = (GRAPH_WIDTH - 5 - intDigits(max)) * val / max;
		cout << "| ";
		for (int i = 0; i < barLength; ++i)
			cout << '*';
		cout << ' ';
		printInt(val, GRAPH_WIDTH - 5 - barLength);
		cout << " |" << endl;
	}
}
