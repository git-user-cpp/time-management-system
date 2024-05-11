/*
MIT License

Copyright (c) 2022 Andrew Kushyk

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

#include "task.hpp"

int main()
{
    //variables for menu options
    Task new_task;
    int menu;
    std::string menus;
    std::string counters;
    int counter;
    int day, month, year;
    std::string bufer1;
    std::string bufer2;
    std::string bufer3;
    std::string taskName;
    std::string taskType;
    std::string answer;
    std::string newName;
    std::string newDeadline;

    //vector for the task elements
    std::vector<Task> table;

    //delimiter for main menu
    std::string delimiter = "|_____________________________________________________________|\n\n";

    //enum type for better readability if-else
    enum {exit, display_table, move_task, create_task, display_del_task, display_later_task, display_license};

    //main menu call
    mainMenu(menus, menu);
    std::cout << delimiter;

    //menu loop
    while(menu != exit)
    {
        //displaying task table
        if(menu == display_table)
        {
            readData(table); //entering data from a file into a vector

            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            readFile(table); //output each element

            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        //change a task
        else if(menu == move_task)
        {
            readData(table);

            std::cout   << " _____________________________________________________________" << std::endl
                        << "| Enter task name to move: ";
            getline(std::cin, taskName);
            std::cout   << "|_____________________________________________________________" << std::endl;
            std::cout   << " _____________________________________________________________" << std::endl
                        << "| Enter to change(name or deadline or type): ";
            getline(std::cin, answer);
            std::cout   << "|_____________________________________________________________" << std::endl;

            if(answer == "name")
            {
                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a new task name: ";
                getline(std::cin, newName);
                std::cout   << "|_____________________________________________________________" << std::endl;

                mvName(table, taskName, newName);
            }
            else if(answer == "deadline")
            {
                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a new task deadline: ";
                getline(std::cin, newDeadline);
                std::cout   << "|_____________________________________________________________" << std::endl;

                mvDate(table, taskName, newDeadline);
            }
            else if(answer == "type")
            {
                std::cout   << " _____________________________________________________________" << std::endl
                            << "| Enter a new task type(to do/done/deleted): ";
                getline(std::cin, taskType);
                std::cout   << "|_____________________________________________________________" << std::endl;

                mvType(table, taskName, taskType);
            }

            saveData(table);

            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        //create a new task
        else if(menu == create_task)
        {
            readData(table);
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
                std::cout   << "| Enter type for this task (to do): ";
                getline(std::cin, bufer3);
                 std::cout   << "|_____________________________________________________________" << std::endl;

                new_task.DataEntry(bufer1, bufer2, bufer3);

                table.push_back(new_task);
            }

            saveData(table); //saving data into a file
                
            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity
                
            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        //displaying deleted tasks
        else if(menu == display_del_task)
        {
            readData(table); //entering data from a file into a vector

            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            readDeletedData(table);

            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
        //displaying later tasks
        else if (menu == display_later_task)
        {
            readData(table); //entering data from a file into a vector

            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            std::cout << " _____________________________________________________________" << std::endl
                << "| Enter your date with \"ENTER \":" << std::endl;
            std::cin >> day >> month >> year;
            std::cin.ignore();
            std::cout << "|_____________________________________________________________" << std::endl;

            readLaterDate(table, day, month, year);

            table.clear(); //deleting each vector element
            table.shrink_to_fit(); //changing the size of the vector to the actual size of its capacity

            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
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
            
            mainMenu(menus, menu);
            std::cout << delimiter << std::endl;
        }
    }


    std::cout   << " _____________________________________________________________" << std::endl
                << "|                   The program is stopped                    |" << std::endl
                << "|_____________________________________________________________|" << std::endl;

    return 0;
}
