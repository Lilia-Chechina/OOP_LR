#pragma once
#include <string>
#include <iostream>
#include <utility>
#include <cmath>

class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> center() const = 0;
    virtual double area() const = 0;
    virtual explicit operator double() const = 0;      
};

class Square : public Figure {
public:
    Square();
    Square(double x[4], double y[4]);
    ~Square();
    bool operator==(Square &other) const;
    Square &operator=(Square &other);
    Square &operator=(Square &&other);
    friend std::ostream &operator<<(std::ostream& os, const Square&);
    friend std::istream &operator>>(std::istream& is, Square&);

    double area() const override {
        return surface;
    }

    std::pair<double, double> center() const override {
        return std::make_pair(mid_x, mid_y);
    }

    operator double() const override {
        return surface;
    }

protected:
    double x_kords[4];
    double y_kords[4];
    double surface;
    double mid_x;
    double mid_y;
};

inline std::ostream &operator<<(std::ostream& os, const Square& p) {
    for (int i = 0; i < 4; ++i) {
        os << "Coordinates :" << i + 1 << "(: " << p.x_kords[i] << "," << p.y_kords[i] << " )\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream& is, Square& p) {
    double x, y;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter coordinates" << i + 1 << ":\n";
        std::cout << "x: ";
        is >> x;
        std::cout << "y: ";
        is >> y;
        p.x_kords[i] = x;
        p.y_kords[i] = y;
    }
    return is;
}

class Triangle : public Figure {
public:
    Triangle();
    Triangle(double x[3], double y[3]);
    ~Triangle();

    bool operator==(Triangle &other) const;
    Triangle &operator=(Triangle &other);
    Triangle &operator=(Triangle &&other);

    friend std::ostream &operator<<(std::ostream& os, const Triangle& p);
    friend std::istream &operator>>(std::istream& is, Triangle& p);

    double area() const override {
        return surface;
    }

    std::pair<double, double> center() const override {
        return std::make_pair(mid_x, mid_y);  
    }

    operator double() const override {
        return surface;
    }

protected:
    double x_kords[3];
    double y_kords[3];
    double mid_x;
    double mid_y;
    double surface;
};

inline std::ostream &operator<<(std::ostream& os, const Triangle& p) {
    for (int i = 0; i < 3; ++i) {
        os << "Coordinates :" << i + 1 << ": ( " << p.x_kords[i] << " , " << p.y_kords[i] << ")\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream& is, Triangle& p) {
    double x, y;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter coordinates" << i + 1 << ":\n";
        std::cout << "x: ";
        is >> x;
        std::cout << "y: ";
        is >> y;
        p.x_kords[i] = x;
        p.y_kords[i] = y;
    }
    return is;
}

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double x[4], double y[4]);
    ~Rectangle();
    bool operator==(Rectangle &other) const;
    Rectangle &operator=(Rectangle &other);
    Rectangle &operator=(Rectangle &&other);
    
    std::pair<double, double> center() const override {
        return std::make_pair(mid_x, mid_y);
    }
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &p);
    friend std::istream &operator>>(std::istream &is, Rectangle &p);
    double area() const override {
        return surface;
    }
    operator double() const override {
        return surface;
    }

protected:
    double mid_x;
    double mid_y;
    double surface;
    double x_kords[4];
    double y_kords[4];
};

inline std::ostream &operator<<(std::ostream &os, const Rectangle &p) {
    for (size_t i = 0; i < 4; ++i) {
        os << "Coordinates : " << i + 1 << " ( " << p.x_kords[i] << "," << p.y_kords[i] << " )\n";
    }
    return os;
}

inline std::istream &operator>>(std::istream &is, Rectangle &p) {
    double x, y;
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "Enter coordinates" << i + 1 << ":\n";
        std::cout << "x: ";
        is >> x;
        std::cout << "y: ";
        is >> y;
        p.x_kords[i] = x;
        p.y_kords[i] = y;
    }
    return is;
}

class Array {
public:
    Array();
    Array(size_t size);

    ~Array();
            
    void del_figure(size_t index);
    double avg_area(); 

    Figure *operator[](size_t index);

    void changefigures(size_t index, Figure *other);
    size_t get_size() {
        return _size;
    }

private:
    size_t _size;
    Figure** _figures;
};
