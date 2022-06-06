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
    Task new_task;
    int menu;
    std::string menus;
    std::string counters;
    int counter;
    std::string bufer1;
    std::string bufer2;
    std::string bufer3;
    //vector for the task elements
    std::vector<Task> table;
    //delimiter for main menu
    std::string delimiter = "|_____________________________________________________________|\n\n";

    //enum type for better readability if-else
    enum {exit, display_table, move_task, create_task, delete_task, display_del_task, display_license};

    //main menu call
    mainMenu(menus, menu);
    std::cout << delimiter;
    while(menu != exit)
    {
        if(menu == display_table)
        {

            readData(table); //entering data from a file into a vector

            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            #ifdef testing

                std::cout << table.capacity() << std::endl;
                readFile(table);
                    
            #endif

            readFile(table); //output each element

            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            #ifdef testing

                std::cout << "after erasing" << std::endl;

                std::cout << table.capacity() << std::endl;
                readFile(table);
                    
            #endif

            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        else if(menu == move_task)
        {
            //implement the logic of movement
        }
        else if(menu == create_task)
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "| Enter a number of tasks to emplace: ";
            getline(std::cin, counters);
            std::cout   << "|_____________________________________________________________" << std::endl;
            std::stringstream(counters) >> counter;

            for(int i = 0; i < counter; i++) //entering new words(depends on the number)
            {
                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a new task: ";
                getline(std::cin, bufer1);
                std::cout   << "| Enter deadline for this task: ";
                getline(std::cin, bufer2);
                std::cout   << "| Enter type for this task (to do or done): ";
                getline(std::cin, bufer3);
                 std::cout   << "|_____________________________________________________________" << std::endl;

                new_task.DataEntry(bufer1, bufer2, bufer3);

                table.push_back(new_task);
            }

            saveData(table); //saving data into a file
                
            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            #ifdef testing

                std::cout << "after erasing" << std::endl;

                std::cout << table.capacity() << std::endl;
                for(auto el : table)
                {
                    std::cout << el.getName() << " " << el.getDate() << " " << el.getType() << std::endl;
                }
                    
            #endif
                
            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        else if(menu == delete_task)
        {
            //implement the logic of deleting
        }
        else if(menu == display_del_task)
        {
            //implement the logic
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
