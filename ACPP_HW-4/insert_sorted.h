#pragma once

template <class Container, class T>
void insert_sorted(Container& vect, T num)
{
	auto it = find_if(vect.begin(), vect.end(), [num](T i) {return num < i; });
	if (it != vect.end())
		vect.insert(it, num);
	else
		vect.push_back(num);
}