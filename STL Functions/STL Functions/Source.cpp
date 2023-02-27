#include<iostream>
#include <type_traits> //// for add_const
//#include <bits/stdc++.h> ////for binary_search
#include<algorithm> //// for partition algorithm
#include<vector>
//using namespace std;

#define PI 3.14159265

int main() {

	//.............................std functions starting alphabetically..............................//

	//1.
	std::cout << "1. std::abort\n";

	//std::abort();

	//2.
	std::cout << "2. std::abs\n";

	std::cout << "abs(-4.88): " << std::abs(-4.88);

	//3.
	std::cout << "\n3. std::acos\n";
	std::cout << "acos(0.5): " << std::acos(0.5) * 180 / PI;

	//4.
	std::cout << "\n4. std::acosf\n";
	std::cout << "acosf(0.5) " << std::acosf(0.5) * 180 / PI;

	//5.
	std::cout << "\n5. std::acosh\n";
	std::cout << "acosh(45) : " << std::acosh(45) * 180 / PI;

	//6.
	std::cout << "\n6. std::acoshf\n";

	std::cout << "acoshf(0.5) : " << std::acoshf(0.5) * 180 / PI;

	//7.
	std::cout << "\n7. std::addressof\n";
	int* a;
	std::cout << "addressof: " << std::addressof(a);

	//8.     add_const
	std::cout << "\n8. std::add_const\n";

	std::add_const<double>::type* p = (const double*)0;

	p = p;  // to quiet "unused" warning
	std::cout << "add_const<double> == "
		<< typeid(*p).name() << std::endl;

	//9.
	std::cout << "\n9. std::advance\n";

	//std::cout << std::advance(InputIterator & it, Distance n);

	//10.
	std::cout << "\n10. std::align\n";
	// 
	//std::align(),

	//11.binary_search
	std::cout << "\n11. std::binary_search\n";

	std::vector<int> arr = { 10, 15, 20, 25, 30, 35 };

	//using binary_search to check if 15 exists

	if (binary_search(arr.begin(), arr.end(), 15))
		std::cout << "\n\t15 exists in vector";
	else
		std::cout << "\n\t15 does not exist";

	std::cout << std::endl;

	//12. lower_bound
	std::cout << "\n12.std::lower_bound\n";

	std::vector<int> arr1 = { 10, 15, 20, 25, 30, 35 };

	std::cout << "The position of 20 using lower_bound "
		" (in single occurrence case) : ";
	std::cout << std::lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();

	//13. upper_bound
	std::cout << "\n\n13. std::upper_bound\n";

	std::cout << "The position of 20 using upper_bound "
		" (in single occurrence case) : ";
	std::cout << std::upper_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();


	//14. partition


	//15. is_partitioned
	std::cout << "\n\n14 & 15. std::partition & std::is_partitioned\n";


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


			//16. Stable_partition:  preserve order of partitions 
			std::cout << "\n\n16.std::stable_partition";

			std::vector<int> vect1 = { 2, 1, 5, 6, 8, 7 };
			stable_partition(vect1.begin(), vect1.end(), [](int x)
				{
					return x % 2 == 0;
				});

			// Displaying partitioned Vector
			std::cout << "\nThe partitioned vector is : ";
			for (int& x : vect1) std::cout << x << " ";
			std::cout << std::endl;

			//17. partion_point
			std::cout << "\n\n17. std::partition_point";

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


			////18.  sort() : sort array or vector in ascending order
			//       sort(pointerToArray,positionUptoWhichIsToBeSorted)

			std::cout << "\n\n18. std::sort(arr,position)";


			int arr5[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
			int n = sizeof(arr5) / sizeof(arr5[0]);

			/*Here we take two parameters, the beginning of the
			array and the length n upto which we want the array to
			be sorted*/
			std::sort(arr5, arr5 + n);

			std::cout << "\nArray after sorting using "
				"default sort is : \n";
			for (int i = 0; i < n; ++i)
				std::cout << arr5[i] << " ";

			std::cout << "\n.........How to sort array in descending order?........\n";
			std::cout << "\n\n19. std::greater<int>()  & std::sort(arr,position,greater<int>() )";

			int arr6[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
			int n1 = sizeof(arr6) / sizeof(arr6[0]);

			std::sort(arr6, arr6 + n1, std::greater<int>());

			std::cout << "Array after sorting : \n";
			for (int i = 0; i < n1; ++i)
				std::cout << arr6[i] << " ";
			
			std::cout << "\n\n........Sort the array only in the given range.....\n";
			std::cout << "std::sort(arr + 2, arr + n)";

			int arr7[] = { 0, 1, 5, 8, 9, 6, 7, 3, 4, 2 };
			int n2 = sizeof(arr7) / sizeof(arr7[0]);

			// Sort the elements which lies in the range of 2 to
			// (n-1)
			std::sort(arr7 + 2, arr7 + 6);

			std::cout << "\nArray after sorting : \n";
			for (int i = 0; i < n2; ++i)
				std::cout << arr7[i] << " ";


			std::cout << "\n\n";
			return 0;
}