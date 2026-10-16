
#ifndef TRIANGLE_H
#define  TRIANGLE_H
class Triangle
{
public:
	int width, height;
	Triangle();
	Triangle(int w, int h);
	~Triangle();
	double getArea();
};

#endif
