#pragma once
#include <iostream>
using namespace std;

class String {
private:
    unsigned int m_Size;
    char* m_Buffer;
public:
    String() {};
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
        cout << "Created! \n";
    }
    String(const String& other) = delete;

    String(const string& other) {
        m_Size = other.size();
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.data(), m_Size);
        m_Buffer[m_Size] = 0;
        cout << "Created a String object out of std string. \n";
    }
  
    ~String() {
        delete[] m_Buffer;
        cout << "\nDeleted.";
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    char* operator+(String& b) {
        return b.m_Buffer;
    }

    friend ostream& operator<<(ostream& stream, const String& string);
    friend istream& operator>>(istream& stream, const String& string);
};

ostream& operator<<(ostream& stream, const String& string) {
    return stream;
}

istream& operator>>(istream& stream, const String& string) {
    return stream;
}

template<typename T>
class Vector {
    T* arr;
    int capacity;
    int current;
public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    ~Vector() { delete[] arr; }

    void Push(T data) {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
                cout << "Pushed to a Vector! \n";
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void Print() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << "_";
        }
    }
};

template<typename T, size_t S>
class Array {
public:
    int Size() const { return S; }
    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; } //just in case
    T* Data() { return m_Data; }
    void PrintArray(ostream& stream) {
        for (int i = 0; i < this.Size(); i++) {
            if (this[i] != nullptr)
                cout << *this[i] << endl;
        }
    }
private:
    T m_Data[S]{};
};
