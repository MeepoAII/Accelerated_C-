#include <iostream>

int main()
{
	std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, "<< name
                << std::endl << "And what is yours? ";
    std::string test;
    std::cin >> test;
    std::cout << "Hello, " << test
                << "; nice to meet you too!" << std::endl;
    
    return 0;
}