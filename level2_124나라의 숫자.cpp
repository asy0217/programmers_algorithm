#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	for (int i = 0; i < 7; i++) {
		cout << i;
		if (i == 3) { break; }
	}
	return 0;
}