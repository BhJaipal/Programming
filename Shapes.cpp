#include <iostream>
#include <cmath>
using namespace std;

namespace ThreeD_Shapes {
    class Cuboid {
        public:
        int len;
        int brea;
        int hei;
        Cuboid(int len, int brea, int hei) {
            this->len = len;
            this->brea = brea;
            this->hei = hei;
        }
        double cubo_tsa() {
            return 2* (this->len*this->brea + this->brea*this->hei + this->hei*this->len);
        }
        double cubo_lsa() {
            return 2*(this->len + this->brea) *this->hei;
        }
        double cubo_vol() {
            return this->len*this->brea*this->hei;
        }
        double cubo_dia() {
            return sqrt(pow(this->len, 2) + pow(this->brea, 2) + pow(this->hei, 2));
        }
        void execute() {
            cout << "Total Surface area: ";
            cout << this->cubo_tsa() << endl;
            cout << "Lateral Surface area: ";
            cout << this->cubo_lsa() << endl;
            cout << "Volume: ";
            cout << this->cubo_vol() << endl;
            cout << "Length of Diagonal: ";
            cout << this->cubo_dia() << endl;
        }
    };

    class Cube {
        public:
        int side;
        Cube(int side) {
            this->side = side;
        }
        double cube_tsa() {
            return 6*this->side*this->side;
        }
        double cube_lsa() {
            return 4*this->side*this->side;
        }
        double cube_vol() {
            return pow(this->side, 3);
        }
        double cube_dia() {
            return this->side* 1.73;
        }
        void execute() {
            cout << "Total Surface area: ";
            cout << this->cube_tsa() << endl;
            cout << "Lateral Surface area: ";
            cout << this->cube_lsa() << endl;
            cout << "Volume: ";
            cout << this->cube_vol() << endl;
            cout << "Length of Diagonal: ";
            cout << this->cube_dia() << endl;
        }
    };

    class Sphere {
        public:
        int rad;
        Sphere(int rad) {
            this->rad = rad;
        }
        double sphere_sa() {
            return 4*22/7* this->rad*this->rad;
        }
        double sphere_volume() {
            return 4/3*22/7*pow(this->rad, 3);
        }
        void execute() {
            cout << "Surface area: ";
            cout << this->sphere_sa() << endl;
            cout << "Volume: ";
            cout << this->sphere_volume() << endl;
        }
    };

    class Cylinder {
        public:
        int radi;
        int heig;
        Cylinder(int radi, int heig) {
            this->radi = radi;
            this->heig = heig;
        }
        double cyl_tsa() {
            return 2*22/7* this->radi* (this->heig + this->radi);
        }
        double cyl_csa() {
            return 2*22/7* this->radi*this->heig;
        }
        double cyl_vol() {
            return 22/7* this->radi*this->radi*this->heig;
        }
        void execute() {
            cout << "Total Surface area: ";
            cout << this->cyl_tsa() << endl;
            cout << "Curved Surface area: ";
            cout << this->cyl_csa() << endl;
            cout << "Volume: ";
            cout << this->cyl_vol() << endl;
        }
    };
}
void main_execution() {
    while (true) {
        cout << "Select one:\n1.Sphere\n2.Cube\n3.Cuboid\n4.Cylinder\n5.Exit" << endl;
        cout << "Enter your choice(1-5): ";
        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            int radius;
            cout << "Enter radius: ";
            cin >> radius;
            ThreeD_Shapes::Sphere mySphere(radius);
            mySphere.execute();
        }

        else if (choice == 2) {
            int sides;
            cout << "Enter side: ";
            cin >> sides;
            ThreeD_Shapes::Cube mycube(sides);
            mycube.execute();
        }

        else if (choice == 3) {
            int length; cout << "Enter length: "; cin >> length;
            int breadth; cout << "Enter breadth: "; cin >> breadth;
            int height; cout << "Enter height: "; cin >> height;
            ThreeD_Shapes::Cuboid mycuboid(length, breadth, height);
            mycuboid.execute();
        }

        else if (choice == 4) {
            int radii; cout << "Enter radius: "; cin >> radii;
            int heigh; cout << "Enter height: "; cin >> heigh;
            ThreeD_Shapes::Cylinder mycylinder(radii, heigh);
            mycylinder.execute();
        }

        else if (choice == 5) {
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
        cout << endl;
        cout << "Do you want to continue[Yn]: ";
    char cont; cin >> cont;
    if (cont == 'n' || cont == 'N') {
        break;
    }
    cout << endl;
}
}
int main() {
    main_execution();
    return 0;
}