/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>
#include <iostream>

string calcSum(int* sequence, int size)
{
	int sum, min_sum;
	string pair, result;

	for (int i = 0; i < size; i++)
    {
	    min_sum = INT_MAX;

	    for (int j = 0; j < size - i; j++)
        {
	        sum = 0;

	        for (int k = j; k < j + i + 1; k++)
	            sum += sequence[k];

	        if (sum < min_sum)
            {
	            pair = to_string(sum) + "," + to_string(j) + ";";
	            min_sum = sum;
            }
        }
	    result += pair;
    }
	return result;
}
