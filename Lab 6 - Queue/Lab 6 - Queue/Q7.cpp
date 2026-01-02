#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

struct Task {
    int taskID, priority, time;
    Task* next;
};

class Scheduler {
    Task* front;

public:
    Scheduler() : front(NULL) {}

    void addTask(int id, int pri, int time) {
        Task* newTask = new Task;
        newTask->taskID = id;
        newTask->priority = pri;
        newTask->time = time;
        newTask->next = NULL;

        if (!front || pri < front->priority) {
            newTask->next = front;
            front = newTask;
        } else {
            Task* temp = front;
            while (temp->next && temp->next->priority <= pri)
                temp = temp->next;
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }

    void runScheduler() {
        while (front) {
            Task* current = front;
            front = front->next;

            int execTime = min(5, current->time);
            cout << "Running Task " << current->taskID << " for " << execTime
                 << "s (Priority: " << current->priority << ")\n";

            current->time -= execTime;
            if (current->time > 0)
                addTask(current->taskID, current->priority, current->time);
            delete current;
        }
    }
};

int main() {
    Scheduler s;
    s.addTask(1, 2, 7);
    s.addTask(2, 1, 4);
    s.addTask(3, 3, 12);
    s.runScheduler();
    return 0;
}

