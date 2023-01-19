import java.util.Scanner;
public class GPA{
  static String[] subject = new String[3];
  static int[] creadits = new int[3];
  static String[] grade = new String[3];
  static double[] gradenum = new double[3];

  public static void put(){
    Scanner sc= new Scanner(System.in);
    for(int i=0; i<3; i++){
      System.out.printf("Subject %d is ",i+1);
      String s =sc.next();
      subject[i]=s;
      System.out.printf("Credits %d is ",i+1);
      int c=sc.nextInt();
      creadits[i]=c;
      System.out.printf("Grade %d is ",i+1);
      String g=sc.next();
      grade[i]=g;
    }
  }


  public void turngrade(){
    for(int i=0;i<3;i++){
      if (grade[i].equals("A+"))
       gradenum[i]=4.5;
     else if (grade[i].equals("A"))
        gradenum[i]=4.0;
     else if (grade[i].equals("B+"))
        gradenum[i]=3.5;
     else if (grade[i].equals("B"))
        gradenum[i]=3.0;
     else if (grade[i].equals("C+"))
       gradenum[i]=2.5;
     else if (grade[i].equals("C"))
        gradenum[i]=2.0;
     else if (grade[i].equals("D+"))
        gradenum[i]=1.5;
     else if (grade[i].equals("D"))
        gradenum[i]=1.0;
     else if (grade[i].equals("F"))
       gradenum[i]=0.0;
    }
  }

  public void GPA(){
    double sum;
    sum= ((creadits[0]*gradenum[0])+(creadits[1]*gradenum[1])+(creadits[2]*gradenum[2]))/(creadits[0]+creadits[1]+creadits[2]);
    System.out.println("GPA is "+sum);
  }


  public static void main(String[] args){
    GPA g= new GPA();
    g.put();
    g.turngrade();
    g.GPA();
  }
}
