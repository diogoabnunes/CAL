/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
}

/**
 * Inicia um Sudoku com um conte�do inicial.
 * Lan�a excep��o IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem n�meros repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}
	this->countFilled = 0;
}

/**
 * Obtem o conte�do actual (s� para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku j� est� completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
}



/**
 * Resolve o Sudoku.
 * Retorna indica��o de sucesso ou insucesso (sudoku imposs�vel).
 */
bool Sudoku::solve()
{
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {

            if (numbers[y][x] == 0) { // por preencher

                for (int k = 1; k < 10; k++) {
                    if (lineHasNumber[y][k] || columnHasNumber[x][k] || block3x3HasNumber[y/3][x/3][k])
                        continue; // j� existe este n�mero na linha, coluna ou bloco, por isso este n�o serve

                    numbers[y][x] = k;
                    lineHasNumber[y][k] = true;
                    columnHasNumber[x][k] = true;
                    block3x3HasNumber[y/3][x/3][k] = true;
                    countFilled++;

                    if (solve()) break; // continuar um processo e ver se � poss�vel completar o sudoku

                    numbers[y][x] = 0;
                    lineHasNumber[y][k] = false;
                    columnHasNumber[x][k] = false;
                    block3x3HasNumber[y/3][x/3][k] = false;
                    countFilled--;
                }
                if (numbers[y][x] == 0)
                    return false; // imposs�vel
            }
        }
    }
    return isComplete();
}



/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}
