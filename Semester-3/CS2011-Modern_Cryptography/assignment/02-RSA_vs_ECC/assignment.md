# Comparison Between RSA and ECC

## Introduction

Cryptography protects digital data using math-based methods.
Public-key cryptography uses two keys — a public and a private key — for secure communication.

Two main algorithms are:

- **RSA (Rivest–Shamir–Adleman):** Old and widely used since 1977.
- **ECC (Elliptic Curve Cryptography):** Newer and gives same security with smaller keys.

This paper explains how they work, their pros and cons, common RSA attacks, and safety tips.

## How They Work

| Feature | RSA | ECC |
|----------|-----|-----|
| Idea | Based on factoring large numbers | Based on elliptic curve math |
| Introduced | 1977 | 1985 |
| Security Problem | Integer Factorization | Elliptic Curve Discrete Log |
| Example Key Size | 3072-bit | 256-bit |

### **RSA Steps**

1. Choose two prime numbers $p$ and $q$
2. Compute $n = p \times q$ and $\phi(n) = (p-1)(q-1)$
3. Pick $e$ (often 65537) and find private key $d$
4. Public key = $(n, e)$, Private key = $(n, d)$
5. Encryption: $C = M^e \bmod n$, Decryption: $M = C^d \bmod n$

### **ECC Basics**

Uses points on a curve like $y^2 = x^3 + ax + b$.
If $Q = kP$, finding $k$ from $P$ and $Q$ is very hard.
Smaller keys give same security as larger RSA keys.

## Pros and Cons

| RSA | ECC |
|-----|-----|
| **Advantages** | **Advantages** |
| Well-tested and easy to use | Smaller keys, faster, low power |
| Widely supported | Great for phones and IoT |
| **Disadvantages** | **Disadvantages** |
| Large keys slow performance | Harder math and setup |
| Uses more memory and power | Not supported everywhere |

## RSA Attacks and Fixes

| Attack Type | Description | Protection |
|--------------|-------------|-------------|
| **Factoring** | Breaking $n$ into $p$ and $q$ | Use $\geq$ 2048-bit keys |
| **Timing Attack** | Key leaks from decryption time | Use constant-time code |
| **Small Exponent** | Weak encryption if $e$ is small | Use OAEP padding |
| **Chosen Ciphertext** | Crafted messages reveal key | Use OAEP or PSS |
| **Quantum Attack** | Future threat from quantum computers | Research post-quantum methods |
| **Poor Implementation** | Weak randomness or key reuse | Use secure libraries |

## Improving RSA Security

- **Key Size:** Use $2048$–$4096$ bits
- **Padding:** Always use OAEP (encryption) or PSS (signatures)
- **Implementation:** Use constant-time operations
- **Key Safety:** Store encrypted keys, never reuse
- **Updates:** Keep crypto tools updated

## Conclusion

Both RSA and ECC are vital for encryption.
RSA is simple and widely supported but needs big keys.
ECC gives the same security with smaller keys, faster speed, and lower power use — ideal for new systems.

| Use Case | Recommended Algorithm |
|-----------|-----------------------|
| Old systems or wide compatibility | RSA |
| Mobile, IoT, and modern systems | ECC |

Both will stay useful until **post-quantum cryptography** becomes common.
