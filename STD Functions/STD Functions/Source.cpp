#include<iostream>
#include <type_traits> //// for add_const
//#include <bits/stdc++.h> ////for binary_search
#include<algorithm> //// for partition algorithm
#include<vector>
using namespace std;

#define PI 3.14159265

int main() {

	//.................std functions starting alphabetically..................

	//1.
	 
	//std::abort();

	//2.
	std::cout << "abs(-4.88): " << std::abs(-4.88);

	//3.
	std::cout << "\nacos(0.5): " << std::acos(0.5) *180 / PI;
	
	//4.
	std::cout << "\nacosf(0.5) " << std::acosf(0.5) *180 / PI;

	//5.
	std::cout << "\nacosh(45) : " << std::acosh(45) * 180 / PI;

	//6.
	std::cout << "\nacosf(0.5) : " << std::acosf(0.5) * 180 / PI;

	//7.
	std::cout << "\nacoshf(0.5) : " << std::acoshf(0.5) * 180 / PI;
	
	//8.
	int *a;
	std::cout << "\naddressof: " << std::addressof(a);

	//9.     add_const

	std::add_const<double>::type* p = (const double*)0;

	p = p;  // to quiet "unused" warning
	std::cout << "\nadd_const<double> == "
		<< typeid(*p).name() << std::endl;

	//10.
	//std::cout << std::advance(InputIterator & it, Distance n);

	//11.
	//std::align(),

	//12.binary_search

	std::vector<int> arr = { 10, 15, 20, 25, 30, 35 };

	 //using binary_search to check if 15 exists
	
	if (binary_search(arr.begin(), arr.end(), 15))
		std::cout << "\n15 exists in vector";
	else
		std::cout << "\n15 does not exist";

	std::cout << std::endl;

	//13. lower_bound
	std::vector<int> arr1 = { 10, 15, 20, 25, 30, 35 };

	std::cout << "\nThe position of 20 using lower_bound "
		" (in single occurrence case) : ";
	std::cout << std::lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();
	
	//14. upper_bound
	std::cout << "\nThe position of 20 using upper_bound "
		" (in single occurrence case) : ";
	std::cout << std::upper_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();

		
	//15. partition

		
	//16. is_partitioned

		
	std::vector<int> vect = { 2, 1, 5, 6, 8, 7 };

	// Checking if vector is partitioned
	// using is_partitioned()
		
	is_partitioned(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	}) ?

	std::cout << "\nVector is partitioned" :
		std::cout << "\nVector is not partitioned";
	std::cout << std::endl;

		// partitioning vector using partition()
	partition(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	});

		// Checking if vector is partitioned
		// using is_partitioned()
	is_partitioned(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	}) ?

	std::cout << "\nNow, vector is partitioned after partition operation" :
		std::cout << "\nVector is still not partitioned after partition operation";
	std::cout << std::endl;

	// Displaying partitioned Vector
	std::cout << "\nThe partitioned vector is : ";
	for (int& x : vect) std::cout << x << " ";

	
	 //17. Stable_partition:  preserve order of partitions 
	std::vector<int> vect1 = { 2, 1, 5, 6, 8, 7 };
	stable_partition(vect1.begin(), vect1.end(), [](int x)
	{
		return x % 2 == 0;
	});

	// Displaying partitioned Vector
	std::cout << "\nThe partitioned vector is : ";
	for (int& x : vect1) std::cout << x << " ";
	std::cout << std::endl;

	//18. partion_point
	std::vector<int> vect3 = { 2, 1, 5, 6, 8, 7,3,4,7 };

	std::vector<int>::iterator it1;

	//// using partition_point() to get ending position of partition
	auto it = partition_point(vect3.begin(), vect3.end(), [](int x)
	{
		return x % 2 == 0;
	});

	//// Displaying partitioned Vector
	std::cout << "\nThe vector elements returning true for condition are (without using \"partition\" or \"stable_partition\" ): \n";
	for (it1 = vect3.begin(); it1 != it; it1++)
		std::cout << *it1 << " ";

	////.......see difference btw these two sorts...........
	std::cout << "\n\n.......see difference btw these two sorts...........\n ";

	std::vector<int> vect4 = { 2, 1, 5, 6, 8, 7,3,4,7 };
	partition(vect4.begin(), vect4.end(), [](int x)
	{
		return x % 2 == 0;
	});

	 ////Displaying partitioned Vector
	std::cout << "\nThe partitioned vector is : ";
	for (int& x : vect4) std::cout << x << " ";
	std::cout << std::endl;

	std::vector<int>::iterator it2;

	 ////using partition_point() to get ending position of partition
	auto itr = partition_point(vect4.begin(), vect4.end(), [](int x)
		{
			return x % 2 == 0;
		});

	 ////Displaying partitioned Vector
	std::cout << "\nThe vector elements returning true for condition are (after partition): ";
	for (it2 = vect4.begin(); it2 != itr; it2++)
		std::cout << *it2 << " ";

	



	std::cout << "\n\n";
	return 0;
}