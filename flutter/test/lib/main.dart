import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(home: Home()));

class Home extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Buttons&Icons'),
        centerTitle: true,
        backgroundColor: const Color.fromARGB(255, 228, 208, 121),
      ),
      body: Center(
        /*child: Icon(
          Icons.airport_shuttle,
          color: Colors.cyan,
          size: 150,
        ),*/

        child: FloatingActionButton.large(onPressed: () {},
        icon: Icon().),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          print('You clicked me');
        },
        child: Text('Click me'),
      ),
    );
  }
}
