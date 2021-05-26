#include <iostream>
#include <stack>
using namespace std;


class Squeue {
private:
    stack<int> s1; // The stack used for data storage.
    stack<int> s2; // The stack used for supporting operation "Pop" and "Front".
    
public:
    int Size() const; // Get the size of Squeue.
    bool Empty() const; // Judge whether Squeue is empty.
    void Push(const int &ele); // Push operation of Squeue.
    void Pop(); // Pop operation of Squeue.
    int Front(); // Get the first element of Squeue, return 0 if empty.
    int Back() const; // Get the last element of Squeue, return 0 if empty.
    
    friend void DisplaySqueue(Squeue &sq); // Notice: You NEED NOT to implement this function.
};
int Squeue::Size() const{
    return s1.size();
} // Get the size of Squeue.
bool Squeue::Empty() const{
    return s1.empty();
} // Judge whether Squeue is empty.
void Squeue::Push(const int &ele){
    s1.push(ele);
} // Push operation of Squeue.
void Squeue::Pop(){
    if(!s1.empty()){
        while(s1.size()!=1){
        s2.push(s1.top());
        s1.pop();
        }
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

} // Pop operation of Squeue.
int Squeue::Front(){
    int res=0;
    if(s1.empty()){
        return res;
    }
    else{
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        res=s1.top();
        s2.push(res);
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
}
    // Get the first element of Squeue, return 0 if empty.
int Squeue::Back() const{
    return s1.empty()?0:s1.top();
} // Get the last element of Squeue, return 0 if empty.

void DisplaySqueue(Squeue &sq) {
	cout << "Head->";
	while(!sq.s1.empty()) {
		sq.s2.push(sq.s1.top());
		sq.s1.pop();
	}
	while(!sq.s2.empty()) {
		cout << sq.s2.top() << "->";
		sq.s1.push(sq.s2.top());
		sq.s2.pop();
	}
	cout << "Tail" << endl;
}


int main() {
	Squeue sq;
	int num_commands;
	cin >> num_commands;
	
	string command_type;
	int command_value;
	
	for(int i=1; i<=num_commands; ++i) {
		cout << "No." << i << " Command: ";
		cin >> command_type;
		if(command_type == "Push") {
			cin >> command_value;
			sq.Push(command_value);
			cout << "Squeue after Push(" << command_value << "): ";
			DisplaySqueue(sq);
		}
		else if(command_type == "Pop") {
			sq.Pop();
			cout << "Squeue after Pop(): ";
			DisplaySqueue(sq);
		}
		else if(command_type == "Front") {
			command_value = sq.Front();
			cout << "Front element of Squeue: " << command_value << endl;
		}
		else if(command_type == "Back") {
			command_value = sq.Back();
			cout << "Back element of Squeue: " << command_value << endl;
		}
		else if(command_type == "Size") {
			command_value = sq.Size();
			cout << "Size of Squeue: " << command_value << endl;
		}
	}
	return 0;
}