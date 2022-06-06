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