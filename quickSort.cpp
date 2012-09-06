#include	<iostream>
#include	<cstdlib>
#include	<ctime>
#include	<vector>
#include	<list>
#include	<iterator>
#include	<algorithm>

using namespace std;


int		gen_rand()	{ return	rand() % 10000; }



// -------------------------------------------------------------
//              quick sort --- simple version
// -------------------------------------------------------------
template		< typename	elemType>
list<elemType>		my_concatenate( list<elemType>   less, 
									elemType   pivot, list<elemType>   greater )
{
	// notice the difference between insert() and splice()
	greater.insert( greater.begin(), pivot );
	less.splice( less.end(), greater );

	return	less;
}


template		< typename	elemType>
list<elemType>		quick_sort( list<elemType>   &iList )
{
	int 	middle = iList.size()/2;
	// an list of size 0 or 1 is already sorted
	if ( ! middle )
	{
		return	iList;
	}
	
	list<elemType>								less, greater;
	elemType 									pivot;
	typename	list<elemType>::iterator 		first = iList.begin(), last  = iList.end();  // !! read notes


	// locate pivot's value
	for (int i = 0; i < middle; ++i)
	{
		++first;
	}
	pivot = *first;

	// remove pivot
	iList.erase( first);


	// for each element in iList, if it is less than pivot then append it to less
	// otherwise append it to greater
	for ( first = iList.begin(); first != last; ++first )
	{
		if ( *(first) <= pivot )
			less.push_back( *first );
		else
			greater.push_back( *first );
	};

	iList = my_concatenate( quick_sort(less), pivot, quick_sort(greater) );

	return	iList;
}





int	main(int argc, char* argv[])
{
	int			num_items = atoi( argv[1] ); 

 	// Seed the RNG - Ramdon Number Generator
	srand( time( NULL ) );

	// ----------------------------------------
	// creates a list of random int values
	// ----------------------------------------
	list<int>		iList, li;
	//iList.reserve(num_items);
	generate_n( std::back_inserter(iList), num_items, gen_rand );



	// call sort function
	iList = quick_sort( iList );

	// print the list
	std::ostream_iterator<int>	os( cout, "\t\t" );
	copy( iList.begin(), iList.end(), os );
	cout << endl;

	return	0;
}