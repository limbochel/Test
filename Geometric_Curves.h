#include <math.h>

#define  M_PI
#pragma once
struct Point3D { double x{}, y{}, z{}; };
struct Vector3D { double x{}, y{}, z{}; };

class Geometric_Curves
{
protected:
	Point3D point;
	
public:
	double a,b,x0,y0;
	virtual double get_a() { return a; }
	virtual double get_b() { return b; }
	virtual double get_x0() { return x0; }
	virtual double get_y0() { return y0; }
	virtual Point3D Get_Point(double t) = 0;
	virtual Vector3D Get_vector(double t) const = 0;
	
	const double PI = 3.141592653589793;
};

class Circle : public Geometric_Curves {
public:
	double get_a() { return a; }
	double get_b() { return b; }
	double get_x0() { return x0; }
	double get_y0() { return y0; }
	Circle(double x0 = 0, double y0 = 0, double a = 0) {
		this->x0 = x0;
		this->y0 = y0;
		this->a = a;
		b = 0;
	}
	virtual Vector3D Get_vector(double t) const override
	{
		return Vector3D
		{
			-1 * a * sin(t),
			a * cos(t)
		};
	}
	Point3D Get_Point(double t) override{
		
		point.x = x0 + a * cos(t);
		point.y = y0 + a * sin(t);
		return point;
	}
};

class Ellipse : public Geometric_Curves {
public:
	
	Ellipse(float x0 = 0, float y0 = 0, float a = 0, float b = 0) {

		this->x0 = x0;
		this->y0 = y0;
		this->a = a;
		this->b = b;
	}
	~Ellipse(){

	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_x0() { return x0; }
	double get_y0() { return y0; }
	Point3D Get_Point(double t) override {
		
		point.x = x0 + a * cos(t);
		point.y = y0 + b * sin(t);
		return point;
	}
	virtual Vector3D Get_vector(double t) const override
	{
		return Vector3D
		{
			-1 * a * sin(t),
			b * cos(t)
		};
	}
};

class Helix : public Geometric_Curves {
public:
	double get_a() { return a; }
	double get_b() { return b; }
	double get_x0() { return x0; }
	double get_y0() { return y0; }
	Helix(double x0 = 0, double y0 = 0, double a = 0, double b = 0) {
		this->x0 = x0;
		this->y0 = y0;
		this->a = a;
		this->b = b;
	}
	Point3D Get_Point(double t) override {
		
		point.x = x0 + a * cos(t);
		point.y = y0 + b * sin(t);
		point.z = b * t;
		return point;
	}
	virtual Vector3D Get_vector(double t) const override
	{
		return Vector3D
		{
			a * (cos(t) - t * sin(t)),
			a * (sin(t) + t * cos(t)),
			b
		};
	}
};
