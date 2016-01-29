#include <cmath>
#include <type_traits>

struct foo : std::true_type // for ADL
{
    operator double() const { return 0; }
    operator float() const { return 0; }
};

foo pow(foo, int){ return {}; }

int main() {
    pow(foo{}, 5); // error: call to '__test' is ambiguous at type_traits:1195
}
