#include "HashTable.h"
#include <iostream>
#include <cstdlib>
using namespace std;
HashTable::HashTable(const int tableSize, const CollisionStrategy option)
{
    itemCounter = 0;
    tSize = tableSize;
    collisionOption = option;
    htable = new int[tSize];
    for(int i = 0; i < tSize; i++)
    {
        htable[i] = NULL;
    }
}

HashTable::~HashTable()
{
    delete[] htable;
}

bool HashTable::insert(const int item)
{
    int index = item % tSize;      // Hash function
    bool isInserted = false;
    if(itemCounter == tSize)
    {
        cout<<"The table is full."<<endl;
    }
    else
    {
        if(collisionOption == LINEAR)
        {
            if(htable[index] == NULL)
            {
                htable[index] = item;
                isInserted = true;
                itemCounter++;
            }
            else
            {
                while(!isInserted)
                {
                    index++;
                    if(index  == tSize)
                    {
                        index = 0;
                    }
                    if(htable[index] == NULL)
                    {
                        htable[index] = item;
                        isInserted = true;
                        itemCounter++;
                    }
                }
            }
        }
        else if(collisionOption == QUADRATIC)
        {
            int helper = 1;
            if(htable[index] == NULL)
            {
                htable[index] = item;
                isInserted = true;
                itemCounter++;
            }
            else
            {
                while(!isInserted && helper != tSize)
                {
                    index += (helper * helper);
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == NULL)
                    {
                        htable[index] = item;
                        isInserted = true;
                        itemCounter++;
                    }
                    helper++;
                }
            }

        }
        else if(collisionOption = DOUBLE)
        {
            if(htable[index] == NULL)
            {
                htable[index] = item;
                isInserted = true;
                itemCounter++;
            }
            else
            {
                int helper2  = 1;
                int reversed = 0;
                int tmp;
                int number = item;
                while(number != 0)
                {
                    tmp = number % 10;
                    reversed = reversed * 10 + tmp;
                    number /= 10;
                }
                while(!isInserted && helper2 != tSize)
                {
                    index+= (helper2 * reversed);
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == NULL)
                    {
                        htable[index] = item;
                        isInserted = true;
                        itemCounter++;
                    }
                    helper2++;
                }
            }

        }
    }
    if(!isInserted)
    {
        cout<<item<<" not inserted."<<endl;
    }
    else
    {
        cout<<item<<" inserted."<<endl;
    }
    return isInserted;
}

void HashTable::display()
{
    for(int i = 0; i < tSize; i++)
    {
        if(htable[i] == NULL)
        {
            cout<< i<<": "<<endl;
        }
        else
        {
            cout<< i<<": "<<htable[i]<<endl;
        }
    }
}

bool HashTable::search(const int item, int& numOfProbes)
{
    int index = item % tSize;
    bool isFound = false;
    numOfProbes = 0;
    if(itemCounter != 0)
    {
        if(collisionOption == LINEAR)
        {
            if(htable[index] == item)
            {
                isFound = true;
                numOfProbes++;
            }
            else
            {
                numOfProbes++;
                int counterL = 1;
                while(!isFound && counterL != tSize)
                {
                    index++;
                    numOfProbes++;
                    if(index == tSize)
                    {
                        index = 0;
                    }
                    if(htable[index] == item)
                    {
                        isFound = true;
                    }
                    counterL++;
                }
            }
        }
        else if(collisionOption == QUADRATIC)
        {
            if(htable[index] == item)
            {
                isFound = true;
                numOfProbes++;
            }
            else
            {
                numOfProbes++;
                int counterQ = 1;
                while(!isFound && counterQ != tSize)
                {
                    index += (counterQ * counterQ);
                    numOfProbes++;
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == item)
                    {
                        isFound = true;
                    }
                    counterQ++;
                }
            }
        }
        else if(collisionOption == DOUBLE)
        {
            if(htable[index] == item)
            {
                isFound = true;
                numOfProbes++;
            }
            else
            {
                numOfProbes++;
                int counterD = 1;
                int reversed = 0;
                int tmp;
                int number = item;
                while(number != 0)
                {
                    tmp = number % 10;
                    reversed = reversed * 10 + tmp;
                    number /= 10;
                }
                while(!isFound && counterD != tSize)
                {
                    index += (counterD * reversed);
                    numOfProbes++;
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == item)
                    {
                        isFound = true;
                    }
                    counterD++;
                }
            }

        }
    }
    if(isFound)
    {
        cout<< item<<" found after "<< numOfProbes<<" probes."<<endl;
    }
    else
    {
        cout<< item<< " not found after "<< numOfProbes<<" probes. "<<endl;
    }
    return isFound;
}

bool HashTable::remove(const int item)
{
    int index = item % tSize;
    bool isDeleted = false;
    if(itemCounter != 0)
    {
        if(collisionOption == LINEAR)
        {
            if(htable[index] == item)
            {
                htable[index] = NULL;
                isDeleted = true;
                itemCounter--;
            }
            else
            {
                int counterL = 1;
                while(!isDeleted && counterL != tSize)
                {
                    index++;
                    if(index == tSize)
                    {
                        index = 0;
                    }
                    if(htable[index] == item)
                    {
                        htable[index] = NULL;
                        isDeleted = true;
                        itemCounter--;
                    }
                    counterL++;
                }
            }
        }
        else if(collisionOption == QUADRATIC)
        {
            if(htable[index] == item)
            {
                htable[index] = NULL;
                isDeleted = true;
                itemCounter--;
            }
            else
            {
                int counterQ = 1;
                while(!isDeleted && counterQ != tSize)
                {
                    index += (counterQ * counterQ);
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == item)
                    {
                        htable[index] = NULL;
                        isDeleted = true;
                        itemCounter--;
                    }
                    counterQ++;
                }
            }
        }
        else if(collisionOption == DOUBLE)
        {
            if(htable[index] == item)
            {
                htable[index] = NULL;
                isDeleted = true;
                itemCounter--;
            }
            else
            {
                int counterD = 1;
                int reversed = 0;
                int tmp;
                int number = item;
                while(number != 0)
                {
                    tmp = number % 10;
                    reversed = reversed * 10 + tmp;
                    number /= 10;
                }
                while(!isDeleted && counterD != tSize)
                {
                    index += (counterD * reversed);
                    if(index >= tSize)
                    {
                        index = index % tSize;
                    }
                    if(htable[index] == item)
                    {
                        htable[index] = NULL;

                        isDeleted = true;
                        itemCounter--;
                    }
                    counterD++;
                }
            }
        }
    }
    if(isDeleted)
    {
        cout<< item <<" removed."<<endl;
    }
    else
    {
        cout<< item << " not removed."<<endl;
    }
    return isDeleted;
}

void HashTable::analyze( double& numSuccProbes, double& numUnsuccProbes )
{
    if(collisionOption == LINEAR)
    {
        int checkCounterL = 0;
        int checkCounterU;
        int checkIfOccupied = 0;
        int counterForUnsuc;
        double sumLS = 0;
        double sumLU = 0;
        while(checkCounterL < tSize)
        {
            counterForUnsuc = 0;
            checkCounterU = checkCounterL;
            if(htable[checkCounterL] != NULL)
            {
                checkIfOccupied++;
                if(htable[checkCounterL] % tSize > checkCounterL)
                {
                    sumLS = sumLS + (tSize + 1) - (htable[checkCounterL] % tSize);
                }
                else
                {
                    sumLS = sumLS + abs((htable[checkCounterL] % tSize) - checkCounterL) + 1;
                }
            }
            checkCounterL++;
            do
            {
                if(checkCounterU >= tSize)
                {
                    checkCounterU = 0;
                }
                sumLU++;
                checkCounterU++;
                counterForUnsuc++;
            }
            while (htable[checkCounterU] != NULL && counterForUnsuc != tSize);
        }
        numSuccProbes = sumLS / checkIfOccupied;
        numUnsuccProbes = sumLU / tSize;
    }
    else if(collisionOption == QUADRATIC)
    {
        double sumQS = 0;
        double sumQU = 0;
        int checkQ = 0;
        int QifOccupied = 0;
        int checkQU;

        while(checkQ < tSize)
        {
            int counterQU = 0;
            checkQU = checkQ;
            int helper2 = 1;
            if(htable[checkQ] != NULL)
            {
                sumQS++;
                int index = htable[checkQ] % tSize;
                QifOccupied++;
                int helper = 1;
                if(index != checkQ)
                {

                    while(index != checkQ && helper < tSize)
                    {
                        sumQS++;
                        index += (helper * helper);
                        if(index >= tSize)
                        {
                            index = index % tSize;
                        }
                        helper++;
                    }
                }
            }
            checkQ++;
            do
            {
                if(checkQU >= tSize)
                {
                    checkQU = checkQU % tSize;
                }
                sumQU++;
                checkQU += helper2 * helper2;
                counterQU++;
                helper2++;
            }
            while(htable[checkQU] != NULL && helper2 != tSize);
        }
        numSuccProbes = sumQS / QifOccupied;
        numUnsuccProbes = sumQU / tSize;
    }
    else if(collisionOption == DOUBLE)
    {
        int checkD = 0;
        double sumDS = 0;
        int indexD;
        int dOcc = 0;
        while(checkD < tSize)
        {
            if(htable[checkD] != NULL)
            {
                dOcc++;
                indexD = htable[checkD] % tSize;
                if(indexD != checkD)
                {
                    while(indexD != checkD)
                    {
                        sumDS++;
                        int helper3 = 1;
                        int helper2  = 1;
                        int reversed = 0;
                        int tmp;
                        int number = htable[checkD];
                        while(number != 0)
                        {
                            tmp = number % 10;
                            reversed = reversed * 10 + tmp;
                            number /= 10;
                        }
                        indexD = indexD + (helper3 * reversed);
                        if(indexD >= tSize)
                        {
                            indexD = indexD % tSize;
                        }
                    }
                }
                else
                {
                    sumDS++;
                }
            }
            checkD++;
        }
        numSuccProbes = sumDS / dOcc;
        numUnsuccProbes = -1;
    }
}
