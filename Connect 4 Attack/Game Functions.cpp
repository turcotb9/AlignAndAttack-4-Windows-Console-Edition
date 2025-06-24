#include <iostream>
#include <vector>
//Function that shows game board
void showGameBoard(std::vector<std::vector<char>>& board) {
	//std::vector<std::vector<char>> board(6, std::vector<char>(7, ' '));
	int rowNum{ 0 };
	std::cout << "   0 1 2 3 4 5 6 \n";
	std::cout << "  _______________\n";
	for (const auto& row : board) {
		std::cout << rowNum++ << " |";
		for (const auto& column : row) {
			std::cout << column << '|';
		}
		std::cout << std::endl;

	}
	std::cout << "  ===============\n" << std::endl;
}

bool horizontalCheck(std::vector<std::vector<char>>& board, char pieceIcon) {
	int counter = 0;
	for (int row = 5; row >= 0; row--) {
		for (int col = 6; col >= 0; col--) {
			if (board[row][col] == pieceIcon) {
				counter++;
			}
			else {
				//Resets counter if it doesn't continue to increase
				counter = 0;
			}
			if (counter >= 4) {
				return true;
			}
		}
		
	}
	return false;
}

bool verticalCheck(std::vector<std::vector<char>>& board, char pieceIcon) {
	int counter = 0;
	for (int col = 6; col >= 0; col--) {
		for (int row = 5; row >= 0; row--) {
			if (board[row][col] == pieceIcon) {
				counter++;
			} 
			else {
				//Resets counter if it doesn't continue to increase
				counter = 0;
			}
			if (counter >= 4) {
				return true;
			}
		}
	}
	return false;
}

//down right diagonal check (up left check)
bool rightDiagonalCheck(std::vector<std::vector<char>>& board, char pieceIcon) {
	int counter = 0;
	for (int row = 2; row >= 0; row--) {
		for (int col = 3; col >= 0; col--) {
			//Reset for each diagonal
			counter = 0;
			for (int i = 3; i >= 0; i--) {
				if (board[(row + i)][(col + i)] == pieceIcon) {
					counter++;
				}
				else {
					//Resets counter if it doesn't continue to increase
					counter = 0;
				}
				if (counter >= 4) {
					return true;
				}
			}
			
		}

	}
	return false;
}
//Down left diagonal check (up right check)
bool leftDiagonalCheck(std::vector<std::vector<char>>& board, char pieceIcon) {
	int counter = 0;
	for (int row = 5; row >= 3; row--) {
		for (int col = 0; col <= 3; col++) {
			//Reset for each diagonal
			counter = 0;
			for (int i = 3; i >= 0; i--) {
				if (board[(row - i)][(col + i)] == pieceIcon) {
					counter++;
				}
				else {
					//Resets counter if it doesn't continue to increase
					counter = 0;
				}
				if (counter >= 4) {
					return true;
				}
			}

		}

	}
	return false;
}




bool checkForWinner(std::vector<std::vector<char>>& board, char pieceIcon) {
	if (horizontalCheck(board, pieceIcon) || verticalCheck(board, pieceIcon) || rightDiagonalCheck(board, pieceIcon) || leftDiagonalCheck(board, pieceIcon)) {
		return true;
	}
	return false;
}

//Function that drops piece on board
void dropPiece(int colNum, std::vector<std::vector<char>>& board, char pieceIcon) {

	for (int i = 5; i >= 0; i--) {
		if (board[i][colNum] == ' ') {
			board[i][colNum] = pieceIcon;
			break;
		}
	}
}

//Function that runs dropFunction and checks for valid inputs. 
void dropFunction(std::vector<std::vector<char>>& board, char pieceIcon) {
	bool _check{ false };
	int colNum{ 0 };
	while (_check != true) {
		std::cout << "Enter which column to drop piece: ";
		std::cin >> colNum;
		if (colNum >= 0 && colNum <= 6) {
			dropPiece(colNum, board, pieceIcon);
			_check = true;
		}
		else {
			std::cout << "Invaild column number, please enter listed column number on board.\n";
			_check = false;
		}
	}
	
}

//Function that allows the player to attack other pieces
void attackPiece(int rowNum, int colNum, std::vector<std::vector<char>>& board, char pieceIcon, char attackDirection) {
	bool attackRight = false;
	bool attackLeft = false;
	if (board[(rowNum - 1)][(colNum + 1)] == pieceIcon && board[(rowNum - 2)][(colNum + 2)] == ' ') {
		attackRight = true;
	}
	if (board[(rowNum - 1)][(colNum - 1)] == pieceIcon && board[(rowNum - 2)][(colNum - 2)] == ' ') {
		attackLeft = true;
	}

}

//Function that runs attackPiece and checks to make sure it runs. 
void attackFunction(std::vector<std::vector<char>>& board, char pieceIcon) {
	bool _check{ false };

}
