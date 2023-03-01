#include <iostream>
using namespace std;

class Point {
    private:
        int id, x, y;
    public:
        Point () { id = 0; }
        Point (int ID, int a) { id = ID; x = a; y = a; }
        Point (int ID, int a, int b) { id = ID; x = a; y = b; }

        ~Point () {
            cout << "Ya se borró el punto " << id << endl;
        }

        void printPoint () {
            cout << "Las coordenadas son (" << x << "," << y << ")" << endl;
        }
};

class Segment {
    private:
        int id;
        Point A, B;
    public:
        Segment () { id = 0; }
        Segment (int ID, Point a, Point b) { id = ID; A = a; B = b; }

        ~Segment () {
            cout << "Ya se borró el segmento " << id << endl;
        }

        void printSegment () {
            cout << "El segmento va del punto ";
            A.printPoint();
            cout << " al punto ";
            B.printPoint();
            cout << endl;
        }
};

void point () {
    Point p3 (4, 1, 2);
    p3.printPoint();
}

int main () {
    Point ori (1, 0);
    Point p1 (2, 1);
    Point p2 (3, 2, 5);

    p2.printPoint();
    point();
    ori.printPoint();

    Segment s1 (5, ori, p1);
    Segment s2 (6, p1, p2);

    s2.printSegment();
}