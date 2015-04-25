#include <iostream>

#define VALUETYPE long
#define EVEN(x) ((x&1)==0)
#define ODD(x) ((x&1)==1)

//  Compute x^n mod y in a quick way.
VALUETYPE PowerMod(VALUETYPE x, VALUETYPE y, VALUETYPE n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  if EVEN(n) return PowerMod(x*x%y, y, n/2) % y;
  return PowerMod(x*x%y, y, n/2) * x % y;
}

//  If n is a prime
bool Miller_Rabin(VALUETYPE n) {
  if (n == 2) return true;
  if ((n<2)||EVEN(n)) return false;
  VALUETYPE d;
  d = n-1;
  while EVEN(d) d = d >> 1;
  VALUETYPE base[7] = { 2, 3, 5, 7, 11, 13, 17};
  int td, t;
  for (int i=0; i<7; i++) {
    if (base[i] >= n) break;
    td = d;
    t = PowerMod( base[i], n, td);
    while ((td!=n-1)&&(t!=1)&&(t!=n-1)) {
      t = t*t % n;
      td = td << 1;
    }
    if ((t == n-1)||ODD(td)) ; else return false;
  }
  return true;
}

using namespace std;

int main() {
  while(1) {
    VALUETYPE k;
    cin>>k;
    cout<<(Miller_Rabin(k) ? "True" : "False")<<endl;
  }
  return 0;
}
