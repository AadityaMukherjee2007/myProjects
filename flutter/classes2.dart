void main() {
  User user1 = User("Alex", 16);
  print(user1.userName);
  print(user1.age);
  user1.login();
}

class User {
  String userName;
  int age;

  User(String n, int a) {
    this.userName = n;
    this.age = a;
  }

  void login() {
    print("Logged In!\n");
  }
}
