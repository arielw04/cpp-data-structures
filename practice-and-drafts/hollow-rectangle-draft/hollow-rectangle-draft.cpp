#include <iostream>

using namespace std;

int main() {
	int h = 0;
	int w = 0;

	while (h <= 0 || w <= 0) {
		cout << "enter h, w split by space:";
		cin >> h >> w;
		if (h <= 0 || w <= 0) {
			cout << "ERROR: ENTER AGAIN";

		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || i == h - 1) {
				cout << "*"
			}else{
				if (j == 0 || j == w - 1){
					cout <<"*"
				}else{}
					cout << '';
			}
		}
		cout << endl;
	}
	return 0;
}