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