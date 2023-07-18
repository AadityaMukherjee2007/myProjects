void main() {
  print('hello');

  int age = 30;
  print(age);

  String name = 'John';
  name = "ken";
  print(name);

  bool isDay = true;
  print(isDay);

  dynamic val = "var";
  val = 20;
  print(val);

  print(greeting());

  age = currentAge();
  print(age);

  print("\n");
  list();
}

String greeting() => "Holla!";

int currentAge() {
  return 16;
}

void list() {
  List squads = ["Alpha", "Beta", "Charlie"]; // List of any datatype
  squads.add("Delta");
  squads.remove("Alpha");
  squads.add(65);
  print(squads);

  List<int> numList = [
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10
  ]; //LIst of particular datatype
  print(numList);
  //numList.add("Charlie"); this line will cause an error...
}
