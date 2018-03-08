#include<iostream>
#include<string>

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
    }
    if( i < k) {
      prev = cur;
    }
  }
}

int main() {

  unsigned int n, k;
  std::cin >> n >> k;
  std::string e, d;
  std::cin >> e;
  decode(n, k, e, d);
  std::cout << d << std::endl;

}