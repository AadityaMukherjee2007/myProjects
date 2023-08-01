import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

class Home extends StatelessWidget {
  const Home({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('ImageBasics'),
        centerTitle: true,
        backgroundColor: const Color.fromARGB(255, 111, 157, 243),
      ),
      body: Center(
        child: Image.asset('assets/nasa-img.jpg'),
        /*child: Image(
        image: NetworkImage(
            'https://images.unsplash.com/photo-1446776811953-b23d57bd21aa?ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D&auto=format&fit=crop&w=872&q=80'),
      )*/
      ),
    );
  }
}
