#include <iostream>
#include <vector>
#include <string>
class Object {
private:
    std::vector <int> sides;
    std::vector <int> corners;
    std::string name;
public:
    Object() = default;
    int get_corner_one() const { return corners[0]; }
    int get_corner_two() const { return corners[1]; }
    int get_corner_three() const { return corners[2]; }
    int get_corner_four() const { return corners[3]; }
    int get_side_one() const { return sides[0]; }
    int get_side_two() const { return sides[1]; }
    int get_side_three() const { return sides[2]; }
    int get_side_four() const { return sides[3]; }
    std::string get_name() const { return name; }
protected:
    void set_sides(int side) { sides.push_back(side); }
    void set_corners(int corner) { corners.push_back(corner); }
    void set_name(std::string name) { this->name = name; }
};

class TriangleDefault: public Object{
public:
    TriangleDefault() = default;
    TriangleDefault(int i) {
        set_sides(10);
        set_sides(20);
        set_sides(30);
        set_corners(50);
        set_corners(60);
        set_corners(70);
        set_name("Triangle Default");
    }
    friend std::ostream& operator<< (std::ostream& out, TriangleDefault& a) {
        out << a.get_name() << ":" << '\n' <<
            "Sides: a=" << a.get_side_one() << " b=" << a.get_side_two() <<
            " c=" << a.get_side_three() << '\n' <<
            "Corners: A=" << a.get_corner_one() << " B=" << a.get_corner_two() <<
            " C=" << a.get_corner_three() << '\n';
        return out;
    }
};

class TriangleRight: public TriangleDefault {
public:
    TriangleRight() {
        set_sides(10);
        set_sides(20);
        set_sides(30);
        set_corners(50);
        set_corners(60);
        set_corners(90);
        set_name("Triangle Right");
    }
};

class TriangleIsosceles : public TriangleDefault {
public:
    TriangleIsosceles() {
        set_sides(10);
        set_sides(20);
        set_sides(10);
        set_corners(50);
        set_corners(60);
        set_corners(50);
        set_name("Triangle Isosceles");
    }
};

class TriangleEquilateral : public TriangleDefault {
public:
    TriangleEquilateral() {
        set_sides(30);
        set_sides(30);
        set_sides(30);
        set_corners(60);
        set_corners(60);
        set_corners(60);
        set_name("Triangle Equilateral");
    }
};

class QuadrilateralDefault : public Object {
public:
    QuadrilateralDefault() = default;
    QuadrilateralDefault(int i) {
        set_sides(10);
        set_sides(20);
        set_sides(30);
        set_sides(40);
        set_corners(50);
        set_corners(60);
        set_corners(70);
        set_corners(80);
        set_name("Quadrilateral Default");
    }
    friend std::ostream& operator<< (std::ostream& out, QuadrilateralDefault& a) {
        out << a.get_name() << ":" << '\n' <<
            "Sides: a=" << a.get_side_one() << " b=" << a.get_side_two() <<
            " c=" << a.get_side_three() << " d=" << a.get_side_four() << '\n' <<
            "Corners: A=" << a.get_corner_one() << " B=" << a.get_corner_two() <<
            " C=" << a.get_corner_three() << " D=" << a.get_corner_four() << '\n';
        return out;
    }
};

class Rectangle : public QuadrilateralDefault {
public:
    Rectangle() {
        set_sides(10);
        set_sides(20);
        set_sides(10);
        set_sides(20);
        set_corners(90);
        set_corners(90);
        set_corners(90);
        set_corners(90);
        set_name("Rectangle");
    }
};

class Square : public QuadrilateralDefault {
public:
    Square() {
        set_sides(20);
        set_sides(20);
        set_sides(20);
        set_sides(20);
        set_corners(90);
        set_corners(90);
        set_corners(90);
        set_corners(90);
        set_name("Square");
    }
};

class Parallelogram : public QuadrilateralDefault {
public:
    Parallelogram() {
        set_sides(20);
        set_sides(30);
        set_sides(20);
        set_sides(30);
        set_corners(30);
        set_corners(40);
        set_corners(30);
        set_corners(40);
        set_name("Parallelogram");
    }
};

class Rhomb :public QuadrilateralDefault {
public:
    Rhomb() {
        set_sides(30);
        set_sides(30);
        set_sides(30);
        set_sides(30);
        set_corners(30);
        set_corners(40);
        set_corners(30);
        set_corners(40);
        set_name("Rhomb");
    }
};

template<typename T>
void print(T a) {
    std::cout << a << '\n';
}

int main()
{
    TriangleDefault td = 1;
    TriangleRight tr;
    TriangleIsosceles ti;
    TriangleEquilateral te;
    QuadrilateralDefault  qd= 1;
    Rectangle rc;
    Square sq;
    Parallelogram pr;
    Rhomb rh;
    print(td);
    print(tr);
    print(ti);
    print(te);
    print(qd);
    print(rc);
    print(sq);
    print(pr);
    print(rh);
    return 0;
}