#pragma once
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
