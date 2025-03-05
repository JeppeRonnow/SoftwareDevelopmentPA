#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

		cout << endl;

		save_tasks_to_txt();
	}

	// Show tasks
	void show_tasks(){
		// Print new line with each task
		for (int i = 0; i < todolist.size(); i++){
			string status = todolist[i]._status;
			string description = todolist[i]._description;
			int j = i + 1;
			cout << "[" << status << "] " << j << ". " << description << "\n";
		}
		
		// Make new line and flush buffer
		cout << endl;
	}

	// Delete task
	void delete_task() {
		// Function variables
		int index;

		// Get index
		cout << "Enter task number to delete: ";
		cin >> index;
		index--;

		// Check for task and delete
		if (index >= 0 && index < todolist.size()) {
			todolist.erase(todolist.begin() + index);
			cout << "Task deleted!\n" << endl;
		} 
		else {
			cout << "Task not found: " << index + 1 << "\n" << endl;
		}

		save_tasks_to_txt();
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
			cout << "Task updated!\n" << endl;
		} 
		else {
			cout << "Task not found: " << index + 1 << "\n" << endl;
		}

		save_tasks_to_txt();
	}

	void save_tasks_to_txt() {
		// Function variables
		string filename = "todo.txt";

		// Open file
		ofstream file(filename);
		if (file.is_open()) {
			// Write tasks to file
      for (int i = 0; i < todolist.size(); i++) {
			    string status = todolist[i]._status;
			    string description = todolist[i]._description;
			    file << status << " " << description << "\n";
			}
			file.close();
		}
	}

	void load_tasks_from_txt() {
		// Function variables
		string filename = "todo.txt";

		// Open file
		ifstream file(filename);
		if (file.is_open()) {
			// Read tasks from file
			string line;
			while (getline(file, line)) {
				string status = line.substr(0, line.find(" "));
				string description = line.substr(line.find(" ") + 1);
				Task new_task = Task(description, status);
				todolist.push_back(new_task);
			}
			file.close();
		}
	}
};

// Print all commands
void help(const unordered_map<string, function<void()>>& commands) {
	cout << "Available commands:\n";
	for (const auto& pair : commands) {
		cout << pair.first << "\n";
	}
	cout << endl;
}

// Main function
int main() {
	// Create todo list
    	TodoList todo = TodoList();
	
	// Unordered map with all user functions fucntions	
	unordered_map<string, function<void()>> commands = {
		{"create", [&todo]() {todo.create_task(); }},
		{"delete", [&todo]() {todo.delete_task(); }},
		{"update", [&todo]() {todo.update_task(); }},
		{"show",   [&todo]() {todo.show_tasks();  }}
	};

	todo.load_tasks_from_txt();
	// Main loop
	while (true) {
		// Take input
		cout << "ToDo List: ";
		string call;
		cin >> call;
		
		// Check input and call function
		if (commands.find(call) != commands.end()) {
			commands[call](); // Call function from map
		} else if (call == "help") {
			help(commands); // Pass the map with cunctions
		} else {
			cout << "Invalid command (use \"help\" to se list of commands)\n" << endl;
		}

	}

    	return 0;
}
