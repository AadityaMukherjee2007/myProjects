import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

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
        ],
      ),
    );
  }
}