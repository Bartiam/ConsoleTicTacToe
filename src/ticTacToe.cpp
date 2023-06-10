#include <iostream>

int main()
{
	char input_X_or_Y = ' ';
	bool gamer_X = false, gamer_Y = true;
	int x, y;
	const int ROW = 3, COL = 3;
	char tic_tac_toe[ROW][COL]{ ' ', ' ', ' ', 
								' ', ' ', ' ', 
								' ', ' ', ' ', };

	while (true)
	{
		std::cout << "Enter to coordinates: ";
		std::cin >> x >> y;
		
		std::cout << "Enter to element(x or y): ";
		std::cin >> input_X_or_Y;

		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (i == x && j == y) tic_tac_toe[i][j] = input_X_or_Y;
			}
		}
	}

	return 0;
}
