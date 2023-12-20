#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

struct Person
{
    string username;
    int usertime;

    Person()
    {
        username = "";
        usertime = 0;
    }

    Person(string name, int time)
    {
        username = name;
        usertime = time;
    }
};

int main()
{
    Queue<Person> jobs;
    int jobCount;
    string name;
    int time;
    int timeSlotted;
    cin >> jobCount;

    // cout << "number of jobs: " << jobCount << endl;
    for (int i = 0; i < jobCount; i++)
    {
        cin >> name;
        cin >> time;
        Person job(name, time);
        jobs.enqueue(job);
    }

    cin >> timeSlotted;

    while (jobs.length() >= 1)
    {
        Person person = jobs.dequeue();
        if (person.usertime > timeSlotted)
        {
            cout << person.username << " - " << timeSlotted << endl;
            person.usertime -= timeSlotted;
            jobs.enqueue(person);
        }
        else
        {
            cout << person.username << " - " << person.usertime << endl;
        }
    }

    cout << "Done..." << endl;

    return 0;
}