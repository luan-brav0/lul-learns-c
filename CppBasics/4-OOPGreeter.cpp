#include <iostream>
#include <string>

using namespace std;

class User {
private:
  string Name;

public:
  string getName() { return Name; }
  void setName() {
    cout << "What's your name?" << endl;
    string name;
    getline(cin, name);
    Name = name;
    name.clear();
  }
};

int main() {
  User User1;

  User1.setName();

  cout << "Hello " << User1.getName() << endl;

  return 0;
}
