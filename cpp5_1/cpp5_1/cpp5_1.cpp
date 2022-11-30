#include <iostream>
#include <string>

class Object {
protected:
    int sides;
    std::string name;
public:
    Object(): sides(0), name("Object") {}
    int get_sides() const { return sides; }
    std::string get_name() const { return name; }
};

class Triangle: public Object {
public:
    Triangle() { sides = 3; name = "Triangle"; }
};

class Quadrilateral : public Object {
public:
    Quadrilateral() { sides = 4; name = "Quadrilateral"; }
};

int main()
{
    Object obj;
    Triangle tri;
    Quadrilateral quadr;
    std::cout << "Number of sides:\n" <<
        obj.get_name() << ": " << obj.get_sides() << '\n' <<
        tri.get_name() << ": " << tri.get_sides() << '\n' <<
        quadr.get_name() << ": " << quadr.get_sides() << '\n';
    return 0;
}
