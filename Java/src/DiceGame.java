import java.lang.Math;
import java.util.Random;


public class DiceGame{
  Player p1=new Player("KIM");
  Player p2=new Player("JANG");

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

    DiceGame d=new DiceGame();
    d.startGame();
 }
}
