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
        title: const Text('Expanded Widgets'),
        centerTitle: true,
        backgroundColor: Colors.brown,
      ),

      body: Row(
        children: [
          Expanded(
              flex: 3,
              child: Image.asset('assets/nasa-img.jpg')
          ),

          Expanded(
            flex: 3,
            child: Container(
              padding: const EdgeInsets.all(30),
              color: Colors.cyan,
              child: const Text('1'),
            ),
          ),

          Expanded(
            flex: 2,
            child: Container(
              padding: const EdgeInsets.all(30),
              color: Colors.pinkAccent,
              child: const Text('2')
            ),
          ),

          Expanded(
            flex: 1,
            child: Container(
              padding: const EdgeInsets.all(30),
              color: Colors.amber,
              child: const Text('3'),
            ),
          )
        ],
      ),
    );
  }
}