#include <iostream>
#include <array>

using namespace std;

template <class T>
T operator+(const T& a1, const T& a2)
{
  T a;
  for (typename T::size_type i = 0; i < a1.size(); i++)
    a[i] = a1[i] + a2[i];
  return a;
}

int main()
{
  array<int,5> a1 = { 1, 2, 3, 4, 5 };
  array<int,5> a2 = { 2, 3, 4, 5, 6 };
  array<int,5> a3 = a1 + a2;

  for (int i = 0; i < 5; i++)
    cout << a1[i] << '+' << a2[i] << '=' << a3[i] << ' ';

  cout << endl;
  return 0;
}
