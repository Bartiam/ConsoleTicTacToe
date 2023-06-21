#include <iostream>

void draw(char tic_tac_toe[][3])
{
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

int who_did_win_in_diagonal(char tic_tac_toe[][3])
{
	int winnerIs = 0;

	if ((tic_tac_toe[0][0] == 'X' || tic_tac_toe[0][0] == 'x') &&
		(tic_tac_toe[0][0] == tic_tac_toe[1][1] && tic_tac_toe[0][0] == tic_tac_toe[2][2]))
		winnerIs = 1;
	else if ((tic_tac_toe[0][2] == 'X' || tic_tac_toe[0][2] == 'x') &&
		(tic_tac_toe[0][2] == tic_tac_toe[1][1] && tic_tac_toe[0][2] == tic_tac_toe[2][0]))
		winnerIs = 1;

	if ((tic_tac_toe[0][0] == 'O' || tic_tac_toe[0][0] == 'o') &&
		(tic_tac_toe[0][0] == tic_tac_toe[1][1] && tic_tac_toe[0][0] == tic_tac_toe[2][2]))
		winnerIs = 2;
	else if ((tic_tac_toe[0][2] == 'O' || tic_tac_toe[0][2] == 'o') &&
		(tic_tac_toe[0][2] == tic_tac_toe[1][1] && tic_tac_toe[0][2] == tic_tac_toe[2][0]))
		winnerIs = 2;

	return winnerIs;
}

int who_did_win_in_col(char tic_tac_toe[][3])
{
	int x = 0, y = 0, winnerIs = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (tic_tac_toe[j][i] == 'X' || tic_tac_toe[j][i] == 'x') ++x;
			if (tic_tac_toe[j][i] == 'O' || tic_tac_toe[j][i] == 'o') ++y;
		}
		if (x == 3) winnerIs = 1;
		else if (y == 3) winnerIs = 2;
		x = y = 0;
	}

	return winnerIs;
}

int who_did_win(char tic_tac_toe[][3])
{
	int x = 0, y = 0, winnerIs = 0, countXAndY = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (tic_tac_toe[i][j] == 'X' || tic_tac_toe[i][j] == 'x')
			{
				++countXAndY;
				++x;
			}
			if (tic_tac_toe[i][j] == 'O' || tic_tac_toe[i][j] == 'o') 
			{
				++countXAndY;
				++y;
			}
		}
		if (x == 3) winnerIs = 1;
		else if (y == 3) winnerIs = 2;
		else if (countXAndY == 9) winnerIs = 3;
		x = y = 0;
	}
	
	if (winnerIs == 0) winnerIs = who_did_win_in_col(tic_tac_toe);

	if (winnerIs == 0) winnerIs = who_did_win_in_diagonal(tic_tac_toe);

	return winnerIs;
}

bool logic(char tic_tac_toe[][3], int coorX, int coorY, char input_X_or_Y)
{
	int x = 0, y = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (tic_tac_toe[i][j] == 'X' || tic_tac_toe[i][j] == 'x') ++x;
			if (tic_tac_toe[i][j] == 'O' || tic_tac_toe[i][j] == 'o') ++y;
		}
	}

	if (x > y && (input_X_or_Y == 'X' || input_X_or_Y == 'x')) return false;
	else if ((input_X_or_Y == 'X' || input_X_or_Y == 'O' || input_X_or_Y == 'x' || input_X_or_Y == 'o')
		&& tic_tac_toe[coorX - '0'][coorY - '0'] != '_') return false;
	else if (x == y && (input_X_or_Y == 'O' || input_X_or_Y == 'o')) return false;

	return true;
}

bool correct_input_data(char input_X_or_Y, char coorX, char coorY)
{
	if (coorX - '0' < 0 || coorX - '0' > 2 || coorY - '0' < 0 || coorY - '0' > 2) return false;

	if (input_X_or_Y == 'X' || input_X_or_Y == 'x' ||
		input_X_or_Y == 'O' || input_X_or_Y == 'o') return true;

	return false;
}

int main()
{
	char input_X_or_O = ' ';
	bool gamer_X = false, gamer_Y = false, nobody = false;
	char coorX, coorY;
	const int ROW = 3, COL = 3;
	char tic_tac_toe[ROW][COL]{ '_', '_', '_', 
								'_', '_', '_', 
								'_', '_', '_', };

	while (!gamer_X && !gamer_Y && !nobody)
	{
		std::cout << "Enter to coordinates: ";
		std::cin >> coorX >> coorY;
		
		std::cout << "Enter to element(x or o): ";
		std::cin >> input_X_or_O;

		if (!correct_input_data(input_X_or_O, coorX, coorY))
			std::cout << "Error! You can enter only coordinates: 0 - 3. Element: x or y(x or o). \nTry again! " << std::endl;
		else if (!logic(tic_tac_toe, coorX, coorY, input_X_or_O))
		{
			std::cout << "You cannot enter these coordinates, because this field is already full. " << 
				"Or is it another player's turn. Try again!" << std::endl;
		}
		else
		{
			tic_tac_toe[coorX - '0'][coorY - '0'] = input_X_or_O;
			int winner = who_did_win(tic_tac_toe);
			draw(tic_tac_toe);
			switch (winner)
			{
			case 1:
				gamer_X = true;
				std::cout << "Winner is GAMER X!!! " << std::endl;
				break;
			case 2:
				gamer_Y = true;
				std::cout << "Winner is GAMER O!!! " << std::endl;
				break;
			case 3:
				nobody = true;
				std::cout << "There is no winner. " << std::endl;
				break;
			}
		}
	}

	return 0;
}
