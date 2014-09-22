
#pragma once
/**@brief Class used for Piatnashki game.
*
Class randomly generates cells position,
exchanges cells, retrieves cell value and checks for
correct cell disposition
*/
class Field
{
	int mas[4][4];
	int pozX;
	int pozY;

public:
	/**@brief Constructor */
	Field();
	/*!@brief Displays the playing field */
	void view();

	/**@brief Moves the element to the right*/
	void moveRight();
	/**@brief Moves the element to the left*/
	void moveLeft();
	/**@brief Moves the element upwards*/
	void moveUp();
	/**@brief Moves the top element downwards*/
	void moveDown();
	/**@brief Checks for correct cell disposition
	@return True if dispotion is correct and false if incorrect
	*/
	bool location();
	/**@brief Randomly generates cells position*/
	void rnd();
	/**@brief Retrieves cell value
	@param i - Cell number
	@return Cell value
	@throw InputError Wrong cell number (should be from 0 to 15)
	*/
	int operator[] (int i);

};
