import 'package:flutter/material.dart';

void main() {
  runApp(const MaterialApp(
    home: NinjaCard(),
  ));
}

class NinjaCard extends StatefulWidget {
  const NinjaCard({super.key});

  @override
  State<NinjaCard> createState() => _NinjaCardState();
}

class _NinjaCardState extends State<NinjaCard> {

  int ninjaLevel = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Colors.grey[900],
        appBar: AppBar(
          title: const Text('Ninja ID Card'),
          centerTitle: true,
          backgroundColor: Colors.grey[850],
          elevation: 0,
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: () {
            setState(() {
              ninjaLevel += 1;
            });
            },
          backgroundColor: Colors.grey[850],
          child: const Icon(Icons.add),
        ),
        body: Padding(
            padding: const EdgeInsets.fromLTRB(30, 40, 30, 0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const Center(
                  child: CircleAvatar(
                    backgroundImage: AssetImage("assets/kakashi_1.jpg"),
                    radius: 80,
                  ),
                ),
                Divider(
                  height: 50,
                  color: Colors.grey[800],
                ),
                const Text(
                  'NAME',
                  style: TextStyle(color: Colors.grey, letterSpacing: 2),
                ),
                const SizedBox(
                  height: 10,
                ),
                Text(
                  'Kakashi Hatake',
                  style: TextStyle(
                      color: Colors.amberAccent[200],
                      letterSpacing: 2,
                      fontSize: 28,
                      fontWeight: FontWeight.bold),
                ),
                const SizedBox(
                  height: 40,
                ),
                const Text(
                  'CURRENT NINJA LEVEL',
                  style: TextStyle(color: Colors.grey, letterSpacing: 2),
                ),
                const SizedBox(
                  height: 10,
                ),
                Text(
                  '$ninjaLevel',
                  style: TextStyle(
                      color: Colors.amberAccent[200],
                      letterSpacing: 2,
                      fontSize: 28,
                      fontWeight: FontWeight.bold),
                ),
                const SizedBox(
                  height: 40,
                ),
                Row(
                  children: [
                    Icon(
                      Icons.email,
                      color: Colors.grey[400],
                    ),
                    const SizedBox(
                      width: 10,
                    ),
                    Text(
                      'kakashi.hatake@ninja.com',
                      style: TextStyle(
                        color: Colors.grey[400],
                        fontSize: 18,
                        letterSpacing: 1
                      ),
                    )
                  ],
                )
              ],
            )
        ),
    );
  }
}