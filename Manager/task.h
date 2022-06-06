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

#pragma once
#include "menu.h"

//Task class
class Task
{
    private:
        std::string name;
        std::string date;
        std::string type;
    public:
        //setters
        void setName(std::string name);
        void setDate(std::string date);
        void setType(std::string type);

        //getters
        std::string getName();
        std::string getDate();
        std::string getType();

        //function for entering the data
        void DataEntry(std::string bufer1, std::string bufer2, std::string bufer3);
};

//function for saving the data
void saveData(std::vector<Task> &table);

//to read data from file to vector
void readData(std::vector<Task> &table);

//output data from the vector
void readFile(std::vector<Task> &table);

//function for changing the task type
void mvType(std::vector<Task> &table, std::string taskName,std::string taskType);

//function for changing the task name
void mvName(std::vector<Task> &table, std::string taskName, std::string newName);

//function for changing the task deadline
void mvDate(std::vector<Task> &table, std::string taskName, std::string newDeadline);

//function for reading deleted tasks
void readDeletedData(std::vector<Task> &table);