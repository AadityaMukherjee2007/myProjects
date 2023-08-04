import 'package:flutter/material.dart';

<<<<<<< HEAD
void main() => runApp(const MaterialApp(home: Home()));
=======
void main() => runApp(MaterialApp(home: Home()));
>>>>>>> e3cf57fe3e5bb85a4faee6f9459fdc94fa8a130f

class Home extends StatelessWidget
{
  const Home({super.key});

  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Columns'),
        centerTitle: true,
        backgroundColor: Colors.brown,
      ),

      body: Column(
        //mainAxisAlignment: MainAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.end,
        //mainAxisAlignment: MainAxisAlignment.spaceEvenly,

        //crossAxisAlignment: CrossAxisAlignment.stretch,
        //crossAxisAlignment: CrossAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.end,
        //crossAxisAlignment: CrossAxisAlignment.start,

        children: [
          const Row(
            children: [
              Text('Hello'),
              Text('World')
            ],
          ),
          Container(
            padding: const EdgeInsets.all(20),
            color: Colors.cyan,
            child: const Text('One')
          ),

<<<<<<< HEAD
          Padding(
            padding: const EdgeInsets.all(20),
            child: Container(
                padding: const EdgeInsets.all(30),
                color: Colors.pinkAccent,
                child: const Text('Two')
            ),
          ),

          Center(
            child: Container(
                padding: const EdgeInsets.all(40),
                color: Colors.amber,
                child: const Text('Three')
            ),
          )
=======
          Container(
              padding: const EdgeInsets.all(30),
              color: Colors.pink,
              child: const Text('Two')
          ),

          Container(
              padding: const EdgeInsets.all(40),
              color: Colors.yellow,
              child: const Text('Three')
          ),
>>>>>>> e3cf57fe3e5bb85a4faee6f9459fdc94fa8a130f
        ],
      ),
    );
  }
}