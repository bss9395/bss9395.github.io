---
layout:    en_post
Topic:     Computer
Title:     Cryptography Based on Rational Number
Revised:   2020-12-27 08:38:00 +08 @ China-Guangdong-Zhanjiang +08
Authors:   BSS9395
Resources:
---

# Rational Cryptography
CipherText = Encrypt(PrivateKey, PlainText)
PlainText  = Decrypt(PublicKey , CipherText)

PlainText  ≡              Plain_Numerator  / Plain_Denominator
CipherText ≡              Cipher_Numerator / Cipher_Denominator
PrivateKey ≡ (Private_Numerator % Modulus) / (Private_Denominator % Modulus)
PublicKey  ≡ (Public_Numberator % Modulus) / (Private_Denominator % Modulus)

# Asymmetric Key Pair
    Private_Numer × Public_Numer % Modulus   Private_Numer % Modulus   Public_Numer % Modulus
1 = —————————————————————————————————————— = ——————————————————————— × ——————————————————————
    Private_Denom × Public_Denom % Modulus   Private_Denom % Modulus   Public_Denom % Modulus

# Encryption
Cipher_Numer   Plain_Numer   Private_Numer % Modulus    ⌘ Plain_Numer < Modulus
———————————— = ——————————— × ———————————————————————
Cipher_Denom   Plain_Denom   Private_Denom % Modulus    ⌘ Plain_Denom < Modulus

# Decryption
Plain_Numer   Cipher_Numer   Public_Numer % Modulus
——————————— = ———————————— × ——————————————————————
Plain_Denom   Cipher_Denom   Public_Denom % Modulus

