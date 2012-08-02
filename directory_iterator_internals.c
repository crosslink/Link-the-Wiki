/*
	DIRECTORY_ITERATOR_INTERNALS.C
	------------------------------
	Copyright (c) 2012 University of Otago
	Designed and implemented by Andrew Trotman
*/
#include <stdio.h>
#include "directory_iterator_internals.h"

/*
	ANT_DIRECTORY_ITERATOR_INTERNALS::ANT_DIRECTORY_ITERATOR_INTERNALS()
	--------------------------------------------------------------------
*/
ANT_directory_iterator_internals::ANT_directory_iterator_internals()
{
#ifdef _MSC_VER
	file_list = INVALID_HANDLE_VALUE;
#else
	file_list = NULL;
#endif
}

