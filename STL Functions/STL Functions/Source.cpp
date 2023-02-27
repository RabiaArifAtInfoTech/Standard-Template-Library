#include<iostream>
#include <type_traits> //// for add_const
//#include <bits/stdc++.h> ////for binary_search
#include<algorithm> //// for partition algorithm
#include<vector>
#include<string>
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

			//// 20. std::stable_sort(arr,position): 
			std::cout << "\n\n20. std::stable_sort(arr,position): preserves physical order of semantically equivalent values\n";
			
			//// 21. std::partial_sort(begin,middle,end): 

			std::cout << "\n21. std::partial_sort\n";
				// which is used for sorting not the entire range, but only a sub - part of it.\n";
			//std::cout << "\n void partial_sort (RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last); \n";

			std::vector<int> v5 = { 1, 3, 1, 10, 3, 4, 7, 7, 8 }, i2;

			std::vector<int>::iterator ip;

			// Using std::partial_sort
			std::partial_sort(v5.begin(), v5.begin() + 5, v5.end());

			// Displaying the vector after applying
			// std::partial_sort
			for (ip = v5.begin(); ip != v5.end(); ++ip) {
				std::cout << *ip << " ";
			}

			////22. rotate(begin,middle,end)
			std::cout << "\n\n22. std::rotate\n";

			std::vector<int> arrV;

			// set some values: 1 2 3 4 5 6
			// 7 8 9
			for (int i = 1; i < 10; ++i)
				arrV.push_back(i);

			// Use of rotate
			rotate(arrV.begin(), arrV.begin() + 4, arrV.end());

			// prints the content:
			std::cout << "arr contains:";
			for (auto i = arrV.begin(); i != arrV.end(); i++)
				std::cout << ' ' << *i;
			
			////23. rotate_copy(begin,middle,end)
			std::cout << "\n\n23. std::rotate_copy\n";

			int arrR[] = { 10, 20, 30, 40, 50, 60, 70 };
			int nR = sizeof(arrR) / sizeof(arrR[0]);

			// Use of rotate_copy
			std::vector<int> gfg(7);
			std::rotate_copy(arrR, arrR + 4, arrR + nR, gfg.begin());


			// prints the content:
			std::cout << "gfg contains:";
			for (auto i = gfg.begin(); i != gfg.end(); i++)
				std::cout << ' ' << *i;

			std::cout << "\narrR contains:";
			for (int i=0; i < nR ; i++)
				std::cout << ' ' << arrR[i];

			////24. Accumulate : adds all elements
			std::cout << "\n\n24. std::Accumulate\n";

			//std::vector<int> vecAc{ 1,2,3,4,5,6,7,8,9 };

			//// Taking initial sum as 0
			//int sum = 0;
			//std::cout << "\n Initial value of sum = " << sum << std::endl;

			//// Demonstration of accumulate function
			//// to sum all the elements of the vector
			//sum = std::accumulate(vecAc.begin(), vecAc.end(), sum);

			//std::cout << " Value of sum after accumulate = " << sum << std::endl;

			////25. rotate_copy(begin,middle,end)
			std::cout << "\n25. std::equal\n";

			std::vector<int> arr11{ 3, 2, 1, 4, 5, 6, 7 };

			std::vector<int> arr22{ 3, 2, 1, 4, 5 };

			bool equal = std::equal(arr11.begin(), arr11.begin() +  4, arr22.begin());
			if (equal)
			{
				std::cout << "both ranges are exactly equal \n";
			}
			else
			{
				std::cout << "both ranges are not exactly equal \n";
			}



			////26. includes(first1, end1, first2, end2)
			std::cout << "\n26. includes(first1, end1, first2, end2)\n";


			std::vector<int> arr111{ 3, 5, 7, 9 };
			std::vector<int> arr222{ 5, 9 };

			if (std::includes(arr111.begin(), arr111.end(), arr222.begin(), arr222.end()))
				std::cout << "arr111 contains arr2\n";
			else
				std::cout << "arr111 doesn't contain arr222\n";

			
			////27. find(arr.begin(), arr.end(), searching_element);
			std::cout << "\n27. find(arr.begin(), arr.end(), searching_element)\n";


			std::vector<int> arrF{ 1, 2, 3, 8, 4, 3 };

			int searching_element = 8;
			std::vector<int>::iterator itF;
			//starting iterator of range= arr.begin()
			//end iterator of range =arr.end()

			itF = find(arrF.begin(), arrF.end(), searching_element);
			if (itF != arrF.end())
				std::cout << searching_element << " is at position: " << itF - arrF.begin() << std::endl;
			else
				std::cout << searching_element << "not found";


			////28. find(arr.begin(), arr.end(), searching_element);
			std::cout << "\n27. find_first_of()\n";


			std::string str = "#includehelp";

			std::string re = "fssaad";
			//its searching in the string str
			//it searches any character from the string re
			//now if any character of re is found then it simply 
			//returns the position of the character found

			std::cout << "the first vowel appearing in the string: " << str << " is at " << str.find_first_of(re) << std::endl;

			//now this will start searching in str from position=1
			//thus it skips the fisrt vowel 'i'
			std::cout << "the second vowel appearing in the string: " << str << " is " << str[str.find_first_of(re, 1)] << std::endl;

			////29. next_permutation(nums.begin(), nums.end())
			std::cout << "\n29. next_permutation(nums.begin(), nums.end())\n";


			std::cout << "\nEnter number of elements in the permutation: ";
			int input;
			std::cin >> input;

			//first permutation is 1,2,3,4...,n
			std::vector<int> nums(input);
			for (int i = 0; i < input; i++)
				nums[i] = i + 1;

			int count1 = 1;

			//the while loop will break when no more 
			//next Permutation is possible
			//as the function next_permutation will 
			//return false then
			do {
				std::cout << "Permutation " << count1++ << std::endl;
				for (auto it : nums)
					std::cout << it << " ";
				std::cout << std::endl;
			} //in places converts to next permutation if there exists the next permutation
			while (next_permutation(nums.begin(), nums.end()));








			std::cout << "\n\n";
			return 0;
}