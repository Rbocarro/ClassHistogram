#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

enum calcOptions{total,average,numPassed,highest,lowest};//enum to control calc options

vector<int> marks;// global vector containing students marks

void input()
{
	int currentInput=0;
	while (currentInput <= 100)
	{
		cout << "Input Marks:";
		cin >> currentInput;
		if (currentInput <= 100)
		{
		marks.push_back(currentInput);
		}
		system("cls");// command is not system agnostic so may not work on some machines
	}	
}
string calc( int lowerLimit, int upperlimit )
{
	string output="";
	int counter = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		if (marks[i] >= lowerLimit && marks[i] <= upperlimit)
		{
			counter++;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		output.append("*");
	}
	return(output);
}
string calc( calcOptions c)
{
	string output="";
	switch (c) 
	{
	case calcOptions::total:
		output = to_string(marks.size());
		break;
	case calcOptions::average:
		output = to_string(accumulate(marks.begin(),marks.end(),0)/marks.size());
		break;
	case calcOptions::numPassed:
		output = to_string(count_if(marks.begin(),marks.end(), [](int i) {return i >= 30; } ));
		break;
	case calcOptions::highest:
		output = to_string(*max_element(marks.begin(), marks.end()));
		break;
	case calcOptions::lowest:
		output = to_string(*min_element(marks.begin(), marks.end()));
		break;
	default:
		output = "Error";
	}
	return(output);
}
void draw()
{	
	cout << "0-29:   "			<< calc(  0, 29)<< endl;
	cout << "30-39   "			<< calc( 30, 39)<< endl;
	cout << "40-69   "			<< calc( 40, 69)<< endl;
	cout << "70-100  "			<< calc( 70, 100)<< endl;
	cout << "Total Students: "		<< calc( calcOptions::total)<< endl;
	cout << "Average Marks Awarded: "	<< calc( calcOptions::average)<< endl;
	cout << "number of students passing: "	<< calc( calcOptions::numPassed)<< endl;
	cout << "Highest Mark: "		<< calc( calcOptions::highest)<< endl;
	cout << "Lowest Mark: "			<< calc( calcOptions::lowest)<< endl;
}
int main() 
{
	input();
	draw();
	return(0);
}