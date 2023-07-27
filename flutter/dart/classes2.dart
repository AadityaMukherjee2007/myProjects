void main() {
  User user1 = User("Alex", 16);
  print(user1.userName);
  print(user1.age);
  user1.login();

  User user2 = User("Mario", 10);
  print(user2.userName);
  print(user2.age);
  user2.login();
  //user2.publish(); will show error as it does not have access to class SuperUser

  SuperUser user3 = SuperUser("Peter", 20);
  print(user3.userName);
  print(user3.age);
  user3.login();
  user3.publish();
}

class User {
  String userName = "";
  int age = 0;

  User(String name, int age) {
    this.userName = name;
    this.age = age;
  }

  void login() {
    print("Logged In!\n");
  }
}

class SuperUser extends User {
  SuperUser(String name, int age) : super(name, age);
  void publish() {
    print("published update");
  }
}
