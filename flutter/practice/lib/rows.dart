import 'package:flutter/material.dart';

void main() => runApp(const MaterialApp(home: Home()));

class Home extends StatelessWidget
{
  const Home({super.key});

  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Rows'),
        centerTitle: true,
        backgroundColor: Colors.orange
      ),

      body: Row(
        //mainAxisAlignment: MainAxisAlignment.center,
        //mainAxisAlignment: MainAxisAlignment.spaceBetween,
        //mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        //mainAxisAlignment: MainAxisAlignment.end,
        mainAxisAlignment: MainAxisAlignment.spaceAround,

        //crossAxisAlignment: CrossAxisAlignment.stretch,
        //crossAxisAlignment: CrossAxisAlignment.center,
        //crossAxisAlignment: CrossAxisAlignment.start,
        crossAxisAlignment: CrossAxisAlignment.end,

        children: [
          const Text('Hello, World!'),
          TextButton(
            onPressed: () {print('Button Clicked!');},

            style: TextButton.styleFrom(
              foregroundColor: Colors.white,
              backgroundColor: Colors.grey
            ),
            child: const Text('Click me'),
          ),

          Container(
            color: Colors.cyan,
            padding: const EdgeInsets.all(30),
            child: const Text('inside container'),
          )
        ],
      ),
    );
  }
}