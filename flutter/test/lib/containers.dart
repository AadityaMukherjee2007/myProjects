import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

class Home extends StatelessWidget
{
  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Containers'),
        centerTitle: true,
        backgroundColor: Colors.redAccent,
      ),

      body: Container(
        //padding
        //padding: const EdgeInsets.all(20),
        //padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 10),
        padding: const EdgeInsets.fromLTRB(10, 20, 30, 40),

        //margin
        margin: const EdgeInsets.all(30),
        color: Colors.grey[400],
        child: const Text('Hello'),
      ),
    );
  }
}