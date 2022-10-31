public class Catatan {
    
    public Catatan() { //this is called a constructor
        // System.out.println("Hello World!");

        // System.out.println("Hello");
        // System.out.print("World");

        // /*
        //  * Primitive Data Types
        //  * int --> whole number
        //  * float --> fractional number
        //  * double --> fractional too, but more precise than float
        //  * boolean --> true or false
        //  * long --> int, but has bigger range
        //  */

        //  // we can do the same thing as C in declaring, printing, and initializing variables
        // int a = 10; // declaring and initializing in one line
        // System.out.println(a);
        // int b;      //declaring and initializing in two line
        // b = 20; 
        // System.out.println("B bernilai " + b); // append a variable value to a print by doing this. can be concatted

        // /*
        //  * Print Format Specifiers
        //  * %d --> for integers
        //  * %f --> float
        //  * %c --> char
        //  * %s --> string
        //  */

        //  System.out.printf("B bernilai %d\n", b);
        //  char c = 'A';
        //  System.out.printf("C adalah huruf : %c", c);
         
        //  float f = 0.5f;    // when we initialize a float, append the letter f after the numbers 
        //  double d = 0.7;    // whilst when initializing a double, we dont need it

        // /*
        // * Type Casting
        // * is usually used to change a data type from int to float/double and vice-versa
        // */

        // int anum= (int) f; 
        // System.out.println(anum);

        // /*
        //  * String Datatype
        //  * we can initialize a string datatype as-is
        //  */

        //  String s = "Hello";
        //  s = "goood";
        //  String ss = "deff";

        //  System.out.println(s.equals(ss));

        // /* 
        //  * Mathematical operations
        //  * mostly they are the same as c, we can use shorthand operators, and basic math operations
        //  */

        // /*
        //  * Relational Operator
        //  * those you use as if or loop conditions
        //  * <, <=, >=, >, ==, !=
        //  */

        // /*
        //  * Logical Operator
        //  * && --> AND 
        //  * || --> OR
        //  * ! --> NOT
        //  */

        // /* 
        //  * Bitwise Operator
        //  * | --> OR
        //  * & --> AND
        //  * ^ --> XOR
        //  * << --> Left Shift
        //  * >> --> Right Shift
        //  */

        // /*
        //  * Ternary Operator
        //  * (paramaeter)? value1 : value2
        //  * value 1 will happen if true, value 2 will happen if false
        //  */

        //  int x = (10<20)? 100:0; 
        //  System.out.println(x);
        
        // /*
        //  * Selection
        //  * a set of parameter that if returns true will run a block of code
        //  */
            
        //  if (condition) {
        //     /* code block that will run if statement is true */
        //  } else {
        //     /* alternate code block that will run if statement is false */
        //  }

        // switch (key) {
        //     case value:
                
        //         break;
        
        //     default:
        //         break;
        // }

        // /*
        //  * Nested Selection
        //  * basically a selection that houses another selection. can repeat so many times
        //  */

        //  if (condition) {
        //     if (condition) {
                
        //     }
        //  } else {
            
        //  }

        // switch (key) {
        //     case value:
        //             switch (key) {
        //                 case value:
                            
        //                     break;
                    
        //                 default:
        //                     break;
        //             }
        //         break;
        
        //     default:
        //         break;
        // }

        // /*
        //  * Scanning User Input
        //  * when scanning user input in java, we need to import the Scanner class and create an object from it
        //  * 
        //  * arguments for a scanner object is: 
        //  * objName.nextLine(); --> scans until a \n or \r is read
        //  * objName.nextInt(); --> scans an integer value from user
        //  * objName.next().charAt(x) --> scans a user input starting from the x-th index of the string
        //  *                              (remember that the string index is like an array; starts from 0)
        //  * 
        //  */

        // /*
        //  * Looping
        //  * tired of printing the same old code again and again? fear not. there are loops!
        //  * 
        //  * for (statement1; statement2; statement3){ code block } 
        //  * initialize at 1, loop continue if 2 returns TRUE, increment var from 1 on 3
        //  * 
        //  * while (statement) { code blocks } --> check statement first, run code block later
        //  *                                       loop continues as long as statement returns true
        //  * 
        //  * do { code block } while (statement);
        //  * run the code block first, check statement later.
        //  * loop continues as long as statement returns true
        //  */

        // /* 
        //  * Exception Handling 
        //  * displays custom error message when runtime error happens
        //  */

        //  try {
        //     /* code block */
        //  } catch (Exception e) {
        //     // TODO: handle exception
        //     /* code block that will be run if the one from "try" returns runtime error */
        //  } finally {
        //     /* code block that will run regardless if there is an error or not */
        //  }

        // /*
        //  * Misc 
        //  * Math.random() --> will return a 0. decimal random numbers. 
        //  */
    }
    
    public static void main(String[] args) {
        new Catatan();
    }
}
