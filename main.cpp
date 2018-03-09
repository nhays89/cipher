#include<iostream>
#include<string>


/*
Given an encoded binary string, enc, its decoded length, n, and k, the number
of times enc is XOR'd with itself shifted by 0,1...K-1 bits at each operation, 
determines the original, decoded, binary string.

i.e
sample input:
7 4
1110100110

sample output:
1001010

reasoning:
We have a decoded binary string.
We the first bit of th



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

where sample input.txt:
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