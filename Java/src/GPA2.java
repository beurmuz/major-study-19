import java.util.Scanner;

public class GPA2{
  static double computegrade(String grade) {
    double marks;
    if (grade.equals("A")){
      marks = 4.0;
    } else if (grade.equals("B")){
      marks = 3.0;
    } else if (grade.equals("C")){
      marks = 2.0;
    } else if (grade.equals("D")){
      marks = 1.0;
    } else {
      marks = 0.0;
    }
    return marks;
  }
  public static void main(String[] args) {
    String[] subject = new String[3];
    int[] credits = new int[3];
    String[] grade = new String[3];
    double[] marks = new double[3];
    int sumCredit = 0;
    double sumMarks = 0.0;
    double gpa = 0.0;
    Scanner sc = new Scanner(System.in);
    for(int i = 0; i < 3; i++) {
      System.out.print("Enter Subject Credits Grade: \n");
      subject[i] = sc.next();
      credits[i] = sc.nextInt();
      grade[i] = sc.next();
      marks[i] = computegrade(grade[i]);
    }
    for(int i = 0; i < 3; i++) {
      sumCredit += credits[i];
      sumMarks += marks[i] * credits[i];
    }
    gpa = sumMarks/sumCredit;
    System.out.printf("my GPA is %f", gpa);
  }
}
