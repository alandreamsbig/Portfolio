int *test (int);

main ()
 {
  int *p;
  int x, y, z;
  x = 61;
  y = 62;
  z = 63;
  p = test(x);
  z = *p;
  *p = 70;
  z = *p;
  y = foo(x);
  z = *p;
  return(2);
 }

int *test (v)
int v;
 {
  int c;
  dummy(v);
  c = v;
  return(&c);
 }

foo (x)
int x;
 {
  int i, j, k;
  i = 65;
  j = 66;
  k = i + j;
  dummy(k);
  return(k);
 }

__main ()
 {
  return(0);
 }

dummy (v)
int v;
 {
  return(0);
 }
