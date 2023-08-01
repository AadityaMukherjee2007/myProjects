import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

class Home extends StatelessWidget
{
  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Containers & Padding'),
        centerTitle: true,
        backgroundColor: Colors.redAccent,
      ),


    );
  }
}