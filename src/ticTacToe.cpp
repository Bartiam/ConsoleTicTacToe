#include <iostream>

void draw(char tic_tac_toe[][3])
{
	system("cls");
	std::cout << "\n\n\n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\t";
		for (int j = 0; j < 3; ++j)
		{
			std::cout << tic_tac_toe[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
}

bool correct_input_data(char input_X_or_Y, int x, int y)
{
	if (x < 0 || x > 3 || y < 0 || y > 3) return false;

	if (input_X_or_Y == 'X' || input_X_or_Y == 'x' ||
		input_X_or_Y == 'Y' || input_X_or_Y == 'y') return true;
	else return false;
}

int main()
{
	char input_X_or_Y = ' ';
	bool gamer_X = false, gamer_Y = false;
	int coorX, coorY;
	const int ROW = 3, COL = 3;
	char tic_tac_toe[ROW][COL]{ '_', '_', '_', 
								'_', '_', '_', 
								'_', '_', '_', };

	while (true)
	{
		std::cout << "Enter to coordinates: ";
		std::cin >> coorX >> coorY;
		
		std::cout << "Enter to element(x or y): ";
		std::cin >> input_X_or_Y;

		if (!correct_input_data(input_X_or_Y, coorX, coorY))
			std::cout << "Error! You can enter only coordinates: 0 - 3. Element: x or y(X or Y). \nTry again! " << std::endl;
		else 
		{
			draw(tic_tac_toe);
		}
	}

	return 0;
}
