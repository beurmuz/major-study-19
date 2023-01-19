public class GuguMain{
    public static void main(String[] args)  {
    int[] a={1,2,3,4,5,6,7,8,9};
    Gugu m=new Gugu();
    m.gu();
  }
}

class Gugu{
  public static int[] a=new int[9];
  public static void gu(){
    int i, j;
    for(i=1;i<=9;i++) {
      System.out.printf("\n%d´Ü :",i);
        for(j=1;j<=9;j++) {
        System.out.printf("\t%dx%d=%2d ",i,j,i*j);
    }
  }
}
}
