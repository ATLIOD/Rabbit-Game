#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//initialize matrix to represent the garden
	int garden[8][10] = {
		{10,15,9,7,6,4,3,2,1,12},
		{12,2,3,4,1,6,7,8,10,0},
		{0,1,7,6,2,5,3,6,0,23},
		{4,9,0,5,12,14,2,4,4,2},
		{22,21,6,1,16,2,5,5,0,6},
		{9,8,5,3,7,6,12,6,12,3},
		{10,2,0,6,8,9,14,22,13,15},
		{9,6,5,4,1,10,12,10,2,1}
	};

	//array that hold coordinates for the initial position
	int position[] = {4,4};




	int findGreatest(int,int,int,int);		//function will take 4 values, and use the max function form the stl to return the greatestvalue
	int rabbitRampage(int[][10], int[]);	//function will take the garden matrix and position of the rabbit and output the number of carrots the rabbit eats in the game

	//outputs results of game
	cout << "\nThe rabbit ate " << rabbitRampage(garden, position) << " carrots!!" << endl;

	return 0;

}

int findGreatest(int right, int down, int left, int up)
{
	//values two at a time and returns the largest of them
	return max(max(up, down), max(right, left));
}

int rabbitRampage(int garden[][10], int position[])
{
	
	int y = position[0];			//x coord for position
	int x = position[1];			//y coord for position
	int carrotsAte = garden[x][y];	//total number of carrots ate by the rabbit
	int right, left, up, down;		//variables to hold values in relation to the rabbit's current position
	int nextSquare;					//holds value of the adjacent square with the largest number of carrots/ the next square the rabbit will move to

	//set values for the adjacent squares to the rabbits initial position.
	right = garden[y][x+1];
	left = garden[y][x-1];
	up = garden[y-1][x];
	down = garden[y+1][x];
	
	//loop will exit when all adjacent squares hold 0 as the value
	while (right != 0|| left != 0 || up != 0|| down != 0)
	{
		garden[y][x] = 0;									//set current square to zero
		nextSquare = findGreatest(right, down, left, up);	//sets next square to the largest of the adjacent squares
		carrotsAte += nextSquare;							//adds the value in the next square to the total number of carrots ate
		
		//checks all adjacent squares and moves the position to the rabbi to that square if it holds the greatest adjacent value
		if (nextSquare == right)
		{
			 x+= 1;
		}
		else if (nextSquare == left)
		{
			x -= 1;
		}
		else if (nextSquare == up)
		{
			y -= 1;
		}
		else if (nextSquare == down)
		{
			y += 1;
		}
		else
		{
			cout << "error";
			return 0;
		}

		//changes values of right, left, up, and down in relation to the new square
		//if the spot doesnt exist (is out of bounds) then the value of that direction is set to zero
		if (x + 1 <= 9)
			right = garden[y][x + 1];
		else
			right = 0;

		if (x - 1 >= 0)
			left = garden[y][x - 1];
		else
			left = 0;

		if (y - 1 >= 0)
			up = garden[y - 1][x];
		else up = 0;

		if (y + 1 <= 7)
			down = garden[y + 1][x];
		else down = 0;
		
	}
	garden[y][x] = 0;

	return carrotsAte;
}