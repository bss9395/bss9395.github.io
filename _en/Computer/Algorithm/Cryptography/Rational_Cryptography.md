---
layout:    en_post
Topic:     Computer
Title:     Cryptography Based on Rational Number
Revised:   2020-12-27 09:57:00 +08 @ China-Guangdong-Zhanjiang +08
Authors:   BSS9395
Resources:
---

# Rational Cryptography
CipherText = Encrypt(PrivateKey, PlainText)
PlainText  = Decrypt(PublicKey , CipherText)

PlainText  ≡              Plain_Numerator  / Plain_Denominator
CipherText ≡              Cipher_Numerator / Cipher_Denominator
PrivateKey ≡ (Private_Numerator % Private_Numerator_Modulus) / (Private_Denominator % Private_Denominator_Modulus)
PublicKey  ≡ (Public_Numberator % Public_Numerator_Modulus)  / (Public_Denominator  % Public_Denominator_Modulus)

# Asymmetric Key Pair
    (Private_Numer % Private_Numer_Modu) × (Public_Numer % Public_Numer_Modu)
1 = —————————————————————————————————————————————————————————————————————————
    (Private_Denom % Private_Denom_Modu) × (Public_Denom % Public_Denom_Modu)

    Private_Numer % Private_Muner_Modu   Public_Numer % Public_Numer_Modu
1 = —————————————————————————————————— × ————————————————————————————————
    Private_Denom % Private_Denom_Modu   Public_Denom % Public_Denom_Modu

# Encryption
Cipher_Numer   (Plain_Numer   Private_Numer) % Private_Numer_Modu    ⌘ Plain_Numer < Private_Numer_Modu
———————————— = ———————————— × ———————————————————————————————————
Cipher_Denom   (Plain_Denom   Private_Denom) % Private_Denom_Modu    ⌘ Plain_Denom < Private_Denom_Modu

# Decryption
Plain_Numer   (Cipher_Numer   Public_Numer) % Public_Numer_Modu      ⌘ Plain_Numer < Public_Numer_Modu
——————————— = ————————————— × —————————————————————————————————
Plain_Denom   (Cipher_Denom   Public_Denom) % Public_Denom_Modu      ⌘ Plain_Denom < Public_Denom_Modu

