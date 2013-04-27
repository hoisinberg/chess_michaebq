#include "chesspiece.h"
using namespace std;

ChessPiece_Rook::ChessPiece_Rook(ChessBoard *board, char color) : ChessPiece(board, 'R', color, 5)
{
}

vector<int> ChessPiece_Rook::legalMoves()
{
	vector<int> legalMoves;
	
	//right
	int index = square_->index() + 1;
	while(index < 64 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		++index;
	}
	
	//left
	index = square_->index() - 1;
	while(index >= 0 && index % 8 != 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		--index;
	}
	
	//up
	index = square_->index() + 8;
	while(index < 64)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		index += 8;
	}
	
	//down
	index = square_->index() - 8;
	while(index >= 0)
	{
		if(board_->square(index)->getPiece() != NULL && 
			board_->square(index)->getPiece()->color() == piece_color) //friendly piece
			break;
		legalMoves.push_back(index);
		if(board_->square(index)->getPiece() != NULL) //this square contains an enemy piece
			break;
		index -= 8;
	}
	
	return legalMoves;
}
