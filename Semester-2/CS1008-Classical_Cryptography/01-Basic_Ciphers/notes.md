# Classical Cryptography

## Basic Terms

### Cryptography

Cryptography is the practice and study of techniques for secure communication
in the presence of third parties called adversaries. More generally, cryptography
is about constructing and analyzing protocols that prevent third parties or the
public from reading private messages; various aspects in information security
such as data confidentiality, data integrity, authentication, and non-repudiation
are central to modern cryptography.

### Encoding

Encoding is the process of converting data from one form to another. It specifies
a format in which data is stored and transmitted.

### Hashing

Hashing is the process of converting an input (e.g. a string) into a fixed-size
string of bytes. It is a one-way function, meaning that it is not possible to
reverse the process. It is used to verify data integrity by generating a hash
value for the original data and comparing it to the hash value of the received data.

### Steganography

Steganography is the practice of concealing a file, message, image, or video
within another file, message, image, or video. It is often used to hide the
existence of the information being communicated by embedding it in a seemingly
innocuous carrier.

### Encryption

Encryption is the process of converting plaintext into ciphertext using an
algorithm and a key. It is used to protect data confidentiality by making the
information unreadable to unauthorized users.

#### Symmetric Encryption

Symmetric encryption uses a single key to encrypt and decrypt data. It is faster
and more efficient than asymmetric encryption, but it requires the secure exchange
of the single key between the communicating parties.

#### Asymmetric Encryption

Asymmetric encryption uses a pair of keys (public and private) to encrypt and
decrypt data. It is slower and less efficient than symmetric encryption, but it
does not require the secure exchange of the private key between the communicating
parties. It is often used for key exchange and digital signatures. The public key
can be shared with anyone, while the private key is kept secret.

## Ciphers

### Caesar Cipher

Caesar cipher is a substitution cipher in which each letter in the plaintext is
shifted a certain number of places down or up the alphabet.

#### Caesar Cipher Encryption

To encrypt a message using the Caesar cipher, each letter in the plaintext is
shifted by a fixed number of positions down the alphabet. For example, with a
shift of 3, 'A' would be replaced by 'D', 'B' would become 'E', and so on. The
shift value is the key to the encryption.

#### Caesar Cipher Decryption

To decrypt a message encrypted with the Caesar cipher, each letter in the ciphertext
is shifted by the same number of positions up the alphabet. For example, with a
shift of 3, 'D' would be replaced by 'A', 'E' would become 'B', and so on. The
shift value used for decryption must be the same as the one used for encryption.

#### Caesar Cipher Example

- Plaintext: HELLO
- Shift: 3
- Ciphertext: KHOOR

#### Caesar Cipher Table

| Letter | Number |
| ------ | ------ |
| A      | 1      |
| B      | 2      |
| C      | 3      |
| D      | 4      |
| E      | 5      |
| F      | 6      |
| G      | 7      |
| H      | 8      |
| I      | 9      |
| J      | 10     |
| K      | 11     |
| L      | 12     |
| M      | 13     |
| N      | 14     |
| O      | 15     |
| P      | 16     |
| Q      | 17     |
| R      | 18     |
| S      | 19     |
| T      | 20     |
| U      | 21     |
| V      | 22     |
| W      | 23     |
| X      | 24     |
| Y      | 25     |
| Z      | 26     |

The Caesar cipher is one of the simplest and most widely known encryption techniques.
However, it is also easily broken and should not be used for secure communication.

### Vigenère Cipher

Vigenère cipher is a method of encrypting alphabetic text by using a simple form
of polyalphabetic substitution. It uses a keyword to shift the letters in the plaintext.

#### Vigenère Cipher Encryption

To encrypt a message using the Vigenère cipher, a keyword is repeated to match
the length of the plaintext. Each letter in the plaintext is shifted by the
numerical value of the corresponding letter in the keyword. The key is repeated
until it matches the length of the plaintext, and each letter in the plaintext
is shifted by the corresponding letter in the key.

#### Vigenère Cipher Decryption

To decrypt a message encrypted with the Vigenère cipher, the keyword is repeated
to match the length of the ciphertext. Each letter in the ciphertext is shifted
back by the numerical value of the corresponding letter in the keyword. The key
is repeated until it matches the length of the ciphertext, and each letter in the
ciphertext is shifted back by the corresponding letter in the key.

#### Vigenère Cipher Example

<!--TODO: Example-->

The Vigenère cipher is more secure than the Caesar cipher, but it is still vulnerable
to various forms of cryptanalysis, especially if the keyword is short or if the
ciphertext is long.

#### Vigenère Cipher Table

The Vigenère cipher uses a table known as the Vigenère square or Vigenère table.
It consists of the alphabet written out 26 times in different rows, each alphabet
shifted cyclically to the left compared to the previous alphabet, forming a 26x26
grid of letters.

|     | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| A   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   |
| B   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   |
| C   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   |
| D   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   |
| E   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   |
| F   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   |
| G   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   |
| H   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   |
| I   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   |
| J   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   |
| K   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   |
| L   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   |
| M   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   |
| N   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   |
| O   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   |
| P   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   |
| Q   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   |
| R   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   |
| S   | S   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   |
| T   | T   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   |
| U   | U   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   |
| V   | V   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   |
| W   | W   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   |
| X   | X   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   |
| Y   | Y   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   |
| Z   | Z   | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   |

### Hill Cipher

The Hill cipher is a polygraphic substitution cipher that uses linear algebra for encryption and decryption.
It involves the following steps:

1. **Key Matrix**: Choose a square matrix (key matrix) of size $( n \times n )$ with integer entries.
   The matrix must be invertible modulo 26 (for the English alphabet).

2. **Plaintext Vector**: Convert the plaintext message into vectors of size $ n $ by grouping the letters and converting them to numerical values (A=0, B=1, ..., Z=25).

3. **Encryption**: Multiply each plaintext vector by the key matrix and take the result modulo 26 to get the ciphertext vector.

4. **Decryption**: To decrypt, multiply the ciphertext vector by the inverse of the key matrix (modulo 26).

### Affine Cipher

Affine cipher is a type of monoalphabetic substitution cipher, where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter.

#### Affine Cipher Encryption

Encryption function for the affine cipher is:

$$ E(x) = (ax + b) \mod m $$

where:

- E(x) is the encrypted letter,
- x is the numerical value of the plaintext letter,
- a and b are keys of the cipher,
- m is the size of the alphabet (for the English alphabet, m = 26).

The keys a and m must be coprime to ensure that each letter maps to a unique letter.

#### Affine Cipher Decryption

Decryption function for the affine cipher is:

$$ D(x) = a^{-1}(x - b) \mod m $$

where:

- D(x) is the decrypted letter,
- x is the numerical value of the ciphertext letter,
- a and b are keys of the cipher,
- m is the size of the alphabet (for the English alphabet, m = 26),
- a^-1 is the modular multiplicative inverse of a modulo m.
  Example: a = 3, m = 26, a^-1 = 9.

The key a must have a multiplicative inverse modulo m to ensure that each letter maps back to a unique letter.

#### Affine Cipher Example

![Geeksforgeeks example image](https://media.geeksforgeeks.org/wp-content/uploads/affin-cipher.png)
