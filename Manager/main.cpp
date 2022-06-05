/*
MIT License

Copyright (c) 2022 m!haly4

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "task.h"

int main()
{
    //variable for menu options
    int menu;
    //delimiter for main menu
    std::string delimiter = "|_____________________________________________________________|\n\n";

    //enum type for better readability if-else
    enum {exit, display_table, move_task, create_task, delete_task, display_license};

    //main menu call
    mainMenu();
    std::cin >> menu;
    std::cout << delimiter;
    while(menu != exit)
    {
        if(menu == display_table)
        {
            //output the table
        }
        else if(menu == move_task)
        {
            //implement the logic of movement
        }
        else if(menu == create_task)
        {
            //implement the logic of creating
        }
        else if(menu == delete_task)
        {
            //implement the logic of deleting
        }
        else if(menu == display_license)
        {
            //outputting info
            std::cout   << " _____________________________________________________________" << std::endl
                        << "| ---> Creator of this program: git-user-cpp (m!haly4) <---" << std::endl
                        << "|_____________________________________________________________" << std::endl
                        << "|      ---> Link: https://github.com/git-user-cpp <---" << std:: endl
                        << "|_____________________________________________________________" << std::endl
                        << "| ---> License: https://github.com/git-user-cpp/time-management-system/blob/main/LICENSE <---" << std::endl
                        << "|_____________________________________________________________" << std::endl;
        }
    }


    std::cout   << " _____________________________________________________________" << std::endl
                << "|                   The program is stopped                    |" << std::endl
                << "|_____________________________________________________________|" << std::endl;

    return 0;
}
