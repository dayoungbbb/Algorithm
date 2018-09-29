
#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>
#define MONEY 20000
using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int sum = 0;
	for (int distance; !(ss >> distance).fail(); ) {
		// @todo Write your code here.
		int pay;
		
		if (distance <= 40) {
			pay = 720;
		}
		else {
			int dist = distance - 40;
			if ((dist % 8) == 0)
				pay = (80 * (dist / 8)) + 720;
			else
				pay = (80 * ((dist / 8) + 1)) + 720;
		}
		if ((MONEY - (sum + pay)) < 0) {
			break;
		}
		else {
			sum += pay;
		}

	}
	// @todo Write your code here.
	cout << MONEY - sum << endl;
	return 0;
}