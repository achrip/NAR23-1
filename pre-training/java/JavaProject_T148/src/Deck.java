import java.util.ArrayList;
import java.util.Collections;

public class Deck {
        private final ArrayList<String> deck = new ArrayList<>();
        private final String[] strings = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        private final char[] chars = {'♧', '♡', '♢', '♤'};


    public Deck(){
        //populate deck
        for (String s : strings){
            for (char c : chars){
                String tmp = s + c;
                deck.add(tmp);
            }
        }
    }

    public void shuffle(){
        Collections.shuffle(deck);
    }

    public String draw(){
        return deck.remove(0);
    }


}
