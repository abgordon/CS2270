//Big O notation
//measure of complexity - how the number of operations your algorithim does depends on the number of "things" you have
//Things = number of nodes in BST, size of maze, size of BigInt
//Aside: in big O we take out scaling factors and constants
//ie n+n+n for every step is not necessarily O(3n) but usually would be O(n) - both are still increasing linearly
// O(n^2) < O(log(n)) n^2 at ∞ is worse because it groes exponentially 

//Big O rules of thumb:
//Nested loops are multiplied n - loop in loop = O(n^2)
//loops in sequence are added (which can generally be scaled out) O(2n) = O(n)

// O(l) < O(log n) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(a^n) < O(n^n)