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
        title: const Text('Login'),
        centerTitle: true,
        backgroundColor: Colors.grey,
      ),

      body: Column(
        children: [
          const Padding(
            padding: EdgeInsets.fromLTRB(50, 50, 50, 30),
            child: SizedBox(
              width: 280,
              child: TextField(
                decoration: InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'User'
                ),
              ),
            ),
          ),

          const Padding(
            padding: EdgeInsets.fromLTRB(50, 0, 50, 30),
            child: SizedBox(
              width: 280,
              child: TextField(
                obscureText: true,
                decoration: InputDecoration(
                  labelStyle: TextStyle(),
                  border: OutlineInputBorder(),
                  labelText: 'Password'
                ),
              ),
            ),
          ),

          SizedBox(
            width: 100,
            child: ElevatedButton(
              onPressed: () {print('Processing');},
              child: const Text('Login')
            )
          )
        ]
      ),
    );
  }
}