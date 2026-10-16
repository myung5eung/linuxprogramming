#include <iostream>
#include "Sphere.hpp"
using namespace std;
int main() {
	Sphere sph1; // 반지름=1로초기화
	cout << "구의부피는" << sph1.getVolume() << endl;
	Sphere sph2(3); // 반지름=3로초기화
	cout << "구의부피는" << sph2.getVolume() << endl;
	return 0;
}
