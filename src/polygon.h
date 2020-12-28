#ifndef POLYGON
#define POLYGON
#include "vector.h"
#include "bubbleSort.h"
#include "shape.h"


class PolygonFactory; // forward declaration, for friend class


class Polygon : public Shape {
private:
  int _numVertices;

  Vector * _vertices;


public:
  Polygon(Vector * input,int inputVerties){
    cout<<"polygon"<<endl;
      _numVertices = inputVerties;

      _vertices = new Vector(_numVertices);
      


      for (int i = 0; i < _numVertices; i++) {

        _vertices[i] = input[i];
      }
      cout<<"polygonEnd"<<endl;
  }
  friend class PolygonFactory;

  ~Polygon() override {
    cout << "Polygon deconstructor" << endl;
  }
  


  static Polygon CreatePolygon(Vector * input,int numVertices){
      Vector c = Vector::centroid(input, numVertices);
      Vector b = input[0] - c;
      angleComparator comp = angleComparator(c, b);
      //std::sort(input,input+numVertices,comp);
      bubbleSort(input,input+numVertices,comp);
      return Polygon(input,numVertices);
  }
  Polygon(){
    /// _numVertices = 0;
    _vertices = new Vector(_numVertices);
  }
  int getNumberOfVerties() const {
    return _numVertices;
  }
  double perimeter() const override {
    double perimeter = 0;
    for (int i = 0; i < _numVertices; i++) {
      perimeter += (_vertices[(i+1)%_numVertices] - _vertices[i]).length();
    }
    return perimeter;
  }
  double area() const override {
    cout<<"polygonarea"<<endl;

     double area = 0;
     cout <<_numVertices<<endl;
    for (int i  = 0; i < (_numVertices - 2); i++){
      
      area += getArea(_vertices[0], _vertices[i+1], _vertices[i+2]);
  }
    

    cout<<area<<endl;
    cout<<"polygonareaEnd"<<endl;
    return area;
  }
  Vector centroid(){
    Vector sum(2);
    for(int i=0;i<_numVertices;i++){
      sum.at(1) += _vertices[i].at(1);
      sum.at(2) += _vertices[i].at(2);
    }
    sum.at(1) /= _numVertices;
    sum.at(2) /= _numVertices;
    return sum;
  }
  void changeNameTo(string input) override {
    _name = input;
  }
  string toString(){
    stringstream ss;
    ss << "Polygon" << "{\n" << _name << "\n" << _numVertices <<"\n" <<"}";
  }
};

class PolygonFactory{
public:
  Polygon CreatePolygon(Vector vertices[], int num){
    Vector c = centroid(vertices, num);
    // try to make centrid as friend class :)
    Vector b = vertices[0] - c;
    angleComparator comp = angleComparator(c, b);
    bubbleSort(vertices,vertices+num,comp);
    return Polygon(vertices,num);
  }
};

class Triangle : public Polygon{
private:
  Vector _centrid;
public:
  Triangle(Vector *v) : Polygon(v,3){
    _centrid = this->centroid();
  }

  Vector getCentroid() const {
    return _centrid;
  }
};
#endif
