#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS // Hello, strtok

const char* const CSV_DELIMITER = ",";
const int MAX_BUFF_LINE = 12000;
const int MAX_ELEM = 6000;

void stock(char* tempTab[])
{
	for (int i = 0; tempTab[i]; i++)
      cout << "data[" << i << "] = " << tempTab[i] << endl;
    cout << endl;
}

int main(int ac, char* av[])
{
	if (ac == 2 && av[1])
	{
		ifstream file;
		file.open(av[1]);
		if (file.good())
		{
			while (!file.eof())
			{
				char buff[MAX_BUFF_LINE];
				file.getline(buff, MAX_BUFF_LINE);
                char* tempTab[MAX_ELEM];
				tempTab[0] = strtok(buff, CSV_DELIMITER);

				if (tempTab[0])
				{
					for (int i = 1; i < MAX_ELEM; i++)
					{
						tempTab[i] = strtok(0, CSV_DELIMITER);
						if (!tempTab[i])
							break;
					}
				}
			stock(tempTab);
			}
		}
		else
		{
			puts("Failed at opening file");
			return 1;
		}
	}
	return 0;
}
