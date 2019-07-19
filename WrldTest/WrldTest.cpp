// WrldTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include <vector>
#include<math.h>
#include<string>

using namespace std;

//function to get the euclidean distance
double euclideanDistance(double x1, double y1, double x2, double y2)
{
	double x = x2 - x1;
	double y = y2 - y1;
	double dist;

	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);

	return dist;
}


int main()
{
	//variables used in the program
	vector<string> name;
	vector<int> xVal, yVal;
	
	double distance = 0;
	double totalDistance = 0;
	double greatestDist = 0;



	string place;
	int x, y;
	string placeNum;

	ifstream readableFile;
	readableFile.open("problem_small.txt");


	//read the file and put values into vectors for place value and x,y co-ordinates
	while (!readableFile.eof())
	{
		readableFile >> place >> x >> y;
		name.push_back(place);
		xVal.push_back(x);
		yVal.push_back(y);
	}



	readableFile.close();

	//calculate for each point, get the total distance and set it to the furthest point if total distance is the highest
	for (int i = 0; (i < xVal.size() - 1); i++)
	{
		//maybe thread this to make it faster???
		//could also try storing previously found values but havn't found a way to work these out yet
		for (int j = 0; (j < xVal.size() - 1); j++)
		{
			distance = euclideanDistance(xVal[i], yVal[i], xVal[j], yVal[j]);
			totalDistance += distance;
		}
	
		if (totalDistance > greatestDist)
		{
			greatestDist = totalDistance;
	
			placeNum = name[i];
		}

		totalDistance = 0;
	}
	
	// get the most isolated place and put it to the console
	cout << placeNum << endl;

	return 0;

}
