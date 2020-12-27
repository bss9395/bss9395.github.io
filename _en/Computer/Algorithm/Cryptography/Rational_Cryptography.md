---
layout:    en_post
Topic:     Computer
Title:     Cryptography Based on Rational Number
Revised:   2020-12-27 23:07:00 +08 @ China-Guangdong-Zhanjiang +08
Authors:   BSS9395
Resources:
---

# Rational Cryptography
CipherText = Encrypt(PrivateKey, PlainText)
PlainText  = Decrypt(PublicKey , CipherText)

PlainText  ≡   Plain_Numerator  / Plain_Denominator
CipherText ≡   Cipher_Numerator / Cipher_Denominator
PrivateKey ≡ (Private_Numerator % Prime_Numerator) / (Private_Denominator % Prime_Denominator)
PublicKey  ≡ (Public_Numerator  % Prime_Numerator) / (Public_Denominator  % Prime_Denominator)

# Asymmetric Key Pair
    (Private_Numer × Public_Numer) % Prime_Numer   Rat
1 = ———————————————————————————————————————————— = ———
    (Private_Denom × Public_Denom) % Prime_Denom   Rat

    Private_Numer % Prime_Numer   Public_Numer % Prime_Numer
1 = ——————————————————————————— × ——————————————————————————
    Private_Denom % Prime_Denom   Public_Denom % Prime_Denom

# Encryption
Cipher_Numer   (Plain_Numer   Private_Numer) % Prime_Numer    ⌘ Plain_Numer × Rat < Prime_Numer
———————————— = ———————————— × ————————————————————————————
Cipher_Denom   (Plain_Denom   Private_Denom) % Prime_Denom    ⌘ Plain_Denom × Rat < Prime_Denom

# Decryption
Plain_Numer   (Cipher_Numer   Public_Numer) % Prime_Numer
——————————— = ————————————— × ———————————————————————————
Plain_Denom   (Cipher_Denom   Public_Denom) % Prime_Denom

# Example
PlainText  = 4/5 = 0.8
PrivateKey = (4 % 17)/(13 % 23)
PublicKey  = (5 % 17)/(2  % 23)

CipherText = 4/5   × (4 % 17)/(13 % 23) = (4 × 4  % 17)/(5  × 13 % 23) = 16/19
PlainText  = 16/19 × (5 % 17)/(2  % 23) = (16 × 5 % 17)/(19 × 2  % 23) = 12/15 = 0.8

