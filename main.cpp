#include <iostream>
#include <vector>


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    std::vector<int> v{1,2,3};
    for (const int& i : v)
    {
        std::cout << i << " " ;
    }

    std::cout << std::endl ;

    return 0;
}
