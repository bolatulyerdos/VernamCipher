# Vernam cipher (one-time pad)
Implementation of Vernam cipher, also known as one-time pad.

## Description
The Vernam cipher is a symmetric cipher invented in 1917 by Gilbert Vernam.

The Vernam cipher uses the XOR (exclusive OR) operation. Encryption and decryption is done with the same key. It takes as input a message and a key of the same length. Each bit of the message undergoes an XOR operation with the corresponding bit of the key. The result of the XOR operation is an encrypted message.

It is important that the key consists of truly random bits and is used only once, otherwise the cryptographic strength of the cipher will be violated.

When used correctly, the cipher has absolute cryptographic strength.