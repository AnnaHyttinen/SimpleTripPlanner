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
    }

    String(const String& other) = delete; //disable copying

    ~String() {
        delete[] m_Buffer;
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
    char* operator[](size_t index) { return m_Data[index]; }
    const char& operator[](size_t index) const { return m_Data[index]; }
    char* Data() { return m_Data; }
private:
    char* m_Data[S];
};

int main()
{
    String toDo1 = "Swim in the ocean.";
    cout << toDo1 << endl;

    Array <char**, 5> arr;
    cout << arr.Size();

    //these do not work yet:
    /*cout << arr[0];

    for (int i = 0; i < arr.Size(); i++) {
        *arr[0] = 'Joo';
        cout << arr[i] << endl;
    }*/
    return 0;
}
