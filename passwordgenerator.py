import secrets
import string

length=int(input('Enter length of Password'))

low=string.ascii_lowercase
upper=string.ascii_uppercase
letter=string.ascii_letters
num=string.digits
hex=string.hexdigits
oct=string.octdigits
symbol=string.punctuation

all=low+upper+letter+num+hex+oct+symbol

password=''.join(secrets.choice(all) for _ in range(length))

print(f'Password is: {password}')
