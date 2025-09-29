# These standard tables are defined by the DES specification and cannot be changed

# Initial & Final Permutation Tables
INITIAL_PERM = [
    58,
    50,
    42,
    34,
    26,
    18,
    10,
    2,
    60,
    52,
    44,
    36,
    28,
    20,
    12,
    4,
    62,
    54,
    46,
    38,
    30,
    22,
    14,
    6,
    64,
    56,
    48,
    40,
    32,
    24,
    16,
    8,
    57,
    49,
    41,
    33,
    25,
    17,
    9,
    1,
    59,
    51,
    43,
    35,
    27,
    19,
    11,
    3,
    61,
    53,
    45,
    37,
    29,
    21,
    13,
    5,
    63,
    55,
    47,
    39,
    31,
    23,
    15,
    7,
]

FINAL_PERM = [
    40,
    8,
    48,
    16,
    56,
    24,
    64,
    32,
    39,
    7,
    47,
    15,
    55,
    23,
    63,
    31,
    38,
    6,
    46,
    14,
    54,
    22,
    62,
    30,
    37,
    5,
    45,
    13,
    53,
    21,
    61,
    29,
    36,
    4,
    44,
    12,
    52,
    20,
    60,
    28,
    35,
    3,
    43,
    11,
    51,
    19,
    59,
    27,
    34,
    2,
    42,
    10,
    50,
    18,
    58,
    26,
    33,
    1,
    41,
    9,
    49,
    17,
    57,
    25,
]

# Expansion table - stretches 32 bits to 48 bits
EXPANSION = [
    32,
    1,
    2,
    3,
    4,
    5,
    4,
    5,
    6,
    7,
    8,
    9,
    8,
    9,
    10,
    11,
    12,
    13,
    12,
    13,
    14,
    15,
    16,
    17,
    16,
    17,
    18,
    19,
    20,
    21,
    20,
    21,
    22,
    23,
    24,
    25,
    24,
    25,
    26,
    27,
    28,
    29,
    28,
    29,
    30,
    31,
    32,
    1,
]

# Post-S-box permutation
PBOX = [
    16,
    7,
    20,
    21,
    29,
    12,
    28,
    17,
    1,
    15,
    23,
    26,
    5,
    18,
    31,
    10,
    2,
    8,
    24,
    14,
    32,
    27,
    3,
    9,
    19,
    13,
    30,
    6,
    22,
    11,
    4,
    25,
]

# Key processing tables
KEY_PERM1 = [
    57,
    49,
    41,
    33,
    25,
    17,
    9,
    1,
    58,
    50,
    42,
    34,
    26,
    18,
    10,
    2,
    59,
    51,
    43,
    35,
    27,
    19,
    11,
    3,
    60,
    52,
    44,
    36,
    63,
    55,
    47,
    39,
    31,
    23,
    15,
    7,
    62,
    54,
    46,
    38,
    30,
    22,
    14,
    6,
    61,
    53,
    45,
    37,
    29,
    21,
    13,
    5,
    28,
    20,
    12,
    4,
]

KEY_PERM2 = [
    14,
    17,
    11,
    24,
    1,
    5,
    3,
    28,
    15,
    6,
    21,
    10,
    23,
    19,
    12,
    4,
    26,
    8,
    16,
    7,
    27,
    20,
    13,
    2,
    41,
    52,
    31,
    37,
    47,
    55,
    30,
    40,
    51,
    45,
    33,
    48,
    44,
    49,
    39,
    56,
    34,
    53,
    46,
    42,
    50,
    36,
    29,
    32,
]

# Key rotation schedule
KEY_ROTATIONS = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

# S-boxes for substitution
SBOXES = [
    # S1-S8 boxes defined by the DES standard
    [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
    ],
    [
        [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],
    ],
    [
        [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],
    ],
    [
        [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14],
    ],
    [
        [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],
    ],
    [
        [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13],
    ],
    [
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12],
    ],
    [
        [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11],
    ],
]


def convert_to_bits(data_bytes):
    """Convert bytes to a list of bits."""
    bit_list = []
    for byte in data_bytes:
        # Process each bit in the byte
        for bit_pos in range(7, -1, -1):
            bit_list.append((byte >> bit_pos) & 1)
    return bit_list


def convert_from_bits(bit_list):
    """Convert a list of bits back to bytes."""
    result = bytearray()
    for i in range(0, len(bit_list), 8):
        byte_val = 0
        # Combine 8 bits to form a byte
        for j in range(8):
            byte_val = (byte_val << 1) | bit_list[i + j]
        result.append(byte_val)
    return bytes(result)


def apply_table(input_bits, table):
    """Apply a mapping table to rearrange bits."""
    return [input_bits[pos - 1] for pos in table]


def rotate_bits_left(bit_block, positions):
    """Circular left shift of bits by specified positions."""
    return bit_block[positions:] + bit_block[:positions]


def bit_xor_operation(bits1, bits2):
    """Perform XOR operation on two bit arrays."""
    return [bit1 ^ bit2 for bit1, bit2 in zip(bits1, bits2)]


def generate_round_keys(master_key):
    """Create 16 subkeys for DES rounds from the master key."""
    # Convert key to bits and apply initial permutation
    key_bits = convert_to_bits(master_key)
    key_56 = apply_table(key_bits, KEY_PERM1)

    # Split into left and right halves
    left_half = key_56[:28]
    right_half = key_56[28:]

    # Generate 16 round keys
    round_keys = []
    for round_idx in range(16):
        # Apply appropriate rotation for this round
        shift = KEY_ROTATIONS[round_idx]
        left_half = rotate_bits_left(left_half, shift)
        right_half = rotate_bits_left(right_half, shift)

        # Combine halves and apply compression permutation
        combined = left_half + right_half
        round_key = apply_table(combined, KEY_PERM2)
        round_keys.append(round_key)

    return round_keys


def feistel_round_function(right_half, round_key):
    """The heart of DES: expansion, key mixing, substitution, and permutation."""
    # Expand 32 bits to 48
    expanded = apply_table(right_half, EXPANSION)

    # XOR with the round key
    mixed = bit_xor_operation(expanded, round_key)

    # Apply S-box substitutions (48 bits → 32 bits)
    substituted = []
    for i in range(8):  # Process each 6-bit segment
        segment = mixed[i * 6 : (i + 1) * 6]

        # Determine row (first and last bit)
        row = (segment[0] << 1) | segment[5]

        # Determine column (middle 4 bits)
        col = (segment[1] << 3) | (segment[2] << 2) | (segment[3] << 1) | segment[4]

        # Lookup value in S-box
        value = SBOXES[i][row][col]

        # Convert S-box output (4 bits) to bit list
        for j in range(3, -1, -1):
            substituted.append((value >> j) & 1)

    # Final permutation of the round
    return apply_table(substituted, PBOX)


def process_data_block(block, keys):
    """Process a 64-bit block through the DES algorithm using supplied keys."""
    # Convert to bits and apply initial permutation
    bit_block = convert_to_bits(block)
    permuted = apply_table(bit_block, INITIAL_PERM)

    # Split into left and right halves
    left, right = permuted[:32], permuted[32:]

    # Run through 16 rounds of Feistel network
    for i in range(16):
        next_left = right
        next_right = bit_xor_operation(left, feistel_round_function(right, keys[i]))
        left, right = next_left, next_right

    # Final swap and permutation
    result = apply_table(right + left, FINAL_PERM)

    # Convert back to bytes
    return convert_from_bits(result)


def encrypt_block(plaintext_block, key):
    """
    Encrypt a single 8-byte block using DES.

    Args:
        plaintext_block: 8 bytes of data
        key: 8-byte encryption key

    Returns:
        8 bytes of encrypted data
    """
    if len(plaintext_block) != 8:
        raise ValueError("Plaintext must be exactly 8 bytes")
    if len(key) != 8:
        raise ValueError("Key must be exactly 8 bytes")

    keys = generate_round_keys(key)
    return process_data_block(plaintext_block, keys)


def decrypt_block(ciphertext_block, key):
    """
    Decrypt a single 8-byte block using DES.

    Args:
        ciphertext_block: 8 bytes of encrypted data
        key: 8-byte encryption key

    Returns:
        8 bytes of plaintext data
    """
    if len(ciphertext_block) != 8:
        raise ValueError("Ciphertext must be exactly 8 bytes")
    if len(key) != 8:
        raise ValueError("Key must be exactly 8 bytes")

    # For decryption, use round keys in reverse order
    keys = generate_round_keys(key)
    return process_data_block(ciphertext_block, keys[::-1])


if __name__ == "__main__":
    # Standard test vector from DES documentation
    test_key = bytes.fromhex("133457799BBCDFF1")
    test_plaintext = bytes.fromhex("0123456789ABCDEF")
    expected_result = bytes.fromhex("85E813540F0AB405")

    print("DES Algorithm Test")
    print(f"Key:         {test_key.hex().upper()}")
    print(f"Input:       {test_plaintext.hex().upper()}")

    # Encrypt test data
    encrypted = encrypt_block(test_plaintext, test_key)
    print(f"Encrypted:   {encrypted.hex().upper()}")
    print(f"Expected:    {expected_result.hex().upper()}")

    # Decrypt and verify
    decrypted = decrypt_block(encrypted, test_key)
    print(f"\nDecrypted:   {decrypted.hex().upper()}")
    print(f"Original:    {test_plaintext.hex().upper()}")

    # Verify test case
    if encrypted == expected_result and decrypted == test_plaintext:
        print("\nAll DES tests passed successfully!")
    else:
        print("\nTest failed!")
