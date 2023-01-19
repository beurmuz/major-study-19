public class Dice{
  public int number1;
  public void roll(){
    number1=(int)(Math.random()*6)+1;
  }
  public int getNum(){
    return number1;
  }
}
