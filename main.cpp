/*
Author: Nicholas Hays
Date: 3/8/2018
Problem: Hackerrank - Algorithms - Bit Manipulation - Cipher
*/

#include<iostream>
#include<string>

/*
Given an encoded binary string, enc, its decoded length, n, and k, the number
of times enc is XOR'd with a copy of enc shifted by 0, 1...K-1 bits, 
determines the original, decoded, binary string.

i.e
sample input:
7 4
1110100110

sample output:
1001010

Reasoning:
The first bit is always the same for both the encoded and decoded string
because any bit XOR'd with 0 is always itself. b ^ 0 = b.

To solve for the decoded bit, d, at postion x we must know 2 things.
p = output of the XOR sum of the decoded bits starting at position x - k, if x >= k, otherwise 0, to x - 1. i.e XORSum(x - k || 0, x - 1)
e = encoded bit at position x.

Once we determine p and e, solving for d is simple, d = p ^ e.

1001010
 1001010
  1001010
   1001010
----------
1110100110


*/
void decode(unsigned int n, unsigned int k, std::string &enc, std::string &dec) {
  
  int prev = enc[0] - '0';
  dec.push_back(enc[0]);
  for (int i = 1; i < n; i++) {
    int cur = enc[i] - '0';
    if (i >= k) {
      int s = i - k;
      prev ^= (dec[s] - '0'); //undo
    }
    int t = prev ^ cur;
    dec.push_back(t + '0');
    if (i >= k) {
      prev ^= (dec[i] - '0');
    } else {
      prev = cur;
    }
  }
}

/*
program sample input call

main < ./input.txt

where sample input.txt is of the form:
n k
s + k -1

i.e

6 2
1110001

runs in linear time.

*/
int main() {

  unsigned int n, k;
  std::cin >> n >> k;
  std::string e, d;
  std::cin >> e;
  decode(n, k, e, d);
  std::cout << d << std::endl;

}