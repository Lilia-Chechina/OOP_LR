#include "../include/Thirteen_Class.h"
#include <iostream>
#include <cstring>

Thirteen::Thirteen() : m_digits(nullptr), m_size(0) {}

Thirteen::Thirteen(size_t size, char value) : m_size(size) {
    if (!(value >= '0' && value <= '9') && value != 'A' && value != 'B' && value != 'C') {
        throw std::invalid_argument("Недопустимое значение: " + std::string(1, value));
    }

    m_digits = new unsigned char[size];
    memset(m_digits, value >= '0' && value <= '9' ? value - '0' : value - 'A' + 10, size); 
}


Thirteen::Thirteen(std::stringstream& str) {
    std::string temp;
    str >> temp;
    for (char c : temp) {
        if (!( (c >= '0' && c <= '9') || c == 'A' || c == 'B' || c == 'C' )) {
            throw std::invalid_argument("Недопустимый символ в строке: " + std::string(1, c));
        }
    }

    m_size = temp.length();
    m_digits = new unsigned char[m_size];
    for (size_t i = 0; i < m_size; ++i) {
        char c = temp[m_size - 1 - i];
        if (c >= '0' && c <= '9') {
            m_digits[i] = c - '0'; // Числа 0-9
        } else if (c == 'A') {
            m_digits[i] = 10;
        } else if (c == 'B') {
            m_digits[i] = 11;
        } else if (c == 'C') {
            m_digits[i] = 12;
        }
    }
}

Thirteen::Thirteen(const Thirteen& other) : m_size(other.m_size) {
    m_digits = new unsigned char[m_size]; 
    memcpy(m_digits, other.m_digits, m_size);  
}

// конструктор перемещения
Thirteen::Thirteen(Thirteen&& other) noexcept : m_digits(other.m_digits), m_size(other.m_size) {
    other.m_digits = nullptr;
    other.m_size = 0;
}

Thirteen::~Thirteen() {
    clear();
}

bool Thirteen::operator==(const Thirteen& other) const { 
    if (m_size != other.m_size) return false;
    for (size_t i = 0; i < m_size; ++i) { 
        if (m_digits[i] != other.m_digits[i]) return false; 
    }
    return true;
}

bool Thirteen::operator!=(const Thirteen& other) const {
    return !(*this == other);
}

bool Thirteen::operator<(const Thirteen& other) const {
    if (m_size != other.m_size) return m_size < other.m_size;  
    for (size_t i = m_size; i-- > 0;) {
        if (m_digits[i] < other.m_digits[i]) return true;  
        if (m_digits[i] > other.m_digits[i]) return false;
    }
    return false;
}

bool Thirteen::operator>(const Thirteen& other) const {
    return other < *this;
}

Thirteen& Thirteen::operator+=(const Thirteen& other) {
    size_t maxSize = (m_size > other.m_size) ? m_size : other.m_size;
    resize(maxSize + 1);

    unsigned char carry = 0; 
    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < m_size) sum += m_digits[i];
        if (i < other.m_size) sum += other.m_digits[i];
        carry = sum / 13; 
        m_digits[i] = sum % 13;
    }

    if (carry) m_digits[maxSize] = carry;
    return *this;
}  

Thirteen& Thirteen::operator-=(const Thirteen& other) {
    unsigned char borrow = 0;
    for (size_t i = 0; i < m_size || borrow; ++i) {
        unsigned char sub = m_digits[i] - borrow;
        if (i < other.m_size) sub -= other.m_digits[i];
        if (sub >= 13) {
            borrow = 1;
            sub += 13;
        } else {
            borrow = 0;
        }
        m_digits[i] = sub;
    }

    return *this;
}

void Thirteen::resize(size_t newSize) {
    if (newSize > m_size) {  
        unsigned char* newDigits = new unsigned char[newSize];
        memset(newDigits, 0, newSize);
        if (m_digits) { 
            memcpy(newDigits, m_digits, m_size);  
            delete[] m_digits;
        }
        m_digits = newDigits;
        m_size = newSize;
    }
}

void Thirteen::clear() {
    delete[] m_digits;
    m_digits = nullptr;
    m_size = 0;
}

void Thirteen::print(std::stringstream& out) const {
    if (m_size == 0) {
        return;
    }
    
    bool leading_zero = true;
    for (size_t i = m_size; i-- > 0;) {
        if (leading_zero && m_digits[i] == 0) {
            continue;
        }
        leading_zero = false;
        if (m_digits[i] < 10) {
            out << (char)(m_digits[i] + '0');
        } else {
            out << (char)(m_digits[i] - 10 + 'A');
        }
    }
    if (leading_zero) {
        out << '0';
    }
}
