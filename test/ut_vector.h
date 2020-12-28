#include "../src/vector.h"
#include "../src/bubbleSort.h"
#include "../src/polygon.h"
#include "../src/circle.h"
#include "../src/shape.h"
#include <cmath>

double const epsilon = 0.0001;

TEST(ShapeTest, Polygon){
  double a[]={0, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  double b[]={2, 0};
  double f[]={3, 1};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector y(e, 2);
  Vector z(f, 2);
  Vector arr[] = {u, v, w, x, y, z};
  Polygon * poly = new Polygon( arr,6);
  ASSERT_NEAR(6, poly->area(), epsilon);
  ASSERT_NEAR(4 + 4 * sqrt(2), poly->perimeter(), epsilon);

}

TEST(ShapeTest, Circle){
  Circle * c = new Circle(6);
  ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
  ASSERT_NEAR(12 * M_PI, c->perimeter(), epsilon);
}

TEST(ShapeTest, Shape){
  Shape * c = new Circle(6);
  cout <<"here";
  double circle_area = c->area();
  ASSERT_NEAR(6 * 6 * M_PI, circle_area, epsilon);
  cout<<"here2"<<endl;
  double a[]={0, 0};
  double b[]={0, 2};
  double d[]={2, 0};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector arr[] = {u, v, w};
  
  Polygon * poly = new Polygon(arr, 3);
  double poly_area = poly->area();
  //ASSERT_NEAR(2, poly_area, epsilon);
}
