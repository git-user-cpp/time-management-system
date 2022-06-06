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

#include "menu.h"

//main menu function
void mainMenu(std::string &menus, int &menu)
{
    std::cout   << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                    Time management system                   |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                      Choose an option:                      |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|            [1] Display the time management table            |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                  [2] Move or delete a task                  |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                    [3] Create a new task                    |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                  [4] Display deleted tasks                  |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                [5] Display author and license               |" << std::endl
                << "|                         information                         |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________" << std::endl
                << "|                                                             |" << std::endl
                << "|                     [0] Stop the program                    |" << std::endl
                << "|_____________________________________________________________|" << std::endl
                << " _____________________________________________________________ " << std::endl
                << "                          Your choise: ";

    getline(std::cin, menus);
    std::stringstream(menus) >> menu;
}
