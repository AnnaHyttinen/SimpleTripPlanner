#include <iostream>
#include <array>
using namespace std;

template<size_t S>
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
    Array <5> arr;
    cout << arr.Size();

    cout << arr[0];

    for (int i = 0; i < arr.Size(); i++) {
        *arr[0] = 'Joo';
        cout << arr[i] << endl;
    }
    return 0;
}
