#include <iostream>
#include <iod/array_view.hh>
#include "symbols.hh"
#include <cassert>

int main()
{
  using namespace iod;
  using namespace s;

  {
    std::vector<int> A = {1,2,3,4};
    auto v = array_view(A.size(), [&] (int i) {
        return A[i] * 2; });
  
    for (int i = 0; i < int(v.size()); i++)
      assert(v[i] == (i+1) * 2);

    for (auto x : v) std::cout << x << std::endl;
  }
  

  {
    struct Arr1
    {
      Arr1() {};
      Arr1(const Arr1& e) = delete;
      Arr1& operator=(const Arr1& e) = delete;

      decltype(auto) operator[](int i) { return 42; }
      int size() const { return 5; }
    };

    Arr1 A;
    auto v = array_view(5, A);
    for (auto x : v) std::cout << x << std::endl;
    
  }
}
