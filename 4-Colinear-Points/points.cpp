/*
Anthony Pasquariello
Partner: John Delaney

Alogirthm: We use a map to hold a key and data. The key is each 
unique slope value. The data in the map is the coordinates that 
have that slope. We use a structure to hold the coordinates, and 
we check if the map data has 4 or more values per key. If a key 
has more 4 or more values on one slope key, then those coordinates
are colplaner.
Time Complexity: O(n^2)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
	double x;
	double y;
};

void checkPoint(vector<Point> points)
{
	//Get the number of points
	int num = points.size();
	vector<vector<Point>> results;
	vector<Point> resLines;


	//Make an array of all the slopes
	for(int i = 0; i < num - 3; i++)
	{
		std::unordered_map<double,vector<Point>> slopes;

		for(int j = i + 1; j < num; j++)
		{
			double slope = 0;
   			//Special case for infinity slopes
   			if(points[j].x == points[i].x) {
   				slope = 999999.999999;
   			}
   			else
   			{
   				//Find slope -> y1-y2/x1-x2
   				slope = (points[j].y - points[i].y) / (points[j].x - points[i].x);
   			}

   			if ( slopes.find(slope) == slopes.end()) 
   			{
				slopes[slope] = vector<Point>();
				slopes[slope].push_back(points[i]);
				slopes[slope].push_back(points[j]);
			} 
			else 
			{
				slopes[slope].push_back(points[j]);
			}
  		}
  		for(auto it = slopes.cbegin(); it != slopes.cend(); ++it)
		{
			if(it->second.size() >= 4) 
			{
				results.push_back(it->second);
				Point p;
				p.x = it->first;
				p.y = it->second[0].y - (it->first * it->second[0].x);
				resLines.push_back(p);
			}
		}
	}
	int badInds[results.size()];
	for(int i = 0; i < results.size(); i++)
	{
		badInds[i] = 0;
	}
	bool first = true;

	for(int  i = 0; i < resLines.size(); i++) 
	{
		if(!first)
			cout << endl;
		else
			first = false;

		if(!badInds[i]) 
		{
			for(int j = 0; j < results[i].size(); j++) 
			{
				cout << "("<< results[i][j].x << ", " << results[i][j].y << ")" << endl;
			}

			Point p = resLines[i];
			double x = p.x;
			double y= p.y;
			for(int j = i + 1; j < resLines.size(); j++) 
			{
				Point q = resLines[j];
				if(q.x == x && q.y == y) 
				{
					badInds[j] = 1;
				}
			}
		}
	}
}

int main() {

	vector<Point> array;
	ifstream infile("points.txt");

	//This will check if file opens successfully
	if(infile.is_open())
	{
		double n;
		int count;
		infile >> count;
		double x = 0;
		double y = 0;

		for(int i = 0; i < count; i++)
		{
			infile >> x;
			infile >> y;
			Point p;
			p.x = x;
			p.y = y;

			array.push_back(p);
		}

	}
	else
	{
		cout << "Unable to open file" <<endl;
	}

	checkPoint(array);
	return 0;
}