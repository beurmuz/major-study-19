public class Numbers0{
  private int sum=0;
  private int num1;
  void printSum(int from, int to){
      num1=from;
      while(from<=to){
        sum+=from;
        from++;
      }
  System.out.printf("from %d to %d of sum %d",num1,to,sum);
  }

  public static void main(String[] args){
    Numbers0 n=new Numbers();
    n.printSum(1,100);
  }
}
