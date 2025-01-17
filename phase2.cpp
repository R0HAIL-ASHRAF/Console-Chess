/*
   Developer: Muhammad Rohail Ashraf(PSA)
   Highest Degree: BS Computer Science
   Additional Aid: 
   	1. Mastery of Essential C++ Programming (Udemy)
           https://udemy-certificate.s3.amazonaws.com/pdf/UC-60e524a4-06ab-435b-a132-98cf6309e768.pdf
	2. C++ Programming: Beginners to Advanced for Developers(Udemy)
 	   https://udemy-certificate.s3.amazonaws.com/pdf/UC-354e45f3-ef3a-4fed-9ad5-04eea8384c29.pdf
     	3. C++ training Crash Course For C++ Beginners(Udemy)
      	   https://udemy-certificate.s3.amazonaws.com/pdf/UC-91247734-71a2-4519-bd4f-ac5dd1b43d7f.pdf
	  
-------------------------------------------------------------------------------------------------------------------------
   Socials:
   https://www.linkedin.com/in/rohail-ashraf-1aa720280/(LinkedIn)
   https://www.udemy.com/user/rohail-ashraf-2/(Udemy)

   
*/
#include<iostream>
#include<fstream>
#include<Windows.h>

const int bcols = 11;
const int brows = 4;
const int cols = 8;
const int rows = 8;

using namespace std;

void print();
void initialize(char** &board);
void initializeMegaBoard(char**& board, char****& MegaBoard, bool turn);
void printBoard(char****& MegaBoard, char**& board, bool turn);
bool validSource(char** board, int s_x, int s_y, bool turn);
bool turnChange(bool turn);
bool validDestination(char** board, int d_x, int d_y, bool turn, int s_x, int s_y);
bool Rook(char** board, int s_x, int s_y, int d_x, int d_y);
bool bishop(char** board, int s_x, int s_y, int d_x, int d_y);
bool king(char** board, int s_x, int s_y, int d_x, int d_y);
void makeMove(char**& board, int s_x, int s_y, int d_x, int d_y, bool);
void deleteBoard(char** board);
void sourceInput(char** board, int& s_x, int& s_y, bool& turn, char ****&);
void DestinationInput(char** board, int& s_x, int& s_y, int& d_x, int& d_y, bool &turn, char ****&);
bool knight(char** board, int  s_x, int s_y, int d_x, int d_y, bool);
bool pawn(char** board, int  s_x, int s_y, int d_x, int d_y, bool turn);
bool validSourcepawn(char** board, int s_x, int s_y, bool turn);
bool choiceValidation(char choice, bool turn);
void changePawn(char** board, int s_x, int s_y, bool turn);
void delete3D(char**** MegaBoard);
void copyArray(char arr1[brows][bcols], char** arr2);
bool iseven(int n);
void intialize4D(char****& arr);
void deleteBoardBlock(char** board);
char** BlackPawnBlockWhite(char** block);
char** WhitePawnBlockBlack(char** block);
char** EmptySpaceWhite(char** block);
char** EmptySpaceBlack(char** block);
char** WhitePawnBlockWhite(char** block);
char** BlackPawnBlockBlack(char** block);
char** WhiteRookBlockWhite(char** block);
char** WhiteRookBlockBlack(char** block);
char** BlackRookBlockBlack(char** block);
char** BlackRookBlockWhite(char** block);
char** BlackKnightBlockBlack(char** block);
char** BlackKnightBlockWhite(char** block);
char** WhiteKnightBlockWhite(char** block);
char** WhiteKnightBlockBlack(char** block);
char** WhiteBishopBlockBlack(char** block);
char** BlackBishopBlockBlack(char** block);
char** BlackBishopBlockWhite(char** block);
char** WhiteBishopBlockWhite(char** block);
char** BlackQueenBlockBlack(char** block);
char** WhiteQueenBlockBlack(char** block);
char** WhiteQueenBlockWhite(char** block);
char** BlackQueenBlockWhite(char** block);
char** BlackKingBlockBlack(char** block);
char** WhiteKingBlockBlack(char** block);
char** WhiteKingBlockWhite(char** block);
char** BlackKingBlockWhite(char** block);
bool IsCheck(char** board, bool oppturn);
bool validDestinationKing(char** board, int d_x, int d_y, bool turn, int s_x, int s_y);
void onFile(char**& board);
void getRowColbyLeftClick(int& rpos, int& cpos);
bool inputbyclick(int& s_x, int& s_y, char**& board, char****& MegaBoard, bool& turn);
void gotoRowCol(int rpos, int cpos);
void restart(char**& board);
void printBoardRestart(char****& MegaBoard, char**& board, bool turn);
void SetTextColor(int color);
char pawnchoice(int x, int y, bool turn);
bool isCheckmate(char** board, bool turn);
bool FromP2(char** board, int s_x, int s_y);
bool FromP1(char** board, int s_x, int s_y);
void undo(char**& board);
void printBoardSource(char**** MegaBoard, char**& board, bool turn, int s_x, int s_y);
void undowrite(char**& board);
void printBoardundo(char****& MegaBoard, char**& board, bool turn);

int main()
{
	
	bool turn = 0;
	int source_X, source_Y, destination_X, destination_Y;
	
	while (true)
	{
		char** board = new char* [rows];
		char**** MegaBoard = new char*** [rows];
		initialize(board);
		initializeMegaBoard(board, MegaBoard, turn);
		printBoard(MegaBoard, board, turn);
		
		if (isCheckmate(board, turn))
		{
			gotoRowCol(19, 102);
			cout << "GAME OVER";
			gotoRowCol(20, 102);
			cout << "Player " <<turn + 1 << " WINS";
			gotoRowCol(34, 0);
			
		}
		if (inputbyclick(source_X, source_Y, board, MegaBoard, turn))
		{
			gotoRowCol(19, 102);
			cout << "GAME OVER!" << endl;
			gotoRowCol(34, 0);
			break;
		}
		gotoRowCol(19, 102);
		cout << "         ";
		gotoRowCol(20, 102);
		cout << "                ";
		gotoRowCol(34, 0);
		sourceInput(board, source_X, source_Y, turn, MegaBoard);
		DestinationInput(board, source_X, source_Y, destination_X, destination_Y, turn, MegaBoard);
		makeMove(board, source_X, source_Y, destination_X, destination_Y, turn);
		system("CLS");

		if (IsCheck(board, turn))
		{
			gotoRowCol(19, 102);
			cout << "CHECKMATE     ";
			gotoRowCol(20, 102);
			cout << "                  ";
			gotoRowCol(0, 0);

		}

		turn = turnChange(turn);
		onFile(board);
		deleteBoard(board);
		delete3D(MegaBoard);
		
	}
    
	return 0;
}

void initializeMegaBoard(char**& board, char****& MegaBoard, bool turn)
{
	
	intialize4D(MegaBoard);


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
		    if (board[i][j] == 'R' )
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackRookBlockWhite(MegaBoard[i][j]);
				}
				else 
				{
					MegaBoard[i][j] = BlackRookBlockBlack(MegaBoard[i][j]);
					
				}

			}
			else if (board[i][j] == 'r')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhiteRookBlockWhite(MegaBoard[i][j]);
				}
				else
				{
						MegaBoard[i][j] = WhiteRookBlockBlack(MegaBoard[i][j]);
				}


			}
			else if (board[i][j] == 'N')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackKnightBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = BlackKnightBlockBlack(MegaBoard[i][j]);

				}

			}
			else if (board[i][j] == 'n')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhiteKnightBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = WhiteKnightBlockBlack(MegaBoard[i][j]);
				}


			}
			else if (board[i][j] == 'B')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackBishopBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = BlackBishopBlockBlack(MegaBoard[i][j]);

				}

			}
			else if (board[i][j] == 'b')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhiteBishopBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = WhiteBishopBlockBlack(MegaBoard[i][j]);
				}


			}
			else if (board[i][j] == 'K')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackKingBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = BlackKingBlockBlack(MegaBoard[i][j]);

				}

			}
			else if (board[i][j] == 'k')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhiteKingBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = WhiteKingBlockBlack(MegaBoard[i][j]);
				}


			}
			else if (board[i][j] == 'Q')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackQueenBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = BlackQueenBlockBlack(MegaBoard[i][j]);

				}

			}
			else if (board[i][j] == 'q')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhiteQueenBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = WhiteQueenBlockBlack(MegaBoard[i][j]);
				}


			}
			else if (board[i][j] == 'P')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = BlackPawnBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = BlackPawnBlockBlack(MegaBoard[i][j]);

				}

			}
			else if (board[i][j] == 'p')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = WhitePawnBlockWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = WhitePawnBlockBlack(MegaBoard[i][j]);
				}


			}
			
			else if (board[i][j] == '_')
			{
				if (iseven(i + j))
				{
					MegaBoard[i][j] = EmptySpaceWhite(MegaBoard[i][j]);
				}
				else
				{
					MegaBoard[i][j] = EmptySpaceBlack(MegaBoard[i][j]);
				}


			}
			

		}
	}
}
void printBoard(char**** &MegaBoard, char ** & board, bool turn)
{
	
	SetTextColor(12);
	for (int w = 0; w < bcols*cols+2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(14);

	for (int z = 0; z < rows; z++)
	{ 
		for (int i = 0; i < brows; i++)
		{ 
			SetTextColor(12);

			cout << "|";
			SetTextColor(14);

			for (int j = 0; j < rows; j++)
			{  
				for (int w = 0; w < bcols; w++)
				{  
					if (MegaBoard[z][j][i][w] == '|')
					{
						SetTextColor(1);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if (MegaBoard[z][j][i][w] == '#')
					{
						SetTextColor(0);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if(MegaBoard[z][j][i][w] == '!')
					{
						SetTextColor(10);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else
						cout << MegaBoard[z][j][i][w];
				}

			}
			SetTextColor(12);
			cout <<"|" <<endl;
			SetTextColor(14);

		}
		
	}
	SetTextColor(12);

	for (int w = 0; w < bcols * cols+2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(11);
	

	print();
}
bool turnChange(bool turn)
{
	if (!turn)
		return 1;
	return 0;
}
bool validSource(char** board, int s_x, int s_y, bool turn)
{
	if ((s_x > -1 && s_x < rows) && (s_y > -1 && s_y < cols))
	{
		char whites[6] = { 'r','n','b','q','k','p' };
		char blacks[6] = { 'R','N','B','Q','K','P' };
		if (turn == 0)
		{
			for (int i = 0; i < 6; i++)
			{
				if (board[s_x][s_y] == *(whites + i))
					return 1;

			}
			return 0;
		}
		else if (turn == 1)
		{
			for (int i = 0; i < 6; i++)
			{
				if (board[s_x][s_y] == *(blacks + i))
					return 1;

			}
			return 0;
		}

	}
	return 0;


}
bool validDestination(char** board, int d_x, int d_y, bool turn, int s_x, int s_y)
{
	if ((d_x > -1 && d_x < rows) && (d_y > -1 && d_y < cols))
	{
		
			if (s_x == d_x && s_y == d_y)
				return 0;
			if (validSource(board, d_x, d_y, turn))
				return 0;
			if (board[s_x][s_y] == 'r' || board[s_x][s_y] == 'R')
			{
				if (Rook(board, s_x, s_y, d_x, d_y))
					return 1;

			}
			else if (board[s_x][s_y] == 'B' || board[s_x][s_y] == 'b')
			{
				if (bishop(board, s_x, s_y, d_x, d_y))
					return 1;
			}
			else if (board[s_x][s_y] == 'q' || board[s_x][s_y] == 'Q')
			{
				if (bishop(board, s_x, s_y, d_x, d_y) || Rook(board, s_x, s_y, d_x, d_y) )
					return 1;
			}
			else if (board[s_x][s_y] == 'k' || board[s_x][s_y] == 'K')
			{
				if (king(board, s_x, s_y, d_x, d_y))
					return 1;

			}
			else if (board[s_x][s_y] == 'n' || board[s_x][s_y] == 'N')
			{
				if (knight(board, s_x, s_y, d_x, d_y, turn))
					return 1;
			}
			else if (board[s_x][s_y] == 'P' || board[s_x][s_y] == 'p')
			{
				if (pawn(board, s_x, s_y, d_x, d_y, turn))
					return 1;
			}

		

	}
	return 0;

}
bool Rook(char** board, int s_x, int s_y, int d_x, int d_y)
{
	if (s_y == d_y)
	{
		if (s_x > d_x)
		{
			for (int i = s_x - 1; i > d_x; i--)
			{
				if (board[i][s_y] != '_')
					return false;
			}
		}
		else if (s_x < d_x)
		{
			for (int i = s_x + 1; i < d_x; i++)
			{
				if (board[i][s_y] != '_')
					return 0;
			}
		}
		return 1;
	}
	else if (s_x == d_x)
	{
		
		if (s_y > d_y)
		{
			for (int i = s_y - 1; i > d_y; i--)
			{
				if (board[s_x][i] != '_') 
					return 0;
			}
		}
		
		else if (s_y < d_y)
		{
			for (int i = s_y + 1; i < d_y; i++)
			{
				if (board[s_x][i] != '_') 
					return 0;
			}
		}
		return 1; 
	}




	return false;
}
bool bishop(char** board, int s_x, int s_y, int d_x, int d_y)
{
	int j = 0;
	int temp_i = 0;
	int temp_j = 0;
	if (king(board, s_x, s_y, d_x, d_y)&&!Rook(board, s_x, s_y, d_x, d_y))
		return 1;
	if ((s_x >-1 && s_x < rows) && (s_y > -1 && s_y < cols-1))
	{
		if (s_x > d_x && s_y > d_y)
		{
			j = s_y - 1;
			
			for (int i = s_x - 1; i > d_x && j > d_y; i--, j--)
			{
				if (board[i][j] != '_')
					return 0;
				temp_i = i;
				temp_j = j;
			}
			if (temp_i - 1 == d_x && temp_j - 1 == d_y)
				return 1;
			return 0;


		}
		else if (s_x < d_x && s_y < d_y)
		{
			j = s_y + 1;
		
			for (int i = s_x + 1; i < d_x && j < d_y; i++, j++)
			{
				if (board[i][j] != '_')
					return 0;

				temp_i = i;
				temp_j = j;
			}
			if (temp_i + 1 == d_x && temp_j + 1 == d_y)
				return 1;
			return 0;
		}
		else if (s_x > d_x && s_y < d_y)
		{
			
			j = s_y + 1;
			for (int i = s_x - 1; i > d_x && j < d_y; i--, j++)
			{
				if (board[i][j] != '_')
					return 0;
				temp_i = i;
				temp_j = j;
			}
			if (temp_i - 1 == d_x && temp_j + 1 == d_y)
				return 1;
			return 0;

		}
		else if (s_x < d_x && s_y > d_y)
		{
			j = s_y - 1;
			
			for (int i = s_x + 1; i < d_x && j > d_y; i++, j--)
			{
				if (board[i][j] != '_')
					return 0;
				temp_i = i;
				temp_j = j;

			}
			if (temp_i + 1 == d_x && temp_j - 1 == d_y)
				return 1;
			return 0;
		}
	}
	if (Rook(board, s_x, s_y, d_x, d_y))
	{
		return 0;
	}

}
bool king(char** board, int s_x, int s_y, int d_x, int d_y)
{

	if (s_x + 1 == d_x && s_y + 1 == d_y)
		return 1;
	else if (s_x - 1 == d_x && s_y - 1 == d_y)
		return 1;
	else if (s_x + 1 == d_x && s_y - 1 == d_y)
		return 1;
	else if (s_x - 1 == d_x && s_y + 1 == d_y)
		return 1;
	else if (s_x + 1 == d_x && s_y == d_y)
		return 1;
	else if (s_x - 1 == d_x && s_y == d_y)
		return 1;
	else if (s_x == d_x && s_y + 1 == d_y)
		return 1;
	else if (s_x == d_x && s_y - 1 == d_y)
		return 1;
	return 0;

}
void makeMove(char**& board, int s_x, int s_y, int d_x, int d_y, bool turn)
{
	if ((d_x > -1 && d_x < rows) && (d_y > -1 && d_y < cols)&&
		(s_x > -1 && s_x < rows) && (s_y > -1 && s_y < cols))
	{

		board[d_x][d_y] = board[s_x][s_y];
		board[s_x][s_y] = '_';
		if (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'P')
		{
			if (d_x == 0 || d_x == 7)
			{
				changePawn(board, d_x, d_y, turn);
			}
		}
	}
}
void onFile(char** & board)
{
	char** temp2D = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp2D[i] = new char[cols];
	}

	fstream fout;
	fout.open("board.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fout >> temp2D[i][j];
		}
	}
	undowrite(temp2D);
	fout.close();
	fout.open("board.txt");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fout << board[i][j];
		}
		fout << endl;
	}
	fout.close();
	for (int i = 0; i < rows; i++)
	{
		delete[] temp2D[i];
	}
	delete[] temp2D;
}
void deleteBoard(char** board)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
void sourceInput(char** board, int& s_x, int& s_y, bool& turn, char ****& MegaBoard)
{
	do
	{
		gotoRowCol(3, 102);
		cout << "Waiting for Source Input                      ";
		gotoRowCol(2, 102);
		cout << "Player " << turn + 1 << endl;
		inputbyclick(s_x, s_y, board, MegaBoard, turn);
		gotoRowCol(30, 0);

	} while (!validSource(board, s_x, s_y, turn));
}
void DestinationInput(char** board, int& s_x, int& s_y, int& d_x, int& d_y, bool& turn, char **** & MegaBoard)
{

	do
	{
		
		gotoRowCol(0, 0);
		printBoardSource(MegaBoard, board, turn, s_x, s_y);
		gotoRowCol(3, 102);
		cout << "Valid Source! Waiting for Destination Input";
		gotoRowCol(2, 102);

		cout << "Player " << turn + 1 << endl;
		gotoRowCol(34, 0);
		inputbyclick(d_x,d_y, board, MegaBoard, turn);

		if (!validDestination(board, d_x, d_y, turn, s_x, s_y))
		{
			gotoRowCol(0, 0);
			printBoard(MegaBoard, board, turn);
			gotoRowCol(34, 0);

			sourceInput(board, s_x, s_y, turn, MegaBoard);
		}
	} while (!validDestination(board, d_x, d_y, turn, s_x, s_y));
}
bool knight(char** board, int  s_x, int s_y, int d_x, int d_y, bool turn)
{
	if (!validSource(board, d_x, d_y, turn))
	{
		if (d_x == s_x + 2 && d_y == s_y + 1)
		{
			return 1;
		}
		if (d_x == s_x + 1 && d_y == s_y + 2)
		{
			return 1;
		}
		if (d_x == s_x - 2 && d_y == s_y - 1)
		{
			return 1;
		}
		if (d_x == s_x - 1 && d_y == s_y - 2)
		{
			return 1;
		}
		if (d_x == s_x + 2 && d_y == s_y - 1)
		{
			return 1;
		}
		if (d_x == s_x - 1 && d_y == s_y + 2)
		{
			return 1;
		}
		if (d_x == s_x - 2 && d_y == s_y + 1)
		{
			return 1;
		}
		if (d_x == s_x + 1 && d_y == s_y - 2)
		{
			return 1;
		}

	}
	return 0;

}
bool pawn(char** board, int  s_x, int s_y, int d_x, int d_y, bool turn)
{
	if (turn == 0)
	{
		if (s_x == 1 && d_y == s_y)
		{
			if (d_x == s_x + 2 || d_x == s_x + 1)
				return 1;
		}
		else if (s_y == d_y)
		{
			if ((d_x == s_x + 1)&& board[s_x +1][s_y] == '_')
				return 1;
		}
		else if (d_x == s_x + 1 && d_y == s_y + 1 && !validSourcepawn(board, d_x, d_y, turn))
		{
			return 1;
		}
		else if (d_x == s_x + 1 && d_y == s_y - 1 && !validSourcepawn(board, d_x, d_y, turn))
		{
			return 1;
		}
		if (d_x == 7)
		{

		}
	}
	else if (turn == 1)
	{
		if (s_x == 6 && d_y == s_y)
		{
			if (d_x == s_x - 2 || d_x == s_x - 1)
				return 1;
		}
		else if (s_y == d_y)
		{
			if (d_x == s_x - 1 && board[s_x - 1][s_y] == '_')
				return 1;
		}
		else if (d_x == s_x - 1 && d_y == s_y - 1 && !validSourcepawn(board, d_x, d_y, turn))
		{
			return 1;
		}
		else if (d_x == s_x - 1 && d_y == s_y + 1 && !validSourcepawn(board, d_x, d_y, turn))
		{
			return 1;
		}
	}
	return 0;
}
bool validSourcepawn(char** board, int s_x, int s_y, bool turn)
{
	if ((s_x > -1 && s_x < rows) && (s_y > -1 && s_y < cols))
	{
		char whites[7] = { 'r','n','b','q','k','p','_' };
		char blacks[7] = { 'R','N','B','Q','K','P','_' };
		if (turn == 0)
		{
			for (int i = 0; i < 7; i++)
			{
				if (board[s_x][s_y] == *(whites + i))
					return 1;

			}
			return 0;
		}
		else if (turn == 1)
		{
			for (int i = 0; i < 7; i++)
			{
				if (board[s_x][s_y] == *(blacks + i))
					return 1;

			}
			return 0;
		}

	}
	return 0;


}
void changePawn(char** board, int s_x, int s_y, bool turn)
{
	int x = 13, y;
	char choice = '-';
	
		do {
			gotoRowCol(10, 102);
			cout << "Choose One: ";
			gotoRowCol(11, 102);
			cout << "Rook ";
			gotoRowCol(12, 102);
			cout << "Knight ";
			gotoRowCol(13, 102);
			cout << "Queen";
			gotoRowCol(14, 102);
			cout << "Bishop ";
	
			getRowColbyLeftClick(x, y);
			gotoRowCol(34, 0);
			choice = pawnchoice(x, y, turn);

		} while (choiceValidation(choice, turn));

	
	
	board[s_x][s_y] = choice;


}
char pawnchoice(int x, int y, bool turn)
{
	if (turn)
	{
		if (x == 11)
			return 'R';
		else if (x == 12)
			return 'N';
		else if (x == 13)
			return 'Q';
		else
			return 'B';
	}
	else
	{

		if (x == 11)
			return 'r';
		else if (x == 12)
			return 'n';
		else if (x == 13)
			return 'q';
		else
			return 'b';
	}
}
bool choiceValidation(char choice, bool turn)
{
	char whites[5] = { 'r','n','b','q','k' };
	char blacks[5] = { 'R','N','B','Q','K' };
	if (turn == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (choice == whites[i])
				return 1;

		}
		return 0;
	}
	if (turn == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (choice == blacks[i])
				return 1;

		}
		return 0;
	}


}
void delete3D(char**** MegaBoard)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			deleteBoardBlock(MegaBoard[i][j]);
		}
	}
	delete[] MegaBoard;
}
void copyArray(char arr1[brows][bcols], char** arr2)
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			arr2[i][j] = arr1[i][j];
		}
	}
}
bool iseven(int n)
{
	if (n % 2 == 0)
		return 1;
	return 0;
}
char** EmptySpaceBlack(char** block)
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			block[i][j] = '#';
		}
	}
	return block;
}
char** EmptySpaceWhite(char** block)
{
	for (int i = 0; i < brows; i++)
	{
		for (int j = 0; j < bcols; j++)
		{
			block[i][j] = '0';
		}
	}
	return block;
}
char** WhitePawnBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '|', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '|', '|', '|', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '|', '#', '#', '#', '#', '#'},
		{'#', '#', '|', '|', '|', '|', '|', '|', '|', '#', '#'},
	};

	copyArray(block1, block);
	return block;
}
char** BlackPawnBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '!', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '!', '!', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '!', '0', '0', '0', '0', '0'},
		{'0', '0', '!', '!', '!', '!', '!', '!', '!', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** WhitePawnBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '|', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '|', '|', '|', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '|', '0', '0', '0', '0', '0'},
		{'0', '0', '|', '|', '|', '|', '|', '|', '|', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackPawnBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '!', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '!', '!', '!', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '!', '#', '#', '#', '#', '#'},
		{'#', '#', '!', '!', '!', '!', '!', '!', '!', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteRookBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0','0','|','0','|','|','|','0','|','0','0'},
		{'0','0','|','|','|','|','|','|','|','0','0'},
		{'0','0','0','0','|','|','|','0','0','0','0'},
		{'0','0','|','|','|','|','|','|','|','0','0'},
	};

	copyArray(block1, block);
	return block;
}
char** WhiteRookBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '|', '#', '|', '|', '|', '#', '|', '#', '#'},
		{'#', '#', '|', '|', '|', '|', '|', '|', '|', '#', '#'},
		{'#', '#', '#', '#', '|', '|', '|', '#', '#', '#', '#'},
		{'#', '#', '|', '|', '|', '|', '|', '|', '|', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackRookBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '!', '#', '!', '!', '!', '#', '!', '#', '#'},
		{'#', '#', '!', '!', '!', '!', '!', '!', '!', '#', '#'},
		{'#', '#', '#', '#', '!', '!', '!', '#', '#', '#', '#'},
		{'#', '#', '!', '!', '!', '!', '!', '!', '!', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackRookBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '!', '0', '!', '!', '!', '0', '!', '0', '0'},
		{'0', '0', '!', '!', '!', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '!', '!', '!', '0', '0', '0', '0'},
		{'0', '0', '!', '!', '!', '!', '!', '!', '!', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackKnightBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '#', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '#', '!', '!', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '!', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '!', '!', '!', '!', '!', '!', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackKnightBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '0', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '!', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '!', '!', '!', '!', '!', '!', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteKnightBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '0', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '0', '|', '|', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '|', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '|', '|', '|', '|', '|', '|', '0', '0'},
	};

	copyArray(block1, block);
	return block;
}
char** WhiteKnightBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '#', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '#', '|', '|', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '|', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '|', '|', '|', '|', '|', '|', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteBishopBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '|', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '#', '|', '|', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '|', '|', '#', '#', '#', '#'},
		{'#', '#', '#', '|', '|', '|', '|', '|', '#', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackBishopBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '#', '!', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '#', '!', '!', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '!', '!', '#', '#', '#', '#'},
		{'#', '#', '#', '!', '!', '!', '!', '!', '!', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackBishopBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '!', '!', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '!', '!', '0', '0', '0', '0'},
		{'0', '0', '0', '!', '!', '!', '!', '!', '!', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteBishopBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '0', '|', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '0', '|', '|', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '|', '|', '0', '0', '0', '0'},
		{'0', '0', '0', '|', '|', '|', '|', '|', '|', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackQueenBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '!', '#', '#', '!', '#', '#', '!', '#', '#'},
		{'#', '#', '#', '!', '!', '!', '!', '!', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '!', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '!', '!', '!', '#', '#', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteQueenBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '|', '#', '#', '|', '#', '#', '|', '#', '#'},
		{'#', '#', '#', '|', '|', '|', '|', '|', '#', '#', '#'},
		{'#', '#', '#', '#', '#', '|', '#', '#', '#', '#', '#'},
		{'#', '#', '#', '#', '|', '|', '|', '#', '#', '#', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteQueenBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '|', '0', '0', '|', '0', '0', '|', '0', '0'},
		{'0', '0', '0', '|', '|', '|', '|', '|', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '|', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '|', '|', '|', '0', '0', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackQueenBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '!', '0', '0', '!', '0', '0', '!', '0', '0'},
		{'0', '0', '0', '!', '!', '!', '!', '!', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '!', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '!', '!', '!', '0', '0', '0', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackKingBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '!', '!', '!', '#', '#', '#', '#'},
		{'#', '!', '!', '!', '!', '!', '!', '!', '!', '!', '#'},
		{'#', '#', '!', '!', '!', '!', '!', '!', '!', '#', '#'},
		{'#', '!', '!', '!', '!', '!', '!', '!', '!', '!', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteKingBlockBlack(char** block)
{
	char block1[brows][bcols] = {
		{'#', '#', '#', '#', '|', '|', '|', '#', '#', '#', '#'},
		{'#', '|', '|', '|', '|', '|', '|', '|', '|', '|', '#'},
		{'#', '#', '|', '|', '|', '|', '|', '|', '|', '#', '#'},
		{'#', '|', '|', '|', '|', '|', '|', '|', '|', '|', '#'}
	};

	copyArray(block1, block);
	return block;
}
char** WhiteKingBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '0', '|', '|', '|', '0', '0', '0', '0'},
		{'0', '|', '|', '|', '|', '|', '|', '|', '|', '|', '0'},
		{'0', '0', '|', '|', '|', '|', '|', '|', '|', '0', '0'},
		{'0', '|', '|', '|', '|', '|', '|', '|', '|', '|', '0'}
	};

	copyArray(block1, block);
	return block;
}
char** BlackKingBlockWhite(char** block)
{
	char block1[brows][bcols] = {
		{'0', '0', '0', '!', '!', '!', '!', '!', '0', '0', '0'},
		{'0', '!', '!', '!', '!', '!', '!', '!', '!', '!', '0'},
		{'0', '0', '!', '!', '!', '!', '!', '!', '!', '0', '0'},
		{'0', '!', '!', '!', '!', '!', '!', '!', '!', '!', '0'}
	};

	copyArray(block1, block);
	return block;
}
void intialize4D(char****& arr)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char** [cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = new char* [brows];
			for (int l = 0; l < brows; l++)
			{
				arr[i][j][l] = new char[bcols];
			}
		}
	}
	
}
void deleteBoardBlock(char** board)
{
	for (int i = 0; i < brows; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
bool IsCheck(char** board, bool oppturn)
{
	int King_dx = -1, King_dy = -1;
	bool flag = false;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((!oppturn && board[i][j] == 'K') || (oppturn && board[i][j] == 'k'))
			{
				King_dx = i;
				King_dy = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
				if (validDestinationKing(board, i, j, !oppturn, King_dx, King_dy))
				{
					return true;
				}
			
		}
	}

	return 0;
}
bool isCheckmate(char** board, bool turn)
{

	if (!IsCheck(board, turn))
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((turn && FromP2(board, i, j)) || (!turn && FromP1(board, i, j)))
			{
				for (int x = 0; x < rows; x++)
				{
					for (int y = 0; y < cols; y++)
					{

						if (validDestinationKing(board, i, j, turn, x, y)) {

							char temp = board[x][y];
							board[x][y] = board[i][j];
							board[i][j] = '_';

							if (!IsCheck(board, turn))
							{

								board[i][j] = board[x][y];
								board[x][y] = temp;
								return false;
							}


							board[i][j] = board[x][y];
							board[x][y] = temp;
						}
					}
				}
			}
		}
	}
	return true;
}
bool validDestinationKing(char** board, int s_x, int s_y, bool turn, int d_x, int d_y)
{
	if (s_x == d_x && s_y == d_y)
		return 0; 
	if (board[s_x][s_y] == '_')
		return 0; 

	
	bool isOppPiece = (turn && FromP1(board, s_x, s_y)) || (!turn && FromP2(board, s_x, s_y));
	if (!isOppPiece) 
		return 0;

	
	if (board[s_x][s_y] == 'r' || board[s_x][s_y] == 'R') 
	{  
		if (Rook(board, s_x, s_y, d_x, d_y))
			return true;
	}
	else if (board[s_x][s_y] == 'b' || board[s_x][s_y] == 'B') 
	{ 
		if (bishop(board, s_x, s_y, d_x, d_y)) 
			return true;
	}
	else if (board[s_x][s_y] == 'q' || board[s_x][s_y] == 'Q') 
	{  
		if (Rook(board, s_x, s_y, d_x, d_y) || bishop(board, s_x, s_y, d_x, d_y))
			return 1;
	}
	else if (board[s_x][s_y] == 'k' || board[s_x][s_y] == 'K')
	{ 
		if (king(board, s_x, s_y, d_x, d_y))
			return 1;
	}
	else if (board[s_x][s_y] == 'n' || board[s_x][s_y] == 'N')
	{ 
		if (knight(board, s_x, s_y, d_x, d_y, turn))
			return 1;
	}
	else if (board[s_x][s_y] == 'p' || board[s_x][s_y] == 'P')
	{ 
		if (pawn(board, s_x, s_y, d_x, d_y, turn))
			return 1;
	}

	return false;  
}
bool FromP1(char** board, int s_x, int s_y)
{
	if (board[s_x][s_y] >= 'a' && board[s_x][s_y] <= 'z')
		return true;
	return false;
}
bool FromP2(char** board, int s_x, int s_y)
{
	if (board[s_x][s_y] >= 'A' && board[s_x][s_y] <= 'Z')
		return true;
	return false;
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
bool inputbyclick(int& s_x, int& s_y, char**& board, char****& MegaBoard, bool& turn)
{
	int x, y;
	getRowColbyLeftClick(x, y);
	if (x == 8 && y > 100)
	{
		return 1;
	}
	else if (x == 5 && y > 100)
	{
		gotoRowCol(0, 0);
		printBoardRestart(MegaBoard, board, turn);
		turn = 0;
		
	}
	else  if (x == 6 && y > 100)
	{
		gotoRowCol(0, 0);
		printBoard(MegaBoard, board, turn);
	}
	
	else if (x == 7 && y > 100)
	{
		gotoRowCol(0, 0);
		printBoardundo(MegaBoard, board, turn);
		turn = turnChange(turn);
	}
	

	else if (y > -1 && y < 98)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int i = 0; i < cols; ++i)
			{

				if ((y >= (i * bcols + 1) - 1 && y < (i + 1) * bcols + 1) &&
					(x >= (j * brows + 1) - 1 && x < (j + 1) * brows + 1)) {
					s_x = j;
					s_y = i;
					return 0;
				}
			}
		}
	}
	return 0;
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void print()
{
	SetTextColor(9);

	gotoRowCol(5, 102);
	cout << "Restart";
	gotoRowCol(6, 102);
	cout << "Resume";
	gotoRowCol(7, 102);
	cout << "Undo";
	gotoRowCol(8, 102);
	cout << "Quit Game!";
	gotoRowCol(29, 102);
	cout << "Developer : ROHAIL ASHRAF";
	gotoRowCol(31, 102);
	cout << "SEMESTER PROJECT";
	gotoRowCol(32, 102);
	cout << "NAME OF PROJECT: CHESS";
	gotoRowCol(34, 0);
	SetTextColor(11);

}
void restart(char**& board)
{
	fstream file;
	for (int i = 0; i < rows; i++)
	{
		*(board + i) = new char[cols];
	}
	file.open("resume.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> *(*(board + i) + j);
		}

	}
	file.close();
	onFile(board);
	
}
void initialize(char**& board)
{
	fstream file;
	for (int i = 0; i < rows; i++)
	{
		*(board + i) = new char[cols];
	}
	file.open("board.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> *(*(board + i) + j);
		}

	}
	file.close();
}
void printBoardRestart(char****& MegaBoard, char**& board, bool turn)
{
	restart(board);
	initializeMegaBoard(board, MegaBoard, turn);
	

	SetTextColor(12);
	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(14);

	for (int z = 0; z < rows; z++)
	{
		for (int i = 0; i < brows; i++)
		{
			SetTextColor(12);

			cout << "|";
			SetTextColor(14);

			for (int j = 0; j < rows; j++)
			{
				for (int w = 0; w < bcols; w++)
				{
					if (MegaBoard[z][j][i][w] == '|')
					{
						SetTextColor(1);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if (MegaBoard[z][j][i][w] == '#')
					{
						SetTextColor(0);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if (MegaBoard[z][j][i][w] == '!')
					{
						SetTextColor(10);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else
						cout << MegaBoard[z][j][i][w];
				}

			}
			SetTextColor(12);
			cout << "|" << endl;
			SetTextColor(14);

		}

	}
	SetTextColor(12);

	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(11);
	print();
}
void SetTextColor(int color) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void undo( char**& board)
{
	fstream file;
	file.open("previous.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file >> *(*(board + i) + j);
		}

	}
	file.close();
	
}
void printBoardSource(char**** MegaBoard, char**& board, bool turn, int s_x, int s_y)
{

	SetTextColor(12);
	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;

	SetTextColor(14);  
	
	for (int z = 0; z < rows; z++)
	{
		for (int i = 0; i < brows; i++)
		{
			SetTextColor(12);
			cout << "|"; 
			SetTextColor(14);

			for (int j = 0; j < rows; j++) 
			{
				for (int w = 0; w < bcols; w++) 
				{
					
					if (validDestination(board, z, j, turn , s_x, s_y)) 
					{
							SetTextColor(5); 
							
							if (MegaBoard[z][j][i][w] == '|')
							{
								SetTextColor(1);
								cout << MegaBoard[z][j][i][w];
								SetTextColor(14);
							}
							else if (MegaBoard[z][j][i][w] == '!')
							{
								SetTextColor(10);
								cout << MegaBoard[z][j][i][w];
								SetTextColor(14);
							}
							else
							{
								SetTextColor(5);
								cout << MegaBoard[z][j][i][w];
								SetTextColor(14);
							}
					}
					else
					{
						if (MegaBoard[z][j][i][w] == '|')
						{
							SetTextColor(1);
							cout << MegaBoard[z][j][i][w];
							SetTextColor(14);
						}
						else if (MegaBoard[z][j][i][w] == '!')
						{
							SetTextColor(10);
							cout << MegaBoard[z][j][i][w];
							SetTextColor(14);
						}
						else if (MegaBoard[z][j][i][w] == '#')
						{
							SetTextColor(0);
							cout << MegaBoard[z][j][i][w];
							SetTextColor(14);
						}
						else 
							cout << MegaBoard[z][j][i][w];
					}
					
				}
			}
			SetTextColor(12);
			cout << "|" << endl;
			SetTextColor(14); 
		}
	}

	SetTextColor(12);
	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(11); 
	print();
}
void undowrite(char**& board)
{
	fstream file;
	file.open("previous.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			file << board[i][j];
		}
		file << endl;
	}
	file.close();
	
}
void printBoardundo(char****& MegaBoard, char**& board, bool turn)
{
	undo(board);
	initializeMegaBoard(board, MegaBoard, turn);

	SetTextColor(12);
	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(14);

	for (int z = 0; z < rows; z++)
	{
		for (int i = 0; i < brows; i++)
		{
			SetTextColor(12);

			cout << "|";
			SetTextColor(14);

			for (int j = 0; j < rows; j++)
			{
				for (int w = 0; w < bcols; w++)
				{
					if (MegaBoard[z][j][i][w] == '|')
					{
						SetTextColor(1);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if (MegaBoard[z][j][i][w] == '#')
					{
						SetTextColor(0);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else if (MegaBoard[z][j][i][w] == '!')
					{
						SetTextColor(10);
						cout << MegaBoard[z][j][i][w];
						SetTextColor(14);
					}
					else
						cout << MegaBoard[z][j][i][w];
				}

			}
			SetTextColor(12);
			cout << "|" << endl;
			SetTextColor(14);

		}

	}
	SetTextColor(12);

	for (int w = 0; w < bcols * cols + 2; w++)
	{
		cout << "-";
	}
	cout << endl;
	SetTextColor(11);
	onFile(board);

	print();
}
