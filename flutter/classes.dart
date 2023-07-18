void main() {
  User userOne = User();
  print(userOne.userName);
  print(userOne.age);
  userOne.login();
  print("\n");

  User userTwo = User();
  userTwo.userName = "Peter";
  userTwo.age = 17;
  print(userTwo.userName);
  print(userTwo.age);
  userTwo.login();
}

class User {
  String userName = "Alex";
  int age = 16;

  void login() {
    print("User logged in!");
  }
}
