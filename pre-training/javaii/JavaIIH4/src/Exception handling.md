# Exception handling

### What is an exception?

Exception are abnormalities that are found in a code in java. In Java, exceptions are divided into two types: 

+ Built-In Exceptions

  These are exceptions that are built-in by Java. In Java, there is something known as error handling, or as we call it *exception handling.* It basically means that actions that will be taken if we run into some abnormalities in our code. Some example of built-in exceptions are: 

  1. `ArithmeticException`
  2. `NullPointerException`
  3. `InputMismatchException`
  4. `ArrayIndexOutOfBoundsException`

+ User-Defined Exceptions

  These are exceptions that are built-in by developers.

  

------

### Why do we need exception handling? 

When we run into exceptions in our Java code, by default, Java already has an algorithm to handle the situation. But this comes with some caveats, that is, the code will abruptly stopped after Java handles the error (usually it prints the stack trace). This is useful to us developers, but for general day-to-day users of our program, they don't need to know about these. Hence, exception handling that are "custom made" by developers is needed. 



------

### How do we handle exceptions? 

There are several ways for developers to handle exceptions, one of the most used is the `try-catch block`.  Below is an example of a `try-catch block`

```java
import java.util.Scanner; 

public class Main{
	private Scanner in; 

	public static void main(String []args) {
		in = new Scanner(System.in());
        int num;
        boolean flag = true; 
        do {
        	System.out.println("Input a number");
        	try {
        		num = in.nextInt(); 
        		in.nextLine(); 
        	} catch (Exception e) {
        		System.out.println("Input must be a number!!");
        	}
        } while (flag)
	}
}
```

The code snippet above shows that a program will try running a code block in the `try block`. Then, if the program encounters an exception, the `catch block` will then be effective to check depending on what exception that we encounter. In this case, I used `Exception e` to mind every exceptions that will be thrown by Java, and not just a specific one. An example of a specific exception handling is if we change the argument of the catch block into `IOException`, `FileNotFound`, etc.

After we handle exceptions using the `try-catch` block , we can run any code after it as usual. But there is also a syntax that makes Java run a block of code regardless of the fact that it went through the catch block or not. This syntax is called the `finally` block. If we implement the finally block into our code above, we will have something like this



```java
import java.util.Scanner; 

public class Main{
	private Scanner in; 
    
    public static void main(String []args) {
        in = new Scanner(System.in());
        int num;
        boolean flag = true; 
        do {
            System.out.println("Input a number");
            try {
                num = in.nextInt(); 
                in.nextLine(); 
            } catch (Exception e) {
                System.out.println("Input must be a number!!");
            } finally {
                System.out.println("I am independent!")
            }
        } while (flag)
	}
}
```


------

### Throwables

Throwables is the superclass of the Java Exception and Error class. As such, when the need arises, we can create our own Exception class by making it a subclass of the exception class. By default, if you extend the Exception class, this makes your custom exception a checked exception (that means it has to be catched at some point if thrown). If by some means you want to create an unchecked exception, then our custom exception must extent the RuntimeException class.