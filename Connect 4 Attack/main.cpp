#include <iostream>
#include <vector>

//Function Declaration 
void showGameBoard(std::vector<std::vector<char>>& board);
void dropFunction(std::vector<std::vector<char>>& board, char pieceIcon);
void attackPiece(int rowNum, int colNum, std::vector<std::vector<char>>& board, char pieceIcon);
bool checkForWinner(std::vector<std::vector<char>>& board, char pieceIcon);

//Player Icon Constants
const char PLAYER_ONE_ICON = 'X';
const char PLAYER_TWO_ICON = 'O';


int main() {

	//Title
	std::cout << "-------------------------------\n";
	std::cout << "Align & Attack 4 (Console Ver.)\n";
	std::cout << "-------------------------------\n";

	//Author and Version Number
	std::cout << "Made by Ben Turcotte\n";
	std::cout << "\nVersion 0.04225 (IDK), 4/2/2025\n";
	std::cout << "Added:\n";
	std::cout << "-Fully finished win conition function\n";
	std::cout << "-Added ability to replay game without have to close console\n";
	std::cout << "-Added rules and title page\n";
	std::cout << "Planned updates:\n";
	std::cout << "-Need to add attack function\n" << std::endl;

	//Rules 
	std::cout << "---------------\n";
	std::cout << "   The Rules   \n";
	std::cout << "---------------\n";
	std::cout << "1. To win players must get their pieces to align up 4 in row, column, or diagonal.\n";
	std::cout << "2. Player 1 Always goes first.\n";
	std::cout << "3. After 8 turns, the players can begining attacking the other players pieces\n";
	std::cout << "4. Players can only attack a piece if it is up and to the right or left of a piece and have an open slot behind piece being attacked.\n";
	std::cout << "5. Gravity is real, pieces that attack will drop down if nothing supports them.\n";
	std::cout << "6. If both players have 4 in a row after an attack, the player that attacked wins.\n";
	std::cout << "---------------\n" << std::endl;
	//Start Selection 
	char replayAnswer = 'N';
	bool replayCondition{ true };
	std::cout << "Would you like to play? (Y/N): ";
	std::cin >> replayAnswer;
	if (replayAnswer == 'N') {
		replayCondition = false;
		std::cout << "\nHave a good day!\n";
	}
	else {
		replayCondition = true;
		std::cout << "\n---------------\n";
	}

	//Overall Game loop
	while (replayCondition == true) {

		//board declaration
		std::vector<std::vector<char>> board(6, std::vector<char>(7, ' '));
		//Player Icon and Name declaration (Player 1 will always go first in this version)
		char activePiece = PLAYER_ONE_ICON;
		std::string player1Name{ " " };
		std::string player2Name{ " " };
		//Player name input
		std::cout << "Enter player 1 name (they will go first): ";
		std::cin >> player1Name;
		std::cout << "Enter player 2 name (they will go second): ";
		std::cin >> player2Name;
		std::cout << "----------------------------\n";

		//Game variable declarations
		std::string activePlayer = player1Name;
		int turnCounter{ 1 };
		bool winCondition{ false };
		char moveChoice{ 'D' };

		//Current Game Loop
		while (winCondition != true) {
			showGameBoard(board);

			// TODO: Change this into a function once attack function is made. 
			std::cout << "Turn " << turnCounter << " | " << activePlayer << "'s move\n";
			/*
			if (turnCounter >= 8) {
				std::cout << "Would you like to Attack (A) or Drop (D) a piece?: ";
				std::cin >> moveChoice;
			}
			*/
			if (moveChoice == 'D') {
				dropFunction(board, activePiece);
			}
			else if (moveChoice == 'A') {
				//attackFunction()
			}
			else {
				//Invaild Option.
			}
			std::cout << "----------------------------\n";

			//Check for winner.
			winCondition = checkForWinner(board, activePiece);

			//If no winner, switch who is active player and keep playing.
			if (winCondition != true) {
				//Switich Active Player and Piece Icon
				if (activePiece == PLAYER_ONE_ICON) {
					activePiece = PLAYER_TWO_ICON;
					activePlayer = player2Name;
				}
				else {
					activePiece = PLAYER_ONE_ICON;
					activePlayer = player1Name;
				}
				//Turn Counter Increase
				turnCounter += 1;
			}
			// If winner, show board and say who wins with current turn.
			else {
				showGameBoard(board);
				std::cout << activePlayer << " Wins! (Turn: " << turnCounter << ")\n";
			}
		}
		//Replay Selection
		std::cout << "\nWould you like to play again? (Y/N): ";
		std::cin >> replayAnswer;
		if (replayAnswer == 'N') {
			replayCondition = false;
			std::cout << "\nHave a good day!\n";
		} else {
			replayCondition = true;
			std::cout << std::endl;
		}
	}
    return 0;
}