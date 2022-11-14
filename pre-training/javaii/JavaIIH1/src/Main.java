import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
    private Scanner sc = new Scanner(System.in);
    private ArrayList<Anime> animu = new ArrayList<>();

    void cls() {
        for (int i = 0; i < 32; i++) {
            System.out.println();
        }
    }

    public Main(){
        while (true) {
            System.out.println("""
                 __     __     _      _   _                 _                 ____     _____
                 \\ \\   /"/uU  /"\\  u | \\ |"|       ___     |"|        ___    / __"| u |_ " _|
                  \\ \\ / //  \\/ _ \\/ <|  \\| |>     |_"_|  U | | u     |_"_|  <\\___ \\/    | |
                  /\\ V /_,-./ ___ \\ U| |\\  |u      | |    \\| |/__     | |    u___) |   /| |\\
                 U  \\_/-(_//_/   \\_\\ |_| \\_|     U/| |\\u   |_____|  U/| |\\u  |____/>> u |_|U
                   //       \\\\    >> ||   \\\\,-.-,_|___|_,-.//  \\\\.-,_|___|_,-.)(  (__)_// \\\\_
                  (__)     (__)  (__)(_")  (_/ \\_)-' '-(_/(_")("_)\\_)-' '-(_/(__)    (__) (__)
                ==========================================================================================
                1. View Anime List
                2. Add New Anime
                3. Delete Anime
                4. Exit VAniList""");
            System.out.print("Which one do you want to choose [1-4] ? ");
            int choose = sc.nextInt() ;
            sc.nextLine();

            switch (choose) {
                case 1 -> query();
                case 2 -> insert();
                case 3 -> delete();
                case 4 -> seeYa();
                default -> {}
            }
        }

    }
        private void query(){
            String check, search;
            boolean flag = false;
            if (animu.isEmpty()) {
                System.out.println("There's no anime");
                sc.nextLine();
                return;
            } else {
                do {
                    System.out.print("Do you want to search by title [Yes or No] ? ");
                    check = sc.nextLine();
                    if (check.equals("Yes") || check.equals("No")) flag = true;
                    else System.out.println("Input must be Yes or No");
                } while (!flag);

                do {
                    if (check.equals("Yes")) {
                        System.out.print("Input the title that you want to search : ");
                        search = sc.nextLine();

                        for (Anime anime: animu) {
                            if (anime.getTitle().contains(search)) {
                                view(search);
                                return;
                            }
                        }
                        System.out.println("The title that you have searched doesn't exist");
                }
            } while (true);
        }

    }

    private void view(String title) {
        cls();
        System.out.println("""
                   __    _  _  ____  __  __  ____  __    ____  ___  ____
                  /__\\  ( \\( )(_  _)(  \\/  )( ___)(  )  (_  _)/ __)(_  _)
                 /(__)\\  )  (  _)(_  )    (  )__)  )(__  _)(_ \\__ \\  )(
                (__)(__)(_)\\_)(____)(_/\\/\\_)(____)(____)(____)(___/ (__)
                +=====+==========+========+======================================================+
                | No. | Anime ID | Rating | Anime Title                                          |
                +=====+==========+========+======================================================+""");
        animu.sort(Comparator.comparing(Anime::getRating));
        for (int i = 0; i < animu.size(); i++) {
            System.out.printf("| %-3d .| %-9s| %-7.2f| %-54s|\n", (i + 1), animu.get(i).getId(), animu.get(i).getRating(), animu.get(i).getTitle());
            System.out.println("+=====+==========+========+======================================================+");
        }
        System.out.println();

        int choose;
        boolean flag = false;
        do {
            System.out.print("Please choose which anime to view detail [0 to go back] : ");
            choose = sc.nextInt();
            sc.nextLine();
            if (choose < 1 || choose > animu.size()) System.out.printf("Input must be [1 - %d] ", animu.size());
            else flag = true;
        } while (!flag);
        detail(choose);
        return;
    }

    private void detail(int index) {
        String check;
        boolean flag = false;
        cls();
        System.out.printf("%-15s : %s", "ID", animu.get(index).getId());
        System.out.printf("%-15s : %s", "Title", animu.get(index).getTitle());
        System.out.printf("%-15s : %.2f", "Rating", animu.get(index).getRating());
        System.out.printf("%-15s : %d", "Episodes", animu.get(index).getEpisode());
        System.out.printf("%-15s : %s", "Description", animu.get(index).getDescription());
        System.out.printf("%-15s : %s", "Genre", animu.get(index).getGenre());
        do {
            System.out.print("\nDo you want to add rating [Yes or No] ? ");
            check = sc.nextLine();
            if (check.equals("Yes") || check.equals("No")) flag = true;
            else System.out.println("Input must be Yes or No");
        } while (!flag);

        if (check.equals("No")) return;
        else {
            System.out.print("Add rating [1 - 10] : ");
            double rating = sc.nextInt();
                        sc.nextLine();
            double temp = animu.get(index).getRating();
            animu.get(index).setRating((temp + rating) / 2);
            System.out.printf("Rating has been added. The current rating of %s is %.2f", animu.get(index).getTitle(), animu.get(index).getRating());
            System.out.println("\nPress Enter to continue...");
            sc.nextLine();
        }
    }

    private void insert() {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        String title, desc, genre = "", release;
        int eps, genreCount;
        boolean flag = false;
        cls();
        do {
            System.out.print("Input the anime's title [ 5 - 50 characters ] : ");
            title = sc.nextLine();
            if (title.length() > 5 && title.length() < 50) flag = true;
            else System.out.println("The title must be between 5 - 50 characters");
        } while (!flag);

        flag = false;
        do {
            System.out.print("Input the anime's description [ 25 or more characters ] : ");
            desc = sc.nextLine();
            if (desc.length() > 25) flag = true;
            else System.out.println("The description must be more than 25 characters");
        } while (!flag);

        flag = false;
        do {
            System.out.print("Input the anime's released episodes [ 0 or more ] : ");
            eps = sc.nextInt();
                    sc.nextLine();
            if (eps > 0) flag = true;
            else System.out.println("The episode must be 0 or more");
        } while (!flag);

        sdf.setLenient(false);
        flag = false;
        do {
            System.out.print("Input the anime's release date [ dd-MM-yyy ] : ");
            release = sc.nextLine();
            try {
                sdf.parse(release) ;
                flag = true;

            } catch (Exception e) {
                System.out.println("Please enter a valid date [ dd-MM-yyyy ]");
            }
        } while (!flag);

        flag = false;
        do {
            System.out.print("Input the amount of the anime's genre [ more than 0 ] : ");
            genreCount = sc.nextInt();
                            sc.nextLine();
            if (genreCount > 0) flag = true;
            else System.out.println("Please input at least one genre!");
        } while(!flag);

        for (int i = 0; i < genreCount; i++) {
            System.out.print("Input the genre to add [ 3 characters or more ] : ");
            String temp = sc.nextLine();
            if (temp.length() < 3) {
                --i;
                continue;
            }
            genre = String.join(",", genre, temp);
        }
        Random rand = new Random();
        String id = String.join("", "AA", String.valueOf(rand.nextInt(10)),
                            String.valueOf(rand.nextInt(10)), String.valueOf(rand.nextInt(10)));
        animu.add(new Anime(id, 0.00, title, desc,genre, eps));
        System.out.println("A new anime has been added!");
        System.out.print("Press enter to continue...");
        sc.nextLine();
    }

    public void delete() {
        if (animu.isEmpty()) {
            System.out.println("There's no anime");
            sc.nextLine();
            return;
        } else {
            cls();
            System.out.println("""
                       __    _  _  ____  __  __  ____  __    ____  ___  ____
                      /__\\  ( \\( )(_  _)(  \\/  )( ___)(  )  (_  _)/ __)(_  _)
                     /(__)\\  )  (  _)(_  )    (  )__)  )(__  _)(_ \\__ \\  )(
                    (__)(__)(_)\\_)(____)(_/\\/\\_)(____)(____)(____)(___/ (__)
                    +=====+==========+========+======================================================+
                    | No. | Anime ID | Rating | Anime Title                                          |
                    +=====+==========+========+======================================================+""");
            animu.sort(Comparator.comparing(Anime::getRating));
            for (int i = 0; i < animu.size(); i++) {
                System.out.printf("| %-3d .| %-9s| %-7.2f| %-54s|\n", (i + 1), animu.get(i).getId(), animu.get(i).getRating(), animu.get(i).getTitle());
                System.out.println("+=====+==========+========+======================================================+");
            }
            System.out.println();
            int choose;
            boolean flag = false;
            do {
                System.out.print("Please choose which anime to delete [ 0 to go back ] : ");
                choose = sc.nextInt();
                sc.nextLine();
                if (choose < 1 || choose > animu.size()) System.out.printf("Input must be [1 - %d] ", animu.size());
                else flag = true;
            } while (!flag);
            System.out.printf("%s has been successfully deleted", animu.get(choose - 1).getTitle());
            animu.remove(choose - 1);
            System.out.print("\nPress Enter to continue...");
            sc.nextLine();
        }
    }

    private void seeYa() {
        System.out.println("""
                Thanks for using this application !
                %%%%%%%%%%%%%%%%%%%%%%#####*****##%%%%%%%%%%%%%%%%%%%%%%%%
                %%%%%%%%%%%%%%%%%%%#######**####=-==++*#%%%%%%%%%%%%%%%%%%
                %%%%%%%%%%%%%%*******+*%%#**#%%%%##**+=-=++*####%%%%%%%%%%
                %%%%%%%%%%#****##%%%#+*%%#**#%%%%%%%##%####****###%%%%%%%%
                %%%%%%%%#++*##%%%##***%%%%%%%%%%%%%#*#%%%%%%#*+#%##%%%%%%%
                %%%%%%#+=*#%%%#**###%%%%%%%%%%%%%%%%%%%%%%%%%%#**%%%%%%%%%
                %%%%%*=+#%%%#**#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#%%*#%%%%%%%%
                %%%%+=+%%%%**#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##%%#*%%%%%%%
                %%*=-+******###%%%%%%%%%%%%#*=::=%%%%%%%%%%%%%%##***%##%%%
                *+=*#####***+**####%%%%%#=:.    +%%%%%%%%%%%%%%%#++#*%*%%%
                +=*%%#%%%%###*+*#%%##*=-.  .:=*#%%%%%%%%%%%%%%%%%%+**+#%%%
                %**%#%##%%%#*##+**=:.    :+#%##%%%%%%%%%%%%%%%%%%#*=#+%%%%
                %%*###*%%######+-.    .=+=+-.  .:-+*#%%%%%%%%##**+*+*#*%%%
                %%*####%####%#*: .. :+#%#*=-::.     ..:=+++*##*#%%%*+#+%%%
                %%*++*#%%##%%#*-     ...-+##%%%#+=-:      .+#%%%%%%*+#+#%%
                %%++*##%%%##%##**+=-:..      -*%%#=:  ..-+%%%%%%%%%+*#+#%%
                %%+*##%%%%######%%%%%##*+-:=+**-.    -*%%%%%%%%%%%%##**#%%
                %%*=##%%%%#####%####%%%%%%#+=:.  .=*#%%%%%%%%%%%%%%%#+##%%
                %%*++%%%%%%%%%#%%%%%#%%#*=.   .-+%%%%%%%%%%%%%%%%%#%**%##%
                %%%%#*%#=*%%%%%%%%%%%%%+.  .-*#%%%##%%%%%%%%%%%%*#%#+#%##%
                %%%%%*##*++%%%%%%%%%%%%%#++#%%#######%%%%%%%%%%+=**+*##%%%
                %%%%%#*#***%%#%%%%%%%%%%%%%%#####%%####%%%%%%*=+*##%%%%%%%
                %%%%%%#*##**#####%%%%%%##%%%%%%#######%%%%%#==**#%%%%%%%%%
                %%%%%%%%***++*######%%##%%%%%%%%%%%%%%%#*#%##++#%%%%%%%%%%
                %%%%%%%%%%#++***#######*##%%%%%%##*++#*=+*###++#%%%%%%%%%%
                %%%%%%%%%%#*+********#%+#%#**++=--==+#########%%%%%%%%%%%%
                %%%%%%%%%%%%#***++***#*+*##***#**#######%%%%%%%%%%%%%%%%%%
                %%%%%%%%%%%%%%%#%%%%%#+####+*###%%%%%%%%%%%%%%%%%%%%%%%%%%
                %%%%%%%%%%%%%%%%%%%%%#+###*+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n""");

        System.exit(0);
    }
    public static void main(String[] args) { new Main(); }

}
