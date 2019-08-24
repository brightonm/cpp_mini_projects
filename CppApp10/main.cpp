#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <algorithm>

/*Friend classes, Structs, Polymorphism, Abstract Classes, Virtual, Override & Final*/

// Classes have default private fields and methods
// while structs have public
// Structs are used to model new data types, while
// classes model more complex real world objects
struct Shape{
    // Variables are public by default
    double length, width;
    
    // Constructors are public by default
    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }
    
    // Structs can contain functions
    double Area(){
        return length * width;
    }
    
    // Structs can contain private members
private:
    int id;
};

// You can inherit from a struct
struct Circle : Shape{
    // Override the constructor
    // You also use this with structs
    Circle(double width){
        this->width = width;
    }
    
    // Override Area()
    double Area(){
        return 3.14159 * std::pow((width / 2), 2);
    }
};

// Private members of a class are not accessable
// to outside code unless a class is marked as
// a friend
class Customer{
private:
    friend class GetCustomerData;
    std::string name; 
public:
    Customer(std::string name){
        this->name = name;
    }
};
 
class GetCustomerData{
public:
    static std::string GetName(Customer& customer){
        return customer.name;
    }
};

// Polymorphism is a feature in which similar 
// objects can be treated the same, but also
// utilize their differences automatically
// for any methods marked as virtual
 
class Shape2{
protected:
    double height;
    double width;
public:
    // Assume that if only 1 value is passed
    // that height and width are equal
    Shape2(double length){
        height = length;
        width = length;
    }
    Shape2(double h, double w){
        height = h;
        width = w;
    }
    virtual double Area2(){
        return height * width;
    }
};
 
class Circle2 : public Shape2{
public:
    Circle2(double w) :
    Shape2(w){
 
    }
    
    // Override Area()
    double Area2(){
        return 3.14159 * std::pow((width / 2), 2);
    }
};
 
// This function receives Shapes but uses the 
// correct Area() automatically
void ShowArea(Shape2& shape){
    std::cout << "Area : " << shape.Area2() << "\n";
}

// Shape here has no purpose except for
// being able to to group similar objects
// so it should be instead an Abstract
// Class
 
class Shape3{
public:
    virtual double Area3() = 0;
};
 
class Circle3 : public Shape3{
protected:
    double width;
public:
    Circle3(double w){
        width = w;
    }
    
    // Override Area()
    // You should use override to force the
    // compiler to check if the base class
    // virtual fucntion is the same as
    // the subclass
    double Area3() override{
        return 3.14159 * std::pow((width / 2), 2);
    }
};
 
class Rectangle3 : public Shape3{
protected:
    double height, width;
public:
    Rectangle3(double h, double w){
        height = h;
        width = w;
    }
    // Override Area()
    // Marking a method as final means
    // that subclasses that inherit from
    // Rectangle can't override Area()
    double Area3() override final{
        return height * width;
    }
};
 
class Square3 : public Rectangle3{
public:
    Square3(double h, double w) :
    Rectangle3(h,w){
        
    }
    
    /* This would trigger an error
    double Area() override{
        return height * 2;
    }
    */
};
 
// This function receives Shapes but uses the 
// correct Area() automatically
void ShowArea3(Shape3& shape){
    std::cout << "Area : " << shape.Area3() << "\n";
}


int main(int argc, char** argv) {
    
    // Create a struct
    Shape shape(10, 10);
    
    // Call a Struct function
    std::cout << "Square Area : " << shape.Area() 
            << "\n";
    
    // Create a struct
    Circle circle(10);
    
    // Call a Struct function
    std::cout << "Circle Area : " << circle.Area() 
            << "\n";
    
    // You can initialize a struct or class using
    // an aggregate
    Shape rectangle{10,15};
    std::cout << "Rectangle Area : " << 
            rectangle.Area() << "\n";
    
    Customer tom("Tom");
    GetCustomerData getName;
    std::cout << "Name : " << 
            getName.GetName(tom) << "\n";
    
    Shape2 square(10,5);
    Circle2 circle2(10);
    ShowArea(square);
    ShowArea(circle2);
    
    Rectangle3 rectangle3(10,5);
    Circle3 circle3(10);
    ShowArea3(rectangle3);
    ShowArea3(circle3);
    
    Square3 square3(10,10);
    ShowArea3(square3);
    
    
    return 0;
}

