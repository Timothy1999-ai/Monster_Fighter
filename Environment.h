#include <string>

class Environment()
{
public:
	string battlefield();
	string getEnvironment();
	Environment();
};

string Environment getEnvironment()
{
	cout << "Choose the Battlefield! " << endl;
	cout << "The options are:" << endl;
	cout << "1 - Wolfsbane Field" << endl;
	cout << "2 - Sunny Beach" << endl;
	cout << "3 - Wax Museum" << endl;
	cout << "4 - Disease Research Lab" << endl;
	cout << "5 - Eye of a Hurricane" << endl;
	cout << "6 - Space Spation" << endl;

}
