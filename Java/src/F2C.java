import java.util.Scanner;

public class F2C{
  public static void f2c(float f){
  float celsius=((float)5/9)*(f-32);
  System.out.printf("F %.1f -> %.1f C",f,celsius);
  }

  public static void main(String[] args){
    System.out.print("Enter Fahrenheit: ");
    Scanner sc=new Scanner(System.in);
    float f=sc.nextFloat();
    f2c(f);
  }
}
