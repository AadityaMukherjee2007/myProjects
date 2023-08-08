import 'package:flutter/material.dart';

void main() => runApp(const MaterialApp(home: Home()));

class Home extends StatelessWidget {
  const Home({super.key});

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

        /*
        child: ElevatedButton.icon(
          onPressed: () {  },
          icon: const Icon(
            Icons.mail,
          ),
          label: const Text('mail me'),
          style: ElevatedButton.styleFrom(
            backgroundColor: Colors.amber
          ),
        ),*/

        child: IconButton(
          onPressed: () {print('you clicked me');},
          icon: const Icon(Icons.alternate_email),
          color: Colors.amber,
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          print('You clicked me');
        },
        child: const Text('Click'),
      ),
    );
  }
}

