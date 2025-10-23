def my_function(fname):
  print(fname + " Refsnes")

my_function("Emil")
my_function("Tobias")
my_function("Linus")


def my_function2(fname, lname):
  print(fname + " " + lname)

my_function2("Emil", "Refsnes")


def my_function3(*kids):
  print("The youngest child is " + kids[2])

my_function3("Emil", "Tobias", "Linus")


def my_function4(child3, child2, child1):
  print("The youngest child is " + child3)

my_function4(child1 = "Emil", child2 = "Tobias", child3 = "Linus")


def my_function5(**kid):
  print("His last name is " + kid["lname"])

my_function5(fname = "Tobias", lname = "Refsnes")


def my_function6(country = "Norway"):
  print("I am from " + country)

my_function6("Sweden")
my_function6("India")
my_function6()
my_function6("Brazil")
