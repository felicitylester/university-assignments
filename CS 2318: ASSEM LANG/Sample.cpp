// Some silly C++ function code for use in 
// discussing the mechanics of functions

# function prototypes
int quadit(int);
int factorial(int);


# how does quadit give answer back to main?
# quadit cant know? it doesnt know. just knows to put value here
# main could ignore quadit
int main()
{
   int x, y = 4;
   # quadit
   cout << quadit(y);
   # quadit called twice 
   # ( quadit( 2) doesnt matter call inside another call
   # all same stuff going in and out
   # then quadit called 
   x = quadit( quadit( 2));
   # call here arguments in, where you gonna return etc.
   x = factorial(y);
}

int quadit(int n)
{
  int x;
  x = n * 2;
  # this return statement
  return x * 2;
}

# n is 4
# second one running thinks its n is 3
	# two n's in memory w/ different values
# possible b/c recursion call
int factorial(int n)
{
    int q;	# local variable 
    if (n == 1) return 1;
    # recursive call = function calling itself
    # factorial(n-1) = call to factorial
    	# all same stuff sent back and forth
    return n*factorial(n-1);
}