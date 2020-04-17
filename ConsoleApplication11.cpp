#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string date;

void Find(string log, string iname)
{
	string name, time, result;

	int a = 0;
	for (int i = 0; i < log.size(); i++)
	{
		if (log[i] != ':' && a == 0)
			time = log[i];
		else if (log[i] == ':' && a == 0)
			a = 1;
		else if (log[i] != ':' && a == 1)
			name.push_back(log[i]);
		else if (log[i] == ':' && a == 1)
			a = 2;
		else if (log[i] != ':' && a == 2)
			result.push_back(log[i]);
	}
		if (name == iname)
			cout << date << "-0" << time << "||\t||" << result << endl;
}

int main()
{
	ifstream file;
	string str, dev_name;
	vector<string> files;

	for (auto& p : std::experimental::filesystem::directory_iterator("C:/Users/kiril/Desktop/lesson_1-master/logs"))
		files.push_back(p.path().string());

	cout << "Enter device name: ";
	cin >> dev_name;

	if (cin.fail())
	{
		cout << "Error";
		return 0;
	}
	else 
	{
		if (dev_name.find("garbage") == -1)
		{
			cout << "Time:\t\t\tResult:\n";

			for (int i = 0; i < files.size(); i++)
			{
				file.open(files[i]);

				for (int j = files[i].size() - 21; j < files[i].size() - 5; j++)
					date.push_back(files[i][j]);

				while (!file.eof())
				{
					getline(file, str);
					Find(str, dev_name);
				}

				file.close();
				date.clear();
			}
		}
		else
			cout << "Current device is unavailable\n";
	}
	return 0;
}