#include <iostream>
#include <array>
using namespace std;

class String {
private:
    unsigned int m_Size;
    char* m_Buffer;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
        cout << "Created! \n";
    }

    String(const String& other) = delete; //disable copying

    ~String() {
        delete[] m_Buffer;
        cout << "\nDeleted.";
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend ostream& operator<<(ostream& stream, const String& string);
};

ostream& operator<<(ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

template<typename T, size_t S>
class Array {
public:
    int Size() const { return S; }
    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }
    T* Data() { return m_Data; }
private:
    T m_Data[S]{};
};

int main()
{
    Array <String*, 5> arr1;
    cout << arr1.Size() << endl;

    String toDo1 = "Swim with the dolphins.";
    cout << toDo1 << endl;
    cout << &toDo1 << endl;

    arr1[0] = &toDo1;
    cout << arr1[0];

    for (int i = 0; i < arr1.Size(); i++) {
        if (arr1[i] != nullptr)
            cout << *arr1[i] << endl;
    }

    String hotel = "Oceanside hotel";
    
    return 0;
}
