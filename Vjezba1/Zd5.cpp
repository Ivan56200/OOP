/*Definirajte strukturu Point s koordinatama x i y (double).
◦ Napišite funkcije void move_by(Point* p, double dx, double dy) i double dist(
const Point* a, const Point* b) kao u C-u, pomoću pointera.
◦ Iste funkcije napišite pomoću referenci. Usporedite pozive u main funkciji.
◦ Za niz od pet točaka pronađite točku najbližu ishodištu.
Napomena: std::sqrt se nalazi u #include <cmath>.*/

#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return std::sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point a{ 3.0, 4.0 };
    Point b{ 0.0, 0.0 };

    move_by(&a, 1.0, -1.0); 
    double d1 = dist(&a, &b);
    std::cout << "Pointer: d = " << d1 << '\n';

    a = { 3.0, 4.0 }; 
    move_by(a, 1.0, -1.0);
    double d2 = dist(a, b);
    std::cout << "Referenca: d = " << d2 << '\n';

    Point niz[5] = {{0, 2},
    {3, 5},
    {6, 9},
    {-1, 0},
    {4, 2}
    };

    Point ishodiste{ 0, 0 };
    int najbliza = 0;

    for (int i = 1; i < 5; i++) {
        if (dist(&niz[i], &ishodiste) < dist(&niz[najbliza], &ishodiste)) {
            najbliza = i;
        }
    }

    std::cout << "Najbliza tocka: " << niz[najbliza].x << ", " << niz[najbliza].y << "\n";

    return 0;
}