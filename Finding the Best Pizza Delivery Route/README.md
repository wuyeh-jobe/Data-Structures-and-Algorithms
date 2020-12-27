# Finding the Best Pizza Delivery Route


   OptiPizza � a new pizza restaurant � wants to minimize its delivery costs while not compromising on delivery times 
   by delivering pizzas in batches to a small number of customers. To do this, they need to know the best route linking 
   their pizza restaurant and the customers for each delivery run.  Given the distance between each customer drop-off point 
   and the distance from the restaurant to each customer drop-off point, this application produces an optimal route for OptiPizza, 
   i.e. the sequence in which a delivery moto should call to the customers after leaving the restaurant, returning to the restaurant 
   once all pizzas have been delivered. The delivery moto calls to each customer location only once.

   Input data for several test cases is provided in an input file: input.txt
   Output for each test case is written to an output file: output.txt


   Input
   -----

   - The first line of the input file consists of an integer number k specifying the number of test cases in the file.  
   - This is followed by the data specifying each test case, beginning on the next line.  
   - There are no blank lines in the input file.
   - Each test case begins with a line containing an integer number n giving the number of pizza drop-offs locations. 
   - This is followed by n+1 lines containing 
   
     - the n locations (i.e. the names and addresses) of each customer 
     - followed by the location of the restaurant. 
     - It is assumed that n < 10 and that each address is on a separate line.  

   - This is followed by n+1 lines each containing n+1 integers specifying the distances between each location (including itself).  
   - The jth number on line i gives the distance from location i to location j. 
   - The j+1st number on line i gives the distance from customer i to the restaurant.  
   - Note that the distance from location i to location j may not be the same as the distance from location j to location i 
     since you may not be able to take the same path (we assume the delivery drivers obey the law and don�t drive the wrong way 
     on a one-way street).  
   - Line n+1 gives the distance of the restaurant to each customer location.
   

   Output
   ------


   - For each test case in the input
   
     - The test case number is printed on a separate line
     - The total distance that needs to be travelled is printed on the next line
     - This is followed the sequence of customers that the delivery moto should use to minimize distance, 
        starting at the restaurant and returning to the restaurant.

        Each customer name and address is printed on a separate line
     
   - If there is more than one tour (i.e. route from the restaurant to all delivery locations and back to the shop) 
     that gives the same minimum distance, it prints the first one found.


   Sample Input
   ------------
      1
      4
      Mr. Somename, #1 Some Street.
      Mr. Someothername, #2 Someother Street.
      Ms. Altname, #3 Alt Street.
      Ms. Ctrlaltname, #4 Delete Street.
      OptiPizza, #1 Mozzarella Road. 
      0   3  10  5 12 
      3   0  10  8  6 
      10 11   0  3  6 
      5   8   4  0  6 
      12  6   9  7  0 


   Sample Output
   -------------
      1
      24
      OptiPizza, #1 Mozzarella Road. 
      Mr. Someothername, #2 Someother Street.
      Mr. Somename, #1 Some Street.
      Ms. Ctrlaltname, #4 Delete Street.
      Ms. Altname, #3 Alt Street.
      OptiPizza, #1 Mozzarella Road. 

   Solution Strategy
   -------------------------
   The solution uses combinatorial search with backtracking and pruning. 
   Hence we seek the permutation of the locations that provides the minimum length tour.
   Instead of enumerating permutations of the location names and addresses 
   we associate an integer key with each location and form permutations of these keys.
