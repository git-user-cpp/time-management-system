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

//setters for the class "Task"
void Task::setName(std::string name)
{
    this->name = name;
}
void Task::setDate(std::string date)
{
    this->date = date;
}
void Task::setType(std::string type)
{
    this->type = type;
}

//getters for the class "Task"
std::string Task::getName()
{
    return name;
}
std::string Task::getDate()
{
    return date;
}
std::string Task::getType()
{
    return type;
}

//function for entering the data
void Task::DataEntry(std::string bufer1, std::string bufer2, std::string bufer3)
{
    this->setName(bufer1);
    this->setDate(bufer2);
    this->setType(bufer3);
}

//function for saving the data
void saveData(std::vector<Task> &table)
{
    std::fstream record;
    record.open("table.txt", std::ios::out); //opening the file to add data to the end

        if(record)
        {            
            for(auto &el : table) //recording each element into file
            {
                record << el.getName() << '\n';
                record << el.getDate() << '\n';
                record << el.getType() << '\n';
            }
            record.close();
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                    Error(file recording)                    |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }

    std::cout   << " _____________________________________________________________" << std::endl
                << "|                       Data is recorded                      |" << std::endl
                << "|_____________________________________________________________|" << std::endl;
}

//to read data from file to vector
void readData(std::vector<Task> &table)
{
    Task task; //variable for input into the vector
    char str[510]; //string to read from a file
    int counter = 0;
    int flag = 0;

    std::fstream reading;
    reading.open("table.txt", std::ios::in);

        if(reading)
        {
            while(reading.getline(str, 510, '\n')) //reading each line of the file
            {
                if(counter == 0 || counter == 3 || counter == 6 || counter == 9 || counter == 12) //separation of the word from its translation
                {
                    task.setName(str);
                    flag++;
                }
                else if(counter == 1 || counter == 4 || counter == 7 || counter == 10 || counter == 13)
                {
                    task.setDate(str);
                    flag++;
                }
                else if(counter == 2 || counter == 5 || counter == 8 || counter == 11 || counter == 14)
                {
                    task.setType(str);
                    flag++;
                }

                if(flag % 3 == 0) //if a word and its translation are found, insert them into the vector
                {
                    table.push_back(task);
                }


                counter++;
            }
            
            reading.close();
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                     Error(file reading)                     |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }

    std::cout   << " _____________________________________________________________" << std::endl
                << "|                         Data is red                         |" << std::endl
                << "|_____________________________________________________________|" << std::endl;
}

//output data from the vector
void readFile(std::vector<Task> &table)
{
    for(auto &element : table)
    {
        if(element.getType() != "deleted")
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "| " << element.getName() << " --> " << element.getDate() << " --> " << element.getType() << std::endl
                        << "|_____________________________________________________________" << std::endl;
        }
    }
}

//function for changing the task type
void mvType(std::vector<Task> &table, std::string taskName, std::string taskType)
{
    for(auto &el : table)
    {
        if(el.getName() == taskName)
        {
            el.setType(taskType);
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                    Error: Invalid input                     |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }
    }
}

//function for changing the task name
void mvName(std::vector<Task> &table, std::string taskName, std::string newName)
{
    for(auto &el : table)
    {
        if(el.getName() == taskName)
        {
            el.setName(newName);
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                    Error: Invalid input                     |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }
    }
}

//function for changing the task deadline
void mvDate(std::vector<Task> &table, std::string taskName, std::string newDeadline)
{
    for(auto &el : table)
    {
        if(el.getName() == taskName)
        {
            el.setDate(newDeadline);
        }
        else
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "|                    Error: Invalid input                     |" << std::endl
                        << "|_____________________________________________________________|" << std::endl;
        }
    }
}

//function for reading deleted tasks
void readDeletedData(std::vector<Task> &table)
{
    for(auto &element : table)
    {
        if(element.getType() == "deleted")
        {
            std::cout   << " _____________________________________________________________" << std::endl
                        << "| " << element.getName() << " --> " << element.getDate() << " --> " << element.getType() << std::endl
                        << "|_____________________________________________________________" << std::endl;
        }
    }
}
