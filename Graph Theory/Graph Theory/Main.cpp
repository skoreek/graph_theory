#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

class Graph
{
private:
	vector<int> vecGraph;

public:

	void readGraph(string fileName)
	{
		ifstream read(fileName);
		if (!read.is_open())
			cout << "File not found!" << endl;

		else 
		{
			while (!read.eof())
				copy(istream_iterator<int>(read), istream_iterator<int>(), back_inserter(vecGraph));
		}
	}
	void writeGraph(string fileName)
	{
		ofstream write(fileName);
		if (!write.is_open())
			cout << "File not found!" << endl;

		else
		{
			copy(vecGraph.begin(), vecGraph.end(), ostream_iterator<int>(write, " "));
			write.close();
		}
	}
};

int main()
{

	Graph myGraph;

	myGraph.readGraph("input.txt");
	myGraph.writeGraph("output.txt");

	return 0;
}