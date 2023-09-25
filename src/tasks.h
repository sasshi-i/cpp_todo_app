#ifndef _H_TASKS_
#define _H_TASKS_

#include <string>

using namespace std;

class Tasks {
    public:
        void create(string name);
        void index();
        void update(string name, int task_id);
        void done_task(int task_id);
        void destroy(int task_id);
};

#endif