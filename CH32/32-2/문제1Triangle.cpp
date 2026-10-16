#include <iostream>
#include "Triangle.hpp"
using namespace std;
Triangle::Triangle() : Triangle(1, 1) {}
Triangle::Triangle(int w, int h) : width(w), height(h)
{
	cout << "밑변" << width << "높이" << height << "인 삼각형 생성\n";
}
Triangle::~Triangle()
{
	cout << "밑변" << width << "높이" << height << "인 삼각형 소멸\n";
}
double Triangle::getArea()
{
	return (1.0 / 2.0) * width * height;
}
