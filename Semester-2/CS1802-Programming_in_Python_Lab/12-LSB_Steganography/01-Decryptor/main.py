#!/usr/bin/env python3

class LSBSteg:

  def __init__(self, inp: list[int]) -> None:
    self.image = inp

  def _is_odd(self, inp: int) -> str:
    return str(int(inp % 2 != 0))

  def _to_ascii(self, inp: int) -> int:
      return int(str(inp), base=2 )

  def _to_char(self, inp: int) -> str:
    return chr(inp)

  def decode(self) -> list:
    i = 0
    enc_basciilist = []
    while True:
      try:
        enc_basciichar = []
        for j in range(i*8, (i+1)*8):
          enc_basciichar.append(self.image[j])
        
        enc_basciilist.append(enc_basciichar)
        i += 1

      except IndexError as e:
        break

    decoded = []
    for enc_bascii in enc_basciilist:
      bascii = (int("".join(list(map(self._is_odd, enc_bascii)))))
      print(self._to_char(self._to_ascii(bascii)))
      decoded.append(self._to_char(self._to_ascii(bascii)))

    return decoded



        
    

def main():
  inp = []
  with open("Sample12.txt") as f:
    for line in f.readlines():
      for char in line.split():
        inp.append(int(char))

  steg = LSBSteg(inp)

  print(steg.decode())
      

if __name__ == "__main__":
  main()