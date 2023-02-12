#include <lib/lib.hpp>

#include <iostream>

int main(int ac, char* av[])
{
    std::cout << "Hello app\n";

    try
    {
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Exception of unknown type!\n";
    }

    return 0;
}
