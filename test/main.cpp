#include "light-log"

#include <iostream>
#include <string>

int main()
{
    llog::file file;
    while (true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit")
        {
            break;
        }

        file << input << '\n';
    };
    file.write();
    return 0;
}