import 'package:flutter/material.dart';

void main() => runApp(const MaterialApp(home: Home()));

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("My First App"),
        centerTitle: true,
        backgroundColor: Colors.red[700],
      ),
      body: Center(
        child: Text(
          "Flutter",
          style: TextStyle(
              fontSize: 50.0,
              fontFamily: 'IndieFlower',
              fontWeight: FontWeight.bold,
              letterSpacing: 2.0,
              color: Colors.grey[700]),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {},
        backgroundColor: Colors.red[700],
        child: const Text("Click"),
      ),
    );
  }
}
