import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    private final ArrayList<Type> farm = new ArrayList<>();
    private final Scanner sc = new Scanner(System.in);
    private Owner chief;
    private int currLand = 0, currSalt = 0, currFresh = 0;
    public Main() {
        while (true) {
            if (farm.isEmpty()) System.out.println("farm is empty!");
            else {
                farm.sort(Comparator.comparing(Type::getName));
                for (int i = 0; i < farm.size(); i++) {
                    System.out.printf("%-3d. %-30s| %-20s| %-30s| %-20d| %-30s|", (i + 1),
                            farm.get(i).getName(), farm.get(i).getSize(), farm.get(i).getHabitat(),
                            farm.get(i).getFood(), farm.get(i).getSpecies());
                }

                for (Type t : farm) {
                    switch (t.getHabitat()) {
                        case "Land" -> currLand++;
                        case "Salt Water" -> currSalt++;
                        case "Fresh Water" -> currFresh++;
                    }
                }

                System.out.println("\n\n");
                chief = new Owner(1, 5000, currLand, currFresh, currSalt);
                System.out.printf("%-40s: %d","Money\n",  chief.getMoney());
                System.out.printf("%-40s: %d/%d", "Land Size Capacity\n", chief.getLand(), (10 + (chief.getLevel() * 4)));
                System.out.printf("%-40s: %d/%d", "Fresh Water Size Capacity\n", chief.getFreshWater(), (10 + (chief.getLevel() * 2)));
                System.out.printf("%-40s: %d/%d", "Salt Water Size Capacity\n\n", chief.getSaltWater(), (10 + (chief.getLevel() * 2)));

                System.out.println("""
                        FarmLy
                        ======
                        1. Buy Animal
                        2. Feed All Animal(s)
                        3. Sell Animal
                        4. Sell All Animal(s)
                        5. Upgrade Farm
                        6. Exit""");
                int choose = sc.nextInt(); sc.nextLine();
                switch (choose) {
                    case 1 -> buy();
                    case 2 -> feedAll();
                    case 3 -> sell();
                    case 4 -> sellAll();
                    case 5 -> upgrade();
                    case 6 -> System.exit(0);
                    default -> {}
                }
            }
        }
    }

    private void buy() {
        String habitat, animal, name, size, type;
        boolean flag = false;
        do {
            System.out.print("Input animal habitat [Land/Water] : \n");
            habitat = sc.nextLine();
            if (habitat.equals("Land") || habitat.equals("Water"))
                flag = true;
        } while (!flag);
        if (habitat.equals("Water")) {
            do {
                System.out.print("Input animal  [Catfish/Salmon] : \n");
                animal = sc.nextLine();
                if (animal.equals("Catfish") || animal.equals("Salmon"))
                    flag = false;
            } while (flag);

            if (animal.equals("Salmon")) {
                do {
                    System.out.print("Input animal name [3 - 5 characters] : \n");
                    name = sc.nextLine();
                    if (name.length() > 2 && name.length() < 6)
                        flag = true;
                } while (!flag);

                do {
                    System.out.print("Input animal size [Small | Medium | Large] : \n");
                    size = sc.nextLine();
                    if (size.equals("Small") || size.equals("Medium") || size.equals("Large"))
                        flag = false;
                } while (flag);

                do {
                    System.out.printf("Input %s type [Sockeye Salmon | Chinook Salmon] : \n", animal);
                    type = sc.nextLine();
                    if (type.equals("Sockeye Salmon") || type.equals("Chinook Salmon"))
                        flag = true;
                } while (!flag);

                if (chief.getMoney() < 800) System.out.println("Money is not enough");
                else chief.setMoney(chief.getMoney() - 800);

                farm.add(new Type(habitat, animal, size, name, 0, type));
                currSalt+=2;
            } else {
                do {
                    System.out.print("Input animal name [3 - 5 characters] : \n");
                    name = sc.nextLine();
                    if (name.length() > 2 && name.length() < 6)
                        flag = true;
                } while (!flag);

                do {
                    System.out.print("Input animal size [Small | Medium | Large] : \n");
                    size = sc.nextLine();
                    if (size.equals("Small") || size.equals("Medium") || size.equals("Large"))
                        flag = false;
                } while (flag);

                do {
                    System.out.printf("Input %s type [Channel Catfish | Blue Catfish] : \n", animal);
                    type = sc.nextLine();
                    if (type.equals("Channel Catfish") || type.equals("Blue Catfish"))
                        flag = true;
                } while (!flag);

                if (chief.getMoney() < 100) System.out.println("Money is not enough");
                else chief.setMoney(chief.getMoney() - 100);
                farm.add(new Type(habitat, animal, size, name, 0, type));
                currFresh+=2;

            }
        } else {
            do {
                System.out.print("Input animal  [Cow/Duck] : ");
                animal = sc.nextLine();
                if (animal.equals("Cow") || animal.equals("Duck"))
                    flag = false;
            } while (flag);

            if (animal.equals("Duck")) {
                do {
                    System.out.print("Input animal name [3 - 5 characters] : \n");
                    name = sc.nextLine();
                    if (name.length() > 2 && name.length() < 6)
                        flag = true;
                } while (!flag);

                do {
                    System.out.print("Input animal size [Small | Medium | Large] : \n");
                    size = sc.nextLine();
                    if (size.equals("Small") || size.equals("Medium") || size.equals("Large"))
                        flag = false;
                } while (flag);

                do {
                    System.out.printf("Input %s type [Bali Duck | Campbell Duck] : \n", animal);
                    type = sc.nextLine();
                    if (type.equals("Bali Duck") || type.equals("Campbell Duck"))
                        flag = true;
                } while (!flag);

                if (chief.getMoney() < 200) System.out.println("Money is not enough");
                else chief.setMoney(chief.getMoney() - 200);

                farm.add(new Type(habitat, animal, size, name, 0, type));
                currLand+=2;
            } else {
                do {
                    System.out.print("Input animal name [3 - 5 characters] : \n");
                    name = sc.nextLine();
                    if (name.length() > 2 && name.length() < 6)
                        flag = true;
                } while (!flag);

                do {
                    System.out.print("Input animal size [Small | Medium | Large] : \n");
                    size = sc.nextLine();
                    if (size.equals("Small") || size.equals("Medium") || size.equals("Large"))
                        flag = false;
                } while (flag);

                do {
                    System.out.printf("Input %s type [Angus Cow | Hereford Cow] : \n", animal);
                    type = sc.nextLine();
                    if (type.equals("Angus Cow") || type.equals("Hereford Cow"))
                        flag = true;
                } while (!flag);

                if (chief.getMoney() < 400) System.out.println("Money is not enough");
                else chief.setMoney(chief.getMoney() - 400);
                farm.add(new Type(habitat, animal, size, name, 0, type));
                currLand+=4;

            }
        }
    }

    private void sell() {
        boolean flag = false;
        do {
            int sold = 0;
            System.out.printf("Input animal index [1 - %d] : \n", farm.size());
            int index = sc.nextInt(); sc.nextLine();
            if (index > 0 && index < farm.size()) {
                String temp = farm.get(index - 1).getSize();
                String tmp = farm.get(index - 1).getKind();
                farm.remove(index - 1);
                System.out.println("Animal successfully sold");
                flag = true;

                switch (tmp) {
                    case "Cow" -> sold +=500;
                    case "Duck" -> sold +=280;
                    case "Catfish" -> sold +=120;
                    case "Salmon" -> sold +=1000;
                }

                switch (temp) {
                    case "Small" -> sold +=70;
                    case "Medium" -> sold +=350;
                    case "Large" -> sold +=800;
                }
            }

        } while (!flag);
    }
    public static void main(String[] args) {
        new Main();
    }
}