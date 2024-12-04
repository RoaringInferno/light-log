#include "light-log"

#include <iostream>
#include <string>

int main()
{
    llog::file file;
    while (true)
    {
        {
            std::cout << "> ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "exit")
            {
                break;
            }

            file << input << '\n';
        }

        {
            std::cout << "> ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "exit")
            {
                break;
            }

            llog::file::push(input);
        }
    };
    file.write();
    return 0;
}