#include <memory>
#include <concepts>
#include <type_traits>
#include <iostream>

template <typename T>
concept Scalar = std::is_scalar_v<T>;

template <Scalar T>
class Point {
private:
    T x, y;

public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Point(Point&& other) noexcept : x(other.x), y(other.y) {
        other.x = 0;
        other.y = 0;
    }

    Point& operator=(Point&& other) noexcept {
        if (this != &other) {
            x = other.x;
            y = other.y;
            other.x = 0;
            other.y = 0;
        }
        return *this;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    T get_x() const { return x; }
    T get_y() const { return y; }
};
