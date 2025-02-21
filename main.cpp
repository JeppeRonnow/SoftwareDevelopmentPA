#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Task {
	public:
	string _description;
	string _status;
	Task(string description, string status){
		_description = description;
		_status = status;
	}
};

class TodoList {
	
	public:
	vector<Task> todolist;
	TodoList(){}
	
	// Create new task
	void create_task(string des, string stat){
		Task new_task = Task(des, stat);
		todolist.push_back(new_task);
		// TEST PRINT
		cout << todolist.size() << endl;
	}

	void delete_task(int index) {

		if (index >= 0 && index < todolist.size()) {
			todolist.erase(todolist.begin() + index);
		}
		std::cout << "Task ikke fundet: " << index << std::endl;
	}

};

int main() {

    TodoList todo = TodoList();

    // Create new task
    todo.create_task("TEST", "OnGoing");

    // TEST PRINT
    cout << todo.todolist.size() << endl;

    return 0;
}
