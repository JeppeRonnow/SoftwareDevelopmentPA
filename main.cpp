#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

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

	// Show tasks
	void show_tasks(){
		// Print new line with each task
		for (int i = 0; i < todolist.size(); i++){
			string status = todolist[i]._status;
			string description = todolist[i]._description;
			cout << format("[{}] {}. {}\n", status, i, description);
		}
		
		// Make new line and flush buffer
		cout << endl;
	}

	// Delete task
	void delete_task(int index) {
		if (index >= 0 && index < todolist.size()) {
			todolist.erase(todolist.begin() + index);
		} 
		else {
			std::cout << "Task ikke fundet: " << index << std::endl;
		}
	}

};

int main() {
	// Create todo list
    	TodoList todo = TodoList();

    	// Create new task
    	todo.create_task("TEST", "OnGoing");
    	todo.create_task("TEST2", "DONE");

	// TEST PRINT
    	cout << todo.todolist.size() << endl;

	// Delete task at index 0
	todo.delete_task(0);

    	// TEST PRINT
    	cout << todo.todolist.size() << endl;

    	//Show tasks
    	todo.show_tasks();

    	return 0;
}
