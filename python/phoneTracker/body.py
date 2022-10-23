import phonenumbers
from phonenumbers import geocoder
from phonenumbers import carrier

number = input("Enter number: ")

ch_number = phonenumbers.parse(number, "CH") #'CH' stands for country history
print(geocoder.description_for_number(ch_number, "en"))
service_provider = phonenumbers.parse(number, "RO")
print(carrier.name_for_number(service_provider, "en"))
