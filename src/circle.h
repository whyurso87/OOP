#ifndef CIRCLE
#define CIRCLE
#include <cmath>
#include "shape.h"
#include "vector.h"
#include<string>

using namespace std;

// Dervied class of shape class
// Circle inherets Shape
class Circle : public Shape {
private:
  double _radius;
  Vector _point;
public:
  Circle() : _radius(0){
    cout << "Constructor in circle" << endl;
    _point = Vector();
  //  _radius = 0;
  }
  Circle(double radius, Vector point, string name) : Shape(name){ //constructor initialization list
    _radius = radius;
    _point = point;
  }
  Circle(double radius){ //constructor initialization list
    _radius = radius;

  }

  ~Circle() override {
    cout << "Circle deconstructor" << endl;
  }

  double perimeter() const override {
    return 2*_radius*M_PI;
  }
  double area() const override {
    cout <<"123"<<endl;
    cout<< _radius<<endl;
    cout<<M_PI<<endl;
    cout<<_radius*_radius*M_PI<<endl;
    return _radius*_radius*M_PI;
  }
  void changeNameTo(string input) override {
    _name = input;
  }

};

#endif
