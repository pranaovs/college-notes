"""
AES-128 Implementation
This module provides a custom implementation of the Advanced Encryption Standard (AES)
with 128-bit key support for educational purposes.
"""

# Constants and lookup tables
RCON = [
    0x00,
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x1B,
    0x36,
    0x6C,
    0xD8,
    0xAB,
    0x4D,
    0x9A,
]

# AES S-box
S_BOX = [
    0x63,
    0x7C,
    0x77,
    0x7B,
    0xF2,
    0x6B,
    0x6F,
    0xC5,
    0x30,
    0x01,
    0x67,
    0x2B,
    0xFE,
    0xD7,
    0xAB,
    0x76,
    0xCA,
    0x82,
    0xC9,
    0x7D,
    0xFA,
    0x59,
    0x47,
    0xF0,
    0xAD,
    0xD4,
    0xA2,
    0xAF,
    0x9C,
    0xA4,
    0x72,
    0xC0,
    0xB7,
    0xFD,
    0x93,
    0x26,
    0x36,
    0x3F,
    0xF7,
    0xCC,
    0x34,
    0xA5,
    0xE5,
    0xF1,
    0x71,
    0xD8,
    0x31,
    0x15,
    0x04,
    0xC7,
    0x23,
    0xC3,
    0x18,
    0x96,
    0x05,
    0x9A,
    0x07,
    0x12,
    0x80,
    0xE2,
    0xEB,
    0x27,
    0xB2,
    0x75,
    0x09,
    0x83,
    0x2C,
    0x1A,
    0x1B,
    0x6E,
    0x5A,
    0xA0,
    0x52,
    0x3B,
    0xD6,
    0xB3,
    0x29,
    0xE3,
    0x2F,
    0x84,
    0x53,
    0xD1,
    0x00,
    0xED,
    0x20,
    0xFC,
    0xB1,
    0x5B,
    0x6A,
    0xCB,
    0xBE,
    0x39,
    0x4A,
    0x4C,
    0x58,
    0xCF,
    0xD0,
    0xEF,
    0xAA,
    0xFB,
    0x43,
    0x4D,
    0x33,
    0x85,
    0x45,
    0xF9,
    0x02,
    0x7F,
    0x50,
    0x3C,
    0x9F,
    0xA8,
    0x51,
    0xA3,
    0x40,
    0x8F,
    0x92,
    0x9D,
    0x38,
    0xF5,
    0xBC,
    0xB6,
    0xDA,
    0x21,
    0x10,
    0xFF,
    0xF3,
    0xD2,
    0xCD,
    0x0C,
    0x13,
    0xEC,
    0x5F,
    0x97,
    0x44,
    0x17,
    0xC4,
    0xA7,
    0x7E,
    0x3D,
    0x64,
    0x5D,
    0x19,
    0x73,
    0x60,
    0x81,
    0x4F,
    0xDC,
    0x22,
    0x2A,
    0x90,
    0x88,
    0x46,
    0xEE,
    0xB8,
    0x14,
    0xDE,
    0x5E,
    0x0B,
    0xDB,
    0xE0,
    0x32,
    0x3A,
    0x0A,
    0x49,
    0x06,
    0x24,
    0x5C,
    0xC2,
    0xD3,
    0xAC,
    0x62,
    0x91,
    0x95,
    0xE4,
    0x79,
    0xE7,
    0xC8,
    0x37,
    0x6D,
    0x8D,
    0xD5,
    0x4E,
    0xA9,
    0x6C,
    0x56,
    0xF4,
    0xEA,
    0x65,
    0x7A,
    0xAE,
    0x08,
    0xBA,
    0x78,
    0x25,
    0x2E,
    0x1C,
    0xA6,
    0xB4,
    0xC6,
    0xE8,
    0xDD,
    0x74,
    0x1F,
    0x4B,
    0xBD,
    0x8B,
    0x8A,
    0x70,
    0x3E,
    0xB5,
    0x66,
    0x48,
    0x03,
    0xF6,
    0x0E,
    0x61,
    0x35,
    0x57,
    0xB9,
    0x86,
    0xC1,
    0x1D,
    0x9E,
    0xE1,
    0xF8,
    0x98,
    0x11,
    0x69,
    0xD9,
    0x8E,
    0x94,
    0x9B,
    0x1E,
    0x87,
    0xE9,
    0xCE,
    0x55,
    0x28,
    0xDF,
    0x8C,
    0xA1,
    0x89,
    0x0D,
    0xBF,
    0xE6,
    0x42,
    0x68,
    0x41,
    0x99,
    0x2D,
    0x0F,
    0xB0,
    0x54,
    0xBB,
    0x16,
]

# Inverse S-box
INV_S_BOX = [
    0x52,
    0x09,
    0x6A,
    0xD5,
    0x30,
    0x36,
    0xA5,
    0x38,
    0xBF,
    0x40,
    0xA3,
    0x9E,
    0x81,
    0xF3,
    0xD7,
    0xFB,
    0x7C,
    0xE3,
    0x39,
    0x82,
    0x9B,
    0x2F,
    0xFF,
    0x87,
    0x34,
    0x8E,
    0x43,
    0x44,
    0xC4,
    0xDE,
    0xE9,
    0xCB,
    0x54,
    0x7B,
    0x94,
    0x32,
    0xA6,
    0xC2,
    0x23,
    0x3D,
    0xEE,
    0x4C,
    0x95,
    0x0B,
    0x42,
    0xFA,
    0xC3,
    0x4E,
    0x08,
    0x2E,
    0xA1,
    0x66,
    0x28,
    0xD9,
    0x24,
    0xB2,
    0x76,
    0x5B,
    0xA2,
    0x49,
    0x6D,
    0x8B,
    0xD1,
    0x25,
    0x72,
    0xF8,
    0xF6,
    0x64,
    0x86,
    0x68,
    0x98,
    0x16,
    0xD4,
    0xA4,
    0x5C,
    0xCC,
    0x5D,
    0x65,
    0xB6,
    0x92,
    0x6C,
    0x70,
    0x48,
    0x50,
    0xFD,
    0xED,
    0xB9,
    0xDA,
    0x5E,
    0x15,
    0x46,
    0x57,
    0xA7,
    0x8D,
    0x9D,
    0x84,
    0x90,
    0xD8,
    0xAB,
    0x00,
    0x8C,
    0xBC,
    0xD3,
    0x0A,
    0xF7,
    0xE4,
    0x58,
    0x05,
    0xB8,
    0xB3,
    0x45,
    0x06,
    0xD0,
    0x2C,
    0x1E,
    0x8F,
    0xCA,
    0x3F,
    0x0F,
    0x02,
    0xC1,
    0xAF,
    0xBD,
    0x03,
    0x01,
    0x13,
    0x8A,
    0x6B,
    0x3A,
    0x91,
    0x11,
    0x41,
    0x4F,
    0x67,
    0xDC,
    0xEA,
    0x97,
    0xF2,
    0xCF,
    0xCE,
    0xF0,
    0xB4,
    0xE6,
    0x73,
    0x96,
    0xAC,
    0x74,
    0x22,
    0xE7,
    0xAD,
    0x35,
    0x85,
    0xE2,
    0xF9,
    0x37,
    0xE8,
    0x1C,
    0x75,
    0xDF,
    0x6E,
    0x47,
    0xF1,
    0x1A,
    0x71,
    0x1D,
    0x29,
    0xC5,
    0x89,
    0x6F,
    0xB7,
    0x62,
    0x0E,
    0xAA,
    0x18,
    0xBE,
    0x1B,
    0xFC,
    0x56,
    0x3E,
    0x4B,
    0xC6,
    0xD2,
    0x79,
    0x20,
    0x9A,
    0xDB,
    0xC0,
    0xFE,
    0x78,
    0xCD,
    0x5A,
    0xF4,
    0x1F,
    0xDD,
    0xA8,
    0x33,
    0x88,
    0x07,
    0xC7,
    0x31,
    0xB1,
    0x12,
    0x10,
    0x59,
    0x27,
    0x80,
    0xEC,
    0x5F,
    0x60,
    0x51,
    0x7F,
    0xA9,
    0x19,
    0xB5,
    0x4A,
    0x0D,
    0x2D,
    0xE5,
    0x7A,
    0x9F,
    0x93,
    0xC9,
    0x9C,
    0xEF,
    0xA0,
    0xE0,
    0x3B,
    0x4D,
    0xAE,
    0x2A,
    0xF5,
    0xB0,
    0xC8,
    0xEB,
    0xBB,
    0x3C,
    0x83,
    0x53,
    0x99,
    0x61,
    0x17,
    0x2B,
    0x04,
    0x7E,
    0xBA,
    0x77,
    0xD6,
    0x26,
    0xE1,
    0x69,
    0x14,
    0x63,
    0x55,
    0x21,
    0x0C,
    0x7D,
]


# Core encryption and decryption functions


def encrypt_block(data, key):
    """Encrypt a single 16-byte block with AES-128"""
    if len(data) != 16:
        raise ValueError("Input data block must be exactly 16 bytes")
    if len(key) != 16:
        raise ValueError("Key must be exactly 16 bytes (128-bit)")

    keys = expand_key(key)
    block = to_matrix(data)

    # Initial round
    block = xor_with_key(block, keys[0])

    # Main rounds
    for i in range(1, 10):
        block = apply_sbox(block)
        block = shift_matrix_rows(block)
        block = mix_matrix_columns(block)
        block = xor_with_key(block, keys[i])

    # Final round
    block = apply_sbox(block)
    block = shift_matrix_rows(block)
    block = xor_with_key(block, keys[10])

    return matrix_to_bytes(block)


def decrypt_block(data, key):
    """Decrypt a single 16-byte block with AES-128"""
    if len(data) != 16:
        raise ValueError("Input data block must be exactly 16 bytes")
    if len(key) != 16:
        raise ValueError("Key must be exactly 16 bytes (128-bit)")

    keys = expand_key(key)
    block = to_matrix(data)

    # Initial round
    block = xor_with_key(block, keys[10])

    # Main rounds (in reverse)
    for i in range(9, 0, -1):
        block = inverse_shift_rows(block)
        block = inverse_sbox(block)
        block = xor_with_key(block, keys[i])
        block = inverse_mix_columns(block)

    # Final round
    block = inverse_shift_rows(block)
    block = inverse_sbox(block)
    block = xor_with_key(block, keys[0])

    return matrix_to_bytes(block)


# Galois field operations


def gf_multiply(x, y):
    """Galois field multiplication for AES"""
    result = 0
    for _ in range(8):
        if y & 1:
            result ^= x
        msb_set = x & 0x80
        x = (x << 1) & 0xFF
        if msb_set:
            x ^= 0x1B  # AES irreducible polynomial: x^8 + x^4 + x^3 + x + 1
        y >>= 1
    return result


# Matrix operations


def to_matrix(data):
    """Convert bytes to 4x4 state matrix (column-major format)"""
    matrix = [[0 for _ in range(4)] for _ in range(4)]
    for r in range(4):
        for c in range(4):
            matrix[r][c] = data[r + 4 * c]
    return matrix


def matrix_to_bytes(matrix):
    """Convert 4x4 state matrix back to bytes (column-major format)"""
    result = []
    for c in range(4):
        for r in range(4):
            result.append(matrix[r][c])
    return bytes(result)


def xor_with_key(matrix, key_bytes):
    """XOR state matrix with round key"""
    result = [[0 for _ in range(4)] for _ in range(4)]
    for r in range(4):
        for c in range(4):
            result[r][c] = matrix[r][c] ^ key_bytes[r + 4 * c]
    return result


# Transformation operations


def apply_sbox(matrix):
    """Apply S-box substitution to state matrix"""
    return [[S_BOX[matrix[r][c]] for c in range(4)] for r in range(4)]


def inverse_sbox(matrix):
    """Apply inverse S-box substitution to state matrix"""
    return [[INV_S_BOX[matrix[r][c]] for c in range(4)] for r in range(4)]


def shift_matrix_rows(matrix):
    """Circular left shift of rows (0, 1, 2, 3 positions)"""
    result = [row[:] for row in matrix]
    for r in range(1, 4):
        result[r] = matrix[r][r:] + matrix[r][:r]
    return result


def inverse_shift_rows(matrix):
    """Circular right shift of rows (0, 1, 2, 3 positions)"""
    result = [row[:] for row in matrix]
    for r in range(1, 4):
        result[r] = matrix[r][-r:] + matrix[r][:-r]
    return result


def mix_matrix_columns(matrix):
    """Apply MixColumns transformation"""
    result = [[0 for _ in range(4)] for _ in range(4)]

    for c in range(4):
        # Get column values
        col = [matrix[r][c] for r in range(4)]

        # Matrix multiplication in GF(2^8)
        result[0][c] = (
            gf_multiply(0x02, col[0]) ^ gf_multiply(0x03, col[1]) ^ col[2] ^ col[3]
        )
        result[1][c] = (
            col[0] ^ gf_multiply(0x02, col[1]) ^ gf_multiply(0x03, col[2]) ^ col[3]
        )
        result[2][c] = (
            col[0] ^ col[1] ^ gf_multiply(0x02, col[2]) ^ gf_multiply(0x03, col[3])
        )
        result[3][c] = (
            gf_multiply(0x03, col[0]) ^ col[1] ^ col[2] ^ gf_multiply(0x02, col[3])
        )

    return result


def inverse_mix_columns(matrix):
    """Apply inverse MixColumns transformation"""
    result = [[0 for _ in range(4)] for _ in range(4)]

    for c in range(4):
        # Get column values
        col = [matrix[r][c] for r in range(4)]

        # Inverse matrix multiplication in GF(2^8)
        result[0][c] = (
            gf_multiply(0x0E, col[0])
            ^ gf_multiply(0x0B, col[1])
            ^ gf_multiply(0x0D, col[2])
            ^ gf_multiply(0x09, col[3])
        )
        result[1][c] = (
            gf_multiply(0x09, col[0])
            ^ gf_multiply(0x0E, col[1])
            ^ gf_multiply(0x0B, col[2])
            ^ gf_multiply(0x0D, col[3])
        )
        result[2][c] = (
            gf_multiply(0x0D, col[0])
            ^ gf_multiply(0x09, col[1])
            ^ gf_multiply(0x0E, col[2])
            ^ gf_multiply(0x0B, col[3])
        )
        result[3][c] = (
            gf_multiply(0x0B, col[0])
            ^ gf_multiply(0x0D, col[1])
            ^ gf_multiply(0x09, col[2])
            ^ gf_multiply(0x0E, col[3])
        )

    return result


# Key schedule operations


def rotate_word(word):
    """Rotate word bytes left by one position"""
    return word[1:] + word[:1]


def substitute_word(word):
    """Apply S-box to each byte in a word"""
    return [S_BOX[b] for b in word]


def expand_key(key):
    """Expand 128-bit key to 11 round keys"""
    # Extract initial 4 words from key
    key_words = [list(key[i : i + 4]) for i in range(0, 16, 4)]

    # Expand to 44 words (11 round keys * 4 words each)
    for i in range(4, 44):
        temp = key_words[i - 1][:]

        if i % 4 == 0:
            # Apply RotWord, SubBytes, and XOR with Rcon
            temp = rotate_word(temp)
            temp = substitute_word(temp)
            temp[0] ^= RCON[i // 4]

        # XOR with word 4 positions earlier
        key_words.append([temp[j] ^ key_words[i - 4][j] for j in range(4)])

    # Convert to round keys
    round_keys = []
    for i in range(0, 44, 4):
        key_bytes = []
        for col in range(4):
            key_bytes.extend(key_words[i + col])
        round_keys.append(bytes(key_bytes))

    return round_keys


# Test function
if __name__ == "__main__":
    # Test vector
    key = bytes.fromhex("000102030405060708090a0b0c0d0e0f")
    plaintext = bytes.fromhex("00112233445566778899aabbccddeeff")
    expected = bytes.fromhex("69c4e0d86a7b0430d8cdb78070b4c55a")

    print("AES-128 Test:")
    print(f"Key:       {key.hex()}")
    print(f"Plaintext: {plaintext.hex()}")

    # Encrypt
    encrypted = encrypt_block(plaintext, key)
    print(f"Encrypted: {encrypted.hex()}")
    print(f"Expected:  {expected.hex()}")
    print(f"Matches:   {encrypted == expected}")

    # Decrypt
    decrypted = decrypt_block(encrypted, key)
    print(f"\nDecrypted: {decrypted.hex()}")
    print(f"Matches original: {decrypted == plaintext}")

    assert encrypted == expected, "Encryption test failed"
    assert decrypted == plaintext, "Decryption test failed"

    print("\nAll tests passed!")
