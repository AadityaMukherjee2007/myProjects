import 'package:flutter/material.dart';

void main() => runApp(const MaterialApp(
  home: QuoteList(),
));

class QuoteList extends StatefulWidget {
  const QuoteList({super.key});



  @override
  State<QuoteList> createState() => _QuoteListState();
}

class _QuoteListState extends State<QuoteList> {

  List<String> quotes = [
    'Accept everything just the way it is.',
    'Do not seek pleasure for its own sake.',
    'Do not, under any circumstances, depend on a partial feeling.',
    'Think lightly of yourself and deeply of the world.',
    'Be detached from desire your whole life long.',
    'Do not regret what you have done.',
    'Never be jealous.',
    'Never let yourself be saddened by a separation.',
    'Resentment and complaint are appropriate neither for oneself nor others.',
    'Do not let yourself be guided by the feeling of lust or love.',
    'In all things have no preferences.',
    'Be indifferent to where you live.',
    'Do not pursue the taste of good food.',
    'Do not hold on to possessions you no longer need.',
    'Do not act following customary beliefs.',
    'Do not collect weapons or practice with weapons beyond what is useful.',
    'Do not fear death.',
    'Do not seek to possess either goods or fiefs for your old age.',
    'Respect Buddha and the gods without counting on their help.',
    'You may abandon your own body but you must preserve your honour.',
    'Never stray from the Way.',
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[800],
      appBar: AppBar(
        title: const Text('Quotes by Miyamoto Musashi'),
        centerTitle: true,
        backgroundColor: Colors.grey[900],
        foregroundColor: Colors.redAccent,
      ),
      
      body: Column(
        children: quotes.map((quote) {
          return Column(
            children: [
              const SizedBox(height: 30),
              Center(
                child: Text(
                    quote,
                    style: TextStyle(
                      color: Colors.amber[200],
                      fontSize: 15
                    ),
                ),
              ),
            ],
          );
        }).toList(),
      ),
    );
  }
}
