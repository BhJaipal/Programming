# include <iostream>
# include <cmath>
using namespace std;

const double pi= 22/7;

class Sphere {
    public:
    double radius;
    double sphere_volume(double radius) {
        return 4/3 * pi * radius*radius*radius;}
        /* Volume of sphere= 4/3 * pi * (radius)^3
        */

    double sphere_area(double radius) {
        return 4 * pi * radius*radius;}
        /* Surface area of sphere= 4*pi* (radius)^2
        */
    void exec() {
    cout << "********* Sphere **********" << endl;
    cout << "Surface area: " << sphere_area(radius) << endl;
    cout << "Volume: " << sphere_volume(radius) << endl;
    cout << "**************************" << endl;
    }
};

class Cube {
    public:
    double side;
    double cube_volume(double side) {
        return pow(side, 3);}
        /* Volume of Cube = a ^ 3
        */

    double cube_tsa(double side) {
        return 6* pow(side,2);}
        /* Total Surface area of Cube = 
                                    6 * a^2
        */

    double cube_diagonal(double side) {
        return side* sqrt(3);}
        /* Diagonal of Cube = a * root(3)
        */

    double cube_lsa(double side) {
        return 4* pow(side,2);}
        /* Lateral Surface area of Cube = 
                                    4 * a^2
        */
    void exec() {
    cout << "********* Cube *********" << endl;
    cout << "Total Surface area: " << cube_tsa(side) << endl;
    cout << "Lateral Surface area: " <<  cube_lsa(side) << endl;
    cout << "Volume: " << cube_volume(side) << endl;
    cout << "Length of Diagonal: " <<  cube_diagonal(side) << endl;
    cout << "************************" <<endl;
    }
};

class Cuboid {
    public:
    double len; double breadth; double height;
    double cuboid_volume(double len, double breadth, double height){
        return len*breadth*height;}
        /* Volume of Cuboid = l*b*h
        */

    double cuboid_diagonal(double len, double breadth, double height)
        {return sqrt((pow(len,2) + pow(breadth,2) +  pow(height,2)));}
        /* Diagonal of Cuboid = 
            square root of (l^2 + b^2 + h^2)
        */

    double cuboid_tsa(double len, double breadth, double height) {
        return 2*(len*height + breadth*height + breadth* len);}
        /* Total Surface area of Cuboid = 
                       2 * (l*b + b*h + l*h)
        */

    double cuboid_lsa(double len, double breadth, double height) {
        return 2 * height * (len + breadth);}
        /* Lateral Surface area of Cuboid = 
                             2 * (l + b) *h
        */
    void exec() {
    cout << "********* Cuboid *********" << endl;
    cout << "Total Surface area: " << cuboid_tsa(len, breadth, height) << endl;
    cout << "Lateral Surface area: " << cuboid_lsa(len, breadth, height) << endl;
    cout << "Volume: " << cuboid_volume(len, breadth, height) << endl;
    cout << "Length of Diagonal: " << cuboid_diagonal(len, breadth, height) << endl;
    cout << "**************************" << endl;
    }
};

class Cylinder {
    public:
    double radius; double height;
    float cylinder_tsa(double radius, double height) {
        return 2*pi*radius*(height + radius);}
        /* Total Surface area of Cylinder = 
                2*pi*radius *(height + radius)
        */

    float cylinder_csa(double radius, double height) {
        return 2*pi* radius*height;}
        /* Curved Surface area of Cylinder = 
                        2*pi * radius *height
        */

    float cylinder_volume(double radius, double height) {
        return pi* pow(radius, 2)* height;}
        /* Volume of Cylinder = 
                    pi * (radius)^2 * height
        */
    void exec() {
    cout << "********* Cylinder **********" << endl;
    cout << "Total Surface area: " << cylinder_tsa(radius, height) << endl;
    cout << "Curved Surface area: " << cylinder_csa(radius, height) << endl;
    cout << "Volume: " << cylinder_volume(radius, height) << endl;
    cout << "****************************" << endl;
    }
};

void three_d_shapes() {
    while (true) {
        int choice;
        cout << "Choose any one: \n1. Sphere " << endl << "2. Cube" << endl << "3. Cuboid" << endl << "4. Cylinder" << endl << "Enter your choice number: ";
        cin >> choice;
        if (choice == 1) {
            double rad;
            cout << "Enter radius: ";
            cin >> rad;
            Sphere mySphere;
            mySphere.radius= rad;
            cout << endl;
            mySphere.exec();
        }
            
        else if (choice == 2) {
            double side;
            cout << "Enter side: ";
            cin >> side;
            Cube mycube;
            mycube.side= side;
            cout << endl;
            mycube.exec();
        }
            
        else if (choice == 3) {
            double length, bre, hei;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter breadth: ";
            cin >> bre;
            cout << "Enter height: ";
            cin >> hei;
            Cuboid myCuboid;
            myCuboid.len= length;
            myCuboid.breadth= bre;
            myCuboid.height= hei;
            cout << endl;
            myCuboid.exec();
        }
        
        else if (choice == 4) {
            double radi, heig;
            cout << "Enter radius: ";
            cin >> radi;
            cout << "Enter height: ";
            cin >> heig;
            Cylinder myCylinder;
            myCylinder.radius= radi;
            myCylinder.height= heig;
            cout << endl;
            myCylinder.exec();
        }
        
        else {
            cout << "Currently cone is unavailable" << endl;
        }
        char cont;
        cout << "Do you want to continue? [Yn]: ";
        cin >> cont;
        cout << endl;
        if (cont == 'n' || cont == 'N') 
        {break;}
    }
}

int main() {
    three_d_shapes();
    return 0;
}