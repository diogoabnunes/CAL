/*
 * Change.cpp
 */

#include "Change.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// coinValues[] = {1, 2, 5}
// exite um stock ilimitado de moedas de cada valor

string calcChange(int m, int numCoins, int *coinValues)
{
    if (m == 0)
        return "";

    vector<string> c(m + 1, "-");
    int aux;

    for (int i = 1; i <= m; i++) { // Iterate over quantity
        for (int j = numCoins - 1; j >= 0; j--) { //Iterate over coins (starting with the one with highest value)
            aux = i - coinValues[j];

            if (aux >= 0) {
                string value = to_string(coinValues[j]) + ";";

                if (aux != 0)
                    value += c[aux];

                if (value.length() < c[i].length() || c[i] == "-")
                    c[i] = value;
            }
        }
    }

    return c.back();
}
