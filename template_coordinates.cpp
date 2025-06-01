#include <iostream>
using namespace std;

template <typename T>
class TwoDim {
protected:
    T x, y;

public:
    TwoDim() : x(0), y(0) {}
    TwoDim(T xVal, T yVal) : x(xVal), y(yVal) {}

    virtual void print() {
        cout << "2D Coordinates: (" << x << ", " << y << ")" << endl;
    }

    virtual ~TwoDim() {}
};

template <typename T>
class ThreeDim : public TwoDim<T> {
    T z;

public:
    ThreeDim() : TwoDim<T>(), z(0) {}
    ThreeDim(T xVal, T yVal, T zVal) : TwoDim<T>(xVal, yVal), z(zVal) {}

    void print() override {
        cout << "3D Coordinates: (" << this->x << ", " << this->y << ", " << z << ")" << endl;
    }
};

int main() {
    TwoDim<int>* ptr;

    TwoDim<int> point2D(10, 20);
    ThreeDim<int> point3D(10, 20, 30);

    ptr = &point2D;
    ptr->print();

    ptr = &point3D;
    ptr->print();

    return 0;
}
