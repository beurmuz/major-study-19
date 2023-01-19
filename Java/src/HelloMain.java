//여러나라 말로 인사하기.. 인사해라 

public abstract class Hello{
  protected String name;
  public Hello(String name){
    this.name=name;
  }
  abstract public void sayHello();
}
//--------------------------------------------------------------------------
class HelloChinese extends Hello{
  public HelloChinese(String name){
    super(name);
  }
  @Override
  public void sayHello(){
    System.out.println("Nihao" + name);
  }
}
//--------------------------------------------------------------------------
class HelloJapanese extends Hello{
  public HelloJapanese(String name){
    super(name);
  }
  @Override
  public void sayHello(){
    System.out.println("connizziwha "+ name);
  }
}
//--------------------------------------------------------------------------
class HelloKorean extends Hello{
  public HelloKorean(String name){
    super(name);
  }
  @Override
  public void sayHello(){
    System.out.println("안녕하세요"+ name);
  }
}
//--------------------------------------------------------------------------
public class HelloMain{
  public static void main(String[] args){
    Hello[] h=new Hello[3];
    h[0]=new HelloChinese("sr1");
    h[1]=new HelloJapanese("sr2");
    h[2]=new HelloKorean("sr3");
    for(int i=0;i<h.length;i++){
      h[i].sayHello();
    }
    for(int i=0; i<3; i++){
      // System.out.println(h[i]);
    }
  }
}
