// - Alikhan Ongdassyn,
// - aongdassyn@myseneca.ca,
// - 158486225,
// - 1/16/24.

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "io.h"
#include "graph.h"

using namespace seneca;

int main()
{
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;

	drawLine(GRAPH_WIDTH);
	drawLineWithLabel(GRAPH_WIDTH, "Welcome to SeneGraph");
	drawLine(GRAPH_WIDTH);

	while (!done)
	{
		int userChoice = menu(noOfSamples);
		switch (userChoice)
		{
		case 1:
			printMsg("Enter number of available samples: ");
			noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else
			{
				printMsg("Please enter the sample values:\n");
				getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else if (samples[0] == 0)
			{
				printMsg("Samples missing. Please enter the sample values.\n");
			}
			else
			{
				printGraph(samples, noOfSamples, "SeneGraph");
			}
			break;
		case 0:
			printMsg("Thank you for using SeneGraph. Bye!\n");
			done = true;
		}
	}
}
