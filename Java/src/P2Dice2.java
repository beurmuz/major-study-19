import java.lang.Math;
import java.util.Random;

public class Dice{
  public int number1;
  public void roll(){
    number1=(int)(Math.random()*6)+1;
  }
  public int getNum(){
    return number1;
  }
}

class Player{
  public String name;
  public int number2;

  public Player(String name){
      this.name = name;
  }
  public void play(){
    Dice d1=new Dice();
    d1.roll();
    this.number2=d1.getNum();
  }
}

class P1Dice{
  Player p1=new Player("A");
  Player p2=new Player("B");

  public void startGame(){
    System.out.println("Start the game");

    p1.play();
    p2.play();
    System.out.println("Who is winner?  ");

    if(p1.number2>p2.number2)
      System.out.println("the winner is "+ p1.name);
    else if(p1.number2<p2.number2)
      System.out.println("the winner is "+ p2.name);
    else if(p1.number2==p2.number2)
      System.out.println("finish a tie");
    else
      System.out.println("ff");

  }
  public static void main(String []args){

    P1Dice d=new P1Dice();
    d.startGame();
 }
}
