from chatterbot import ChatBot
from chatterbot.trainer import ChatterBotCorpusTrainer

chatbot = ChatBot('ChatBot')
trainer = ChatterBotCorpusTrainer(chatbot)

trainer.train("chatterbot.corpus.english.greetings", "chatterbot.corpus.english.conversations")

user = input("> ")
response = chatbot.get_response(user)
print(response)
