/*
    Method is basically a what a function is called in java.
    it can have access modifiers such as public, default, private, etc.
    Same as in C, a method can have a return value or not; do so by appending
    'void' or other corresponding data type in front of the method name.

    Method Overloading is a condition where two or more methods have
    the same name, but different parameters.

    A method can be called as-is (without creating an object of said method)
    IF and ONLY IF we are working with one java Class. In the events that we use
    two or more java Classes, we should append the 'static' modifier to call
    said method. Otherwise, we'd need to create an object of said method.
    Another exception to this rule is if the method is still within the same
    Class, then we do not have the need to declare an object of said function.

    A static method (or objects and even variables) can receive static or
    non-static arguments. Whilst a non-static method can only receive
    non-static arguments. An exception to this is if psvm calls a class constructor.

    In java, math functions are already built in by default, so we don't need to import
    another Class/package to do so. Just call the 'Math' Class and see what you can do.

    Here, we can also delay a program by calling the 'Thread' class with the .sleep method.

    Java doesn't have
 */


import java.util.jar.Manifest;

public class Main {
    String s = "hanie";
    int a = 9;
    int b = 3;
    int row = 0;
    int col = 0;
    char [][] map = {
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
            {'#','P',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    void cls(){
        for (int i = 0; i < 32; i++){
            System.out.println();
        }
    }

    // recursive example
    void floodFill(int x, int y){
        if (map[x][y] == '#' || x < 0 ||
        y < 0 || x > 6 || y > 14 || map[x][y] == '.') return;
        // void method should have 'return;' for the sake of telling that
        // this is the end of the method OR telling the method to stop
        cls();
        printMap();
//        sleep();
        map[x][y] = '.';         // mark that we've passed the area
        floodFill(x+1, y);    // move downwards
        floodFill(x-1, y);    // move upwards
        floodFill(x, y+1);    // move right
        floodFill(x, y-1);    // move left
    }
    void printMap(){
       /*
        for (char cs[] : map){
            for (char c : cs){
                System.out.print(c);
            }
            System.out.println();
        }
        */
        for (int i = 0; i < map.length; i++){
            for (int j = 0; j < map[i].length; j++){
                if (map[i][j] == 'P'){
                    row = i;
                    col = j;
                }
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
    public Main(){          // Main class constructor
//        count(a,b);
//        System.out.println(count(a, b));
//        sleep();
//        System.out.println(count(s));
        cls();
        printMap();
        floodFill(row, col);
        printMap();

    }

    String count(String s){     // a String method that accepts a string arg
        return ("Hello " + s + " ?");
    }

    int count(int a, int b){    /* an int method that has the same name as another method
                                   this is called method overloading
                                */
        return a*b;
    }

    public void sleep() {
        try {
            Thread.sleep(1000);     // interrupts the program for a set of time
            // counts in milliseconds
        } catch (Exception e ){
            e.printStackTrace();
        }

    }
    public static void main(String[] args) {
        new Main();
    }
}