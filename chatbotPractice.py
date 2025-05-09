import nltk 
import random 
from nltk.chat.util import Chat , reflections 


#Define Patterns and responses 
pairs = [
    [
        r"hi(.*)|hello(.*)|hey(.*)" ,
        ["Hello ! Welcome to our customer service . " ,
         "Hi there ! how may i help you ? "]
        
    ],
    [
        r"bye|goodbye|quit|exit" ,
        ["Thank you for contacting us . Have a great day !" ,
         "Goodbye ! Feel free to reach us again"]
    ],
    [
        r"(.*)order status|track my order|where is my package" ,
        ["I can check your order status.Please provide your order number."]
    ],
    [
        r"(.*)store open|store timings" ,
        ["Our Store is Open Monday - Friday 9AM - 9pm , Saturday 10AM - 8PM."]
    ]
]

def customer_service_chatbot():
    print("Customer Service Bot : Hello ! How can I help you today? (Type 'quit' to exit)")
    chat = Chat(pairs,reflections)
    chat.converse()

# Run the Chatbot 
if __name__ == '__main__' :
    customer_service_chatbot()