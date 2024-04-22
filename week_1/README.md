The plan is roughly as follows:

	Create a marble class containing marble-y data like size and color.
	Create a bag class containing a list of marbles.
		- The bag class should have a method for adding a marble to the bag.
		- The bag class should have a method for removing a specific marble index from the bag.
		- The bag class should have a method for listing all the marbles in the bag.
		- The bag class should have a method for counting the number of marbles in the bag.
		- The bag class should have a method for getting the data of a specific marble.
	Start the program by creating a bag and adding some marbles to it.
	Begin a loop that asks the user what they want to do, including options for at least most of the above options.
	Include the option to quit the program.
	When the user quits the program, delete the bag.

Implementation:

	I did not make it as simple as possible, whoops.
	NOTE: The debug version works but the release version does not. I have no idea why.

	The marbles are a class that contains a size and a color. The size is an integer and the color is a string.
	The bag is a class which contains a list of marbles.
		The bag has a method for adding a marble to the bag.
		The bag has a method for removing a specific marble index from the bag.
		The bag has a method for listing all the marbles in the bag.
		The bag has a method for counting the number of marbles in the bag.
		The bag has a method for getting the data of a specific marble.
	You can call these methods from the main loop by typing the corresponding number given in the menu.

Tests:

	If you don't input a number when needed, the program will repeatedly ask you to input a valid number.
	if you input a number that is out of bounds, in most cases you will be warned that the number was invalid, the exception being integer overflow errors and such.
	If you enter the index of a marble which does not exist, it will tell you and do nothing.
	If you try to remove a marble from an empty bag, it will tell you and do nothing.
	If you try to get the data of a marble that does not exist, it will tell you and do nothing.
	If you try to over-fill the bag, it will tell you and do nothing.
	If you try to add a marble with a size of 0 or less, it will do it because that's funny.

