#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>
#include <unordered_map>
#include <functional>

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
	void create_task(){
		// Function variables
		string description;
		string status;

		// Get description
		cout << "Enter new task description: ";
		cin >> description;

		// Get status
		cout << "Enter status of task: ";
		cin >> status;

		// Create new task
		Task new_task = Task(description, status);

		// Add task to todolist
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
			int j = i + 1;
			cout << format("[{}] {}. {}\n", status, j, description);
		}
		
		// Make new line and flush buffer
		cout << endl;
	}

	// Delete task
	void delete_task() {
		// Function variables
		int index;

		// Get index
		cin >> index;
		index--;

		// Check for task and delete
		if (index >= 0 && index < todolist.size()) {
			todolist.erase(todolist.begin() + index);
		} 
		else {
			std::cout << "Task not found: " << index << std::endl;
		}
	}

	void update_task() {
		// Function variables
		int index;
		string status;

		// Get index
		cout << "Enter task number to update: ";
		cin >> index;
		index--;

		// Get new status
		cout << "Enter new status: ";
		cin >> status;
		
		// Check for task and update
		if (index >= 0 && index < todolist.size()) {
			todolist[index]._status = status;
			cout << "Task updated!" << endl;
		} 
		else {
			std::cout << "Task ikke fundet: " << index << std::endl;
		}
	}

};

int main() {
	// Create todo list
    	TodoList todo = TodoList();
	
	// Unordered map with all user functions fucntions	
	unordered_map<string, function<void()>> commands = {
		{"Create", [&todo]() {todo.create_task(); }},
		{"Delete", [&todo]() {todo.delete_task(); }},
		{"Update", [&todo]() {todo.update_task(); }},
		{"Show",   [&todo]() {todo.show_tasks();  }}
	};

	// Main loop
	while (true) {
		// Take input
		cout << "ToDo List: ";
		string call;
		cin >> call;
		
		// Check input and call function
		if (commands.find(call) != commands.end()) {
			commands[call]();
		} else {
			cout << "Invalid command (use \"Help\" to se list of commands)" << endl;
		}

	}

    	return 0;
}
