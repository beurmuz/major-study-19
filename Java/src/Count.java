//7HongiDong 에서 숫자, 대문자, 소문자 개수와 목록 출력하기

import java.util.*;
import java.io.*;

public class Count{
  static Map<String,Integer> wc= new HashMap<String,Integer>();
  static ArrayList<Integer> numList=new ArrayList<Integer>();
  static ArrayList<String> charList1=new ArrayList<String>();
  static ArrayList<String> charList2=new ArrayList<String>();

  static String s="7HongiDong";
  static char[] letters=s.toCharArray();

  static String keyName;
  static int ascii;
  static Map getFrequencies(String words){
  for(char c:letters){
    ascii=(int)c;
    if(ascii>=48 && ascii<=57){
      keyName="DIGITS";
      numList.add(Character.getNumericValue(c));
    } else if(ascii>=65 && ascii<=90){
      keyName="big LETTERS";
      charList1.add(Character.toString(c));
    } else if(ascii>=97 && ascii<=122){
      keyName="small LETTERS";
      charList2.add(Character.toString(c));
    }
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
  Count c=new Count();
  c.getFrequencies("7HongiDong");
  System.out.print(wc);
  System.out.print(numList);
  System.out.print(charList1);
  System.out.print(charList2);

  }
}
