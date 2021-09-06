#include <iostream>
#include <vector>
#include <algorithm>
#include "insert_sorted.h"

int main()
{
	std::vector<int> vect(25);
	std::generate(vect.begin(), vect.end(), []() {return rand() % 100; });
	std::sort(vect.begin(), vect.end());

	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	insert_sorted<std::vector<int>, int>(vect, 5);
	insert_sorted<std::vector<int>, int>(vect, 35);
	insert_sorted<std::vector<int>, int>(vect, 99);

	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;
}

