#pragma once
#include <sstream>
#include <stdexcept>

class Thirteen {
private:
    unsigned char* m_digits; 
    size_t m_size;
    void resize(size_t newSize);
    void clear();
public:
    Thirteen();
    Thirteen(size_t size, char value);
    Thirteen(std::stringstream& str);
    Thirteen(const Thirteen& other);
    Thirteen(Thirteen&& other) noexcept;
    ~Thirteen();

    Thirteen& operator+=(const Thirteen& other);
    Thirteen& operator-=(const Thirteen& other);
    bool operator==(const Thirteen& other) const;  
    bool operator!=(const Thirteen& other) const;
    bool operator<(const Thirteen& other) const;
    bool operator>(const Thirteen& other) const;
    void print(std::stringstream& out) const;
};
