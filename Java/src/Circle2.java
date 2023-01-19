import java.util.Scanner;

public class Circle2{
  public float radius;
  public double result;
  public Circle2(float r){
    radius=r;
  }

public double calcArea(){
  result=radius*radius*(float)3.14;
  System.out.printf("Area: %.1f",result);
  return 0;
}

public static void main(String[] args){
  System.out.println("Enter radius: ");
  Scanner sc=new Scanner(System.in);
  float ent=sc.nextFloat();
  Circle c=new Circle(ent);
  c.calcArea();
}
}
