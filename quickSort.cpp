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
list<elemType>		quick_sort_1( list<elemType>   &iList )
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

	// assembly sorted sub-lists
	iList = my_concatenate( quick_sort_1(less), pivot, quick_sort_1(greater) );

	return	iList;
}




// -------------------------------------------------------------
//              quick sort --- in-place version
// -------------------------------------------------------------
template	< typename   elemType, typename   InputIter, typename   outputIter >
outputIter 	partition( 	InputIter   left, InputIter   right, 
						InputIter   pivotIndex, outputIter   storeIndex, const elemType	  pivot )
{
	// ????????
	cout << "About to call partition: " << *left << " - " << *right << " - " << *pivotIndex << " - "
			<< *storeIndex << " - " << pivot << "\n" << endl;



	// move pivot to end
	cout << "About to swap pivotIndex & right: " << *pivotIndex << "..." << *right << "\n" << endl; 
	iter_swap( pivotIndex, right );

	// main loop
	for ( ; left != right; ++left )
	 	if ( *left < pivot && left != storeIndex)
	 	{
			cout << "About to swap left & storeIndex: " << *left << "..." << *storeIndex << "\n" << endl; 
	 		iter_swap( left, storeIndex );
	 		++storeIndex;
	 	};

	// move pivot to its final place
	cout << "About to swap storeIndex & right: " << *storeIndex << "..." << *right << "\n" << endl; 
 	iter_swap( storeIndex, right );

	return 	storeIndex;
}



template		< typename	IterType>
void	quick_sort_2( IterType   left, IterType   right, IterType   end )
{
	int 		size;
	IterType	iter = left, pivotIndex = left;

	// check validity
	if ( left == right )
	{
		return;
	}

	// calculate the size
	for ( size = 1; iter != right; ++size, ++iter ) 	{
	}


	// ????????
	cout << "About to call quick_sort_2, size is " << size << "\n" << endl;
	for ( iter = left; iter != end; ++iter )
	{
		cout << "   " << *iter;
	}
	cout << "   " << endl;
	// ????????



	// if 'left' > 'right', my_swap them
	if ( *left > *right )
	{
		cout << "About to swap left & right: " << *left << "..." << *right << "\n" << endl; 
		iter_swap( left, right );
	}

	// if the list has 1 or 2 elements
	if ( size <= 2 )
		return;


	// right now the list has more than 2 elements and 'left' <= 'right' 

	// choose 'pivotIndex' as the middle
	size /= 2;
	for ( int i = 1; i <= size; ++i, ++pivotIndex )	{
	}

	// get lists of bigger and smaller elements and final position of pivot
	pivotIndex = partition( left, right, pivotIndex, left, *pivotIndex );

	cout << "New pivotIndex is: " << *pivotIndex << "........" << endl;

	// recursively sort elements smaller than the pivot
	iter = pivotIndex;
	if ( iter != left )
		quick_sort_2( left, --iter, pivotIndex );

	// recursively sort elements smaller than the pivot
	quick_sort_2( ++pivotIndex, right, end );
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

	// print the list
	std::ostream_iterator<int>	os( cout, "\t\t" );
	copy( iList.begin(), iList.end(), os );
	cout << "\n" << endl;



	// call sort function
	quick_sort_2( iList.begin(), --iList.end(), iList.end() );



	// print the list
	//std::ostream_iterator<int>	os( cout, "\t\t" );
	copy( iList.begin(), iList.end(), os );
	cout << endl;

	return	0;
}