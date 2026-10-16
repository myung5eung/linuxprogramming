#include <iostream>
#include "Sphere.hpp"
using namespace std;
Sphere::Sphere() :Sphere(1) {}
Sphere::Sphere(int a) : rad(a)
{
	cout << "반지름" << rad << "인 구 생성\n";
}
Sphere::~Sphere()
{
	cout << "반지름" << rad << "인 구 소멸\n";
}
double Sphere::getVolume()
{
	return (4.0 / 3.0) * 3.141592 * rad * rad * rad;
}
