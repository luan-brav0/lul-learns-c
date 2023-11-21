#include <iostream>

using namespace std;

int main() {
  string name = "Urmom";
  cout << "What's your name?" << endl;
  getline(cin, name);

  cout << "Hello " << name << endl;

  return 0;
}
