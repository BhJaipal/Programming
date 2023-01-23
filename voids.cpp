# include <iostream>
# include <cmath>
using namespace std;

const double pi=3.14;

double sphere_volume(double radius) {
    return 4/3 * pi * radius*radius*radius;}
    /* Volume of sphere= 4/3 * pi * (radius)^3
    */

double sphere_area(double radius) {
    return 4 * pi * radius*radius;}
    /* Surface area of sphere= 4*pi* (radius)^2
    */

double cuboid_tsa(double len, double breadth, double height) {
    return 2*(len*height + breadth*height + breadth* len);}
    /* Total Surface area of Cuboid = 
    *                     2 * (l*b + b*h + l*h)
    */

double cuboid_lsa(double len, double breadth, double height) {
    return 2 * height * (len + breadth);}
    /* Lateral Surface area of Cuboid = 
    *                     2 * (l + b) *h
    */

double cube_volume(double side) {
    return pow(side, 3);}
    /* Volume of Cube = a ^ 3
    */

double cube_tsa(double side) {
    return 6* pow(side,2);}
    /* Total Surface area of Cube = 6 * a^2
    */

double cube_lsa(double side) {
    return 4* pow(side,2);}
    /* Lateral Surface area of Cube = 4 * a^2
    */

double cuboid_volume(double len, double breadth, double height) {
    return len*breadth*height;}
    /* Volume of Cuboid = l*b*h
    */

double cuboid_diagonal(double len, double breadth, double height) {
    return pow((pow(len,2) + pow(breadth,2) +  pow(height,2)), 1/2);}
    /* Diagonal of Cuboid = square root of (l^2 + b^2 + h^2)
    */

double cube_diagonal(double side) {
    return side* pow(3, 1/2);}
    /* Diagonal of Cube = a * root(3)
    */

double cylinder_tsa(double radius, double height) {
    return 2*pi* radius *(height + radius);}
    /* Total Surface area of Cylinder = 2*pi*radius *(height + radius)
    */

double cylinder_csa(double radius, double height) {
    return 2*pi* radius*height;}
    /* Curved Surface area of Cylinder = 2*pi * radius *height
    */

double cylinder_volume(double radius, double height) {
    return pi* pow(radius, 2)* height;}
    /* Volume of Cylinder = pi * (radius)^2 * height
    */

void Cube(double side) {
    cout << "********* Cube *********" << endl;
    cout << "Total Surface area: " << cube_tsa(side) << endl;
    cout << "Lateral Surface area: " <<  cube_lsa(side) << endl;
    cout << "Volume: " << cube_volume(side) << endl;
    cout << "Length of Diagonal: " <<  cube_diagonal(side) << endl;
    cout << "************************" << endl;
}

void Cuboid(double len, double breadth, double height) {
    cout << "********* Cuboid *********" << endl;
    cout << "Total Surface area: " << cuboid_tsa(len, breadth, height) << endl;
    cout << "Lateral Surface area: " << cuboid_lsa(len, breadth, height) << endl;
    cout << "Volume: " << cuboid_volume(len, breadth, height) << endl;
    cout << "Length of Diagonal: " << cuboid_diagonal(len, breadth, height) << endl;
    cout << "**************************" << endl;
}

void Cylinder(double radius, double height) {
    cout << "********* Cylinder *********" << endl;
    cout << "Total Surface area: " << cylinder_tsa(radius, height) << endl;
    cout << "Curved Surface area: " << cylinder_csa(radius, height) << endl;
    cout << "Volume: " << cylinder_volume(radius, height) << endl;
    cout << "****************************" << endl;
}
void Sphere(double radius) {
    cout << "********* Sphere *********" << endl;
    cout << "Surface area: " << sphere_area(radius) << endl;
    cout << "Volume: " << sphere_volume(radius) << endl;
    cout << "**************************" << endl;
}

void three_d_shapes() {
    while (true) {
        int choice;
        cout << "Choose any one \n1. Sphere " << endl << "2. Cube" << endl << "3. Cuboid" << endl << "4. Cylinder" << endl << "Enter your choice number: ";
        cin >> choice;
        if (choice == 1) {
            double rad;
            cout << "Enter radius: ";
            cin >> rad; Sphere(rad);}
            
        else if (choice == 2) {
            double side;
            cout << "Enter side: ";
            cin >> side; Cube(side);}
            
        else if (choice == 3) {
            double length, bre, hei;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter breadth: ";
            cin >> bre;
            cout << "Enter height: ";
            cin >> hei;
            Cuboid(length, bre, hei);}
        
        else if (choice == 4) {
            double radi, heig;
            cout << "Enter radius: ";
            cin >> radi;
            cout << "Enter height: ";
            cin >> heig;
            Cylinder(radi, heig);}
        else
            {cout << "Currently cone is unavailable" << endl;}
        char cont;
        cout << "Do you want to continue? [Yn]: ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') 
        {break;}
    }
}

int main() {
    three_d_shapes();
    return 0;
}