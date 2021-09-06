#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include "insert_sorted.h"

int main()
{
	std::vector<int> vect(25);
	std::generate(vect.begin(), vect.end(), []() {return rand() % 100; });
	std::sort(vect.begin(), vect.end());

	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	insert_sorted(vect, 5);
	insert_sorted(vect, 35);
	insert_sorted(vect, 99);

	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	std::vector<double> analog(100);
	std::generate(analog.begin(), analog.end(), [n = 0.0]() mutable {
		double sinus = std::sin(n);
		n+=0.1;
		return sinus*100;
		});
	std::cout << "Analog signal:" << std::endl;
	std::copy(analog.begin(), analog.end(), std::ostream_iterator<double>{std::cout, " "});
	std::cout << std::endl;

	std::vector<int> digital(100);
	std::transform(analog.begin(), analog.end(), digital.begin(), [](double i) {return (int)std::round(i); });
	std::cout << "Digital signal:" << std::endl;
	std::copy(digital.begin(), digital.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	std::cout << "Signal flaw: ";
	std::cout << std::inner_product(analog.begin(), analog.end(), digital.begin(), 0.0, [](double x, double y) {return x + y; }, [](double a, int b) {
		return std::pow((a - b), 2);
		});
	std::cout << std::endl;
}

