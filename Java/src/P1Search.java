import java.util.*;
import java.io.*;

public class P1Search{
  static Map<String,Integer> wc= new HashMap<String,Integer>();
  // static ArrayList<Integer> numList=new ArrayList<Integer>();
  // static ArrayList<String> charList1=new ArrayList<String>();
  static ArrayList<String> charList2=new ArrayList<String>();


  public static String s;
  // "as i stand in this plaza with many of our citizens today to commemorate the 30th anniversary of the June 10 democratic struggle, my heart is indeed filled with deep emotions.";
  // "people, ranging from teenagers to elders in their 70s, from jeju to Seoul and from the southeastern part of korea to the southwestern part of the P1Searchry, shouted with one voice for constitutional revision and the end of dictatorship.";
  // "their fervent chant is still ringing vividly in my ears. in june, 30 years ago, we showed our greatness as a people. in june, 30 years ago, we witnessed the victory of the people.";
  static char[] letters=s.toCharArray();

  static String keyName;
  static int ascii;
  static Map getFrequencies(String words){
  for(char c:letters){
    ascii=(int)c;

    if(ascii>=97 && ascii<=122){
      keyName="LETTERS";
      charList2.add(Character.toString(c));


    s=Character.toString(c);
    if(wc.containsKey(keyName)){
      wc.put(keyName,wc.get(keyName)+1);
    } else{
      wc.put(keyName,1);
    }
  }
return wc;
}

  public static void main(String[] args){
  P1Search c=new P1Search();
  c.getFrequencies("as i stand in this plaza with many of our citizens today to commemorate the 30th anniversary of the June 10 democratic struggle, my heart is indeed filled with deep emotions.
  people, ranging from teenagers to elders in their 70s, from jeju to Seoul and from the southeastern part of korea to the southwestern part of the P1Searchry, shouted with one voice for constitutional revision and the end of dictatorship.
  their fervent chant is still ringing vividly in my ears. in june, 30 years ago, we showed our greatness as a people. in june, 30 years ago, we witnessed the victory of the people.");
  System.out.print(wc);
  // System.out.print(numList);
  // System.out.print(charList1);
  System.out.print(charList2);

  }
}
