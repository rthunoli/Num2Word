#include<iostream>
#include<map>
#include<string>

using namespace std;

string n2w(int number)
{
	map<int, string>nw;
	nw[0] = "zero";
	nw[1]= "one";
	nw[2] = "two";
	nw[3] = "three";
	nw[4] = "four";
	nw[5] = "five";
	nw[6] = "six";
	nw[7] = "seven";
	nw[8] = "eight";
	nw[9] = "nine";
	nw[10] = "ten";
	nw[11] = "eleven";
	nw[12] = "twelve";
	nw[13] = "thirteen";
	nw[14] = "fourteen";
	nw[15] = "fifteen";
	nw[16] = "sixteen";
	nw[17] = "seventeen";
	nw[18] = "eighteen";
	nw[19] = "nineteen";
	nw[20] = "twenty";
	nw[30] = "thirty";
	nw[40] = "forty";
	nw[50] = "fifty";
	nw[60] = "sixty";
	nw[70] = "seventy";
	nw[80] = "eighty";
	nw[90] = "ninety";

	int rem;
	string word;
	if (nw.find(number) == nw.end())
	{
		if (number < 100)
		{
			rem = number % 10;
			number -= rem;
			word = n2w(rem);
			word = n2w(number) + " " + word;
		}
		else if (number < 1000)
		{
			rem = number % 100;
			number /= 100;
			if(rem > 0)
				word = n2w(rem);
			word = n2w(number) + " hundred " + word;
		}
		else if (number < 1000000)	//less than one million
		{
			rem = number % 1000;
			number /= 1000;
			if (rem > 0)
				word = n2w(rem);
			word = n2w(number) + " thousand " + word;
		}
		else if (number < 1000000000)	//less than one billion
		{
			rem = number % 1000000;
			number /= 1000000;
			if (rem > 0)
				word = n2w(rem);
			word = n2w(number) + " million " + word;
		}

	}
	else
	{
		return nw[number];
	}

	return word;
}

int main()
{

	string number;
	while (true)
	{
		cout << "Enter a number (q to quit): ";
		cin >> number;
		if (number == "q" || number == "Q")
			break;
		cout << n2w(stoi(number)) << endl;
	}
	system("pause");
	return 0;
}