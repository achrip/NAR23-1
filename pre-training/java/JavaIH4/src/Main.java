import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in);
    ArrayList<String> patients = new ArrayList<>();
    ArrayList<String> diseases = new ArrayList<>();

    public Main(){
        while (true){
            menu();
        }
    }

    private void menu(){
        int choose = 0;
        do {
            System.out.println("""
                     _    _        __      ___ _______    _   _      _     _
                    | |  | |       \\ \\    / (_)__   __|  | | | |    (_)   | |
                    | |__| | ___  __\\ \\  / / _   | | __ _| | | |     _ ___| |_
                    |  __  |/ _ \\/ __\\ \\/ / | |  | |/ _` | | | |    | / __| __|
                    | |  | | (_) \\__ \\\\  /  | |  | | (_| | | | |____| \\__ \\ |_
                    |_|  |_|\\___/|___/ \\/   |_|  |_|\\__,_|_| |______|_|___/\\__|""".indent(1));
            System.out.println("""
                    1. Add Patient
                    2. View Patients
                    3. Discharge Patient
                    4. Exit""");
            System.out.print("> ");
            try {
                choose = sc.nextInt();
                sc.nextLine();
            } catch (InputMismatchException e){
                e.printStackTrace();
                break;
            }
        } while (choose < 1 || choose > 4);

        switch (choose){
            case 1 -> admit();
            case 2 -> check();
            case 3 -> discharge();
            case 4 -> bye();
            default -> {}
        }
    }

    private void admit(){
        String name, complaint;
        do {
            System.out.print("Input patient's name [Starts with 'Mr.' or 'Mrs.']: ");
            name = sc.nextLine();
        } while (!(name.startsWith("Mr.") || name.startsWith("Mrs.")));

        do {
            System.out.print("Input patient's disease [Must be at least 5 characters long]: ");
            complaint = sc.nextLine();
        } while (complaint.length() < 5 );

        patients.add(name);
        diseases.add(complaint);

        System.out.println("Patient had been added successfully");
        System.out.println("Press Enter to Continue...");
        sc.nextLine();
    }

    private void check(){
        if (patients.size() == 0){
            System.out.println("There are no Patients");
            System.out.println("Press Enter to Continue...");
            sc.nextLine();
            return;
        } else {
            System.out.println("==============================================================================");
            System.out.println("| No. | Patient's Name                  | Patient's Disease                  |");
            System.out.println("==============================================================================");

            mergeSort(0, patients.size() - 1);

            for (int i = 0; i < patients.size(); i++){
                System.out.printf("| %d. | %-32s | %-34s |\n", (i+1), patients.get(i), diseases.get(i));
            }
            System.out.println("==============================================================================");
            System.out.println("\nPress Enter to Continue...");
            sc.nextLine();
        }

    }

    private void discharge(){
        if (patients.size() == 0){
            System.out.println("There are no Patients");
            System.out.println("Press Enter to Continue...");
            sc.nextLine();
            return;
        } else {
            System.out.println("==============================================================================");
            System.out.println("| No. | Patient's Name                  | Patient's Disease                  |");
            System.out.println("==============================================================================");

            for (int i = 0; i < patients.size(); i++){
                System.out.printf("| %d. | %-32s | %-34s |\n", (i+1), patients.get(i), diseases.get(i));
            }
            System.out.println("==============================================================================");
            int choose;
            do {
                System.out.print("Input patient number you want to discharge: ");
                choose = sc.nextInt();
                    sc.nextLine();
            } while (choose < 1 || choose > patients.size());

            patients.remove(choose-1);
            diseases.remove(choose-1);

            System.out.printf("\n%s is now healthy and has been discharged\n", patients.get(choose-1));
            System.out.println("Press Enter to Continue...");
            sc.nextLine();

        }
    }

    public void mergeSort(int from, int to){
        if (from == to){
            return;
        }
        int mid = from + (to-from) / 2;

        mergeSort(from, mid);
        mergeSort(mid+1, to);
        merge(from, mid, to);
    }

    public void merge(int from, int mid, int to){
        int n = to - from + 1;
        int l = mid - from + 1;
        int r = to - mid;
        int i = 0;
//        String[] sR = new String[n];
//        String[] sL = new String[n];
//        String[] cR = new String[n];
//        String[] cL = new String[n];
//
//        for (i = 0; i < r; i++){
//            sR[i] = patients.get(mid + 1 + i);
//            cR[i] = diseases.get(mid + 1 + i);
//        }
//
//        for (i = 0; i < l; i++){
//            sL[i] = patients.get(from + i);
//            cL[i] = diseases.get(from + i);
//        }
//
//        int dexLeft = 0, dexRight = 0;
//        int currDex = from;
//
//        while (dexLeft < l && dexRight < r){
//            if (sL[dexLeft].compareTo(sR[dexRight]) < 0){
//                patients.set(currDex, sL[dexLeft]);
//                diseases.set(currDex, cL[dexLeft]);
//                dexLeft++;
//            } else {
//                patients.set(currDex, sR[dexRight]);
//                diseases.set(currDex, cR[dexRight]);
//                dexRight++;
//            }
//            currDex++;
//        }
//
//        while (dexLeft < l){
//            patients.set(currDex, sL[dexLeft]);
//            diseases.set(currDex, cL[dexLeft]);
//            dexLeft++;
//            currDex++;
//        }
//
//        while (dexRight < r) {
//            patients.set(currDex, sR[dexRight]);
//            diseases.set(currDex, cR[dexRight]);
//            dexRight++;
//            currDex++;
//        }

//        while (r <= mid && l <= to){
//            if (patients.get(l).compareTo(patients.get(r)) < 0){
//                s[i] = patients.get(l);
//                c[i] = diseases.get(l);
//                l++;
//            } else {
//                s[i] = patients.get(r);
//                c[i] = diseases.get(r);
//                r++;
//            }
//            i++;
//        }
//
//        while (l <= mid){
//            s[i] = patients.get(l);
//            c[i] = diseases.get(l);
//            l++;
//            i++;
//        }
//
//        while (r <= mid){
//            s[i] = patients.get(r);
//            c[i] = diseases.get(r);
//            r++;
//            i++;
//        }
//
//        for (i = 0; i < n; i++){
//            patients.set(from + i, s[i]);
//            diseases.set(from + i, c[i]);
//        }
    }

    private void bye(){
        System.out.println("""
                  Thank you for using this program.
                                          .......,*...
                                   ......&..........,%&&&*&.......
                                 ...%.,.../(..&/,     .....,..(..,*....
                              ..#,......#*,..............   ..../%.....
                           .,/(.....(, .*....................  ...*
                          .,#,...,,. .........................  ,...% .
                      ...&/((&#*,...............*&@@%...........  ,*,,....
                     ..(,*.... ./,.%,...... /&@@@@@ .............  .*,/...
                      ......./ .....*** &@@@@@&#.................. ..(,&
                         (,.,....,..(@@@@@@/./@@@@@@@@@#*.......,*...,*.(
                         %,,,..,,,.,.@@@@@@@#&......,@@@@@@@@@%.... .,/,%
                       ..%,,. ..,..,,,,../@@@@@@@@.../@@@@@#...... ..*,*(,
                       ..#... ..,,..,..........,,.(@@@@@ ......... ..../.,.
                        ./.... .. ......... .,&@@@@@%............. .*.,% /.
                        .  ...,#........... *@@@(.....,...........,(..#..,..
                            .*. ,................,......,.......,&,,..
                             *.,.(...*......,.......,..,.. .  .&,..
                               ..,,,* . .*..,......    ...,%(...(,..
                               .,**#,*#,..(.#...,,,#&%###...*,*,...
                               . ...&&/.*&,.*&.......(#.
                                    ..   ..*...,,..
                                          .......


                                        - Bluejackets 22-1 -
                Alongside courage and perseverance, we shape and define our future.""".indent(8));
        System.exit(0);
    }
    public static void main(String[] args) {
        new Main();
    }
}