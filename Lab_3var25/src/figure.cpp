#include "../include/figure.h"
#include <exception>
#include <algorithm>

Square::Square() {
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0.0;
    mid_y = 0.0;
    surface = 0;
}

Square::Square(double x[4], double y[4]) {
    mid_x = 0.0;
    mid_y = 0.0;
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    mid_x = mid_x / 4;
    mid_y = mid_y / 4;

    double x1 = x_kords[0];
    double y1 = y_kords[0];
    double x2 = x_kords[1];
    double y2 = y_kords[1];

    double side = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    surface = side * side;
}

Square::~Square() {
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0;
    mid_y = 0;
    surface = 0;
}

bool Square::operator==(Square &other) const {
    return surface == other.surface;
}

Square &Square::operator=(Square &other) {
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = other.x_kords[i];
        y_kords[i] = other.y_kords[i];
    }
    mid_x = other.mid_x;
    mid_y = other.mid_y;
    surface = other.surface;
    return *this;
}

Square &Square::operator=(Square &&other) {
    mid_x = std::move(other.mid_x);
    mid_y = std::move(other.mid_y);
    surface = std::move(other.surface);
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = other.x_kords[i];
        y_kords[i] = other.y_kords[i];
    }

    return *this;
}

Triangle::Triangle() {
    for (int i = 0; i < 3; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0.0;
    mid_y = 0.0;
    surface = 0;
}

Triangle::Triangle(double x[3], double y[3]) {
    mid_x = 0.0;
    mid_y = 0.0;
    for (int i = 0; i < 3; ++i) {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    mid_x = mid_x / 3;
    mid_y = mid_y / 3;

    double a = std::sqrt(std::pow((x[1] - x[0]), 2) + std::pow((y[1] - y[0]), 2));
    double b = std::sqrt(std::pow((x[2] - x[1]), 2) + std::pow((y[2] - y[1]), 2));
    double c = std::sqrt(std::pow((x[2] - x[0]), 2) + std::pow((y[2] - y[0]), 2));

    double p = (a + b + c) / 2;
    surface = std::sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::~Triangle() {
    for (int i = 0; i < 3; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0;
    mid_y = 0;
    surface = 0;
}

bool Triangle::operator==(Triangle &other) const {
    std::pair<double, double> vertices1[3] = {
        {x_kords[0], y_kords[0]},
        {x_kords[1], y_kords[1]},
        {x_kords[2], y_kords[2]}
    };

    std::pair<double, double> vertices2[3] = {
        {other.x_kords[0], other.y_kords[0]},
        {other.x_kords[1], other.y_kords[1]},
        {other.x_kords[2], other.y_kords[2]}
    };

    std::sort(std::begin(vertices1), std::end(vertices1));
    std::sort(std::begin(vertices2), std::end(vertices2));
    return std::equal(std::begin(vertices1), std::end(vertices1), std::begin(vertices2));
}

Triangle &Triangle::operator=(Triangle &other) {
    for (int i = 0; i < 3; ++i) {
        x_kords[i] = other.x_kords[i];
        y_kords[i] = other.y_kords[i];
    }
    mid_x = other.mid_x;
    mid_y = other.mid_y;
    surface = other.surface;
    return *this;
}

Triangle &Triangle::operator=(Triangle &&other) {
    mid_x = std::move(other.mid_x);
    mid_y = std::move(other.mid_y);
    surface = std::move(other.surface);

    for (int i = 0; i < 3; ++i) {
        x_kords[i] = other.x_kords[i];
        y_kords[i] = other.y_kords[i];
    }

    return *this;
}

Rectangle::Rectangle() {
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0.0;
    mid_y = 0.0;
    surface = 0;
}

Rectangle::Rectangle(double x[4], double y[4]) {
    mid_x = 0;
    mid_y = 0;
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }

    double xA = x_kords[0];
    double yA = y_kords[0];
    double xB = x_kords[1];
    double yB = y_kords[1];
    double xC = x_kords[2];
    double yC = y_kords[2];
    double xD = x_kords[3];
    double yD = y_kords[3];

    double length = std::sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
    double width = std::sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));
    mid_x = (xA + xC) / 2;
    mid_y = (yA + yC) / 2;

    surface = length * width;
}

Rectangle::~Rectangle() {
    for (int i = 0; i < 4; ++i) {
        x_kords[i] = 0.0;
        y_kords[i] = 0.0;
    }
    mid_x = 0;
    mid_y = 0;
    surface = 0;
}

Array::Array(){
    _size=10;
    _figures=new Figure *[_size];
    for(size_t i{0};i<_size;++i){
        _figures[i]=nullptr;

    }

    
}
Array::Array(size_t size){
    _size=size;
    _figures=new Figure *[_size];
    for(size_t i{0};i<_size;++i){
        _figures[i]=nullptr;

    }

}
Array::~Array() {
    for (size_t i = 0; i < _size; ++i) {
        if (_figures[i] != nullptr) {
            delete _figures[i];
            _figures[i] = nullptr;
        }
    }
    delete[] _figures;
    _figures = nullptr;
}

Figure *Array::operator[](size_t index){
    return _figures[index];
}

void Array::del_figure(size_t index){
    delete _figures[index];
    _figures[index]=nullptr;
}

void Array::changefigures(size_t index, Figure *other){
    if(_figures[index]!=nullptr){
        _figures[index]=nullptr;
    }
    _figures[index]=other;
}

double Array::avg_area(){
    double summary=0;
    for(size_t i{0};i<_size;++i){
        summary+=(double)*_figures[i];
    }
       return summary;
}