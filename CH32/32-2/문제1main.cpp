
#include <iostream>
#include "Triangle.hpp"
using namespace std;

int main() {
	Triangle tri1; //밑변,높이 1로 초기화
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
	Triangle tri2(2, 4); //밑변=2,높이=4로 초기화
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	return 0;
}
