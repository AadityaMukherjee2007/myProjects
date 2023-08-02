import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

class Home extends StatelessWidget
{
  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Padding'),
        centerTitle: true,
        backgroundColor: Colors.orange
      ),

      body: const Padding(
        padding: EdgeInsets.all(90),
        child: Text('Hello'),
      ),
    );
  }
}