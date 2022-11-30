#include <iostream>
#include <vector>
#include <string>
class Object {
private:
    std::vector <int> sides;
    std::vector <int> corners;
    std::string name;
public:
    Object(): name("Object") {}
    int get_corner_one() const { return corners[0]; }
    int get_corner_two() const { return corners[1]; }
    int get_corner_three() const { return corners[2]; }
    int get_corner_four() const { return corners[3]; }
    int get_side_one() const { return sides[0]; }
    int get_side_two() const { return sides[1]; }
    int get_side_three() const { return sides[2]; }
    int get_side_four() const { return sides[3]; }
    std::string get_name() const { return name; }
    int get_count_sides() const { return sides.size(); }
    virtual void print() {
        std::cout << get_name() << ":\n" << std::boolalpha << check_object() << '\n' <<
            "Number of sides: " << get_count_sides() << '\n';
    }
protected:
    virtual bool check_object() {
        if (sides.size() >= 0) {
            return true;
        }
        return false;
    }
    void set_sides(int side) { sides.push_back(side); }
    void set_corners(int corner) { corners.push_back(corner); }
    void set_name(std::string name) { this->name = name; }
};

class TriangleDefault : public Object {
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

    void print() override {
        Object::print();
        std::cout << "Sides: a=" << get_side_one() << " b=" << get_side_two() << " c=" << get_side_three() << '\n' <<
            "Corners: A=" << get_corner_one() << " B=" << get_corner_two() << " C=" << get_corner_three() << '\n' ;
    }

protected:
    bool check_sides()  {
        if (get_count_sides() == 3)
            return true;
        return false;
    }

    bool check_leght_sum() {
        if (get_side_one() + get_side_two() >= get_side_three() ||
            get_side_one() + get_side_three() >= get_side_two() || get_side_two() + get_side_three() >= get_side_one())
            return true;
        return false;
    }

    bool check_corner_sum() {
        if (get_corner_one() + get_corner_two() + get_corner_three() == 180)
            return true;
        return false;
    }
    bool check_object() override {
        if (check_sides() && check_corner_sum() && check_leght_sum())
            return true;
        return false;
    }
};

class TriangleRight : public TriangleDefault {
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
    bool check_object() override {
        if (TriangleDefault::check_object() && (get_corner_one() == 90 ||
            get_corner_two() == 90 || get_corner_three() == 90))
            return true;
        return false;
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
    bool check_object() override {
        if (TriangleDefault::check_object() && (get_side_one() == get_side_two() ||
            get_side_one() == get_side_three() || get_side_three() == get_side_two()))
            return true;
        return false;
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

    bool check_object() override {
        if (TriangleDefault::check_object() &&
            (get_side_one() == get_side_two() && get_side_two() == get_side_three()))
            return true;
        return false;
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

    void print() override {
        Object::print();
        std::cout << "Sides: a=" << get_side_one() << " b=" << get_side_two() << " c=" << get_side_three() <<
           " d="<<get_side_four() << '\n' << "Corners: A=" << get_corner_one() << " B=" << get_corner_two() <<
           " C=" << get_corner_three() << " D=" << get_corner_four() << '\n';
    }

protected:
    bool check_sides() {
        if (get_count_sides() == 4)
            return true;
        return false;
    }

    bool check_leght_sum() {
        if (get_side_one() <= get_side_two() + get_side_three() + get_side_four() ||
            get_side_two() <= get_side_one() + get_side_three() + get_side_four() ||
            get_side_three() <= get_side_one() + get_side_two() + get_side_four() ||
            get_side_four() <= get_side_one() + get_side_two() + get_side_three())
            return true;
        return false;
    }

    bool check_corners_sum() {
        if (get_corner_one() + get_corner_two() + get_corner_three() + get_corner_four() == 360)
            return true;
        return false;
    }
    
    bool check_object() override {
        if (check_sides() && check_leght_sum() && check_corners_sum())
            return true;
        return false;
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

protected:
    bool check_object() override {
        if (QuadrilateralDefault::check_object() && (get_corner_one() == 90 &&
            get_corner_two() == 90 && get_corner_three() == 90 && get_corner_four() == 90))
            return true;
        return false;
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

protected:
    bool check_object() override {
        if (QuadrilateralDefault::check_object() && (get_corner_one() == 90 &&
            get_corner_two() == 90 && get_corner_three() == 90 && get_corner_four() == 90) &&
            (get_side_one() == get_side_two() && get_side_two() == get_side_three() && 
            get_side_three() == get_side_four()))
            return true;
        return false;
    }
};

class Parallelogram : public QuadrilateralDefault {
public:
    Parallelogram() = default;
    Parallelogram(int i) {
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
protected:
    bool check_object() override {
        if (QuadrilateralDefault::check_object() && (get_side_one() == get_side_three() &&
            get_side_two() == get_side_four()) && (get_corner_one() + get_corner_two() == 180 &&
            get_corner_three() + get_corner_four() == 180))
            return true;
        return false;
    }
};

class Rhomb :public Parallelogram {
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

protected:
    bool check_object() override {
        if (Parallelogram::check_object() && (get_side_one() == get_side_two() && get_side_two() == get_side_three() &&
            get_side_three() == get_side_four()))
            return true;
        return false;
    }
};

template <typename T>
void print(Object* o, T &x) {
    o = &x;
    o->print();
    std::cout << '\n';
}

int main() {
    Object obj;
    Object* o = &obj;
    TriangleDefault td{1};
    TriangleRight tr;
    TriangleEquilateral te;
    TriangleIsosceles ti;
    QuadrilateralDefault qd{1};
    Rectangle rec;
    Square sq;
    Parallelogram para{1};
    Rhomb rh;
    
    print(o, obj);
    print(o, td);
    print(o, tr);
    print(o, te);
    print(o, ti);
    print(o, qd);
    print(o, rec);
    print(o, sq);
    print(o, para);
    print(o, rh);
    return 0;
}