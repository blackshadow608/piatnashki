
#pragma once
class Field
{
	int mas[4][4];
	int pozX;
	int pozY;

public:
	Field();
	/*! Displays the playing field..do not rerurn value*/
	void view();
	
	/**Moves the element to the left to position the empty cells*/
	void moveRight();
	
	/**Moves the element to the right to position the empty cells*/
	void moveLeft();
	/**Moves the element below the position of the empty cells*/
	void moveUp();
	/**Moves the top element of the position of the empty cells*/
	void moveDown();
	/**Checks collected field or not*/
	bool location();
	/**Generates a random position of the cells of the field*/
	void rnd();

};

