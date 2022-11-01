import java.util.Scanner;
import java.util.Vector;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
// import java.io.File;
// import java.io.FileNotFoundException;

public class Main {
    static int choose; 
    // static String owner, name, brand, model;      
    static Scanner sc = new Scanner(System.in);
    // static Car car = new Car(owner, name, brand, model);
    static Vector<String> newData = new Vector<>();
    static Vector<String> owner = new Vector<>();
    static Vector<String> name = new Vector<>();
    static Vector<String> brand = new Vector<>();
    static Vector<String> type = new Vector<>();
    

    public Main() {
        homePage();
    }

    static void homePage(){
        
        do{
            System.out.println("Welcome to BWengkel");
            System.out.println("1. Add car to repair list");
            System.out.println("2. Repair car");
            System.out.println("3. Take out car");
            System.out.println("4. Exit");
            System.out.print(">> ");
            choose = sc.nextInt(); sc.nextLine(); 
            
            switch (choose){
                case 1: 
                addCar(); 
                break; 
                
                case 2: 
                repairCar(); 
                break; 
                
                case 3: 
                pickUp();
                break; 
                
                case 4: 
                System.exit(0);
                break; 
                
                default: 
                break; 
            }
        } while (choose < 1 || choose > 3); 
    }

    static void addCar(){

        String tempowner, tempbrand, tempmodel, tempname;
        do {
            System.out.print("Input car's owner [starts with 'Mr. /Mrs. ']: ");
            tempowner = sc.nextLine(); 
        } while (!(tempowner.contains("Mr. ") || tempowner.contains("Mrs. ")));
        
        do {
            System.out.print("Input car's name [more than or equals to 3 chars]: ");
            tempname = sc.nextLine(); 
        } while (tempname.length() < 3);
        
        do {
            System.out.print("Input car's brand [more than or equals to 5 chars]: ");
            tempbrand = sc.nextLine(); 
        } while (tempbrand.length() < 5);
        
        do {
            System.out.print("Input car's type [Sedan, Coupe, SUV] case sensitive: ");
            tempmodel = sc.nextLine(); 
        } while (!(tempmodel.equals("Sedan") ||!tempmodel.equals("Coupe") || 
        !tempmodel.equals("SUV")));


        // append to vector all these data
        newData.add(tempowner);
        newData.add(tempname);
        newData.add(tempbrand);
        newData.add(tempmodel);
        
        // append to file after concatting strings
        // I DONT KNOW HOW FOR THE SAKE OF GOD
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("reparationList.txt"));
            
            for (String s : newData){
                bw.write(s + ";");
            }
            bw.write("\n");
            bw.close();
        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        }


        System.out.println("Success add car to the list!");
        System.out.print("Press enter to continue...");
        sc.nextLine(); 
    }

    static void repairCar(){
        // if repair list == null then return...?

        try {
            BufferedReader br = new BufferedReader(new FileReader("reparationList.txt"));
            String s; 
            while ((s = br.readLine()) != null){
                String[] temp = s.split(";");
                for (int i=0; i<temp.length; i++){
                    switch (i){
                        case 0: 
                            owner.add(temp[i]); 
                            break;
                        
                        case 1: 
                            name.add(temp[i]); 
                            break; 

                        case 2: 
                            brand.add(temp[i]); 
                            break; 

                        case 3: 
                            type.add(temp[i]) ;
                            break; 

                        default: 
                            break;
                    }
                }
            }

            br.close();
        } catch (IOException e) {
            // TODO: handle exception
            e.printStackTrace();
        }

        System.out.println("BWengkel Car's list");
        System.out.println();
        System.out.println("========================================================================");
        System.out.println("| No. | Owner      | Car's Name     | Car's Brand     | Car's Type     |");
        System.out.println("========================================================================");
        for (int i=0; i<owner.size(); i++){
            System.out.printf(" %d | %6s| %5s| %5s| %5s|", 
            i+1, owner.get(i), name.get(i), brand.get(i), type.get(i));
            System.out.println("========================================================================");
        }

        do {
            System.out.print("Choose car's index to be repaired ['0' to go back]: ");
            choose = sc.nextInt(); sc.nextLine(); 

            if (choose < 0 || choose > owner.size()){
                System.out.println("Index not found!");
            } else{
                break;
            }
        } while (true);
    }


    static void pickUp(){

    }
    public static void main(String[] args) throws Exception {
        new Main();
    }
}
