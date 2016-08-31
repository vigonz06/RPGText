#include "Coord.h"
#include "Board.h"

Coord Coord::next(Direction dir, Board board)
{
	Coord coor(x, y);

	if (dir == left &&  (board.operator[](coor) == VL || board.operator[](coor) == ENMY)) coor.y--;
	if (dir == up &&    (board.operator[](coor) == HL || board.operator[](coor) == ENMY)) coor.x--;
	if (dir == right && (board.operator[](coor) == VL || board.operator[](coor) == ENMY)) coor.y++;
	if (dir == down &&  (board.operator[](coor) == HL || board.operator[](coor) == ENMY)) coor.x++;

	return coor;
}