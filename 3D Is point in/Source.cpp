#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file;
	file.open("test.svg");
	char* word = new char[256];
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> word;
			if (strcmp(word, "<svg>") == 0)
			{
				while (strcmp(word, "</svg>") != 0)
				{
					file >> word;
					int cnt = 0;
					while (cnt != strlen(word))
					{
						if (word[cnt] == '"')
						{
							cnt++;
							cnt++;
							char* part = new char[256];
							while (word[cnt] == '"')
							{

								part[strlen(part) - 1] = word[cnt];
							}
							cout << part << " ";


						}
						cnt++;
					}
					//cout << word << " ";
					if (strcmp(word, "/>") == 0)
						cout << endl;
				}
			}
		}
	}
	cout << "8===D" << endl;
	return 0;
}