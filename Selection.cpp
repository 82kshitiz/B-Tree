#pragma once
#include "Selection.h"
#include <iostream>
#include <fstream>
// ------------------------------
// Definition of Selection Class
// ------------------------------

//-- Public Methods --//

// Default Constructor
template <class Type>
Selection<Type>::Selection()
{

}

// DONE
template <class Type>
Selection<Type>::Selection(vector<vector<Type> > items)
{
	init(items);

}

template <class Type>
void Selection<Type>::init(vector<vector<Type> > items) {
	HEAPSIZE = (int)items.size();
	master_data = items;
	size = 0;
	data.reserve(HEAPSIZE);
	for (int i = 0; i < HEAPSIZE; i++) {
		its.push_back(master_data[i].begin());
	}
	for (int i = 0; i < HEAPSIZE; i++) {
		push(i);
	}
	/** \endcode */
}

//
template <class Type>
void Selection<Type>::sort()
{
	/** \code */
	while (size != 0) {
		run.push_back(pop());
	}
}

template <class Type>
vector<Type> Selection<Type>::retrieve()
{
	return run;
}

template <class Type>
void Selection<Type>::logFile(ofstream& outFile2)
{

	outFile2 << "The number of records that can fit in memory are " << HEAPSIZE << endl;

	int counter = 0;

	for (typename vector<vector<Type> >::iterator outit = master_data.begin(); outit != master_data.end(); ++outit)
	{
		for (typename vector<Type>::iterator init = (*outit).begin(); init != (*outit).end(); ++init)
		{
			counter++; //keeps track of how many elements are in the vector of vectors
					   //i.e. the number of records
		}
	}

	outFile2 << "The number of records are " << counter << endl;

	outFile2 << "The number of runs are " << HEAPSIZE << endl;

	size_t max = (int)master_data[0].size();
	size_t min = (int)master_data[0].size();

	for (int i = 0; i < HEAPSIZE; i++)
	{
		// master_data[i].size()
		if (master_data[i].size() > max)
		{
			max = (int)master_data[i].size();
		}

		if (master_data[i].size() < min)
		{
			min = (int)master_data[i].size();
		}

	}

	outFile2 << "The smallest number of records in all of the runs is " << min << endl;
	outFile2 << "The largest number of records in all of the runs is " << max << endl;
	outFile2 << "The arithmetic mean number of records in all of the runs is " << counter / HEAPSIZE << endl;
	
	int height = static_cast<int>(ceil(log2(counter))); //ceil(log2(number of records))
	outFile2 << "The height of the Selection tree for the merge is " << height << endl;

}

//---- Support Methods ----//
//-- Private Methods --//

//-- Index Getter --//
// DONE
template <class Type>
int Selection<Type>::l_child(int n) {
	/** \code */
	return 2 * n + 1;
	/** \endcode */
}

// DONE
template <class Type>
int Selection<Type>::r_child(int n) {
	/** \code */
	return 2 * (n + 1);
	/** \endcode */
}

// DONE
template <class Type>
int Selection<Type>::parent(int n) {
	/** \code */
	return (n - 1) / 2;
	/** \endcode */
}

template <class Type>
int Selection<Type>::next(int n) {
	/** \code */
	return n;
	/** \endcode */
}

template <class Type>
int Selection<Type>::head() {
	/** \code */
	return 0;
	/** \endcode */
}

template <class Type>
int Selection<Type>::tail() {
	/** \code */
	return size - 1;
	/** \endcode */
}


//-- Existence Checker --//

// DONE
template <class Type>
bool Selection<Type>::exist_parent(int n) {
	/** \code */
	return parent(n) >= 0;
	/** \endcode */
