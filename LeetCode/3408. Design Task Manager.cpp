class TaskManager {
public:
    map<int, pair<int, int>> task_list;
    set<pair<int, int>> exec_list;

    TaskManager(vector<vector<int>>& tasks) {

        for (auto &v: tasks) {
            // map[ taskID ] = <userID, priority>
            task_list[ v[1] ].first = v[0];
            task_list[ v[1] ].second = v[2];

            // <priority, taskId>
            exec_list.insert({v[2], v[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_list[ taskId ].first = userId;
        task_list[ taskId ].second = priority;
        
        exec_list.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = task_list[taskId].second;

        // Remove from exec_list
        exec_list.erase({oldPriority, taskId});
        
        // Add with newPriority
        exec_list.insert({newPriority, taskId});
        
        // Update task_list with newPriority
        task_list[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = task_list[taskId].second;
    
        exec_list.erase({priority, taskId});
        task_list.erase(taskId);
    }
    
    int execTop() {
        if (exec_list.size() == 0)
            return -1;

        int task = (*--exec_list.end()).second;
        int user = task_list[task].first;

        rmv(task);

        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */